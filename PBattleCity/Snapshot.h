#pragma once
#include "GameManager.h"
class Snapshot
{
private:
	GameManager  gamemanager;
	int puntos;
public:
	
	Snapshot() {
		puntos = 0;
		
	}
	void restaurar()
	{
		puntos = gamemanager.puntuacion(); 
	}
	
};


