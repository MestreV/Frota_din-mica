#include "../include/types.h"
#include "../include/existencia.h"
#include "../include/types.h"
#include <stdio.h>

void mostrar_fabricantes_existentes(dados_aeronave_t *lista)
{
    while (lista) {
        printf(" -> %s", lista->fabricante);
        printf("\n");
        lista = lista->prox;
    }
}

void mostrar_modelos_existentes(dados_aeronave_t *lista)
{
    while (lista) {
        printf(" -> %s", lista->modelo);
        printf("\n");
        lista = lista->prox;
    }
}

void mostrar_anos_de_fabricacao_existentes(dados_aeronave_t *lista)
{
    while (lista) {
        printf(" -> %d", lista->ano_fabricacao);
        printf("\n");
        lista = lista->prox;
    }
}

void mostrar_matriculas_existentes(dados_aeronave_t *lista)
{
    while (lista) {
        printf(" -> %s", lista->matricula);
        printf("\n");
        lista = lista->prox;
    }
}

void mostrar_datas_existentes(dados_rota_t *lista)
{
    while (lista) {
        printf(" -> %d/%d/%d", lista->data_hora.dia, lista->data_hora.mes, lista->data_hora.ano);
        printf("\n");
        lista = lista->prox;
    }
}

void mostrar_destinos_existentes(dados_rota_t *lista)
{
    while (lista) {
        printf(" -> %s", lista->local_destino);
        printf("\n");
        lista = lista->prox;
    }
}

void mostrar_origens_existentes(dados_rota_t *lista)
{
    while (lista) {
        printf(" -> %s", lista->local_partida);
        printf("\n");
        lista = lista->prox;
    }
}


