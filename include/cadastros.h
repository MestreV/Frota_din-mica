#ifndef CADASTROS_H
#define CADASTROS_H

#include "types.h"

dados_aeronave_t *nova_aeronave();
dados_rota_t *nova_rota(dados_aeronave_t *lista_aeronave);

void inserir_lista_aeronave_pelo_inicio(dados_aeronave_t **lista, dados_aeronave_t *nova_aeronave);
void inserir_lista_aeronave_pelo_final(dados_aeronave_t **lista, dados_aeronave_t *nova_aeronave);
void inserir_lista_rota_pelo_inicio(dados_rota_t **lista, dados_rota_t *nova_rota);
void inserir_lista_rota_pelo_final(dados_rota_t **lista, dados_rota_t *nova_rota);

dados_aeronave_t *localizar_fim_lista_aeronave(dados_aeronave_t *lista);
dados_rota_t *localizar_fim_lista_rota(dados_rota_t *lista);

int checar_matricula_alocada(char* matricula_duvidosa, dados_aeronave_t *lista);
int qtd_psg_aeronave_alocada(char* matricula_alocada, dados_aeronave_t *lista);
int checar_situacao_aeronave(char* matricula_alocada, dados_aeronave_t *lista);



#endif