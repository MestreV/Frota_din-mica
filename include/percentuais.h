#ifndef PERCENTUAIS_H
#define PERCENTUAIS_H

#include <stdio.h>
#include "../include/types.h"


int data_inicio_intervalo_em_horas(data_hora_t data_inicio);
int data_final_intervalo_em_horas(data_hora_t data_termino);
int contador_de_destinos(string destino, dados_rota_t *lista);


void percentual_voos_destino_intervalo_datas(string destino, int inicio, int fim, dados_rota_t *lista, dados_rota_t *lista2);
void percentual_voos_realizados_por_aeronave(string matricula_aeronave, dados_rota_t *lista, dados_aeronave_t *lista_a, dados_aeronave_t *lista_a2);

#endif