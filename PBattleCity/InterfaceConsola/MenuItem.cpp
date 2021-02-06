#include "MenuItem.h"

MenuItem::MenuItem()
{
	setTexto("Menu item");
	setAlto(getAnchoBorde());
	setX(5);
	setY(1);
	setAncho(20);
	setAlto(10);
	setAnchoBorde(1);

}

void MenuItem::mostrar()
{
	Panel::mostrar();
}

void MenuItem::inicializar(int _x, int _y, int _ancho, int _alto, int _anchoBorde,
	char _simboloFondoPanel, ColorConsola _colorSimboloFondoPanel, ColorConsola _colorFondoPanel,
	char _simboloBordePanel, ColorConsola _colorSimboloBordePanel, ColorConsola _colorFondoBordePanel) {
	Panel::inicializar(_x, _y, _ancho, _alto, _anchoBorde, _simboloFondoPanel, _colorSimboloFondoPanel, _colorFondoPanel,
		_simboloBordePanel, _colorSimboloBordePanel, _colorFondoBordePanel);
}
