#include "Charco.h"
#include "Nivel01.h"

//void Charco::cargarDatosNivel()
//{
//	DatosSimboloConsola imagen;
//	imagen.simbolo = charcoImagen;
//	imagen.colorSimbolo = charcoColorSimbolo;
//	imagen.colorFondo = charcoColorFondo;
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

Charco::Charco()
{
	tipoActor = TipoActor_Obstaculo;
	tipoObstaculo = TipoObstaculo_Charco;
	direccion = Direccion_MAX;
}

void Charco::renderizar(SistemaRenderizacion* _sistemaRenderizacion) {
	Obstaculo::renderizar(_sistemaRenderizacion);
}

void Charco::setImagen(unsigned char _simbolo, ColorConsola _colorSimbolo, ColorConsola _colorFondo) {
	Obstaculo::setImagen(_simbolo, _colorSimbolo, _colorFondo);
};