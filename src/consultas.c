#include "../include/consultas.h"
#include "../include/complementos.h"
#include "../include/types.h"
#include "../include/listagens.h"
#include "../include/existencia.h"
#include <string.h>

int combustivel_total_por_intervalo(int inicio, int fim, dados_rota_t *lista)
{
    int horas_data;
    int combustivel_total = 0;

    while (lista){
            horas_data = 24* ((30*lista->data_hora.mes) + lista->data_hora.dia);
            for (inicio; inicio <= fim; inicio++){
                    if (inicio == horas_data){
                        combustivel_total += lista->combustivel_necessario;
                    }
            }
            lista = lista->prox;
    }
    return combustivel_total;
}

int consultar_rota_data(data_hora_t data_procurada, dados_rota_t *lista, dados_rota_t *lista2)
{
    int rotas_encontradas = 0;
    int i;

    while (lista) {
        i++;
        if (lista->data_hora.mes == data_procurada.mes && lista->data_hora.dia == data_procurada.dia) {
            printf("Rota:\n");
            mostrar_dados_rota(lista, stdout);
            printf("\n\n");
            rotas_encontradas++;
        }
        lista = lista->prox;
    }

    if (rotas_encontradas == 0){
        printf(" A data procurada nao esta registrada.\n");
        printf(" As datas cadastradas eh:\n");
        mostrar_datas_existentes(lista2);
    }
    msg("Pressione ENTER para continuar");
}    

void busca_aeronave_matricula(char* matricula_procurada, dados_aeronave_t *lista, dados_aeronave_t *lista2)
{
    int matriculas_encontradas = 0;
    int i = 0;

    if (!lista) {
        printf("Nenhuma aeronave cadastrada.\n");
        return;
    }


    while (lista) {
        i++;
        if (strcmp(matricula_procurada, lista->matricula) == 0) {
            printf("Aeronave (%d):\n", i);
            mostrar_dados_aeronave(lista, stdout);
            printf("\n");
            matriculas_encontradas++;
        }
        lista = lista->prox;
    }

    if (matriculas_encontradas == 0){
        printf("Nao ah aeronaves cadastradas com a matricula <%s>.\n", matricula_procurada);
        printf("As matriculas cadastradas eh:\n");
        mostrar_matriculas_existentes(lista2);
        printf("\n\n");
    }
    msg("Pressione ENTER para continuar");   
}


