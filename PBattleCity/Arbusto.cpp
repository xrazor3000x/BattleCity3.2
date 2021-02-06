#include "Arbusto.h"
#include "Nivel01.h"

//void Arbusto::cargarDatosNivel()
//{
//	DatosSimboloConsola imagen;
//	imagen.simbolo = arbustoImagen;
//	imagen.colorSimbolo = arbustoColorSimbolo;
//	imagen.colorFondo = arbustoColorFondo;
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

Arbusto::Arbusto()
{
	tipoActor = TipoActor_Obstaculo;
	tipoObstaculo = TipoObstaculo_Arbusto;
	direccion = Direccion_MAX;
}


void Arbusto::renderizar(SistemaRenderizacion* _sistemaRenderizacion) {
	Obstaculo::renderizar(_sistemaRenderizacion);
}

void Arbusto::setImagen(unsigned char _simbolo, ColorConsola _colorSimbolo, ColorConsola _colorFondo) {
	Obstaculo::setImagen(_simbolo, _colorSimbolo, _colorFondo);
};