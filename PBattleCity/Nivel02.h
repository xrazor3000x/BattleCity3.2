#pragma once
#include "SistemaRenderizacion.h"
#include "Direccion.h"
#include "Nivel01.h"
const unsigned char celdaSimbolo_Pantano = 'P';
const unsigned char celdaSimbolo_Roca = 'R';
const unsigned char celdaSimbolo_Tronco = 'T';
const unsigned char celdaSimbolo_Final = 'F';
const unsigned char datosNivel2[filasNivel][columnasNivel + 1] =
{
	"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
	"@TTT&                                                                                          &TTT@         @",
	"@TTT&                                                                                          &TTT@         @",
	"@&&&&                                                                                          &&&&@         @",
	"@                                               F                                                  @         @",
	"@                                                                                                  @         @",
	"@                                                                                                  @         @",
	"@                                                                                                  @         @",
	"@                                                                                                  @         @",
	"@                                                                                                  @         @",
	"@RRR                                                                                            RRR@         @",
	"@@RR                                                                                            RR@@         @",
	"@@RR                                                                                            RR@@         @",
	"@@RR                                                                                            RR@@         @",
	"@RRR                                                                                            RRR@         @",
	"@                                                                                                  @         @",
	"@                                                                                                  @         @",
	"@                                                                                                  @         @",
	"@                                                                                                  @         @",
	"@                                                                                                  @         @",
	"@                                                                                                  @         @",
	"@&&&&                                2                      1                                  &&&&@         @",
	"@TTT&                                                                                          &TTT@         @",
	"@TTT&                                                                                          &TTT@         @",
	"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
};

//Pantano
const unsigned char	pantanoImagen = 80;
const ColorConsola pantanoColorSimbolo = ColorConsola_Verde;
const ColorConsola pantanoColorFondo = ColorConsola_VerdeOscuro;

//Roca
const unsigned char	rocaImagen = 82;
const ColorConsola rocaColorSimbolo = ColorConsola_Verde;
const ColorConsola rocaColorFondo = ColorConsola_VerdeOscuro;

//Tronco
const unsigned char	troncoImagen = 84;
const ColorConsola troncoColorSimbolo = ColorConsola_Verde;
const ColorConsola troncoColorFondo = ColorConsola_VerdeOscuro;
