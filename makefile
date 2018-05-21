echo cd /mnt/c/Users/micro/Documents/klondike


LDFLAGS= -L/usr/local/lib -lglut -lGL -lGLU -lm

all:	
 g++ -o klondike -std=c++11 -L./libs   -lGL -lGLU -lglut -I./ -I./include -lm  Clouds.cpp SnowMan.cpp GLFigure.cpp main.cpp   MD2File.cpp FrameTimer.cpp  Yoshi.cpp Board.cpp   GLUtils.cpp   MD2Model.cpp Game.cpp  pcxLoader.cpp GLController.cpp  Box.cpp 


