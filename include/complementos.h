#ifndef COMPLEMENTOS_H
#define COMPLEMENTOS_H

#include "types.h"
#include <stdio.h>

void retirar_enter(char* str);
void formatar_maiuculo(char* str);

void mostrar_dados_aeronave(dados_aeronave_t *aeronave, FILE* fp);
void mostrar_dados_rota(dados_rota_t *rota, FILE* fp);

#endif