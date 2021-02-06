#pragma once
#include "Obstaculo.h"
class Charco :
    public Obstaculo
{
public:
    //void cargarDatosNivel();
    Charco();
    void renderizar(SistemaRenderizacion* _sistemaRenderizacion);
    void setImagen(unsigned char _simbolo, ColorConsola _colorSimbolo, ColorConsola _colorFondo);
};

