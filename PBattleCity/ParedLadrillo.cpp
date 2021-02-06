#include "ParedLadrillo.h"


ParedLadrillo::ParedLadrillo()
{
	tipoActor = TipoActor_Obstaculo;
	tipoObstaculo = TipoObstaculo_ParedLadrillo;
	direccion = Direccion_MAX;
}

void ParedLadrillo::renderizar(SistemaRenderizacion* _sistemaRenderizacion) {
	Obstaculo::renderizar(_sistemaRenderizacion);
}

void ParedLadrillo::setImagen(unsigned char _simbolo, ColorConsola _colorSimbolo, ColorConsola _colorFondo) {
	Obstaculo::setImagen(_simbolo, _colorSimbolo, _colorFondo);
};