#include "../include/types.h"
#include "../include/existencia.h"
#include "../include/complementos.h"
#include <stdio.h>
#include <string.h>


void mostrar_dados_aeronave(dados_aeronave_t *aeronave, FILE* fp)
{
    fprintf(fp, "ID da aeronave............: %d\n", aeronave->identificacao);
    fprintf(fp, "Matricula.................: %s\n", aeronave->matricula);
    fprintf(fp, "Modelo....................: %s\n", aeronave->modelo);
    fprintf(fp, "Fabricante................: %s\n", aeronave->fabricante);
    fprintf(fp, "Ano de fabricacao.........: %i\n", aeronave->ano_fabricacao);
    fprintf(fp, "Tipo (carga ou passageiro): %i\n", aeronave->tipo);
    fprintf(fp, "Numero de passageiros.....: %d\n", aeronave->num_passageiros);
    fprintf(fp, "Situacao..................: %i\n", aeronave->situacao);
    fprintf(fp, "Tripulacao necessaria.....:\n");
    fprintf(fp, "  Pilotos....: %d\n", aeronave->tripulacao.pilotos);
    fprintf(fp, "  Comissarias: %d\n", aeronave->tripulacao.comissarias_de_bordo);
    fprintf(fp, "  Total......: %d\n", aeronave->tripulacao.total);
}

void mostrar_dados_rota(dados_rota_t *rota, FILE* fp)
{
    fprintf(fp, "Aeronave alocada........: %s\n", rota->matricula_alocada);
    fprintf(fp, "Codigo..................: %i\n", rota->codigo);
    fprintf(fp, "Data e hora.............: %d/%d/%d as %d:%d\n", rota->data_hora.dia, rota->data_hora.mes, rota->data_hora.ano, rota->data_hora.hora, rota->data_hora.minutos);
    fprintf(fp, "Local de partida........: %s\n", rota->local_partida);
    fprintf(fp, "Local de destino........: %s\n", rota->local_destino);
    fprintf(fp, "Tempo estimado..........: %d horas e %d minutos\n", rota->tempo_estimado.hora, rota->tempo_estimado.minutos);
    fprintf(fp, "Combustivel necessario..: %d Litros\n", rota->combustivel_necessario);
    fprintf(fp, "Qtd de passageiros......: %d\n", rota->qtd_passageiros);
    fprintf(fp, "Qtd de carga............: %i\n", rota->qtd_carga);
    fprintf(fp, "Nomes da tripulacao:....: %s\n", rota->nomes);
}

void listar_aeronaves_cadastradas(dados_aeronave_t *lista)
{
    if (!lista) {
        printf("Nenhuma aeronave cadastrada.\n");
        return;
    }

    while (lista) {
        mostrar_dados_aeronave(lista, stdout);
        printf("\n");
        lista = lista->prox;
    }
    msg("Pressione ENTER para continuar");
}

void listar_rotas_cadastradas(dados_rota_t *lista)
{
    if (!lista) {
        printf("Nenhuma rota cadastrada.\n");
        return;
    }

    while (lista) {
        mostrar_dados_rota(lista, stdout);
        printf("\n");
        lista = lista->prox;
    }
    msg("Pressione ENTER para continuar");
}

void listar_aeronave_fabricante(char* fabricante_procurado, dados_aeronave_t *lista, dados_aeronave_t *lista2)
{
    int fabricantes_encontrados = 0;
    int i = 0;

    if (!lista) {
        printf("Nenhuma aeronave cadastrada.\n");
        return;
    }


    while (lista) {
        i++;
        if (strcmp(fabricante_procurado, lista->fabricante) == 0) {
            printf("Aeronave (%d):\n", i);
            mostrar_dados_aeronave(lista, stdout);
            printf("\n");
            fabricantes_encontrados++;
        }
        lista = lista->prox;
    }

    if (fabricantes_encontrados == 0){
        printf("O fabricante <%s> nao esta registrado.\n", fabricante_procurado);
        printf("Os fabricantes existentes sao:\n");
        mostrar_fabricantes_existentes(lista2);
        printf("\n\n");
    }
    msg("Pressione ENTER para continuar");
}

void listar_aeronave_por_tipo(tipo_t tipo_procurado, dados_aeronave_t *lista)
{
    int aeronaves_encontradas = 0;
    int i = 0;

    if (!lista) {
        printf("Nenhuma aeronave cadastrada.\n");
        return;
    }

    while (lista) {
        i++;
        if (tipo_procurado == lista->tipo) {
            printf("Aeronave (%d):\n", i);
            mostrar_dados_aeronave(lista, stdout);
            printf("\n");
            aeronaves_encontradas++;
        }
        lista = lista->prox;

    }

    if (aeronaves_encontradas == 0){
        printf("O tipo desejado ainda nao possui cadastramentos!\n");
        printf("\n\n");
    }
    msg("Pressione ENTER para continuar");
}

void listar_aeronave_por_modelo(char* modelo_procurado, dados_aeronave_t *lista, dados_aeronave_t *lista2)
{
    int aeronaves_encontradas = 0;
    int i = 0;

    if (!lista) {
        printf("Nenhuma aeronave cadastrada.\n");
        return;
    }

    while (lista) {
        i++;
        if (strcmp(modelo_procurado, lista->modelo) == 0) {
            printf("Aeronave (%d):\n", i);
            mostrar_dados_aeronave(lista, stdout);
            printf("\n");
            aeronaves_encontradas++;
        }
        lista = lista->prox;

    }

    if (aeronaves_encontradas == 0){
        printf("O modelo <%s> nao esta registrado.\n", modelo_procurado);
        printf("Os modelos existentes sao:\n");
        mostrar_modelos_existentes(lista2);
        printf("\n\n");
    }
    msg("Pressione ENTER para continuar");
}

void listar_aeronave_por_ano(int ano_procurado, dados_aeronave_t *lista, dados_aeronave_t *lista2)
{
    int aeronaves_encontradas = 0;
    int i = 0;

    if (!lista) {
        printf("Nenhuma aeronave cadastrada.\n");
        return;
    }

    while (lista) {
        i++;
        if (ano_procurado == lista->ano_fabricacao) {
            printf("Aeronave (%d):\n", i);
            mostrar_dados_aeronave(lista, stdout);
            printf("\n\n");
            aeronaves_encontradas++;
        }
        lista = lista->prox;

    }

    if (aeronaves_encontradas == 0){
        printf("O ano <%d> nao esta registrado.\n", ano_procurado);
        printf("Os anos de fabricacao existentes sao:\n");
        mostrar_anos_de_fabricacao_existentes(lista2);
        printf("\n\n");
    }
    msg("Pressione ENTER para continuar");
}

void listar_aeronave_por_situacao(situacao_t situacao_procurada, dados_aeronave_t *lista)
{
    int aeronaves_encontradas = 0;
    int i = 0;

    if (!lista) {
        printf("Nenhuma aeronave cadastrada.\n");
        return;
    }

    while (lista) {
        i++;
        if (situacao_procurada == lista->situacao) {
            printf("Aeronave (%d):\n", i);
            mostrar_dados_aeronave(lista, stdout);
            printf("\n\n");
            aeronaves_encontradas++;
        }
        lista = lista->prox;

    }

    if (aeronaves_encontradas == 0){
        printf("A situacao desejada ainda nao possui cadastramentos!\n");
        printf("\n\n");
    }  
    msg("Pressione ENTER para continuar"); 
}


void listar_rotas_por_destino(char* destino_procurado, dados_rota_t *lista, dados_rota_t *lista2)
{
    int rotas_encontradas = 0;
    int i = 0;

    if (!lista) {
        printf("Nenhuma aeronave cadastrada.\n");
        return;
    }

    while (lista) {
        i++;
        if (strcmp(destino_procurado, lista->local_destino) == 0) {
            printf("Aeronave (%d):\n", i);
            mostrar_dados_rota(lista, stdout);
            printf("\n\n");
            rotas_encontradas++;
        }
        lista = lista->prox;

    }

    if (rotas_encontradas == 0){
        printf("O destino <%s> nao esta registrado.\n", destino_procurado);
        printf("Os destinos existentes sao:\n");
        mostrar_destinos_existentes(lista2);
        printf("\n\n");
    }
    msg("Pressione ENTER para continuar");
}

void listar_rotas_por_origem(char* origem_procurada, dados_rota_t *lista, dados_rota_t *lista2)
{
    int rotas_encontradas = 0;
    int i = 0;

    if (!lista) {
        printf("Nenhuma aeronave cadastrada.\n");
        return;
    }

    while (lista) {
        i++;
        if (strcmp(origem_procurada, lista->local_partida) == 0) {
            printf("Aeronave (%d):\n", i);
            mostrar_dados_rota(lista, stdout);
            printf("\n\n");
            rotas_encontradas++;
        }
        lista = lista->prox;

    }

    if (rotas_encontradas == 0){
        printf("A origem <%s> nao esta registrada.\n", origem_procurada);
        printf("As origens existentes sao:\n");
        mostrar_origens_existentes(lista2);
        printf("\n\n");
    }
    msg("Pressione ENTER para continuar");
}





int achar_maior_numero_de_passageiros(dados_rota_t *lista, int maior_passageiros)
{
    if (lista == NULL) {
        return maior_passageiros;
    }

    if (maior_passageiros < lista->qtd_passageiros) {
        maior_passageiros = lista->qtd_passageiros;
    }

    return achar_maior_numero_de_passageiros(lista->prox, maior_passageiros);
}



/*
int achar_maior_numero_de_passageiros(dados_rota_t *lista)
{
    int maior_passageiros = 0;

    while (lista) {
        if (maior_passageiros < lista->qtd_passageiros) {
            maior_passageiros = lista->qtd_passageiros;
        }
        lista = lista->prox;
    }
    return maior_passageiros;
}
*/

int achar_menor_numero_de_passageiros(dados_rota_t *lista)
{
    int menor_passageiros = 1000;

    while (lista) {
        if (menor_passageiros > lista->qtd_passageiros) {
            menor_passageiros = lista->qtd_passageiros;
        }
        lista = lista->prox;
    }
    return menor_passageiros;
    
}

void listar_rotas_maior_passageiros(int maior_passageiros, dados_rota_t *lista)
{
    int i = 0;

    if (!lista) {
        printf("Nenhuma aeronave cadastrada.\n");
        return;
    }

    while (lista) {
        i++;
        if (lista->qtd_passageiros == maior_passageiros){
                printf("Rota (%i):\n", i);
                mostrar_dados_rota(lista, stdout);
                printf("\n");                        
        }
        lista = lista->prox;
    }
    printf("\n");
    msg("Pressione ENTER para continuar");
}

void listar_rotas_menor_passageiros(int menor_passageiros, dados_rota_t *lista)
{
    int i = 0;

    if (!lista) {
        printf("Nenhuma aeronave cadastrada.\n");
        return;
    }

    while (lista) {
        i++;
        if (lista->qtd_passageiros == menor_passageiros){
                printf("Rota (%i):\n", i);
                mostrar_dados_rota(lista, stdout);
                printf("\n");                        
        }
        lista = lista->prox;
    }
    printf("\n");
    msg("Pressione ENTER para continuar");
}