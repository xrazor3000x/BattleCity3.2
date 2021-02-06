#pragma once
#include "Actor.h"

enum Direccion;

enum EstadoMunicion{
    Inactivo,
    Activado,
    EnCurso,
    Impactado
};

class Municion :
    public Actor
{
protected:
    TipoActor tipoActorPropietario;
    //DatosSimboloConsola imagen;

    //Direccion direccion;
    EstadoMunicion estado;
    int alcance;
    float velocidad;
public:
    Municion();
    TipoActor getTipoActorPropietario() { return tipoActorPropietario; }
    //DatosSimboloConsola getImagenMunicion() { return imagen; }
    //Direccion getDireccion() { return direccion; }
    EstadoMunicion getEstado() { return estado; }
    float getAlcance() { return alcance; }
    float getVelocidad() { return velocidad; }

    void setTipoActorPropietario(TipoActor _tipoActorPropietario) { tipoActorPropietario = _tipoActorPropietario; }
    //void setImagen(DatosSimboloConsola _imagenMunicion) { imagen = _imagenMunicion; }
    /*void setImagen(char _simbolo, ColorConsola _colorSimbolo, ColorConsola _colorFondo) {
        imagen.simbolo = _simbolo;
        imagen.colorSimbolo = _colorSimbolo;
        imagen.colorFondo = _colorFondo;
    }*/

    void setImagenMunicion(unsigned char _simbolo, ColorConsola _colorImagen, ColorConsola _colorFondo);
    //void setDireccion(Direccion _direccion) { direccion = _direccion; }
    void setEstado(EstadoMunicion _estado) { estado = _estado; }
    void setAlcance(float _alcance) { alcance = _alcance; }
    void setVelocidad(float _velocidad) { velocidad = _velocidad; }

    virtual void renderizar(SistemaRenderizacion* _sistemaRenderizacion);
    virtual void actualizar(float _dt);
    virtual void intersectar(Actor* _actor);
};

