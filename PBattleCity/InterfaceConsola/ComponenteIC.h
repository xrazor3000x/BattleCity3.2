#pragma once
#include "ObjetoIC.h"

class ComponenteIC : public ObjetoIC
{
public:
	ComponenteIC();
	virtual void mostrar() = 0;
};

