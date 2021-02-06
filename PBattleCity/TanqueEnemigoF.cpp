#include "TanqueEnemigoF.h"
TanqueEnemigoF::TanqueEnemigoF(){
    tipoActor = TipoActor_TanqueEF;
    tipoEnemigo = TipoEnemigo_Fuerte;
    energia = energiaEnemigo + 2;
    velocidad = velocidadEnemigo + 0.5;
    analizarTiempo = tiempoAnalisisIAEnemiga;
    analizarTemporizador = getRandomFloat(0.0, analizarTiempo);
    ultimoAnalisisX = 0.0;
    ultimoAnalisisY = 0.0;
    setImagen(ColorConsola_Rojo, ColorConsola_Negro);
}