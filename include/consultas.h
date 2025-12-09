#ifndef CONSULTAS_H
#define CONSULTAS_H

#include "types.h"
#include <stdio.h>

int combustivel_total_por_intervalo(int inicio, int fim, dados_rota_t *lista);
int consultar_rota_data(data_hora_t data_procurada, dados_rota_t *lista, dados_rota_t *lista2);
void busca_aeronave_matricula(char* matricula_procurada, dados_aeronave_t *lista, dados_aeronave_t *lista2);

#endif