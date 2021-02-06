#include "Actor.h"

int Actor::numeroActores = 0;

//int Actor::getNumeroActores() {
//	return numeroActores;
//}

Actor::Actor()
{
	gameManager = nullptr;
	//gameManager = 0;
	numeroActores++;
	numeroActor = numeroActores;
	tipoActor = TipoActor_None;

	x = 0.0;
	y = 0.0;
	xVelocidad = 0.0;
	yVelocidad = 0.0;
	ancho = 1;
	alto = 1;
	energia = 1;
	limiteSuperiorEnergia = 10;
	limiteInferiorEnergia = 1;
	destruirDespuesMuerte = true;
	invulnerable = false;
	fisico = true;

	direccion = Direccion_Arriba;
}

//Actor::Actor(float _x = 0.0, float _y = 0.0, float _xVelocidad = 0.0, float _yVelocidad = 0.0, int _ancho = 1, int _alto = 1, int _energia = 1)
Actor::Actor(float _x , float _y, float _xVelocidad, float _yVelocidad, int _ancho, int _alto, int _energia)
{
	gameManager = nullptr;
	numeroActores++;
	numeroActor = numeroActores;
	tipoActor = TipoActor_None;

	x = _x;
	y = _y;
	xVelocidad = _xVelocidad;
	yVelocidad = _yVelocidad;
	ancho = _ancho;
	alto = _alto;
	energia = _energia;
	destruirDespuesMuerte = true;
	invulnerable = false;
	fisico = true;

	direccion = Direccion_Arriba;
}

Actor::Actor(GameManager* _gameManager, TipoActor _tipoActor, float _x, float _y, float _xVelocidad, float _yVelocidad, int _ancho, int _alto, 
	int _energia, bool _destrirDespuesMuerte, bool _invulnerable, bool _fisico, Direccion _direccion)
{
	gameManager = _gameManager;
	numeroActores++;
	numeroActor = numeroActores;
	tipoActor = _tipoActor;

	x = _x;
	y = _y;
	xVelocidad = _xVelocidad;
	yVelocidad = _yVelocidad;
	ancho = _ancho;
	alto = _alto;
	energia = _energia;
	destruirDespuesMuerte = _destrirDespuesMuerte;
	invulnerable = _invulnerable;
	fisico = _fisico;

	direccion = _direccion;
}


void Actor::renderizar(SistemaRenderizacion* _sistemaRenderizacion)
{
	if (avatar.size() > 0) {
		map<Direccion, map<int, DatosSimboloConsola>>::iterator ida;
		ida = avatar.find(direccion);
		map<int, DatosSimboloConsola>::iterator iia;

		int fila = int(y);
		int columna = int(x);

		for(iia = (*ida).second.begin(); iia != (*ida).second.end(); ++iia){
			_sistemaRenderizacion->dibujarCaracter(fila, columna, (*iia).second.simbolo, (*iia).second.colorSimbolo, (*iia).second.colorFondo);

			if ((*iia).second.simbolo == 13){
				fila++;
				columna = int(x);
			}
			else {
				columna++;
			}
		}
	}
}

void Actor::actualizar(float _dt)
{
	int filaAnterior = int(y);
	int columnaAnterior = int(x);

	float yNueva = y + yVelocidad * _dt;
	float xNueva = x + xVelocidad * _dt;

	int filaNueva = int(yNueva);
	int columnaNueva = int(xNueva);

	if (columnaAnterior != columnaNueva)
		gameManager->moverActorA(this, xNueva, y);
	else
		x = xNueva;

	if (filaAnterior != filaNueva)
		gameManager->moverActorA(this, x, yNueva);
	else
		y = yNueva;
}


void Actor::intersectar(Actor* _actor)
{

}

void Actor::hacerDano(int _dano)
{
	if (getInvulnerable())
		return;

	if (energia > _dano)
		energia -= _dano;
	else
		energia = 0;
}

void Actor::cargarEnergia(int _energia)
{
	if (getInvulnerable())
		return;

	if (energia < limiteSuperiorEnergia)
		energia += _energia;

	if (energia > limiteSuperiorEnergia)
		energia = limiteSuperiorEnergia;
}


bool Actor::operator==(const Actor& derecho) const
{
	if (numeroActor != derecho.numeroActor)
		return false; // arreglos con distinto número de elementos
	else
		return true;
}