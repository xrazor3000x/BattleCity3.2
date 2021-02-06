#include "Tronco.h"
#include "Nivel01.h"

//void Tronco::cargarDatosNivel()
//{
//	DatosSimboloConsola imagen;
//	imagen.simbolo = troncoImagen;
//	imagen.colorSimbolo = troncoColorSimbolo;
//	imagen.colorFondo = troncoColorFondo;
//
//	map<int, DatosSimboloConsola> mid;
//	pair<int, DatosSimboloConsola> pid;
//
//	pid.first = 1;
//	pid.second = imagen;
//
//	mid.insert(pid);
//
//	pair<Direccion, map<int, DatosSimboloConsola>> pAvatar;
//	pAvatar.first = Direccion_MAX;
//	pAvatar.second = mid;
//
//	avatar.insert(pAvatar);
//}

Tronco::Tronco()
{
	tipoActor = TipoActor_Obstaculo;
	tipoObstaculo = TipoObstaculo_Tronco;
	direccion = Direccion_MAX;
}


void Tronco::renderizar(SistemaRenderizacion* _sistemaRenderizacion) {
	Obstaculo::renderizar(_sistemaRenderizacion);
}

void Tronco::setImagen(unsigned char _simbolo, ColorConsola _colorSimbolo, ColorConsola _colorFondo) {
	Obstaculo::setImagen(_simbolo, _colorSimbolo, _colorFondo);
};
