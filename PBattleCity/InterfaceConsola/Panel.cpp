#include "Panel.h"

#include "..\Utilitarios.h"
#include "..\ColorConsola.h"

Panel::Panel() {
	setX(0);
	setY(0);
	setAncho(15);
	setAlto(10);
	anchoBorde = 1;
	simboloFondoPanel = 176;
	colorSimboloFondoPanel = ColorConsola_Amarillo;
	colorFondoPanel = ColorConsola_AzulOscuro;
	simboloBordePanel = 178;
	colorSimboloBordePanel = ColorConsola_Cafe;
	colorFondoBordePanel = ColorConsola_Azul;
}

void Panel::inicializar(int _x, int _y, int _ancho, int _alto, int _anchoBorde,
	char _simboloFondoPanel, ColorConsola _colorSimboloFondoPanel, ColorConsola _colorFondoPanel,
	char _simboloBordePanel, ColorConsola _colorSimboloBordePanel, ColorConsola _colorFondoBordePanel) {
	setX(_x);
	setY(_y);
	setAncho(_ancho);
	setAlto(_alto);

	anchoBorde = _anchoBorde;
	simboloFondoPanel = _simboloFondoPanel;
	colorSimboloFondoPanel = _colorSimboloFondoPanel;
	colorFondoPanel = _colorFondoPanel;
	simboloBordePanel = _simboloBordePanel;
	colorSimboloBordePanel = _colorSimboloBordePanel;
	colorFondoBordePanel = _colorFondoBordePanel;
}

void Panel::generarBordes() {
	Coordenada2D c;

	for (int i = 0; i < anchoBorde; i++) {
		for (int j = i; j < getAncho() - i; j++) {
			c.x = getX() + j;
			c.y = getY() + i;
			gotoxy(c.x, c.y);
			cout << getSimboloBordePanel() << endl;

			c.x = getX() + j;
			c.y = getY() + getAlto() - i - 1;
			gotoxy(c.x, c.y);
			cout << getSimboloBordePanel() << endl;
		}

		for (int k = i; k < getAlto() - i - 2; k++)
		{
			c.x = getX() + i;
			c.y = getY() + k + 1;
			gotoxy(c.x, c.y);
			cout << getSimboloBordePanel() << endl;

			c.x = getX() + getAncho() - i - 1;
			c.y = getY() + k + 1;
			gotoxy(c.x, c.y);
			cout << getSimboloBordePanel() << endl;
		}
	}
}

void Panel::generarFondo()
{
	Coordenada2D c;

	for (int i = anchoBorde; i < getAncho() - anchoBorde; i++) {
		for (int j = anchoBorde; j < getAlto() - anchoBorde; j++) {
			c.x = getX() + i;
			c.y = getY() + j;
			gotoxy(c.x, c.y);
			cout << getSimboloFondoPanel() << endl;
		}
	}
}


void Panel::mostrar()
{
	generarFondo();
	generarBordes();
	gotoxy(getX() + anchoBorde, getY() + anchoBorde);
	cout << texto << endl;
}