#pragma once
#include "Obstaculo.h"

class Bonus :
    public Obstaculo
{
public:
    Bonus();
    void renderizar(SistemaRenderizacion* _sistemaRenderizacion);
    void setImagen(unsigned char _simbolo, ColorConsola _colorSimbolo, ColorConsola _colorFondo);
};

