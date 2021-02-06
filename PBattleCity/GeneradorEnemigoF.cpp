#include "GeneradorEnemigoF.h"
#include "Actor.h"
GeneradorEnemigoF::GeneradorEnemigoF()
{
	tipoActor = TipoActor_GTanqueEF;
	generarTiempo = generadorEnemigosTiempoGeneracion;
	generarTemporizador = getRandomFloat(0.0, generarTiempo);

	fisico = false;
}
//Actor* GeneradorEnemigoF::crearEnemigo(TipoEnemigo _tipoEnemigo, float _x, float _y) {
//	TanqueEnemigo* tanqueEfactory = TanqueEFactory::CrearTanqueEnemigo(_tipoEnemigo);
//
//	tanqueEfactory->setGameManager(this);
//
//	if (GameManager::moverActorA(tanqueEfactory, _x, _y) == false)
//	{
//		delete tanqueEfactory;
//		return NULL;
//	}
//
//	GameManager::lActores.push_back(tanqueEfactory);
//	return tanqueEfactory;
//}
void GeneradorEnemigoF::actualizar(float _dt/*, TanqueEFactory _tanqueEFa*/) {
	Actor::actualizar(_dt);

	generarTemporizador += _dt;

	if (generarTemporizador > generarTiempo) {
		generarTemporizador = 0.0f;

		int enemigosEnElNivel = gameManager->getConteoActores(TipoActor_TanqueEF);
		int enemigosDeReserva = enemigosFuertesPorNivel - enemigosEnElNivel - gameManager->getConteoEnemigosMuertos();

		if (enemigosDeReserva > 0 && enemigosEnElNivel < enemigosFuertesPorNivelMomento) {
			//gameManager->crearActor(TipoActor_TanqueEnemigo, getX(), getY());
			TanqueEFactory* factory = new TanqueEFactory;
			/*factory = NULL;*/
			TanqueEnemigo* TanqueF = factory->CrearTanqueEF();
			/*TanqueEnemigoF* tanqueEnemigoF*/TanqueF= gameManager->crearActor<TanqueEnemigoF>(getX(), getY());
			/*crearEnemigo();*/
			

		}
	}
}