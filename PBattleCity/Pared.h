#pragma once
#include "Obstaculo.h"
class Pared :
    public Obstaculo
{
public:
    Pared();
    void renderizar(SistemaRenderizacion* _sistemaRenderizacion);
    void setImagen(unsigned char _simbolo, ColorConsola _colorSimbolo, ColorConsola _colorFondo);
};

