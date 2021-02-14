#pragma once
#include "TanqueEnemigo.h"
#include "TanqueEnemigoF.h"
#include "TanqueEnemigoBoss.h"
enum Type {
    PROTOTYPE_1 = NULL,
    PROTOTYPE_2
};
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
    TanqueEnemigo* tfb;
    TanqueEnemigo* CrearTanqueEB();
    void cliente(TanqueEFactory& prototype_factory);
};

