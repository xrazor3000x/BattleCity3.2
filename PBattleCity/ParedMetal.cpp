#include "ParedMetal.h"

ParedMetal::ParedMetal()
{
	tipoActor = TipoActor_Obstaculo;
	tipoObstaculo = TipoObstaculo_ParedMetal;
	direccion = Direccion_MAX;
}


void ParedMetal::renderizar(SistemaRenderizacion* _sistemaRenderizacion) {
	Obstaculo::renderizar(_sistemaRenderizacion);
}

void ParedMetal::setImagen(unsigned char _simbolo, ColorConsola _colorSimbolo, ColorConsola _colorFondo) {
	Obstaculo::setImagen(_simbolo, _colorSimbolo, _colorFondo);
};