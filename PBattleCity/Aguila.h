#pragma once
#include <iostream>

using namespace std;

class Aguila
{

private:
	string NombreAguila;
	string RepresentacionVisual;
	int PosicionXI;
	int PosicionXD;
	int PosicionYS;
	int PosicionYI;
public:
	Aguila(string Nombre, string RepresentacionVisual, int _PosicionXI, int _PosicionXD, int _PosicionYS, int PosicionYI);
	void VisualizarEnPantalla();
	void AtraparAnimal() {};
};

