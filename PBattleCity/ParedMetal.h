#pragma once
#include "Obstaculo.h"
class ParedMetal :
    public Obstaculo
{
public:
    ParedMetal();
    void renderizar(SistemaRenderizacion* _sistemaRenderizacion);
    void setImagen(unsigned char _simbolo, ColorConsola _colorSimbolo, ColorConsola _colorFondo);
};

