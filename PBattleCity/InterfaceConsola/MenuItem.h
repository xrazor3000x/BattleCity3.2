#pragma once
#include "Panel.h"

class MenuItem :
    public Panel
{
public:
	MenuItem();
	void agregarItem(Panel* _item) {};
	void eliminarItem(Panel* _item) {};
	void vaciarItems() {};
	void mostrar();
	void inicializar(int _x, int _y, int _ancho, int _alto, int _anchoBorde,
		char _simboloFondoPanel, ColorConsola _colorSimboloFondoPanel, ColorConsola _colorFondoPanel,
		char _simboloBordePanel, ColorConsola _colorSimboloBordePanel, ColorConsola _colorFondoBordePanel);


};

