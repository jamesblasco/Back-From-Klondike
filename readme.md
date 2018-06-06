

# Back from the Klondike

![Screenshoot](./screenshot.png)

## INTRODUCCI�N

El proyecto realizado se basa en el juego de estrategia Back from Klondike, en �l se podr� jugar en modo manual o un
modo autom�tico que te va mostrando la soluci�n. Todo el c�digo esta escrito en ingl�s para dar continuidad al
lenguaje c++ estricto con sintaxis anglosajona y poder compartir posteriormente este c�digo en GitHub para cualquier
desarrollador.

Este programa ha sido compilado correctamente el Ubuntu, Windows y MacOS y deber�a ser compatible con el resto de
plataformas unix.

# GU�A DE COMPILACI�N

Se facilita una gu�a de compilaci�n para las distintas plataformas.

**IMPORTANTE** Los ejecutables creados a partir de uno de estos m�todos no se deben mover a otra ubicaci�n. Durante
su ejecuci�n necesita archivos que se encuentran en esa misma carpeta del proyecto.

**WINDOWS**

Se incluye un proyecto de Microsoft Visual Studio que incluye las librer�as necesarias para compilar el proyecto para la
plataforma WIN32. Abra el archivo **Base Klondike.vcxproj** , comprueba que est� en la plataforma **WIN32** con la
configuraci�n **RELEASE** y no 64 y pulsa la tecla **F5**. En la carpeta del proyecto se crear� un ejecutable **klondike-
windows.exe.**

Si desea usar otro compilador para Windows distinto de MVS, como mingw o cygwin, deber�n introducir manualmente
las librer�as

**MACOS**

Se facilita un **makefile** para compilar el proyecto. Acceda a la carpeta del proyecto a trav�s del **terminal** y ejecute el
siguiente comando

```bash
$ make build-mac
```
Se crear� el ejecutable **klondike-mac** en la carpeta del proyecto. Si prefiere compilarlo manualmente compruebe
compar�ndolo con el makefile que a�ade las librer�as y archivos necesarios

**UBUNTU (UNIX)**

Para compilar este programa es necesario tener GLUT instalado en el ordenador. Una forma r�pida de hacerlo es a
trav�s del siguiente comando:

```bash
$ sudo apt - get install freeglut3 - dev
```
Se facilita un **makefile** para compilar el proyecto. Acceda a la carpeta del proyecto a trav�s del **terminal** y ejecute el
siguiente comando

```bash
$ make build-linux
```
Se crear� el ejecutable **klondike-linux** en la carpeta del proyecto. Si prefiere compilarlo manualmente compruebe
compar�ndolo con el makefile que a�ade las librer�as y archivos necesarios


## DIAGRAMA DE COMUNICACI�N DE LAS FASES DEL JUEGO M�S INTERESANTES

Desde _main()_ se configura toda la parte gr�fica de OpenGL y se a�aden los _callbacks_ de las funciones principales de
OpenGL, y se llama al m�todo _init() de_ **_Game_** que carga las texturas.

OpenGL llama al m�todo **_dra_** _w()_ de Game cada vez que quiere pintar todas las figuras por pantalla y este se encarga de
dibujar cada **_Figure_** y mostrar sus texturas y animaciones.

Las clases **_Keyboard_** y **_Mouse_** tienen cada una un m�todo que se ejecutan cuando se interacciona con el teclado o el
rat�n respectivamente. Estos m�todos llaman a m�todos de la clase _Game_ que se encargan de cambiar par�metros de
configuraci�n o cambiar el camino recorrido por el jugador, estos cambios se ven reflejados visualmente cuando
OpenGL llama de nuevo al m�todo **_draw()_** de la clase Game.

En conclusi�n, Game es la clase principal del juego que gestiona por un lado la parte visual del juego usando funciones
b�sicas de OpenGL y por otro lado sus atributos establecen el estado en el que se encuentra el juego y sus m�todos
permiten modificar ese estado.

## DESCRIPCI�N GENERAL DE FUNCIONES Y ESTRUCTURAS M�S REPRESENTATIVAS

Para permitir una mayor legibilidad se ha organizado la mayor parte del c�digo en clases. Aunque se ha implementado
varias funciones, main() es la m�s relevante.

_-_ **_Main()_**_._ Funci�n origen que ejecuta las funciones b�sicas de configuraci�n de OpenGl ( _glutInit,_
    _glutInitDisplayMode, glutCreateWindow, ...)_ , a�ade los _callbacks_ de las funciones principales de OpenGl e
    inicializa la clase Game (Inicializaba las texturas).

Muchas de las clases son est�ticas ya que son clases que deben tener una �nica instancia accesible a trav�s de todo el
programa. Entre estas clases se encuentran por ejemplo `**_Game_**` _,_ **_Keyboard_** _,_ **_Mouse_** _,_ **_Window_** o **_Perspective_**.

# DESCRIPCI�N GENERAL DE LAS CLASES M�S REPRESENTATIVAS

Se realizar� una breve explicaci�n de las clases m�s representativas, para explicaci�n m�s exhaustiva se pueden revisar
los comentarios en el c�digo.

- **Game:** Es una clase est�tica que se encarga del control del juego por medio de los atributos est�ticos tablero,
    personaje, decoraciones, camino seguido, lista de casillas de la soluci�n y el modo de juego.
    Algunos de los m�todos a destacar en game son: **_solve_** _(resuelve el juego),_ **_draw_** _(dibuja las figuras del juego),_
    **_changeMode_** _(cambia el modo de juego), init (carga las texturas necesarias) y_ **_next_** _/_ **_nextStepInSolution_**
    (avanza una casilla en el modo manual o en el autom�tico respectivamente)
- **Figure:** La clase figura contiene los atributos de posici�n, rotaci�n y altura (cuando la figura est� saltando),
    comunes a todas las figuras (existen las figuras tablero, casilla, nube y Yoshi).
    Los m�todos a destacar en figura son _move (mueve la figura), jump (hace que la figura salte), rotate (hace que_
    _la figura rote), draw (es un m�todo virtual puro, ya que se dibuja cada figura que forma espec�fica)._
- **Board:** Es una clase que extiende de las clases figura y textura. Tiene los atributos del tama�o de cada casilla y
    la matriz que contiene todas las casillas (representaci�n del tablero de juego). Los m�todos empleados
    permiten acceder a las casillas mediante su posici�n relativa respecto a la casilla de salida.


- **Box (Casilla):** Es una clase que extiende de la clase figura. Cuenta con los siguientes atributos:
    - Posici�n relativa respecto casilla de salida
    - N�mero de pasos a realizar.
    - Status. Casilla del momento, casilla pasada.
    - Casilla anterior del camino (puntero).
       - Referencia al tablero (mediante puntero).
       - Tipo de casilla (normal, goal o fuera).
       - State. Revisado o sin revisar para el algoritmo
          de b�squeda
Los m�todos empleados son en su mayor�a de tipo **_get_** y **_set_** , para obtener los valores de los atributos.
Tambi�n se utiliza un m�todo para obtener la posible casilla a las que se puede acceder seg�n una direcci�n
determinada.
- **Keyboard/Mouse:** Se emplean ambas clases para controlar el programa mediante las �rdenes del usuario que
    realiza con teclado y rat�n. Los m�todos empleados son los que mandan informaci�n cada vez que se emplea
    rat�n o teclado y llaman a m�todos de la clase _Game_ encargada del control del juego.
- **Path:** Contiene una lista de referencias a las casillas por las que ha pasado el personaje principal. Los m�todos
    a destacar son **_addBox_** _(a�ade una casilla a la lista) y_ **_clear_** _(vac�a la lista)._

Otras clases no tan importantes pero si necesarias son **_Perspective_** , que controla la perspectiva del observador con
respecto a los objetos opengl; **_Position_** / **_Position2D_** , que facilitan las operaciones y comparaciones entre vectores de 2 y
3 dimensiones; **_Color_** , que facilita el uso intuitivo de colores rgba; **_Texture_** , que lee el archivo de la textura, lo guarda y
lo carga en la figura con opengl; y **_Window_** , para controlar el tama�o del ventana y transformar coordenadas de la
ventana(posici�n del rat�n) a coordenadas de opengl.

# DESCRIPCI�N DE PRUEBAS REALIZADAS PARA PROBAR EL CORRECTO FUNCIONAMIENTO DEL ALGORITMO

Optamos desde un principio por la b�squeda por amplitud, ya que pensamos que ser�a lo �ptimo para el caso que se
nos presentaba.

Se implement� el c�digo del algoritmo sobre una base ya existente con la estructura de las clases casilla, tablero y
dem�s. Se utiliz� para ir realizando pruebas, las salidas en pantalla de cout, indicando que se mostraran los resultados
valores de los pasos correspondientes a cada casilla por pantalla. Tambi�n se empleo la salida por pantalla para ir
revisando los estados de las casillas (revisado o sin revisar). Adem�s, buscamos previamente la soluci�n �ptima y
comprobamos que el algoritmo llegaba a la misma soluci�n.

## GU�A DE USO DEL PROGRAMA EJECUTABLE

Al ejecutar el juego, se abre una ventana que muestra un
tablero con el jugador situado en la casilla de inicio. A
medida que avanzas las casillas se van marcado con
esferas verdes aquellas por las que has pasado.

El juego tiene dos modos de uso: Manual y Autom�tico.
En la esquina superior izquierda se indica el modo actual

Para cambiar de modo se tendr� que pulsar

```
1 Modo Autom�tico
2 Modo Manual
```

- **Modo manual**. Permite al jugador intentar resolverlo. Es el modo que viene por **defecto** y por medio de las
    teclas indicadas se podr� avanzar en distintas direcciones permitidas

```
W Avanzar al NORTE
E Avanzar al NORESTE
D Avanzar al ESTE
C Avanzar al SUDESTE
```
```
X Avanzar al SUR
Z Avanzar al SUROESTE
A Avanzar al OESTE
Q Avanzar al NOROESTE
```
- **Modo autom�tico**. Va mostrando al jugador la soluci�n. Cada vez que se pulse el **tabulador** (barra
    espaciadora) avanzar� una casilla de la soluci�n.

**Movimiento de la c�mara**

Para desplazar la vista por el tablero pulse el **bot�n izquierdo** del rat�n y desl�celo por la ventana, en caso de que sea
un dispositivo t�ctil puede deslizar el dedo dentro de la ventana para el mismo efecto.

Con el **bot�n derecho** puede rotar la vista. En un MacBook funci�n pulsando el touchpad con 2 dedos y arrastrando.

Para cerrar el juego pulse la tecla **ESC**


## PROPUESTAS DE MEJORA Y VALORACI�N PERSONAL

Algunas de las ideas que no ha dado tiempo a llevar a cabo son:

- Mejora del decorado, con la inclusi�n de monta�as, �rboles y otros elementos que aportar�an profundidad al
    juego.
- Se pens� en implementar el modo primera persona, d�nde aparecer�an carteles indicando con km el n�mero
    de pasos a realizar. Se buscaba conseguir una uni�n de la historia y el juego.
- Inclusi�n de botones, para poder jugar �nicamente con el rat�n directamente.
- Men� de inicio, con los modos de juego y una breve introducci�n a la historia del juego

