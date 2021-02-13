#pragma once
#include "Actor.h"
#include "Utilitarios.h"
#include "TanqueEnemigoBoss.h"
#include "TanqueEFactory.h"
class GenerarBoss:
    public Actor
{
private:
    float generarTemporizador;
    float generarTiempo;
public:
    GenerarBoss();
    void actualizar(float _dt);
};

