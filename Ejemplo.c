 

#include <stdlib.h>
#include "glut.h"
#include <stdio.h>
#include <math.h>


#include "GLstuff.h"




// Prototipos de funciones 

//Callbacks de logica del programa
void myLogic();

//Callback de dibujo
void OnDibuja(void);	

//Callback de gestión del teclado
void OnKeyboardDown(unsigned char key, int x, int y);


// Ejemplo de objeto 3D
void drawSnowMan(float x, float y, float z);
  

// Variables globales


// Texture datas tructure
GLuint KLtexture;



float snowman_rot = 0;




int main(int argc,char* argv[])
{
	


 
  // Inicializaciones


  // Inicialización GLUT
  glutInit(&argc, argv);

  // Inicializaciones openGL (ver GLstuff.c)
  init_GL_stuff();
  

  // Definición call backs de GLUT
  glutDisplayFunc(OnDibuja);
	
  glutIdleFunc(myLogic);

  glutKeyboardFunc(OnKeyboardDown);
 
  // posicciona el punto de vista 
  gluLookAt(0,-10,10,           // posicion del  ojo  
	    0.0, 0, 0.0,	// hacia que punto mira  
	    0.0, 1.0, 0.0);     // vector "UP"  (vertical positivo)


  // Carga la textura
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  KLtexture= LoadTexture(900,1074, "klondike.bmp" ); 
  glBindTexture (GL_TEXTURE_2D, KLtexture);

 
  
  // bucle del programa
  glutMainLoop();
  
  return 0;   

  /**************************************************************/}
 


void myLogic()
{

  snowman_rot += 2.0;

  if(snowman_rot>360) snowman_rot = 0;
  
}

/**************************************************************/
/**************************************************************/
/**************************************************************/
/**************************************************************/

void OnDibuja(void)
{ 
  int i;

  //Borrado de la pantalla	
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  // proyeccion de las figuras


  displaytext(KLtexture);
  drawSnowMan(0.03,-0.15,0.2);
  
  
  glLoadIdentity();

  // posicciona el punto de vista 
  gluLookAt(0,-10,10,  // posicion del  ojo  
	    0.0, 0, 0.0,		        // hacia que punto mira  
	    0.0, 1.0, 0.0);         // vector "UP"  (vertical positivo)
  
  
  
  //Al final, cambiar el buffer
  glutSwapBuffers();
  glutPostRedisplay();//se le indica que redibuje la pantalla
  /**************************************************************/
}

 
 


void drawSnowMan(float x, float y, float z)
{

  static float s=0;
  
  // bouncing Snowman
  s+=0.05;
  z = 0.3*sin(s);
  if (s>3.14) {s=0;}


  
  glColor3f(1.0f, 1.0f, 1.0f);

  glPushMatrix();
  
  glTranslatef(x,y,z);
  glRotatef(90,1,0,0);
  glRotatef(snowman_rot,0,1,0);
  glRotatef(0,0,0,1);
  
  
  // Draw Body	
  //  glTranslatef(1.0 ,1.0, 1.0);
  glutSolidSphere(0.15f,20,20);
  
  
  // Draw Head
  glTranslatef(0.0f, 0.15f+0.08f, 0.0f);
  glutSolidSphere(0.08f,20,20);
  
  // Draw Eyes
  glPushMatrix();
  glColor3f(0.0f,0.0f,0.0f);
  glTranslatef(0.015f, 0.06f, 0.08f);
  glutSolidSphere(0.015f,10,10);
  glTranslatef(-0.03f, 0.0f, 0.0f);
  glutSolidSphere(0.015f,10,10);
  glPopMatrix();
  
  // Draw Nose
  glColor3f(1.0f, 0.5f , 0.5f);
  glRotatef(0.0f,1.0f, 0.0f, 0.0f);
  glutSolidCone(0.03f,0.15f,10,2);
  glPopMatrix();
  
}


