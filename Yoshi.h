#include "MD2Model.h"
#include "GlFigure.h"


class Yoshi : MD2Model, Figure {
private:
	unsigned int texture;
public:
	void init();
	void draw();
	void update();
};