#pragma once
#include <Windows.h>
#include "ColorConsola.h"
#include <iostream>
#include <vector>

using namespace std;

const int filasPantalla = 25;
const int columnasPantalla = 110;

struct DatosSimboloConsola {
	char simbolo;
	ColorConsola colorSimbolo;
	ColorConsola colorFondo;
};

class SistemaRenderizacion
{
private:
	HANDLE handdleConsola;
	//DatosSimboloConsola bufferPantalla[filasPantalla][columnasPantalla];
	//DatosSimboloConsola bufferFondoPantalla[filasPantalla][columnasPantalla];
	vector<vector<DatosSimboloConsola>>  mBufferPantalla;
	vector<vector<DatosSimboloConsola>> mBufferFondoPantalla;

public:
	SistemaRenderizacion();

	void inicializar();
	void limpiar();
	void dibujarCaracter(int _fila, int _columna, char _simbolo, ColorConsola _colorSimbolo, ColorConsola _colorFondo);
	void dibujarTexto(int _fila, int _columna, const string _texto, ColorConsola _colorSimbolo, ColorConsola _colorFondo);
	void dibujarTexto(int _fila, int _columna, const char* _texto, ColorConsola _colorSimbolo, ColorConsola _colorFondo);
	void ejecutar();

	void setCursorConsola(int _fila, int _columna);
	void setColorConsola(ColorConsola _colorSimbolo, ColorConsola _colorFondo);
};

