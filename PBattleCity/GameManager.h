#pragma once
#include <ctime>
#include <vector>
#include <list>
#include "Actor.h"
#include "TipoActor.h"
#include "TipoObstaculo.h"
#include "TipoEnemigo.h"
#include "SistemaRenderizacion.h"
#include "Nivel.h"
#include "Nivel01.h"
#include "Nivel02.h"

const int numeroMaximoActores = 1024;

class Actor;

struct DatosEnemigoMuerto {
	int numeroEnemigo;
	TipoActor tipoEnemigo;
	float x;
	float y;
};


class GameManager
{
public:
	list<Actor*> lActores;
	int nivel = 1;
	int puntos;
	bool bonus;
	/*int teclaMenu = 0;*/

private:
	bool juegoActivo;
	clock_t relojUltimoFrame;
	SistemaRenderizacion sistemaRenderizacion;

	//Actor* actores[numeroMaximoActores];
	vector<Actor*> vActores;
	//list<Actor*> lActores;

	Actor* base;
	Actor* jugador1;
	Actor* jugador2;
	bool eleccion;

	int contadorEnemigosMuertos;
	
	//Vector que almacena los enemigos destruidos, almacenando su numeroActor, TipoActor, x e y
	vector<DatosEnemigoMuerto> datosEnemigosMuertos;

	void renderizar();
	void actualizar(float _dt);

	/*GameManager();*/
	static GameManager* instancia;

public:
	static GameManager* getInstancia();
	GameManager();
	void configurarSistema();
	void inicializar(const unsigned char nivel[][111]);
	bool bucle();
	void abandonarJuego();

	template<class T>
	T* crearActor(float _x, float _y);

	//Actor* crearActor(TipoActor _tipoActor, TipoObstaculo = TipoObstaculo_None, float _x, float _y);

	Actor* getJugador1() { return jugador1; }

	void destruirActor(Actor* _actor);
	Actor* detectarColisiones(float _x, float _y, float _ancho, float _alto, Actor* _actorExcluido);
	bool moverActorA(Actor* _actor, float _x, float _y);
	int getConteoActores(TipoActor _tipoActor);
	int getConteoEnemigosMuertos() { return contadorEnemigosMuertos; }
	int incrementarContadorEnemigosMuertos();
	bool Elegirjp2(bool a);
	int puntuacion();
	void Bonus();
	//int agregarEnemigoMuerto(DatosEnemigosMuertos _datosEnemigoMuerto);
	
	Actor* crearObstaculo(TipoObstaculo _tipoObstaculo, float _x, float _y);
	
	//Tanque* crearTanqueDestructor();
};

template<class T>
inline T* GameManager::crearActor(float _x, float _y)
{
	// Encuentra puntero libre y crea objeto
	T* actor = new T();

	if (actor == NULL)
		return NULL;

	actor->setGameManager(this);

	if (moverActorA(actor, _x, _y) == false)
	{
		delete actor;
		return NULL;
	}

	lActores.push_back(actor);

	return actor;
}


// sobrecarga de operadores para la clase actor
