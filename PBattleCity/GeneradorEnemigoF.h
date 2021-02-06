#pragma once
#include "Actor.h"
#include "Utilitarios.h"
//#include "TanqueEnemigo.h"
#include "TanqueEnemigoF.h"
#include "TanqueEFactory.h"
class GeneradorEnemigoF :
    public Actor
{
private:
    float generarTemporizador;
    float generarTiempo;
public:
    GeneradorEnemigoF();
    virtual void actualizar(float _dt/*,TanqueEFactory _tanqueEFa*/);
    //Actor* crearEnemigo(TipoEnemigo _tipoEnemigo, float _x, float _y);

};

