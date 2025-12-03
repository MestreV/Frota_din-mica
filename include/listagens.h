#ifndef LISTAGENS_H
#define LISTAGENS_H

#include <stdio.h>
#include "types.h"


void mostrar_dados_aeronave(dados_aeronave_t *aeronave, FILE* fp);
void mostrar_dados_rota(dados_rota_t *rota, FILE* fp);

void listar_aeronaves_cadastradas(dados_aeronave_t *lista);
void listar_rotas_cadastradas(dados_rota_t *lista);

void listar_aeronave_fabricante(string fabricante_procurado, dados_aeronave_t *lista);
void listar_aeronave_por_tipo(tipo_t tipo_procurado, dados_aeronave_t *lista);
void listar_aeronave_por_modelo(string modelo_procurado, dados_aeronave_t *lista);
void listar_aeronave_por_ano(int ano_procurado, dados_aeronave_t *lista);
void listar_aeronave_por_situacao(situacao_t situacao_procurada, dados_aeronave_t *lista);

void listar_rotas_por_destino(string destino_procurado, dados_rota_t *lista);
void listar_rotas_por_origem(string origem_procurada, dados_rota_t *lista);
int achar_maior_numero_de_passageiros(void);
int achar_menor_numero_de_passageiros(void);
void listar_rotas_maior_passageiros(int maior_passageiros, dados_rota_t *lista);
void listar_rotas_menor_passageiros(int menor_passageiros, dados_rota_t *lista);

#endif