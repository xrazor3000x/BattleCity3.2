#pragma once
#include "TanqueEnemigo.h"
#include "TanqueEnemigoF.h"
class TanqueEFactory :
    public TanqueEnemigo
{
private:
    
public:
    TanqueEFactory();
   /* static TanqueEnemigo* tf;
    static TanqueEnemigo* CrearTanqueEnemigo(TipoEnemigo _tipoEnemigo);*/
    TanqueEnemigo* tf;
    TanqueEnemigo* CrearTanqueEF();

};

