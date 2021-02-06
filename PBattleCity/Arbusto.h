#pragma once
#include "Obstaculo.h"
class Arbusto :
    public Obstaculo
{
public:
    //void cargarDatosNivel();
    Arbusto();
    void renderizar(SistemaRenderizacion* _sistemaRenderizacion);
    void setImagen(unsigned char _simbolo, ColorConsola _colorSimbolo, ColorConsola _colorFondo);
};

