#include "Bonus.h"
#include "Nivel.h"

Bonus::Bonus()
{
	tipoActor = TipoActor_Obstaculo;
	tipoObstaculo = TipoObstaculo_Bonus;
	direccion = Direccion_MAX;
}
void Bonus::renderizar(SistemaRenderizacion* _sistemaRenderizacion) {
	Obstaculo::renderizar(_sistemaRenderizacion);
}

void Bonus::setImagen(unsigned char _simbolo, ColorConsola _colorSimbolo, ColorConsola _colorFondo) {
	Obstaculo::setImagen(_simbolo, _colorSimbolo, _colorFondo);
};