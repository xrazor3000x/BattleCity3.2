#pragma once
#include "..\ColorConsola.h"


class ObjetoIC
{
private:
	int x;
	int y;
	int ancho;
	int alto;
	bool seleccionado;
	bool visible;
public:

	int getX() { return x; }
	int getY() { return y; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	bool getSeleccionado() { return seleccionado; }
	bool getVisible() { return visible; }

	void setX(int _x) { x = _x; }
	void setY(int _y) { y = _y; }
	void setAncho(int _ancho) { ancho = _ancho; }
	void setAlto(int _alto) { alto = _alto; }
	void setSeleccionado(bool _seleccionado) { seleccionado = _seleccionado; }
	void setVisible(bool _visible) { visible = _visible; }

	virtual void mostrar() = 0;

};


