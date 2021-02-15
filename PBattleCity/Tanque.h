#pragma once
#include <iostream>
#include <string>
#include "Actor.h"
#include "Nivel.h"

using namespace std;


class Tanque : public Actor
{
public:
	Tanque();
	virtual void actualizar(float _dt);
	virtual void renderizar(SistemaRenderizacion* _sistemaRenderizacion);

	//void setColor(ColorConsola _colorTanque1, ColorConsola _colorTanque2);
	void setImagen(ColorConsola _colorSimbolo, ColorConsola _colorFondo);
	void setVelocidad(float _velocidad) { velocidad = _velocidad; }
	float getVelocidad() { return velocidad; }
	void mover(Direccion _direccion);
	void disparar();

	virtual Tanque* clone(){ return NULL; };
protected:
	void calcularPosicionCeldaFrontal(float* _x, float* _y);

protected:
	DatosSimboloConsola imagenTanque[Direccion_MAX][tamanoTanque][tamanoTanque];
	
	float fuegoTiempoEnfriamiento;
	float velocidad;
};

