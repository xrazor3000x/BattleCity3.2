#include "Menu.h"
#include "Menu.h"
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include "..\Utilitarios.h"
#include <iostream>
#include <algorithm>

using namespace std;

Menu::Menu()
{
	numeroItems = 0;
	indiceItemActual = 0;
	indiceItemAnterior = 0;
	setTexto("Menu item");
	setAlto(getAnchoBorde());
	setX(5);
	setY(1);
	setAncho(20);
	setAlto(10);
	setAnchoBorde(1);
	siguienteXItem = getX() + getAnchoBorde();
	siguienteYItem = getY() + getAnchoBorde();

}

void Menu::inicializar(int _x, int _y, int _ancho, int _alto, int _anchoBorde,
	char _simboloFondoPanel, ColorConsola _colorSimboloFondoPanel, ColorConsola _colorFondoPanel,
	char _simboloBordePanel, ColorConsola _colorSimboloBordePanel, ColorConsola _colorFondoBordePanel) {
	Panel::inicializar(_x, _y, _ancho, _alto, _anchoBorde, _simboloFondoPanel, _colorSimboloFondoPanel, _colorFondoPanel,
		_simboloBordePanel, _colorSimboloBordePanel, _colorFondoBordePanel);
}

void Menu::agregarItem(Panel* _item)
{
	_item->setX(getX() + getAnchoBorde());
	_item->setY(siguienteYItem);
	items.push_back(_item);
	numeroItems++;
	siguienteYItem = siguienteYItem + _item->getAlto();
	setAlto(getAlto() + _item->getAlto());
}

void Menu::eliminarItem(Panel* _item)
{
	vector<Panel*>::iterator itmi;
	itmi = find(items.begin(), items.end(), _item);
	if (itmi != items.end()) {
		items.erase(itmi);
	}
}

void Menu::vaciarItems()
{
	items.clear();
}

void Menu::mostrar()
{
	Panel::mostrar();
	vector<Panel*>::iterator itItems;

	for (itItems = items.begin(); itItems != items.end(); ++itItems) {
		(*itItems)->mostrar();
		//cout << (*itItems)->getTexto() << endl;
		//(*itItems)->mostrar();

	}

	/*for (int i = 0; i < getAncho(); i++) {
		for (int j = 0; j < getAlto(); j++) {
			gotoxy(getX() + i, getY() + j);
			cout << getCaracterBase() << endl;
		}
	}

	for (unsigned int i = 0; i < hijos.size(); i++)
	{
		hijos[i]->Mostrar();
	}*/
}

void Menu::MostrarSelector() {
	/*int posxSelector = 0;
	int posySelector = 0;

	EstablecerColor(ObjetoIT::getColorFondoBase(), ObjetoIT::getColorCaracterBase());

	posxSelector = hijos[indiceElementoAnterior]->getX() - 4;
	posySelector = hijos[indiceElementoAnterior]->getY();
	gotoxy(posxSelector, posySelector);
	cout << "   " << endl;

	posxSelector = hijos[indiceElementoActual]->getX() - 4;
	posySelector = hijos[indiceElementoActual]->getY();
	gotoxy(posxSelector, posySelector);
	cout << "-->" << endl;*/
}

bool Menu::getTecla() {
	bool teclaPresionada = false;

	/*char key = ';';

	if (_kbhit()) {
		key = _getch();
	}

	if (key == 72) {
		teclaPresionada = true;

		if (indiceElementoActual > 0)
			indiceElementoActual--;
	}

	if (key == 80) {
		teclaPresionada = true;

		if (indiceElementoActual < numeroElementos - 1)
			indiceElementoActual++;
	}

	if (key == 13) {
		teclaPresionada = true;
		hijos[indiceElementoActual]->OnPressEnter();
		opcionMenu = indiceElementoActual;
		opcionSalir = true;
	}*/

	/*
	if (key == 75) {
		teclaPresionada = true;
	}

	if (key == 77) {
		teclaPresionada = true;
	}
	*/
	//if (key == 27) {
	//	opcionSalir = true;
	//}

	//if (key == 13) {
	//	//Llamar al metodo respectivo
	//}



	return teclaPresionada;
}

void Menu::Bucle() {
	/*while (!opcionSalir) {

		indiceElementoAnterior = indiceElementoActual;

		if (getTecla()) {
			if (indiceElementoActual != indiceElementoAnterior) {
				hijos[indiceElementoAnterior]->setSeleccionado(false);
				hijos[indiceElementoAnterior]->Mostrar();
				hijos[indiceElementoActual]->setSeleccionado(true);
				hijos[indiceElementoActual]->Mostrar();
			}

			gotoxy(27, 7);
			EstablecerColor(0, 15);

			switch (indiceElementoActual)
			{
			case 1:
				cout << "Presione este boton para iniciar el juego." << endl;
				break;
			case 2:
				cout << "Presione este boton para elegir el nivel de dificultada de juego." << endl;
				break;
			case 3:
				cout << "Presione este boton para salir del juego." << endl;
				break;
			}

			MostrarSelector();
		}
	}*/
}


void Menu::Iniciar() {
	/*numeroElementos = hijos.size();
	Bucle();*/
}


