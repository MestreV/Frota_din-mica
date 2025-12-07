#include "../include/consultas.h"
#include "../include/types.h"
#include "../include/listagens.h"

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

int consultar_rota_data(data_hora_t data_procurada, dados_rota_t *lista)
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
        printf("A data procurada nao esta registrada.\n");
    }
}    


