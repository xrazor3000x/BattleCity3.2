#pragma once
#include "Actor.h"
class GeneradorEnemigo :
    public Actor
{
private:
    float generarTemporizador;
    float generarTiempo;
public:
    GeneradorEnemigo();
    virtual void actualizar(float _dt);

};

