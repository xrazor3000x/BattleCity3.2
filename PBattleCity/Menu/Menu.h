#pragma once
#include <iostream>
#include <windows.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/*
#define ARRIBA 72
#define ABAJO 80
#define ENTER 13
*/


#define ARRIBA 'w'
#define ABAJO 's'
#define ENTER 13


/*
#define ARRIBA 1
#define ABAJO 0
#define ENTER 13
#define INVALIDO -1
*/

using namespace std;
class Menu
{
public:
	Menu();
	char getch2p();
	void cursorp(USHORT x, USHORT y);
	int menu(const char titulo[], const char* opciones[], int n);
	void menu_principal(LPCWSTR sound1, LPCWSTR sound2, LPCWSTR sound3);
	void jugador1();
	void jugador2();

};

