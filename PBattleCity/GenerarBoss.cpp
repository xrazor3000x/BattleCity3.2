#include "GenerarBoss.h"
#include "GeneradorEnemigoF.h"
#include "Actor.h"
GenerarBoss::GenerarBoss()
{
	tipoActor = TipoActor_GFinelCountdown;
	generarTiempo = generadorEnemigosTiempoGeneracion;
	generarTemporizador = getRandomFloat(0.0, generarTiempo);

	fisico = false;
}
void GenerarBoss::actualizar(float _dt/*, TanqueEFactory _tanqueEFa*/) {
	Actor::actualizar(_dt);

	generarTemporizador += _dt;

	if (generarTemporizador > generarTiempo) {
		generarTemporizador = 0.0f;

		int enemigosEnElNivel = gameManager->getConteoActores(TipoActor_FinelCountdown);
		int enemigosDeReserva = enemigosBossPorNivel - enemigosEnElNivel - gameManager->getConteoEnemigosMuertos();

		if (enemigosDeReserva > 0 && enemigosEnElNivel < enemigosBossPorNivelMomento) {
			//gameManager->crearActor(TipoActor_TanqueEnemigo, getX(), getY());
			//TanqueEFactory* factory = new TanqueEFactory;
			///*factory = NULL;*/
			//TanqueEnemigo* TanqueB = factory->CrearTanqueEB();
			//TanqueB = gameManager->crearActor<TanqueEnemigoBoss>(getX(), getY());
			
			TanqueEnemigoBoss* tanqueEnemigo = gameManager->crearActor<TanqueEnemigoBoss>(getX(), getY());


		}
	}
}
