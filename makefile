build-mac:	
	g++ -std=c++11 main.cpp ./core/Game.cpp ./core/GLFigure.cpp ./core/KeyboardController.cpp ./core/MouseController.cpp ./core/Path.cpp ./core/Perspective.cpp ./core/Texture.cpp ./core/Window.cpp ./figures/Board.cpp ./figures/Box.cpp ./figures/Cloud.cpp ./figures/Clouds.cpp ./figures/Yoshi.cpp ./figures/Snowman.cpp ./utils/Color.cpp ./utils/Position.cpp ./textures/pcxLoader.cpp ./FrameTimer.cpp ./MD2File.cpp MD2Model.cpp -I./ -I./include -I./core -I./figures -I./textures -I./utils -lm -L./libs  -o ./klondike-mac -lSOIL -framework OpenGL -framework GLUT -framework CoreFoundation
	
	
build-linux:	
	g++ -std=c++11 main.cpp ./core/Game.cpp ./core/GLFigure.cpp ./core/KeyboardController.cpp ./core/MouseController.cpp ./core/Path.cpp ./core/Perspective.cpp ./core/Texture.cpp ./core/Window.cpp ./figures/Board.cpp ./figures/Box.cpp ./figures/Cloud.cpp ./figures/Clouds.cpp ./figures/Yoshi.cpp ./figures/Snowman.cpp ./utils/Color.cpp ./utils/Position.cpp ./textures/pcxLoader.cpp ./FrameTimer.cpp ./MD2File.cpp MD2Model.cpp -I./ -I./include -I./core -I./figures -I./textures -I./utils -lm -L./libs  -o ./klondike-linux -lSOIL  -lGL -lGLU -lglut  



