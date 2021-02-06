#pragma once
#include "ObjetoIC.h"
#include <iostream>
#include <string>

using namespace std;

class Panel :
    public ObjetoIC
{
private:
    int anchoBorde;

    char simboloFondoPanel;
    ColorConsola colorSimboloFondoPanel;
    ColorConsola colorFondoPanel;
    char simboloBordePanel;
    ColorConsola colorSimboloBordePanel;
    ColorConsola colorFondoBordePanel;

    string texto;
public:
    Panel();
    virtual void inicializar(int _x, int _y, int _ancho, int _alto, int _anchoBorde,
        char _simboloFondoPanel, ColorConsola _colorSimboloFondoPanel, ColorConsola _colorFondoPanel,
        char _simboloBordePanel, ColorConsola _colorSimboloBordePanel, ColorConsola _colorFondoBordePanel);
    void generarBordes();
    void generarFondo();
    virtual void mostrar();

    virtual void agregarItem(Panel* _item) {};
    virtual void eliminarItem(Panel* _item) {};
    virtual void vaciarItems() {};

    int getAnchoBorde() { return anchoBorde; }
    char getSimboloFondoPanel() { return simboloFondoPanel; }
    ColorConsola getColorSimboloFondoPanel() { return colorSimboloFondoPanel; }
    ColorConsola getColorFondoPanel() { return colorFondoPanel; }
    char getSimboloBordePanel() { return simboloBordePanel; }
    ColorConsola getColorSimboloBordePanel() { return colorSimboloBordePanel; }
    ColorConsola getColorFondoBordePanel() { return colorFondoBordePanel; }
    string getTexto() { return texto; }


    void setAnchoBorde(int _anchoBorde) { anchoBorde = _anchoBorde; }
    void setSimboloFondoPanel(char _simboloFondoPanel) { simboloFondoPanel = _simboloFondoPanel; }
    void setColorSimboloFondoPanel(ColorConsola _colorSimboloFondoPanel) { colorSimboloFondoPanel = _colorSimboloFondoPanel; }
    void setColorFondoPanel(ColorConsola _colorFondoPanel) { colorFondoPanel = _colorFondoPanel; }

    void setSimboloBordePanel(char _simboloBordePanel) { simboloBordePanel = _simboloBordePanel; }
    void setColorSimboloBordePanel(ColorConsola _colorSimboloBordePanel) { colorSimboloBordePanel = _colorSimboloBordePanel; }
    void setColorFondoBordePanel(ColorConsola _colorFondoBordePanel) { colorFondoBordePanel = _colorFondoBordePanel; }

    void setTexto(string _texto) { texto = _texto; }
};

