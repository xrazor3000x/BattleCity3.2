#include "Menu.h"
#include "..\GameManager.h"
#include "..\Snapshot.h"
Menu::Menu()
{
}

char Menu::getch2p()
{
    char c = 0;
    DWORD modo = 0, contador;
    HANDLE ih = GetStdHandle(STD_INPUT_HANDLE);

    // Desactivamos escritura en terminal
    SetConsoleMode(ih, modo & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

    ReadConsoleA(ih, &c, 1, &contador, NULL);

    if (c == 0) {
        ReadConsoleA(ih, &c, 1, &contador, NULL);
    }

    SetConsoleMode(ih, modo); // Devolvemos control normal

    return c;
}

void Menu::cursorp(USHORT x, USHORT y) {
    COORD cp = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
}

void Menu::menu_principal(LPCWSTR sound1, LPCWSTR sound2, LPCWSTR sound3)
{
    bool repite = true;
    int opcion;
    PlaySound((sound1), NULL, SND_LOOP | SND_ASYNC);
    // Titulo del menú y nombres de las opciones
    const char* titulo = "";
    const char* opciones[] = { "1 JUGADOR", "2 JUGADORES", "SALIR" };
    const char* marca = "";
    int n = 3;  // Numero de opciones

    do {
        opcion = menu(titulo, opciones, n);

        switch (opcion) {
        case 1:
            PlaySound(NULL, 0, 0);

            PlaySound((sound2), NULL, SND_LOOP | SND_ASYNC);
            jugador1();

            repite = false;
            break;


        case 2:
            PlaySound(NULL, 0, 0);
            PlaySound((sound2), NULL, SND_LOOP | SND_ASYNC);
            jugador2();

            repite = false;
            break;

        case 3:
            /*cout << "\nEl programa se cerrara!! ADIOS" << endl;*/
            PlaySound(NULL, 0, 0);
            repite = false;
            system("pause>nul");
            break;
        }

    } while (repite);
}

void Menu::jugador1()
{
    system("cls");
    //GameManager gameManager; 

    //gameManager.configurarSistema();
    //gameManager.inicializar(datosNivel0);

    //while (gameManager.bucle());
    //gameManager.abandonarJuego();

    GameManager* gameManager = GameManager::getInstancia();


    gameManager->configurarSistema();
    gameManager->inicializar(datosNivel2);

    while (gameManager->bucle());
    gameManager->abandonarJuego();
}
void Menu::jugador2()
{
    system("cls");
    /*GameManager gameManager;

    gameManager.configurarSistema();
    gameManager.Elegirjp2(true);
    gameManager.inicializar(datosNivel0);

    while (gameManager.bucle());
    gameManager.abandonarJuego();*/

    GameManager* gameManager = GameManager::getInstancia();

    gameManager->Elegirjp2(true);
    gameManager->configurarSistema();
    gameManager->inicializar(datosNivel0);

    while (gameManager->bucle());
    gameManager->abandonarJuego();
}



int Menu::menu(const char titulo[], const char* opciones[], int n)
{
    int opcionSeleccionada = 1;  // Indica la opcionSeleccionada

    int tecla;

    bool repite = true; // controla el bucle para regresar a la rutina que lo llamo, al presionar ENTER

    do {
        system("cls");
        /*system("color 1e");*/
        cursorp(40, 16 + opcionSeleccionada); cout << "==>" << endl;

        // Imprime el título del menú
        cursorp(15, 2); cout << titulo;
        cout << ANSI_COLOR_RED"\n\t\t\t ######                                       #####				  ";
        cout << ANSI_COLOR_RED"\n\t\t\t #     #   ##   ##### ##### #      ######    #     # # ##### #   # ";
        cout << ANSI_COLOR_RED"\n\t\t\t ######  #    #   #     #   #      #####     #       #   #     #   ";
        cout << ANSI_COLOR_RED"\n\t\t\t #     # ######   #     #   #      #         #     # #   #     #   ";
        cout << ANSI_COLOR_RED"\n\t\t\t ######  #    #   #     #   ###### ######     #####  #   #     #   ";
        cout << ANSI_COLOR_RESET;
        // Imprime las opciones del menú
        for (int i = 0; i < n; ++i) {
            cursorp(45, 17 + i); cout << i + 1 << ") " << opciones[i];
        }
       /* snapshot->restaurar();
        cout << ANSI_COLOR_BLUE + snapshot->mostrar();;*/
        cout << ANSI_COLOR_BLUE"\n\n\n\n\n\n\n\n\n\t\t\t\t2021. USFX-Chambergo. Todos los derechos reservados                        v3.2.5";
        cout << ANSI_COLOR_RESET;
        // Solo permite que se ingrese ARRIBA, ABAJO o ENTER

        do {
            tecla = getch2p();
            // gotoxy(15, 15); cout << "tecla presionada: " << (char)tecla << " = " << tecla;
        } while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);

        switch (tecla) {

        case ARRIBA:   // En caso que se presione ARRIBA

            opcionSeleccionada--;

            if (opcionSeleccionada < 1) {
                opcionSeleccionada = n;
            }

            break;

        case ABAJO:
            opcionSeleccionada++;

            if (opcionSeleccionada > n) {
                opcionSeleccionada = 1;
            }

            break;

        case ENTER:
            repite = false;
            break;
        }

    } while (repite);

    return opcionSeleccionada;
}
void Menu::Terminar() {


    int tecla;

         bool repite = true; // controla el bucle para regresar a la rutina que lo llamo, al presionar ENTER
    PlaySound(NULL, 0, 0);
    PlaySound(TEXT("Musica\\Rhapsody Emerald Sword 8bit.wav"), NULL, SND_LOOP | SND_ASYNC);
        system("cls");

        /*system("color 1e");*/
        // Imprime el título del menú
        cursorp(15, 2);
        cout << ANSI_COLOR_RED"\n\t\t  ::::::::      :::     ::::    ::::  ::::::::::  ::::::::  :::     ::: :::::::::: :::::::::";
        cout << ANSI_COLOR_RED"\n\t\t :+:    :+:   :+: :+:   +:+:+: :+:+:+ :+:        :+:    :+: :+:     :+: :+:        :+:    :+: ";
        cout << ANSI_COLOR_RED"\n\t\t +:+         +:+   +:+  +:+ +:+:+ +:+ +:+        +:+    +:+ +:+     +:+ +:+        +:+    +:+ ";
        cout << ANSI_COLOR_RED"\n\t\t :#:        +#++:++#++: +#+  +:+  +#+ +#++:++#   +#+    +:+ +#+     +:+ +#++:++#   +#++:++#:   ";
        cout << ANSI_COLOR_RED"\n\t\t +#+   +#+# +#+     +#+ +#+       +#+ +#+        +#+    +#+  +#+   +#+  +#+        +#+    +#+";
        cout << ANSI_COLOR_RED"\n\t\t #+#    #+# #+#     #+# #+#       #+# #+#        #+#    #+#   #+#+#+#   #+#        #+#    #+#  ";
        cout << ANSI_COLOR_RED"\n\t\t  ########  ###     ### ###       ### ##########  ########      ###     ########## ###    ### ";
        cout << ANSI_COLOR_RESET;

        cout << ANSI_COLOR_RESET;


}
           
           
 
 


 


