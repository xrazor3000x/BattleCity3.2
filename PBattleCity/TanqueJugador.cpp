#include "TanqueJugador.h"
#include "Utilitarios.h"

TanqueJugador::TanqueJugador()
{
	tipoActor = TipoActor_TanqueJugador;
	direccion = Direccion_Arriba;
	teclaIzquierda = 0;
	teclaDerecha = 0;
	teclaArriba = 0;
	teclaAbajo = 0;
	teclaDisparoMetralla = 0;
	teclaDisparoCanon = 0;

	energia = energiaJugador;
	velocidad = velocidadJugador;

	destruirDespuesMuerte = false;
}

void TanqueJugador::actualizar(float _dt)
{

	if (IsKeyDown(teclaIzquierda))
		mover(Direccion_Izquierda);
	else if (IsKeyDown(teclaDerecha))
		mover(Direccion_Derecha);
	else if (IsKeyDown(teclaArriba))
		mover(Direccion_Arriba);
	else if (IsKeyDown(teclaAbajo))
		mover(Direccion_Abajo);
	else {
		setXVelocidad(0);
		setYVelocidad(0);
	}

	if (IsKeyDown(teclaDisparoMetralla))
		disparar();
	if (IsKeyDown(teclaDisparoCanon))
		disparar();

	Tanque::actualizar(_dt);

}

void TanqueJugador::setTeclas(int _teclaIzquierda, int _teclaDerecha, int _teclaArriba, int _teclaAbajo, int _teclaDisparoMetralla, int _teclaDisparoCanon)
{
	teclaIzquierda = _teclaIzquierda;
	teclaDerecha = _teclaDerecha;
	teclaArriba = _teclaArriba;
	teclaAbajo = _teclaAbajo;
	teclaDisparoMetralla = _teclaDisparoMetralla;
	teclaDisparoCanon = _teclaDisparoCanon;
}
