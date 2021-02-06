#pragma once
#include "Actor.h"
class Base :
    public Actor
{
private:
    
    //static Base* instancia;

public:
    Base();
    //static Base* getInstancia();

    virtual void renderizar(SistemaRenderizacion* _sistemaRenderizacion);
};

