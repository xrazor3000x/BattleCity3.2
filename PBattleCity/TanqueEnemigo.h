#pragma once
#include "Tanque.h"
#include "GameManager.h"
#include "TanqueJugador.h"
#include "Actor.h"
#include "TipoEnemigo.h"

class TanqueEnemigo :
    public Tanque
{
private:
    Actor* tanqueJugador;
protected:
    float analizarTemporizador;
    float analizarTiempo;

    float ultimoAnalisisX;
    float ultimoAnalisisY;

    virtual void analizar(Actor* _tanqueJugador);
    virtual void moverDireccionRandom();
    virtual void moverDireccionIA(Actor* _tanqueJugador);

public:
    /*TanqueEnemigo(TipoActor _tipoActor) {
        tipoActor = _tipoActor;
    }*/
    TipoEnemigo tipoEnemigo;
    TanqueEnemigo();
    //TanqueEnemigo(Actor* _tanqueJugador);
    ~TanqueEnemigo();
    virtual void actualizar(float _dt);

    virtual TanqueEnemigo* clone()/*const = NULL*/ { return NULL; };
 /*   Tanque* clone()
    {
        return new TanqueEnemigo();
    }*/
};

