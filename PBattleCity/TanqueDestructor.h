#pragma once
#include "Tanque.h"
class TanqueDestructor :
    public Tanque
{
private:
    Actor* tanqueJugador;
protected:
    float analizarTemporizador;
    float analizarTiempo;

    float ultimoAnalisisX;
    float ultimoAnalisisY;

    void analizar(Actor* _tanqueJugador);
    void moverDireccionRandom();
    void moverDireccionIA(Actor* _tanqueJugador);

public:
    TanqueDestructor();
    virtual Tanque* clone()
    {
        return new TanqueDestructor();
    }
    ~TanqueDestructor();
    void actualizar(float _dt);

};

