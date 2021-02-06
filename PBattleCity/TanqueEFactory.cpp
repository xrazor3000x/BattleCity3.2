#include "TanqueEFactory.h"



//void TanqueEFactory::inicializar()
//{
//	
//	//final = new TanqueEnemigoF();
//}

//TanqueEnemigo* TanqueEFactory::getFinal()
//{
//	return final->clone();
//}

//TanqueEnemigo* TanqueEFactory::getFuerte()
//{
//	return new TanqueEnemigoF->clone();
//}

TanqueEFactory::TanqueEFactory()
{
	tf = new  TanqueEnemigoF();
	//tfi = new  TanqueEnemigoBoss();
}
//TanqueEnemigo* TanqueEFactory::CrearTanqueEnemigo(TipoEnemigo _tipoEnemigo)
//{
//	if (_tipoEnemigo == TipoEnemigo_Fuerte) {
//		return tf->clone();
//	else if (_tipoEnemigo == TipoEnemigo_Final) {
//	}
//
//	else
//		return NULL;
//}
TanqueEnemigo* TanqueEFactory::CrearTanqueEF(){

	return tf->clone();
}