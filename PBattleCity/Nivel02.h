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
	"@TTT&                              ############################                                &TTT@         @",
	"@TTT&       TTTTT                  ############################                     TTTT       &TTT@         @",
	"@&&&&       TTTTT                                                                   TTTT       &&&&@         @",
	"@####PPPPPPP                                    F                                       PPPPPPP####@         @",
	"@####PPPPPPP                                                                            PPPPPPP####@         @",
	"@####PPPPPPP                                                                            PPPPPPP####@         @",
	"@####PPPPPPP                       RR                        RR                         PPPPPPP####@         @",
	"@####PPPPPPP                       RRPPPPPPPPPPPPPPPPPPPPPPPPRR                         PPPPPPP####@         @",
	"@####PPPPPPP                       RRPPPPPPPPPPPPPPPPPPPPPPPPRR                         PPPPPPP####@         @",
	"@RRR                   RRRR##      RRPPPPPPPPPPPPPPPPPPPPPPPPRR      ##RRRR                     RRR@         @",
	"@@RR                   RRRR##      RRTTTTTTTTTTTTTTTTTTTTTTTTRR      ##RRRR                     RR@@         @",
	"@@RR                   RRRR##      RR    TTTTTTTTTTTTTTTT    RR      ##RRRR                     RR@@         @",
	"@@RR                   RRRR##      RR       TTTTTTTTTT       RR      ##RRRR                     RR@@         @",
	"@RRR                   RRRR##                  TTTT                  ##RRRR                     RRR@         @",
	"@####PPPPPPP           RRRR##                   TT                   ##RRRR             PPPPPPP####@         @",
	"@####PPPPPPP                                                                            PPPPPPP####@         @",
	"@####PPPPPPP                                                                            PPPPPPP####@         @",
	"@####PPPPPPP                                                                            PPPPPPP####@         @",
	"@####PPPPPPP                                                                            PPPPPPP####@         @",
	"@####PPPPPPP                                                                            PPPPPPP####@         @",
	"@&&&&       TTTTT                    2                      1                       TTTT       &&&&@         @",
	"@TTT&       TTTTT                                                                   TTTT       &TTT@         @",
	"@TTT&                                                                                          &TTT@         @",
	"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
};

//Pantano
const unsigned char	pantanoImagen = 80;
const ColorConsola pantanoColorSimbolo = ColorConsola_Negro;
const ColorConsola pantanoColorFondo = ColorConsola_Celeste;

//Roca
const unsigned char	rocaImagen = 82;
const ColorConsola rocaColorSimbolo = ColorConsola_Negro;
const ColorConsola rocaColorFondo = ColorConsola_Cafe;

//Tronco
const unsigned char	troncoImagen = 84;
const ColorConsola troncoColorSimbolo = ColorConsola_Cafe;
const ColorConsola troncoColorFondo = ColorConsola_GrisOscuro;
