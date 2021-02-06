#pragma once
#include "Panel.h"
#include <vector>
#include <iostream>
using namespace std;

class Menu : public Panel {
private:
	vector<Panel*> items;
	int numeroItems;
	int indiceItemActual;
	int indiceItemAnterior;
	bool opcionSalir;
	int opcionMenu;
	int siguienteXItem;
	int siguienteYItem;

public:
	Menu();
	void agregarItem(Panel* _item);
	void eliminarItem(Panel* _item);
	void vaciarItems();

	void mostrar();
	bool getTecla();
	void Bucle();
	void Iniciar();
	void MostrarSelector();
	void inicializar(int _x, int _y, int _ancho, int _alto, int _anchoBorde,
		char _simboloFondoPanel, ColorConsola _colorSimboloFondoPanel, ColorConsola _colorFondoPanel,
		char _simboloBordePanel, ColorConsola _colorSimboloBordePanel, ColorConsola _colorFondoBordePanel);

	void setNumeroItems(int _numeroItems) { numeroItems = _numeroItems; }
	int getNumeroItems() { return numeroItems; }

	void setIndiceItemActual(int _indiceElementoActual) { indiceItemActual = _indiceElementoActual; }
	int getIndiceItemActual() { return indiceItemActual; }

	void setIndiceItemAnterior(int _indiceElementoAnterior) { indiceItemAnterior = _indiceElementoAnterior; }
	int getIndiceItemAnterior() { return indiceItemAnterior; }

	void setOpcionSalir(bool _opcionSalir) { opcionSalir = _opcionSalir; }
	bool getOpcionSalir() { return opcionSalir; }

	void setOpcionMenu(int _opcionMenu) { opcionMenu = _opcionMenu; }
	int getOpcionMenu() { return opcionMenu; }
};
