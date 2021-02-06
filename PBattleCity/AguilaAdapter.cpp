#include "AguilaAdapter.h"

AguilaAdapter::AguilaAdapter():Actor(), Aguila("NombreAguila", "W", x, x + ancho, y, y + alto) {
	x = 10;
	y = 15;
	ancho = 1;
	alto = 1;
}


void AguilaAdapter::renderizar(SistemaRenderizacion* _sistemaRenderizacion) {
	Actor::renderizar(_sistemaRenderizacion);
}

void AguilaAdapter::VisualizarEnPantalla()
{

}
