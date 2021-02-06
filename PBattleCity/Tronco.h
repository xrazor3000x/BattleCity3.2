#pragma once
#include "Obstaculo.h"
class Tronco :
    public Obstaculo
{
   public:

    //void cargarDatosNivel();
    Tronco();
    void renderizar(SistemaRenderizacion* _sistemaRenderizacion);
    void setImagen(unsigned char _simbolo, ColorConsola _colorSimbolo, ColorConsola _colorFondo);
};

