#pragma once

#include "SistemaRenderizacion.h"
#include "Direccion.h"
#include "Nivel.h"
const unsigned char celdaSimbolo_Arbusto = '&';
const unsigned char celdaSimbolo_Charco = 'C';
const unsigned char celdaSimbolo_TanqueEF = 's';
const unsigned char datosNivel1[filasNivel][columnasNivel + 1] =
{
	"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
	"@ s                         ###                 &&                 ###                          s  @         @",
	"@                           ###                 &&                 ###                             @         @",
	"@     ###      &&&&&        ###                 &&                 ###        &&&&&      ###       @         @",
	"@     CCC       &&&         @@@&&&&&& S   ###CCCCCCCC### S   &&&&&&@@@         &&&       CCC       @         @",
	"@     CCC       &&&         @@@&&&&&&     ###CCC~ CCC###     &&&&&&@@@         &&&       CCC       @         @",
	"@     CCC       &&&                       ###CCCCCCCC###                       &&&       CCC       @         @",
	"@     ###       &&&                       @@@########@@@                       &&&       ###       @         @",
	"@     @@@                                                                                @@@       @         @",
	"@                              @@@                              @@@                                @         @",
	"@                              @@@                              @@@                                @         @",
	"@       #####@@  &  @@@#####   ##########&&            &&##########   #####@@@  &  @@#####         @         @",
	"@       #####@@  &  @@@#####   ######@@###&&&        &&&###@@######   #####@@@  &  @@#####         @         @",
	"@       #####@@  &  @@@#####   ######@@@##&&&        &&&##@@@######   #####@@@  &  @@#####         @         @",
	"@                                 ###@@@@@&&&@@    @@&&&@@@@@###                                   @         @",
	"@                                   ######&&&@@@@@@@@&&&######                                     @         @",
	"@     @@@                                 &&&########&&&                                 @@@       @         @",
	"@     ###         ##&&&##                   &&######&&                   ##&&&##         ###       @         @",
	"@     CCC         #C&&&C#                                                #C&&&C#         CCC       @         @",
	"@     CCC         #C&&&C#   @@@######                        ######@@@   #C&&&C#         CCC       @         @",
	"@     CCC         ##&&&##   @@@######                        ######@@@   ##&&&##         CCC       @         @",
	"@                                      2   ############ 1                                          @         @",
	"@                                          ##B       ##                                            @         @",
	"@                                          ##        ##                                            @         @",
	"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
};
//Arbusto
const unsigned char	arbustoImagen = 38;
const ColorConsola arbustoColorSimbolo = ColorConsola_Verde;
const ColorConsola arbustoColorFondo = ColorConsola_VerdeOscuro;

//Charco
const unsigned char	charcoImagen = 67;
const ColorConsola charcoColorSimbolo = ColorConsola_Celeste;
const ColorConsola charcoColorFondo = ColorConsola_Celeste;
//
////Arbusto
//const unsigned char	arbustoImagen = 176;
//const ColorConsola arbustoColorSimbolo = ColorConsola_Verde;
//const ColorConsola arbustoColorFondo = ColorConsola_VerdeOscuro;
//
////Charco
//const unsigned char	charcoImagen = 176;
//const ColorConsola charcoColorSimbolo = ColorConsola_Verde;
//const ColorConsola charcoColorFondo = ColorConsola_VerdeOscuro;
//
////Pantano
//const unsigned char	pantanoImagen = 176;
//const ColorConsola pantanoColorSimbolo = ColorConsola_Verde;
//const ColorConsola pantanoColorFondo = ColorConsola_VerdeOscuro;
//
////Roca
//const unsigned char	rocaImagen = 176;
//const ColorConsola rocaColorSimbolo = ColorConsola_Verde;
//const ColorConsola rocaColorFondo = ColorConsola_VerdeOscuro;
//
////Tronco
//const unsigned char	troncoImagen = 176;
//const ColorConsola troncoColorSimbolo = ColorConsola_Verde;
//const ColorConsola troncoColorFondo = ColorConsola_VerdeOscuro;
