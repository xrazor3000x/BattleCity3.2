#include "Obstaculo.h"
#include "Arbusto.h"
#include "Pantano.h"
#include "ParedLadrillo.h"
#include "ParedMetal.h"
#include "Roca.h"
#include "Tronco.h"
#include "TipoObstaculo.h"

Obstaculo::Obstaculo()
{
	tipoActor = TipoActor_Obstaculo; 
	tipoObstaculo = TipoObstaculo_None;
}

void Obstaculo::renderizar(SistemaRenderizacion* _sistemaRenderizacion)
{
	Actor::renderizar(_sistemaRenderizacion);
}

void Obstaculo::setImagen(unsigned char _simbolo, ColorConsola _colorSimbolo, ColorConsola _colorFondo) {
	DatosSimboloConsola imagenPared;
	imagenPared.simbolo = _simbolo;
	imagenPared.colorSimbolo = _colorSimbolo;
	imagenPared.colorFondo = _colorFondo;

	map<int, DatosSimboloConsola> mid;
	pair<int, DatosSimboloConsola> pid;

	pid.first = 1;
	pid.second = imagenPared;

	mid.insert(pid);

	pair<Direccion, map<int, DatosSimboloConsola>> pAvatar;
	pAvatar.first = Direccion_MAX;
	pAvatar.second = mid;

	avatar.insert(pAvatar);
}

Obstaculo* Obstaculo::getObstaculo(TipoObstaculo _tipoObstaculo)
{
	if (_tipoObstaculo == TipoObstaculo_ParedLadrillo) {
		return new ParedLadrillo();
	}
	else if (_tipoObstaculo == TipoObstaculo_ParedMetal) {
		return new ParedMetal();
	}
	else if (_tipoObstaculo == TipoObstaculo_Pantano) {
		return new Pantano();
	}
	if (_tipoObstaculo == TipoObstaculo_Arbusto) {
		return new Arbusto();
	}
	else if (_tipoObstaculo == TipoObstaculo_Roca) {
		return new Roca();
	}
	else if (_tipoObstaculo == TipoObstaculo_Tronco) {
		return new Tronco();
	}
	else{
		return NULL;
	}
}
