#pragma once
#include "Obstaculo.h"
class ParedLadrillo :
    public Obstaculo
{
public:
    ParedLadrillo();
    void renderizar(SistemaRenderizacion* _sistemaRenderizacion);
    void setImagen(unsigned char _simbolo, ColorConsola _colorSimbolo, ColorConsola _colorFondo);

};

