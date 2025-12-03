#include "../include/percentuais.h"
#include "../include/types.h"
#include <string.h>



int data_inicio_intervalo_em_horas(data_hora_t data_inicio)
{
        int horas_inicio;

        horas_inicio = 24 * ((30 * data_inicio.mes) + data_inicio.dia);

        return horas_inicio;
}

int data_final_intervalo_em_horas(data_hora_t data_termino)
{
        int horas_termino;

        horas_termino = 24 * ((30 * data_termino.mes) + data_termino.dia);

        return horas_termino;
}

void percentual_voos_destino_intervalo_datas(string destino, int inicio, int fim, dados_rota_t *lista)
{
    int total_voos_do_intervalo = 0;
    int voos_destino = 0;
    int destinos_encontrados = 0;
    float percentual_voos;
    int horas_data;

    while (lista){
            if(strcmp(lista->local_destino, destino) == 0){
                    destinos_encontrados++;
            }
    }     
        
    if (destinos_encontrados != 0){
        while (lista){
            horas_data = 24* ((30*lista->data_hora.mes) + lista->data_hora.dia);
            for (inicio; inicio <= fim; inicio++){
                if (inicio == horas_data){
                    total_voos_do_intervalo++;
                }
                if (inicio == horas_data && strcmp(lista->local_destino, destino) == 0){
                    voos_destino++;
                }
            }
        }
    if (voos_destino != 0){
        percentual_voos = (voos_destino / total_voos_do_intervalo) * 100;
        printf("Percentual de voos realizados eh: %.2f%%\n\n", percentual_voos);
        }

    if (voos_destino == 0){
        printf("O destino <%s> nao possui voos nesse intervalo de datas.\n", destino);
        printf("Tente outro desses destinos cadastrados:\n");
        //mostrar_destinos_existentes();
        printf("\n");
        }
    }

    if (destinos_encontrados == 0){
            printf("O destino <%s> nao existe na base de dados.\n", destino);
            printf("Os destinos existentes sao:\n");
            //mostrar_datas_existentes();
            printf("\n");
    }    
}

void percentual_voos_realizados_por_aeronave(string matricula_aeronave, dados_rota_t *lista, dados_aeronave_t *lista_a)
{
    int total_voos = 0;
    int voos_aeronave = 0;
    int aeronave_encontrada = 0;
    float percentual_voos;

    while (lista_a) {
        if(strcmp(lista_a->matricula, matricula_aeronave) == 0){
            while (lista){
                total_voos++;
                if (strcmp(lista->matricula_alocada, matricula_aeronave) == 0){
                    voos_aeronave++;
                }
            }
            aeronave_encontrada++;
        }
    }

    if (voos_aeronave != 0){
        percentual_voos = (voos_aeronave / total_voos) * 100;
        printf("Percentual de voos realizados eh: %.2f%%\n\n", percentual_voos);
    }

    if (aeronave_encontrada != 0 && voos_aeronave == 0){
        printf("Esta aeronave nao esta alocada para nenhum voo.\n Percentual: 0%%\n\n");

    }

    if (aeronave_encontrada == 0){
        printf("Matricula <%s> inexistente!\n", matricula_aeronave);
        printf("As matriculas existentes sao:\n");
        //mostrar_matriculas_existentes();
        printf("\n");
    }
}

