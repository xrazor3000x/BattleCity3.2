#include "GeneradorEnemigo.h"
#include "Utilitarios.h"
#include "TanqueEnemigo.h"

GeneradorEnemigo::GeneradorEnemigo()
{
	tipoActor = TipoActor_GeneradorEnemigo;
	generarTiempo = generadorEnemigosTiempoGeneracion;
	generarTemporizador = getRandomFloat(0.0, generarTiempo);

	fisico = false;
}

void GeneradorEnemigo::actualizar(float _dt) {
	Actor::actualizar(_dt);

	generarTemporizador += _dt;

	if (generarTemporizador > generarTiempo) {
		generarTemporizador = 0.0f;

		int enemigosEnElNivel = gameManager->getConteoActores(TipoActor_TanqueEnemigo);
		int enemigosDeReserva = enemigosPorNivel - enemigosEnElNivel - gameManager->getConteoEnemigosMuertos();

		if (enemigosDeReserva > 0 && enemigosEnElNivel < enemigosPorNivelEnUnMomento) {
			//gameManager->crearActor(TipoActor_TanqueEnemigo, getX(), getY());
			
			TanqueEnemigo* tanqueEnemigo = gameManager->crearActor<TanqueEnemigo>(getX(), getY());
		}
	}
}