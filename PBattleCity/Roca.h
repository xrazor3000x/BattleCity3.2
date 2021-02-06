#pragma once
#include "Obstaculo.h"
class Roca :
    public Obstaculo
{public:

    //void cargarDatosNivel();
    Roca();
    void renderizar(SistemaRenderizacion* _sistemaRenderizacion);
    void setImagen(unsigned char _simbolo, ColorConsola _colorSimbolo, ColorConsola _colorFondo);
};

