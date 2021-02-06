#include <iostream>
#include "GameManager.h"
#include "SistemaRenderizacion.h"
#include <vector>
#include <set>
#include <map>
//#include "InterfaceConsola\Panel.h"
//#include "InterfaceConsola\Menu.h"
//#include "InterfaceConsola\MenuItem.h"
#include "Menu/Menu.h"

//#include "Tanque.h"
//#include "Bala.h"
//#include "./Escenario/MuroLadrillo.h"
//#include "./Escenario/MuroMetal.h"
//#include <conio.h>
//#include <stdio.h>
//#include <time.h>
//#include "Municion.h"

using namespace std;



int main()
{
	//El antes de GameManager sin Singleton
	//GameManager gameManager;

	/*Panel* p = new Panel();
	p->inicializar(10, 5, 15, 20, 2, 176, ColorConsola_Azul, ColorConsola_Amarillo, 177, ColorConsola_Blanco, ColorConsola_Cafe);
	p->setTexto("Panel prueba");
	p->mostrar();*/

	//Menu* mRoot = new Menu();
	//mRoot->inicializar(10, 1, 20, 15, 1, 176, ColorConsola_Azul, ColorConsola_Amarillo, 177, ColorConsola_Blanco, ColorConsola_Cafe);
	//mRoot->setTexto("Menu principal");

	//Menu* mSubMenu1 = new Menu();
	//mSubMenu1->inicializar(35, 1, 15, 8, 1, 177, ColorConsola_Azul, ColorConsola_Amarillo, 178, ColorConsola_Blanco, ColorConsola_Cafe);
	//mSubMenu1->setTexto("Submenu 01");
	////mSubMenu1->mostrar();
	//Menu* mSubMenu2 = new Menu();
	//mSubMenu2->inicializar(35, 1, 15, 8, 1, 177, ColorConsola_Azul, ColorConsola_Amarillo, 178, ColorConsola_Blanco, ColorConsola_Cafe);
	//mSubMenu2->setTexto("Submenu 02");
	//Menu* mSubMenu3 = new Menu();
	//mSubMenu3->inicializar(35, 1, 12, 3, 1, 178, ColorConsola_Azul, ColorConsola_Amarillo, 176, ColorConsola_Blanco, ColorConsola_Cafe);
	//mSubMenu3->setTexto("Submenu 03");
	////mSubMenu3->mostrar();
	//
	//MenuItem* mi01 = new MenuItem();
	//mi01->inicializar(55, 1, 12, 3, 1, 219, ColorConsola_Azul, ColorConsola_Amarillo, 240, ColorConsola_Blanco, ColorConsola_Cafe);
	////mi01->mostrar();
	//mSubMenu3->agregarItem(mi01);
	//mSubMenu2->agregarItem(mSubMenu3);
	////mSubMenu2->mostrar();

	//mRoot->agregarItem(mSubMenu1);
	//mRoot->agregarItem(mSubMenu2);
	//mRoot->mostrar();



	/*GameManager* gameManager = GameManager::getInstancia();

	gameManager->configurarSistema();
	gameManager->inicializar();

	while (gameManager->bucle());
	gameManager->abandonarJuego();
	*/

	Menu menu;
	menu.menu_principal(TEXT("Musica\\8_bit_Sabaton_Ghost_Division_menu.wav"), TEXT("Musica\\Live_for_the_Kill_Amon_Amarth_8Bit.wav"), TEXT("Musica\\Sabaton_Night_Witches_8bit.wav"));

	cin.get();
	return 0;
}