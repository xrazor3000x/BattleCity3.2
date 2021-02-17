#include "GameManager.h"
#include "TanqueJugador.h"
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <list>
#include <algorithm>

#include "ParedLadrillo.h"
#include "ParedMetal.h"
#include "Arbusto.h"
#include "Charco.h"
#include "Roca.h"
#include "Pantano.h"
#include "Tronco.h"
#include "Bonus.h"

#include "Base.h"
#include "GeneradorEnemigo.h"
#include "TanqueEnemigo.h"
#include "Municion.h"
#include "TanqueDestructor.h"

#include "GeneradorEnemigoF.h"
#include "GenerarBoss.h"

#include "Snapshot.h"
#include "Menu/Menu.h"
#define ARRIBA 87
#define ABAJO 83
#define IZQUIERDA 65
#define DERECHA 68
#define ESC 27
using namespace std;

GameManager* GameManager::instancia = 0;

GameManager* GameManager::getInstancia()
{
	if (instancia == 0)
	{
		instancia = new GameManager();
	}

	return instancia;
}
int GameManager::agregarBonus() {
	puntos = puntos * bonus;
	return puntos;

}
int GameManager::puntuacion()
{
	puntaje= datosEnemigosMuertos.size();
	
	puntos =  puntaje*100;
	puntaje = 0;
	//if (bE) {
	//	puntos=puntos * 2;
	//}
	/*puntos = puntos * 2;*/
	//bE = false;
	return puntos;
}
//void GameManager::Bonus() {
//
//	puntos * 2;
//}
bool GameManager::Elegirjp2(bool a)
{
	eleccion = a;
	return eleccion;
}
GameManager::GameManager()
{
	juegoActivo = true;
	relojUltimoFrame = 0;
	bossMuerto = false;
	puntos = 1;
	base = 0;
	jugador1 = 0;
	jugador2 = 0;
	bE = false;

	contadorEnemigosMuertos = 0;
}

void GameManager::renderizar()
{
	// Frame inicial
	sistemaRenderizacion.limpiar();

	int contadorActores = 0;
	for (list<Actor*>::iterator iLActores = lActores.begin(); iLActores != lActores.end(); ++iLActores) {
		(*iLActores)->renderizar(&sistemaRenderizacion);
		contadorActores++;
	}

	//Dibuja actores contados
	char buffer[64];
	sprintf_s(buffer, "Objectos: %d", contadorActores);
	sistemaRenderizacion.dibujarTexto(0, 0, buffer, ColorConsola_Gris, ColorConsola_Negro);

	//Dibujar Interface de Usuario
	for (int f = 0; f < filasPantalla; f++) {
		for (int c = columnasNivel; c < columnasPantalla; c++)
			sistemaRenderizacion.dibujarCaracter(f, c, ' ', ColorConsola_GrisOscuro, ColorConsola_GrisOscuro);
	}

	//Dibujar los demas elementos del juego

	sistemaRenderizacion.dibujarTexto(2, 100, "Base", ColorConsola_Blanco, ColorConsola_GrisOscuro);
	if (base)
	{
		int sc = 100;
		int sf = 3;
		int c = 0;
		int f = 0;
		int h = base->getEnergia();
		while (h > 0)
		{
			sistemaRenderizacion.dibujarCaracter(sf + f, sc + c, 3, ColorConsola_Rojo, ColorConsola_RojoOscuro);
			--h;
			++c;
			if (c > 7)
			{
				++f;
				c = 0;
			}
		}
	}

	sistemaRenderizacion.dibujarTexto(5, 100, "Jugador 1", ColorConsola_Blanco, ColorConsola_GrisOscuro);
	if (jugador1)
	{
		int sc = 100;
		int sf = 6;
		int c = 0;
		int f = 0;
		int h = jugador1->getEnergia();
		while (h > 0)
		{
			sistemaRenderizacion.dibujarCaracter(sf + f, sc + c, 3, ColorConsola_Amarillo, ColorConsola_Cafe);
			--h;
			++c;
			if (c > 7)
			{
				++f;
				c = 0;
			}
		}
	}

	sistemaRenderizacion.dibujarTexto(9, 100, "Jugador 2", ColorConsola_Blanco, ColorConsola_GrisOscuro);
	if (jugador2)
	{
		int sc = 100;
		int sf = 10;
		int c = 0;
		int f = 0;
		int h = jugador2->getEnergia();
		while (h > 0)
		{
			sistemaRenderizacion.dibujarCaracter(sf + f, sc + c, 3, ColorConsola_Verde, ColorConsola_VerdeOscuro);
			--h;
			++c;
			if (c > 7)
			{
				++f;
				c = 0;
			}
		}
	}

	sistemaRenderizacion.dibujarTexto(13, 100, "Enemigos", ColorConsola_Blanco, ColorConsola_GrisOscuro);
	int sc = 100;
	int sf = 14;
	int c = 0;
	int f = 0;
	int h = enemigosPorNivel - contadorEnemigosMuertos;
	while (h > 0)
	{
		sistemaRenderizacion.dibujarCaracter(sf + f, sc + c, 127, ColorConsola_Celeste, ColorConsola_CelesteOscuro);
		--h;
		++c;
		if (c > 7)
		{
			++f;
			c = 0;
		}
	}

	//Mostrar el numero de enemigos eliminados y las posicion dende fueron destruidos
	sistemaRenderizacion.dibujarTexto(17, 100, "Puntaje", ColorConsola_Azul, ColorConsola_Amarillo);
	h = datosEnemigosMuertos.size();
	/*puntaje = h*100;*/
	puntuacion();
	sistemaRenderizacion.dibujarTexto(19, 100, to_string(h), ColorConsola_GrisOscuro, ColorConsola_Amarillo);
	
	sistemaRenderizacion.dibujarTexto(18, 100, to_string(puntos), ColorConsola_Negro, ColorConsola_Rojo);
	sc = 100;
	sf = 19;
	c = 0;
	f = 0;

	string texto = "";
	while (h > 0)
	{
		/*texto = to_string(datosEnemigosMuertos[f].numeroEnemigo) + ":[" +
			to_string(datosEnemigosMuertos[f].x) + to_string(datosEnemigosMuertos[f].y) + "]/n";*/
		sistemaRenderizacion.dibujarTexto(sf + f, sc + c, texto, ColorConsola_Celeste, ColorConsola_CelesteOscuro);
		--h;
		++f;
		if (f > 7)
		{
			f = 0;
		}
	}

	// Finalizar frame

	sistemaRenderizacion.ejecutar();
}

void GameManager::actualizar(float _dt)
{
	list<Actor*>::iterator iLActores = lActores.begin();
	list<Actor*>::iterator iLActoresAux;
	while (iLActores != lActores.end()) {
		(*iLActores)->actualizar(_dt);
		if ((*iLActores)->getEnergia() <= 0 && (*iLActores)->getDestruirDespuesMuerte())
		{
			if ((*iLActores)->getTipoActor() == TipoActor_TanqueEnemigo)
			{
				datosEnemigosMuertos.push_back(DatosEnemigoMuerto{ (*iLActores)->getNumeroActor(), (*iLActores)->getTipoActor(), (*iLActores)->getX(), (*iLActores)->getY() });
				contadorEnemigosMuertos++;
				
			}
			if ((*iLActores)->getTipoActor() == TipoActor_TanqueEF) 
			{
				datosEnemigosMuertos.push_back(DatosEnemigoMuerto{ (*iLActores)->getNumeroActor(), (*iLActores)->getTipoActor(), (*iLActores)->getX(), (*iLActores)->getY() });
				contadorEnemigosMuertos = contadorEnemigosMuertos + 2;
			
			}
			if ((*iLActores)->getTipoActor() == TipoActor_FinelCountdown) 
			{
				datosEnemigosMuertos.push_back(DatosEnemigoMuerto{ (*iLActores)->getNumeroActor(), (*iLActores)->getTipoActor(), (*iLActores)->getX(), (*iLActores)->getY() });
				contadorEnemigosMuertos++;
				bonus=bonus+10;
				bossMuerto = true;
				
			}
			iLActoresAux = iLActores;
			iLActoresAux++;
			destruirActor((*iLActores));
			iLActores = iLActoresAux;

			//iLActores = lActores.erase(iLActores);
		}
		else {
			++iLActores;
		}
	}

	// Base destruida
	if (base && base->getEnergia() <= 0)
	{
	/*inicializar();*/
	PlaySound(NULL, 0, 0);
	PlaySound(TEXT("Musica\\Live_for_the_Kill_Amon_Amarth_8Bit.wav"), NULL, SND_LOOP | SND_ASYNC);
	configurarSistema();
	inicializar(datosNivel0);
	while (bucle());
	abandonarJuego();
	}
	// Jugador1 destruido
	if (jugador1 && jugador1->getEnergia() <= 0)
	{
		/*destruirActor(jugador1);
		jugador1 = NULL;*/

		destruirActor(jugador1);
		jugador1 = NULL;
		PlaySound(NULL, 0, 0);
		PlaySound(TEXT("Musica\\Live_for_the_Kill_Amon_Amarth_8Bit.wav"), NULL, SND_LOOP | SND_ASYNC);
		configurarSistema();
		inicializar(datosNivel0);
		while (bucle());
		abandonarJuego();
	}

	// Jugador2 destruido
	if (jugador2 && jugador2->getEnergia() <= 0)
	{
		/*destruirActor(jugador2);
		jugador2 = NULL;*/
		destruirActor(jugador2);
		jugador2 = NULL;
		PlaySound(NULL, 0, 0);
		PlaySound(TEXT("Musica\\Live_for_the_Kill_Amon_Amarth_8Bit.wav"), NULL, SND_LOOP | SND_ASYNC);
		configurarSistema();
		inicializar(datosNivel0);
		while (bucle());
		abandonarJuego();
	}
	
	// Todos los enemigos destruidos
	if (contadorEnemigosMuertos == enemigosPorNivel) 
	{
		nivel++;
		/*inicializar();*/
	/*system("cls");*/
		configurarSistema();
		contadorEnemigosMuertos = 0;
		/*	PlaySound(NULL, 0, 0);
			PlaySound(TEXT("Sabaton_Night_Witches_8bit.wav"), NULL, SND_LOOP | SND_ASYNC);

				inicializar(datosNivel1);
				while (bucle());
				abandonarJuego();*/
		switch (nivel) 
		{
			case 1: {
			/*	jugador1->setEnergia(energiaJugador);
				jugador2->setEnergia(energiaJugador);
				base->setEnergia(energiaBase);*/
				jugador1->cargarEnergia(energiaJugador);
				PlaySound(NULL, 0, 0);
				PlaySound(TEXT("Musica\\Sabaton_Night_Witches_8bit.wav"), NULL, SND_LOOP | SND_ASYNC);
				inicializar(datosNivel1);
				while (bucle());
				abandonarJuego();
				break;
				/*nivel++;*/
			}
			case 2: {
			
			/*	jugador1->setEnergia(energiaJugador);
				jugador2->setEnergia(energiaJugador);
				base->setEnergia(energiaBase);*/
				PlaySound(NULL, 0, 0);
				PlaySound(TEXT("Musica\\Rhapsody Emerald Sword 8bit.wav"), NULL, SND_LOOP | SND_ASYNC);
				inicializar(datosNivel2);
				while (bucle());
				abandonarJuego();
				break;
				/*nivel++;*/
			}
		}
	}
	if (bossMuerto) {
		abandonarJuego();
		/*GameOver(false);*/
		Menu menu;
		menu.Terminar();
		/*Snapshot* snapshot = new Snapshot;*/
		/*snapshot->restaurar();
		cout << snapshot->mostrar();*/
		puntuacion();
		agregarBonus();
		cout <</* "\n\t\t\t"+*/puntos;
		bossMuerto = false;
		
	}
}


void GameManager::configurarSistema()
{
	srand(time(0));
	sistemaRenderizacion.inicializar();
}


Actor* GameManager::crearObstaculo(TipoObstaculo _tipoObstaculo, float _x, float _y) {
	Obstaculo* obstaculo = Obstaculo::getObstaculo(_tipoObstaculo);
	
	obstaculo->setGameManager(this);

	if (moverActorA(obstaculo, _x, _y) == false)
	{
		delete obstaculo;
		return NULL;
	}
	
	lActores.push_back(obstaculo);
	return obstaculo;
}



void GameManager::inicializar(const unsigned char nivel[][111])
{
	abandonarJuego();
	sistemaRenderizacion.limpiar();
	contadorEnemigosMuertos = 0;

	for (int f = 0; f < filasNivel; f++) {
		for (int c = 0; c < columnasNivel; c++) {
			unsigned char celdaSimbolo = nivel[f][c];
			switch (celdaSimbolo)
			{
			case celdaSimbolo_ParedLadrillo:
			{
				//Aqui se crea un actor ladrillo pared.
				//ParedLadrillo* paredLadrillo = crearActor<ParedLadrillo>(c, f);
				ParedLadrillo* paredLadrillo = (ParedLadrillo*)crearObstaculo(TipoObstaculo_ParedLadrillo, c, f);
				paredLadrillo->setImagen(paredLadrilloSimbolo, paredLadrilloColorSimbolo, paredLadrilloColorFondo);

				break;
			}
			case celdaSimbolo_ParedMetal:
			{
				//Aqui se crea un actor bloque metal pared.
				//Pared* pared = (Pared*)crearActor(TipoActor_Pared, c, f);
				ParedMetal* paredMetal = crearActor<ParedMetal>(c, f);
				paredMetal->setImagen(paredMetalSimbolo, paredMetalColorSimbolo, paredMetalColorFondo);
				paredMetal->setInvulnerable(true);
				break;
			}

			case celdaSimbolo_Arbusto:
			{
				Arbusto* arbusto = crearActor<Arbusto>(c, f);
				arbusto->setImagen(arbustoImagen, arbustoColorSimbolo, arbustoColorFondo);
				arbusto->setInvulnerable(true);
				arbusto->setFisico(false);
				break;
			}
			case celdaSimbolo_Charco:
			{
				Charco* charco = crearActor<Charco>(c, f);
				charco->setImagen(charcoImagen, charcoColorSimbolo, charcoColorFondo);
				charco->setInvulnerable(true);
				charco->setFisico(false);
				break;
			}
			case celdaSimbolo_Pantano:
			{
				Pantano* pantano = crearActor<Pantano>(c, f);
				pantano->setImagen(pantanoImagen, pantanoColorSimbolo, pantanoColorFondo);
				pantano->setInvulnerable(true);
				pantano->setFisico(false);
				break;
			}
			case celdaSimbolo_Tronco:
			{
				Tronco* tronco = crearActor<Tronco>(c, f);
				tronco->setImagen(troncoImagen, troncoColorSimbolo, troncoColorFondo);
				break;
			}
			case celdaSimbolo_Roca:
			{
				Roca* roca = crearActor<Roca>(c, f);
				roca->setImagen(rocaImagen, rocaColorSimbolo, rocaColorFondo);
				break;
			}
			case celdaSimbolo_Bonus:
			{
				Bonus* bonus = crearActor<Bonus>(c, f);
				bonus->setImagen(bonusImagen, bonusColorSimbolo, bonusColorFondo);
				this->bonus_ = bonus;
				break;
			}


			case celdaSimbolo_Base:
			{
				//Aqui se crea un actor base.
				//base = crearActor(TipoActor_Base, c, f);
				base = crearActor<Base>(c, f);
				
				break;
			}
			case celdaSimbolo_Jugador1:
			{
				//Aqui se crea un actor jugador 1.
				//TanqueJugador* jugador1 = (TanqueJugador*)crearActor(TipoActor_TanqueJugador, c + 0.5, f + 0.5);
				TanqueJugador* jugador1 = crearActor<TanqueJugador>(c + 0.5, f + 0.5);
				jugador1->setImagen(ColorConsola_Cafe, ColorConsola_Negro);
				jugador1->setTeclas(IZQUIERDA, DERECHA, ARRIBA, ABAJO, VK_SPACE, VK_TAB);
				this->jugador1 = jugador1;
				break;
			}
			case celdaSimbolo_Jugador2:
			{
				//Aqui se crea un actor jugador 2.
				if (eleccion) {
					//Aqui se crea un actor jugador 2.
					TanqueJugador* jugador2 = crearActor<TanqueJugador>(c + 0.5, f + 0.5);
					jugador2->setImagen(ColorConsola_Rojo, ColorConsola_Negro);
					jugador2->setTeclas(VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN, VK_NUMPAD0, VK_NUMPAD1);
					this->jugador2 = jugador2;
				}
				break;
			}
			case celdaSimbolo_GeneradorEnemigo:
			{
				//Aqui se crea un actor generador de enemigos.
				crearActor<GeneradorEnemigo>(c, f);
				break;
			}
			case celdaSimbolo_TanqueEF:
			{/*ParedLadrillo* paredLadrillo = (ParedLadrillo*)crearObstaculo(TipoObstaculo_ParedLadrillo, c, f);*/
				//Aqui se crea un actor generador de enemigos.
				
			crearActor<GeneradorEnemigoF>(c, f);
				break;
			}
			case celdaSimbolo_Final:
			{/*ParedLadrillo* paredLadrillo = (ParedLadrillo*)crearObstaculo(TipoObstaculo_ParedLadrillo, c, f);*/
				//Aqui se crea un actor generador de enemigos.

				crearActor<GenerarBoss>(c, f);
				break;
			}
			}
		}
	}
}

bool GameManager::bucle()
{
	//Calculo del tiempo delta
	clock_t relojAhora = clock();
	clock_t deltaReloj = relojAhora - relojUltimoFrame+2;
	float deltaTiempo = float(deltaReloj) / CLOCKS_PER_SEC;
	relojUltimoFrame = relojAhora;

	renderizar();
	actualizar(deltaTiempo);
	return juegoActivo;
}

void GameManager::abandonarJuego()
{
	lActores.clear();
	/*system("cls");*/
	//sistemaRenderizacion.limpiar();
	
}

//Actor* GameManager::crearActor(TipoActor _tipoActor, TipoObstaculo _tipoObstaculo, float _x, float _y)
//{
//	Actor* actor = NULL;
//
//	switch (_tipoActor){
//		case TipoActor_Obstaculo:
//			actor = Obstaculo::getObstaculo(_tipoObstaculo);
//			break;
//		case TipoActor_Base:				actor = new Base();						break;
//		case TipoActor_Municion:			actor = new Municion();					break;
//		//case TipoActor_Bala:				actor = new Bala();						break;
//		case TipoActor_TanqueJugador:		actor = new TanqueJugador();			break;
//		case TipoActor_TanqueEnemigo:		actor = new TanqueEnemigo(jugador1); 	break;
//		case TipoActor_GeneradorEnemigo:	actor = new GeneradorEnemigo();			break;
//	}
//
//	if (actor == NULL)
//		return NULL;
//
//	actor->setGameManager(this);
//
//	if (moverActorA(actor, _x, _y) == false)
//	{
//		delete actor;
//		return NULL;
//	}
//
//	lActores.push_back(actor);
//
//	return actor;
//}


void GameManager::destruirActor(Actor* _actor)
{
	list<Actor*>::iterator iLActores = find(lActores.begin(), lActores.end(), _actor);
	if (iLActores != lActores.end()) {
		lActores.remove(*iLActores);
	}
}

Actor* GameManager::detectarColisiones(float _x, float _y, float _ancho, float _alto, Actor* _actorExcluido)
{
	int f00 = int(_y);
	int c00 = int(_x);
	int f01 = f00 + _alto - 1;
	int c01 = c00 + _ancho - 1;

	int aux = 0;


	for (list<Actor*>::iterator iLActores = lActores.begin(); iLActores != lActores.end(); ++iLActores) {
		
		if ((*iLActores) != NULL && (*iLActores)->getFisico() && (*iLActores) != _actorExcluido) {
			int f10 = int((*iLActores)->getY());
			int c10 = int((*iLActores)->getX());
			int f11 = f10 + (*iLActores)->getAlto() - 1;
			int c11 = c10 + (*iLActores)->getAncho() - 1;

			if (f00 <= f11 && f01 >= f10 && c00 <= c11 && c01 >= c10) {
				return *iLActores;
			}
		}
	}
		
	return NULL;
}

bool GameManager::moverActorA(Actor* actor, float _x, float _y)
{
	int f0 = int(_y);
	int c0 = int(_x);
	int f1 = f0 + int(actor->getAlto()) - 1;
	int c1 = c0 + int(actor->getAncho()) - 1;

	if (f0 < 0 || c0 < 0 || f1 >= filasNivel || c1 >= columnasNivel)
		return false;

	bool puedeMoverACelda = false;

	Actor* otroActor = detectarColisiones(_x, _y, actor->getAncho(), actor->getAlto(), actor);

	if (otroActor != NULL)
	{
		actor->intersectar(otroActor);
		if (otroActor->getTipoActor() == TipoActor_Obstaculo && ((Obstaculo*)otroActor)->getTipoObstaculo() == TipoObstaculo_Pantano) 
		{
			if ((((Tanque*)actor)->getTipoActor() == TipoActor_TanqueJugador) || (((Tanque*)actor)->getTipoActor() == TipoActor_TanqueEnemigo)) {
				((Tanque*)actor)->setVelocidad(3);
				puedeMoverACelda = true;
			}

		}
		if (otroActor->getTipoActor() == TipoActor_Obstaculo && ((Obstaculo*)otroActor)->getTipoObstaculo() == TipoObstaculo_Bonus)
		{
			if ((((Tanque*)actor)->getTipoActor() == TipoActor_TanqueJugador) /*|| (((Tanque*)actor)->getTipoActor() == TipoActor_TanqueEnemigo)*/)
			{
				bonus++;
				destruirActor(bonus_);
				puedeMoverACelda = true;
			}

		}
	}

	else {
		if ((((Tanque*)actor)->getTipoActor() == TipoActor_TanqueJugador) /*|| (((Tanque*)actor)->getTipoActor() == TipoActor_TanqueEnemigo)*/) {
			((Tanque*)actor)->setVelocidad(velocidadJugador);
		}

		puedeMoverACelda = true;
	}

	if (puedeMoverACelda)
	{
		actor->setX(_x);
		actor->setY(_y);
	}

	return puedeMoverACelda;
}


int GameManager::getConteoActores(TipoActor _tipoActor)
{
	return 0;
}

int GameManager::incrementarContadorEnemigosMuertos()
{
	return 0;
}

//int GameManager::agregarEnemigoMuerto(DatosEnemigosMuertos _datosEnemigoMuerto)
//{
//	datosEnemigosMuertos.push_back(_datosEnemigoMuerto);
//	
//	return _datosEnemigoMuerto.numeroEnemigo;
//}


//Tanque* GameManager::crearTanqueDestructor() {
//
//	/*float _x = 10;
//	float _y = 10;
//	TanqueDestructor* tanqueDestructor = crearActor<TanqueDestructor>(_x, _y);
//	return tanqueDestructor;*/
//	return NULL;
//
//}