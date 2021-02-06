#pragma once
#include "Municion.h"

class Bala :
    public Municion
{

public:
    Bala();
    virtual void actualizar(float _dt);
    virtual void renderizar(SistemaRenderizacion* _sistemaRenderizacion);
    virtual void intersectar(Actor* _actor);
};

