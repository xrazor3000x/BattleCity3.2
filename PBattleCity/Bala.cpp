#include "Bala.h"

Bala::Bala() {
	tipoActor = TipoActor_Bala;
	energia = energiaEnemigo;
	velocidad = velocidadBala;

	setImagenMunicion(imagenBala, ColorConsola_Amarillo, ColorConsola_Negro);
}

void Bala::actualizar(float _dt) {
	//Municion::actualizar(_dt);
	Actor::actualizar(_dt);
}

void Bala::renderizar(SistemaRenderizacion* _sistemaRenderizacion) {
	Municion::renderizar(_sistemaRenderizacion);
}

void Bala::intersectar(Actor* _actor) {
	Municion::intersectar(_actor);
}

