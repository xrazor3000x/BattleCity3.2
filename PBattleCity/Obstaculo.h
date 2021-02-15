#pragma once
#include "Actor.h"
#include "TipoObstaculo.h"


class Obstaculo :
    public Actor
{
public:
    TipoObstaculo tipoObstaculo;

public:
    Obstaculo();
    //virtual void cargarDatosNivel() = 0;
    virtual void renderizar(SistemaRenderizacion* _sistemaRenderizacion);
    virtual void setImagen(unsigned char _simbolo, ColorConsola _colorSimbolo, ColorConsola _colorFondo);
    TipoObstaculo getTipoObstaculo() { return tipoObstaculo; }
    static Obstaculo* getObstaculo(TipoObstaculo _tipoObstaculo);
};

