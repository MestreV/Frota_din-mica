#include "../include/arquivos.h"
#include "../include/cadastros.h"
#include "../include/types.h"
#include "../include/listagens.h"
#include <stdlib.h>
#include <stdio.h>

void salvar_registros_aeronave_arquivo_binario(str_arq nome_arq, dados_aeronave_t *lista)
{
    FILE *fp_arquivo = NULL;

    fp_arquivo = fopen(nome_arq, "wb");

    if (fp_arquivo == NULL) {
        printf("Erro na abertura do arquivo %s\n", nome_arq);
        return;
    }

    while (lista) {
        fwrite(lista, sizeof(dados_aeronave_t), 1, fp_arquivo);
        lista = lista->prox;
    }

    fclose(fp_arquivo);
}

void salvar_registros_rotas_arquivo_binario(str_arq nome_arq, dados_rota_t *lista)
{
    FILE *fp_arquivo = NULL;

    fp_arquivo = fopen(nome_arq, "wb");

    if (fp_arquivo == NULL) {
        printf("Erro na abertura do arquivo %s\n", nome_arq);
        return;
    }

    while (lista) {
        fwrite(lista, sizeof(dados_rota_t), 1, fp_arquivo);
        lista = lista->prox;
    }

    fclose(fp_arquivo);
}

void ler_registros_aeronave_arquivo_binario(str_arq nome_arq, dados_aeronave_t **lista)
{
    FILE *fp_arquivo = NULL;
    dados_aeronave_t *aeronave = NULL;

    fp_arquivo = fopen(nome_arq, "rb");

    if (fp_arquivo == NULL) {
        printf("Erro ao tentar abrir o arquivo %s\n", nome_arq);
        return;
    }

    while (!feof(fp_arquivo)) {
        aeronave = (dados_aeronave_t*)malloc(sizeof(dados_aeronave_t));
        fread(aeronave, sizeof(dados_aeronave_t), 1, fp_arquivo);
        aeronave->prox = NULL;
        if (!feof(fp_arquivo)) {
            inserir_lista_aeronave_pelo_final(lista, aeronave);
        } else {
            free(aeronave);
        }
    }
    fclose(fp_arquivo);
}

void ler_registros_rotas_arquivo_binario(str_arq nome_arq, dados_rota_t **lista)
{
    FILE *fp_arquivo = NULL;
    dados_rota_t *rota = NULL;

    fp_arquivo = fopen(nome_arq, "rb");

    if (fp_arquivo == NULL) {
        printf("Erro ao tentar abrir o arquivo %s\n", nome_arq);
        return;
    }

    while (!feof(fp_arquivo)) {
        rota = (dados_rota_t*)malloc(sizeof(dados_rota_t));
        fread(rota, sizeof(dados_rota_t), 1, fp_arquivo);
        rota->prox = NULL;
        if (!feof(fp_arquivo)) {
            inserir_lista_rota_pelo_final(lista,rota);
        } else {
            free(rota);
        }
    }
    fclose(fp_arquivo);
}