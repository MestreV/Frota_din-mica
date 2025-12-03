#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "types.h"

void salvar_registros_aeronave_arquivo_binario(str_arq nome_arq, dados_aeronave_t *lista);
void salvar_registros_rotas_arquivo_binario(str_arq nome_arq, dados_rota_t *lista);

void ler_registros_aeronave_arquivo_binario(str_arq nome_arq, dados_aeronave_t **lista);
void ler_registros_rotas_arquivo_binario(str_arq nome_arq, dados_rota_t **lista);

#endif