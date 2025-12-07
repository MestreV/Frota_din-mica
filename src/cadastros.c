#include "../include/cadastros.h"
#include "../include/types.h"
#include "../include/complementos.h"
#include <stdlib.h>
#include <stdio.h>

int checar_matricula_alocada(char* matricula_duvidosa, dados_aeronave_t *lista)
{
    int true_or_false = 0;

    while (lista) {
        if (strcmp(matricula_duvidosa, lista->matricula) == 0) {
            true_or_false++;
            return true_or_false;
        }
        lista = lista->prox;
    }
    return true_or_false;
}


dados_aeronave_t *nova_aeronave()
{
    dados_aeronave_t *nova = NULL;

    nova = (dados_aeronave_t*)malloc(sizeof(dados_aeronave_t));

    printf("\n");
    printf("CADASTRO DE AERONAVE:\n");
    printf("Identificacao da aeronave...........: ");
    scanf("%d", &nova->identificacao);
    getchar();

    printf("Matricula da aeronave...............: ");
    fgets(nova->matricula, T_STR, stdin);
    retirar_enter(nova->matricula);
    formatar_maiuculo(nova->matricula);
    
    printf("Modelo da aeronave..................: ");
    fgets(nova->modelo, T_STR, stdin);
    retirar_enter(nova->modelo);
    formatar_maiuculo(nova->modelo);
    
    printf("Fabricante da aeronave..............: ");
    fgets(nova->fabricante, T_STR, stdin);
    retirar_enter(nova->fabricante);
    formatar_maiuculo(nova->fabricante);

    printf("Ano de fabricacao...................: ");
    scanf("%d", &nova->ano_fabricacao);

    printf("OBS(Tipos):\n Carga       <1>\n Passageiro  <2>\n");
    printf("Tipo de aeronave....................: ");
    scanf("%d", &nova->tipo);
    
    if (nova->tipo == PASSAGEIRO) {
        printf("Numero de passageiros...............: ");
        scanf("%d", &nova->num_passageiros);       
    } else {
        nova->num_passageiros = 0;
    }
    
    printf("OBS(situacao):\n Operacao = 1\n Manutencao = 2\n");
    printf("Situacao da aeronave................: ");
    scanf("%d", &nova->situacao);
    
    if (nova->situacao == OPERACAO) {
        printf("Tripulacao necessaria...\n");
        printf(" Pilotos................: ");
        scanf("%d", &nova->tripulacao.pilotos);
        printf(" Comissarias de bordo...: ");
        scanf("%d", &nova->tripulacao.comissarias_de_bordo);
        nova->tripulacao.total = nova->tripulacao.pilotos + nova->tripulacao.comissarias_de_bordo;
        printf("Total: %d", nova->tripulacao.total);
    } else {
        nova->tripulacao.pilotos = 0;
        nova->tripulacao.comissarias_de_bordo = 0;
        nova->tripulacao.total = 0;
    }

    nova->prox = NULL;

    printf("\n");
    return nova; 
}


dados_rota_t *nova_rota(dados_aeronave_t lista_aeronave)
{
    dados_rota_t *nova = NULL;
    int validacao;

    nova = (dados_rota_t*)malloc(sizeof(dados_rota_t));
  
    printf("\n");
    printf("CADASTRO DE ROTA:\n");
    printf("Aeronave alocada.............: ");
    fgets(nova->matricula_alocada, T_STR, stdin);
    retirar_enter(nova->matricula_alocada);
    formatar_maiuculo(nova->matricula_alocada);
    validacao = checar_matricula_alocada(nova->matricula_alocada, lista_aeronave);
    while (validacao = FALSE) {
        printf("Matricula <%s> inexistente para alocacao\n", nova->matricula_alocada);
        printf("As matriculas existentes eh:\n");
        mostrar_matriculas_existentes(lista_aeronave);
        free(nova->matricula_alocada);

        printf("Aeronave alocada.............: ");
        fgets(nova->matricula_alocada, T_STR, stdin);        
    }


    printf("Codigo da rota...............: ");
    scanf("%d", &nova->codigo);

    printf("Data e hora..................:\n");
    printf("Data: ");
    scanf("%d/%d", &nova->data_hora.dia, &nova->data_hora.mes);
    printf("Horario: ");
    scanf("%d:%d", &nova->data_hora.hora, &nova->data_hora.minutos);
    getchar();
    
    printf("Local de partida.............: ");
    fgets(nova->local_partida, T_STR, stdin);
    retirar_enter(nova->local_partida);
    formatar_maiuculo(nova->local_partida);
    
    printf("Local de destino.............: ");
    fgets(nova->local_destino, T_STR, stdin);
    retirar_enter(nova->local_destino);
    formatar_maiuculo(nova->local_destino);

    printf("Tempo estimado...............:\n");
    printf("Horas: ");
    scanf("%d", &nova->tempo_estimado.hora); 
    printf("Minutos: ");
    scanf("%d", &nova->tempo_estimado.minutos);   

    
    printf("Combustivel necessario (L)...: ");
    scanf("%d", &nova->combustivel_necessario);

    printf("Quantidade de passageiros....: ");
    scanf("%d", &nova->qtd_passageiros);

    printf("Quantidade de carga util (Kg) :");
    scanf("%d", &nova->qtd_carga);
    getchar();
    
    printf("Nomes dos tripulantes........: ");
    fgets(nova->nomes, T_STR, stdin);
    retirar_enter(nova->nomes);
    formatar_maiuculo(nova->nomes);

    nova->prox = NULL;
    
    printf("\n");
    return nova;
}

void inserir_lista_aeronave_pelo_inicio(dados_aeronave_t **lista, dados_aeronave_t *nova_aeronave)
{
    if (*lista != NULL) {
        nova_aeronave->prox = *lista;
    }

    *lista = nova_aeronave;
}

void inserir_lista_aeronave_pelo_final(dados_aeronave_t **lista, dados_aeronave_t *nova_aeronave)
{
    dados_aeronave_t *ultimo = NULL;

    if (*lista == NULL) {
        *lista = nova_aeronave;
    }
    else{
        ultimo = localizar_fim_lista_aeronave(*lista);
        ultimo->prox = nova_aeronave;
    }
}

void inserir_lista_rota_pelo_inicio(dados_rota_t **lista, dados_rota_t *nova_rota)
{
    if (*lista != NULL) {
        nova_rota->prox = *lista;
    }

    *lista = nova_rota;
}

void inserir_lista_rota_pelo_final(dados_rota_t **lista, dados_rota_t *nova_rota)
{
    dados_rota_t *ultimo = NULL;

    if (*lista == NULL) {
        *lista = nova_rota;
    }
    else{
        ultimo = localizar_fim_lista_rota(*lista);
        ultimo->prox = nova_rota;
    }
}

dados_aeronave_t *localizar_fim_lista_aeronave(dados_aeronave_t *lista)
{
    for (lista; lista->prox != NULL; lista = lista->prox);

    return lista;
}

dados_rota_t *localizar_fim_lista_rota(dados_rota_t *lista)
{
    for (lista; lista->prox != NULL; lista = lista->prox);

    return lista;
}



