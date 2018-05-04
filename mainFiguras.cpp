//
// Proyecto basico con OpenGL y Glut
// 06-04-2006
// Modelado y Gestion de la información en ingeniería
//

#define ESC 27
#define EPS 5
#define NONE  0
#define TRANS 1
#define ROT   2


#include "glut.h"
#include <stdio.h>
#include <math.h>
//#include <stdlib.h>



// Prototipos de funciones 
void DibujarCubo(void);
void DibujarCaja(void);
void DibujarPoli(void);
void RotarCaja(float);
void DibujarPlaneta(void);
void DibujarTetera(void);
void drawSnowMan();
void myLogic();


//Callback para teclado y raton
void OnKeyboardDown(unsigned char key, int x, int y);
void OnMouseBtn(int button, int state,int x, int y);
void OnMouseMoveBtn(int x, int y);
void OnSpecKeyboardDown(int key, int x, int y);

//Callbacks de dibujo
void OnDibuja(void);	


// variables globales
float pos[6]={0,0,0,-90,0,0};       // vector de posiciones cubo
float vel[6]={0.25,0.25,0.25,5,5,0};   // vector de velocidades
float posC[6]={0,0,0,-90,0,0};       // vector de posiciones caja
float posP[3]={0.1,0.1,0};  // posición del planeta


// posición y step de la camara
float cam_pos[6]={15.0, 10, -10};
float camvel =0.25;

int MODE=NONE;





int main(int argc,char* argv[])
{
	
  float ancho=400,alto=300;


  // Inicializaciones

  //Creacion y definicion de la ventana
  glutInit(&argc, argv);
  glutInitWindowSize(ancho,alto);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutCreateWindow("Ejemplo GLUT");

  //Habilitar las luces, la renderizacion y el color de los materiales
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_COLOR_MATERIAL);
	
  //definir la proyeccion
  glMatrixMode(GL_PROJECTION);
  gluPerspective( 40.0, ancho/alto, 0.1, 50);

  // define call backs te GLUT
  glutDisplayFunc(OnDibuja);
  glutKeyboardFunc(OnKeyboardDown);
  glutSpecialFunc(OnSpecKeyboardDown);
  glutMotionFunc(OnMouseMoveBtn);
  glutMouseFunc(OnMouseBtn);
	
  glutIdleFunc(myLogic);

  glClearColor(1.0f, 0.31f, 0.9f, 1.0f);    
	
  //Para definir el punto de vista
  glMatrixMode(GL_MODELVIEW);	
  
 
  // posicciona el punto de vista 
  gluLookAt(cam_pos[0],cam_pos[1],cam_pos[2],  // posicion del  ojo  
	    0.0, 0, 0.0,		        // hacia que punto mira  
	    0.0, 1.0, 0.0);         // vector "UP"  (vertical positivo)

  // bucle del programa
  glutMainLoop();
  
  return 0;   

  /**************************************************************/}
 


void myLogic()
{
  RotarCaja(0.5); 
  posP[2]+=0.1;
  posP[1]=2*sin(posP[2]);

  if(posP[2]>15) posP[2]=-15;

}
 

void OnDibuja(void)
{ 
  //Borrado de la pantalla	
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // proyeccion de las figuras
  DibujarCaja();
  DibujarCubo();
  DibujarPoli();
  drawSnowMan();
  DibujarPlaneta();
  DibujarTetera();


  glLoadIdentity();
  // posicciona el punto de vista 
  gluLookAt(cam_pos[0],cam_pos[1],cam_pos[2],  // posicion del  ojo  
	    0.0, 0, 0.0,		        // hacia que punto mira  
	    0.0, 1.0, 0.0);         // vector "UP"  (vertical positivo)

  //Al final, cambiar el buffer
  glutSwapBuffers();
  glutPostRedisplay();//se le indica que redibuje la pantalla
  /**************************************************************/}


void DibujarCaja(void)
{
  
  glPushMatrix();
  glTranslatef(posC[0],posC[1],posC[2]);
  glRotatef(posC[3],1,0,0);
  glRotatef(posC[4],0,1,0);
  glRotatef(posC[5],0,0,1);

  glColor3f(0,1,0);

  glutWireCube(10);	

  glPopMatrix();
}


void DibujarPlaneta(void)
{
  glPushMatrix();
  glTranslatef(posP[0],posP[1],posP[2]);
  glColor3f(0.5,1,0.5);

  glutWireSphere(3,10,10);	

  glPopMatrix();
}

void DibujarTetera(void)
{
  glPushMatrix();
  glTranslatef(0,1,2);
  glColor3f(0.5,1,0.5);

  glutSolidTeapot(2);	

  glPopMatrix();
}

void RotarCaja(float speed)
{
  posC[4]+=speed;
  if(posC[4]>360) posC[4]=0;
}

void DibujarCubo(void)
{
  /**************************************************************/

  glPushMatrix();

  glTranslatef(pos[0],pos[1],pos[2]);
  glRotatef(pos[3],1,0,0);
  glRotatef(pos[4],0,1,0);
  glRotatef(pos[5],0,0,1);

  glColor3f(1,0,0);

  glutSolidCube(3);

  glPopMatrix();
 
}

 

void DibujarPoli(void)
{
   
  glBegin(GL_POLYGON);
  glColor3f(1.0f, 1.0f, 1.0f);
  glVertex3f(0,0,0);
  glVertex3f(5,0,0);
  glVertex3f(5,7,0);
  glVertex3f(0,5,0);
  glEnd();	 

}
   


void OnKeyboardDown(unsigned char key, int x, int y)
{ 
  switch(key)
    {
    case 'q':
    case ESC:
      exit(1);
    case GLUT_KEY_DOWN:pos[1]+=vel[1];
      break;
    case GLUT_KEY_UP:pos[1]-=vel[1];
      break;
    case GLUT_KEY_LEFT:pos[0]+=vel[0];
      break;
    case GLUT_KEY_RIGHT:pos[0]-=vel[0];
      break;
    case GLUT_KEY_PAGE_DOWN:pos[2]+=vel[2];
      break;
    case GLUT_KEY_PAGE_UP:pos[2]-=vel[2];
      break;
    case 'w': cam_pos[0]+=camvel; break;
    case 'z': cam_pos[0]-=camvel; break;
    case 'a': cam_pos[1]+=camvel; break;
    case 's': cam_pos[1]-=camvel; break;
    case '>': cam_pos[2]+=camvel; break;
    case '<': cam_pos[2]-=camvel; break;


    }		

}


void OnSpecKeyboardDown(int key, int x, int y)
{ 
  switch(key)
    {

    case GLUT_KEY_DOWN:pos[0]+=vel[0];
      break;
    case GLUT_KEY_UP:pos[0]-=vel[0];
      printf("UPPPP!!!\n");
      break;
    case GLUT_KEY_LEFT:pos[1]+=vel[1];
      break;
    case GLUT_KEY_RIGHT:pos[1]-=vel[1];
      break;
    case GLUT_KEY_PAGE_DOWN:pos[2]+=vel[2];
      break;
    case GLUT_KEY_PAGE_UP:pos[2]-=vel[2];
      break;


    }		

}


void OnMouseBtn(int button, int state,int x, int y)
{
  if(state==GLUT_DOWN)
    if(button==GLUT_LEFT_BUTTON)
      MODE=TRANS;
    else
      if(button==GLUT_RIGHT_BUTTON)
        MODE=ROT;
      else
        MODE=NONE;
 	
}

 

void  OnMouseMoveBtn  (int x, int y)
{
  static int px=0,py=0;

  if(MODE==TRANS)
    {
      if(x-px>EPS)
	pos[0] -= vel[0];
      else
	if(px-x>EPS)
	  pos[0] += vel[0];
  
      if(y-py>EPS)
	pos[1] -= vel[1];
      else
	if(py-y>EPS)
	  pos[1] += vel[1];
    }
  else
    {
      if(x-px>EPS)
	pos[3] -= vel[3];
      else
	if(px-x>EPS)
	  pos[3] += vel[3];
  
      if(y-py>EPS)
	pos[4] -= vel[4];
      else
	if(py-y>EPS)
	  pos[4] += vel[4];
    }

  px = x;
  py = y;
 
 
}
 

void drawSnowMan() {
	glColor3f(1.0f, 1.0f, 1.0f);

// Draw Body	
	glTranslatef(1.0 ,1.0, 1.0);
	glutSolidSphere(0.75f,20,20);


// Draw Head
	glTranslatef(0.0f, 1.0f, 0.0f);
	glutSolidSphere(0.25f,20,20);

// Draw Eyes
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0.05f, 0.10f, 0.18f);
	glutSolidSphere(0.05f,10,10);
	glTranslatef(-0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.05f,10,10);
	glPopMatrix();

// Draw Nose
	glColor3f(1.0f, 0.5f , 0.5f);
	glRotatef(0.0f,1.0f, 0.0f, 0.0f);
	glutSolidCone(0.08f,0.5f,10,2);
}

