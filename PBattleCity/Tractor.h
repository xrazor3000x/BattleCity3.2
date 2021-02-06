#pragma once
#include "Actor.h"


enum TipoTractor
{
	Tractor_LimpiaArbustos,
	Tractor_LimpiaCharcos,
	Tractor_LimpiaPantanos,
	Tractor_LimpiaParedes,
	Tractor_LimpiaRocas,
	Tractor_LimpiaTrocos,
	Tractor_ConstructorArbustos,
	Tractor_ConstructorCharcos,
	Tractor_ConstructorPantanos,
	Tractor_ConstructorParedes,
	Tractor_ConstructorRocas
};

enum MaterialTractor {
	MaterialTractor_Fierro,
	MaterialTractor_Acero,
	MaterialTractor_Platino
};

class Carroceria {
public:
	MaterialTractor materialTractor;
};

enum TipoDesplazamiento {
	TipoDesplazamiento_Ruedas,
	TipoDesplazamiento_Oruga
};

class MecanismoDesplazamiento {
public:
	TipoDesplazamiento tipoDesplazamiento;
};

class Motor {
public:
	float* cilindrada;
};


class Tractor :
    public Actor
{private:
	TipoTractor tipoTractor;
	Carroceria* carroceria;
	MecanismoDesplazamiento* desplazamiento;
	Motor* motor;
};

