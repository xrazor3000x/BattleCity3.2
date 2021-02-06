#pragma once
#include "TanqueEnemigo.h"
#include "Utilitarios.h"
#include "TipoEnemigo.h"
class TanqueEnemigoF :
    public TanqueEnemigo
{
private:
    Actor* tanqueJugador;
protected:
    float analizarTemporizador;
    float analizarTiempo;

    float ultimoAnalisisX;
    float ultimoAnalisisY;

    void analizar(Actor* _tanqueJugador)/*override*/ { TanqueEnemigo::analizar(_tanqueJugador); };
    void moverDireccionRandom()/*override*/ { TanqueEnemigo::moverDireccionRandom(); };
    void moverDireccionIA(Actor* _tanqueJugador)/*override*/ { TanqueEnemigo::moverDireccionIA(_tanqueJugador); };

public:
    TanqueEnemigoF();
    ~TanqueEnemigoF() {};
    void actualizar(float _dt)override { TanqueEnemigo::actualizar(_dt); };
    TanqueEnemigo* clone()override
    {
        return new TanqueEnemigoF; 
    }

};

