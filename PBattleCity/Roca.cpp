#include "Roca.h"
#include "Nivel01.h"

//void Roca::cargarDatosNivel()
//{
//	DatosSimboloConsola imagen;
//	imagen.simbolo = rocaImagen;
//	imagen.colorSimbolo = rocaColorSimbolo;
//	imagen.colorFondo = rocaColorFondo;
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

Roca::Roca()
{
	tipoActor = TipoActor_Obstaculo;
	tipoObstaculo = TipoObstaculo_Roca;
	direccion = Direccion_MAX;
}

void Roca::renderizar(SistemaRenderizacion* _sistemaRenderizacion) {
	Obstaculo::renderizar(_sistemaRenderizacion);
}

void Roca::setImagen(unsigned char _simbolo, ColorConsola _colorSimbolo, ColorConsola _colorFondo) {
	Obstaculo::setImagen(_simbolo, _colorSimbolo, _colorFondo);
};