#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "types.h"

void salvar_registros_aeronave_arquivo_binario(str_arq nome_arq, dados_aeronave_t *lista);
void salvar_registros_rotas_arquivo_binario(str_arq2 nome_arq, dados_rota_t *lista);

void ler_registros_aeronave_arquivo_binario(str_arq nome_arq, dados_aeronave_t **lista);
void ler_registros_rotas_arquivo_binario(str_arq2 nome_arq, dados_rota_t **lista);

void exportar_dados_aeronaves_txt(dados_aeronave_t *lista, char *nome_arq);
void exportar_dados_aeronaves_csv(dados_aeronave_t *lista, char *nome_arq);
void exportar_dados_aeronaves_html(dados_aeronave_t *lista, char *nome_arq);

void exportar_dados_rotas_txt(dados_rota_t *lista, char *nome_arq);
void exportar_dados_rotas_csv(dados_rota_t *lista, char *nome_arq);
void exportar_dados_rotas_html(dados_rota_t *lista, char *nome_arq);

#endif