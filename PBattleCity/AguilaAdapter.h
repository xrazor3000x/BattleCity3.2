#pragma once
#include "Actor.h"
#include "Aguila.h"

class AguilaAdapter :
    public Actor, public Aguila
{
public:
    AguilaAdapter();
	void VisualizarEnPantalla();
	void renderizar(SistemaRenderizacion* _sistemaRenderizacion);
	
};

