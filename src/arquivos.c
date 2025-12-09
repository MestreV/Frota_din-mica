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

void salvar_registros_rotas_arquivo_binario(str_arq2 nome_arq, dados_rota_t *lista)
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

void ler_registros_rotas_arquivo_binario(str_arq2 nome_arq, dados_rota_t **lista)
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

void exportar_dados_aeronaves_txt(dados_aeronave_t *lista, char *nome_arq)
{
    FILE *fp = NULL;

    fp = fopen(nome_arq, "w");

    if (!fp) {
        printf("ERRO - problema na abertura do arquivo %s\n", nome_arq);
    }

    while (lista) {
        mostrar_dados_aeronave(lista, fp);
        fprintf(fp, "\n");
        lista = lista->prox;
    }

    fclose(fp);
}

void exportar_dados_aeronaves_csv(dados_aeronave_t *lista, char *nome_arq)
{
    FILE *fp = NULL;

    fp = fopen(nome_arq, "w");

    if (!fp) {
        printf("ERRO - problema na abertura do arquivo %s\n", nome_arq);
    }

    fprintf(fp, "ID;MATRICULA;MODELO;FABRICANTE;ANO_FABRICACAO;TIPO;NUM_PASSAGEIROS;SITUACAO;PILOTOS;COMISSARIAS\n");
    while (lista) {
        fprintf(fp, "%i;%s;%s;%s;%i;%i;%i;%i;%i;%i\n", lista->identificacao, lista->matricula, lista->modelo, lista->fabricante, lista->ano_fabricacao, lista->tipo, lista->num_passageiros, lista->situacao, lista->tripulacao.pilotos, lista->tripulacao.comissarias_de_bordo);
        lista = lista->prox;
    }

    fclose(fp);
}

void exportar_dados_aeronaves_html(dados_aeronave_t *lista, char *nome_arq)
{
    FILE *fp = NULL;

    fp = fopen(nome_arq, "w");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo %s\n", nome_arq);
        return;
    }

    fprintf(fp, "<HTML> <HEAD> <TITLE> RELATORIO DE AERONAVES </TITLE> </HEAD> <BODY> \n");
    fprintf(fp, "<TABLE border = '1'> <TR> <TH> ID </TH> <TH> MATRICULA </TH> <TH> MODELO </TH> <TH> FABRICANTE </TH> <TH> ANO_FABRICACAO </TH> <TH> TIPO </TH> <TH> NUM_PASSAGEIROS </TH> <TH> SITUACAO </TH> <TH> PILOTOS </TH> <TH> COMISSARIAS </TH> </TR>\n");
    while (lista) {
        fprintf(fp, "<TR> <TD> %i </TD> <TD> %s </TD> <TD> %s </TD> <TD> %s </TD> <TD> %i </TD> <TD> %i </TD> <TD> %i </TD> <TD> %i </TD> <TD> %i </TD> <TD> %i </TD> </TR>\n", lista->identificacao, lista->matricula, lista->modelo, lista->fabricante, lista->ano_fabricacao, lista->tipo, lista->num_passageiros, lista->situacao, lista->tripulacao.pilotos, lista->tripulacao.comissarias_de_bordo);
        lista = lista->prox;
    }
    fprintf(fp, "</TABLE> </BODY> </HTML>\n");

    fclose(fp);
}


void exportar_dados_rotas_txt(dados_rota_t *lista, char *nome_arq)
{
    FILE *fp = NULL;

    fp = fopen(nome_arq, "w");

    if (!fp) {
        printf("ERRO - problema na abertura do arquivo %s\n", nome_arq);
    }

    while (lista) {
        mostrar_dados_rota(lista, fp);
        fprintf(fp, "\n");
        lista = lista->prox;
    }

    fclose(fp);
}

void exportar_dados_rotas_csv(dados_rota_t *lista, char *nome_arq)
{
    FILE *fp = NULL;

    fp = fopen(nome_arq, "w");

    if (!fp) {
        printf("ERRO - problema na abertura do arquivo %s\n", nome_arq);
    }

    fprintf(fp, "AERONAVE_ALOCADA;CODIGO;DATA;HORA;ORIGEM;DESTINO;TEMPO;COMBUSTIVEL;QTD_PASSAGEIROS;QTD_CARGA;NOMES_TRIP\n");
    while (lista) {
        fprintf(fp, "%s;%d;%d/%d/%d;%d:%d;%s;%s;%dh..%dmin;%d;%d;%d;%s\n", lista->matricula_alocada, lista->codigo, lista->data_hora.dia, lista->data_hora.mes, lista->data_hora.ano, lista->data_hora.hora, lista->data_hora.minutos, lista->local_partida, lista->local_destino, lista->tempo_estimado.hora, lista->tempo_estimado.minutos, lista->combustivel_necessario, lista->qtd_passageiros, lista->qtd_carga, lista->nomes);
        lista = lista->prox;

    }

    fclose(fp);
}

void exportar_dados_rotas_html(dados_rota_t *lista, char *nome_arq)
{
    FILE *fp = NULL;

    fp = fopen(nome_arq, "w");

    if (!fp) {
        printf("Erro ao tentar abrir arquivo %s\n", nome_arq);
        return;
    }

    fprintf(fp, "<HTML> <HEAD> <TITLE> RELATORIO DE ROTAS </TITLE> </HEAD> <BODY> \n");
    fprintf(fp, "<TABLE border = '1'> <TR> <TH> AERONAVE_ALOCADA </TH> <TH> CODIGO </TH> <TH> DATA </TH> <TH> HORA </TH> <TH> ORIGEM </TH> <TH> DESTINO </TH> <TH> TEMPO </TH> <TH> COMBUSTIVEL </TH> <TH> QTD_PASSAGEIROS </TH> <TH> QTD_CARGA </TH> <TH> NOMES_TRIP </TH> </TR>\n");
    while (lista) {
        fprintf(fp, "<TR> <TD> %s </TD> <TD> %d </TD> <TD> %d/%d/%d </TD> <TD> %d:%d </TD> <TD> %s </TD> <TD> %s </TD> <TD> %dh..%dmin </TD> <TD> %d </TD> <TD> %d </TD> <TD> %d </TD> <TD> %s </TD> </TR>\n", lista->matricula_alocada, lista->codigo, lista->data_hora.dia, lista->data_hora.mes, lista->data_hora.ano, lista->data_hora.hora, lista->data_hora.minutos, lista->local_partida, lista->local_destino, lista->tempo_estimado.hora, lista->tempo_estimado.minutos, lista->combustivel_necessario, lista->qtd_passageiros, lista->qtd_carga, lista->nomes);
        lista = lista->prox;
    }
    fprintf(fp, "</TABLE> </BODY> </HTML>\n");

    fclose(fp);
}