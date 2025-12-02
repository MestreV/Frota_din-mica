#include "./include/menus.h"
#include "./include/cadastros.h"
#include "./include/listagens.h"
#include "./include/consultas.h"
#include "./include/types.h"
#include "./include/percentuais.h"
#include "./include/main.h"
#include "./include/complementos.h"
#include <stdio.h>


int main()
{   
    dados_aeronave_t *lista_aeronaves = NULL, *aux_aeronave = NULL;
    dados_rota_t *lista_rotas = NULL. *aux_rotas = NULL;
    int opc, opc1;
    unsigned int insercao = 2;

    do {
        opc = menu();
            
        switch (opc) {
            case 1: do {
                        opc1 = CADASTROS();

                        switch (opc1) {
                                case 1: printf("  0 = inicio\n");
                                        printf("  1 = final\n")
                                        printf("Lado desejado da insercao: %d\n", insercao);

                                        if (insercao == 0) {
                                            aux_aeronave = nova_aeronave();
                                            inserir_lista_aeronave_pelo_inicio(&lista_aeronaves, aux_aeronave);       
                                        }

                                        if (insercao == 1) {
                                            aux_aeronave = nova_aeronave();
                                            inserir_lista_aeronave_pelo_final(&lista_aeronaves, aux_aeronave);
                                        }

                                        if (insercao > 1 || insercao < 1) {
                                        printf("Tipo de insercao nao compativel!\n");
                                        }
                                        break;
                                
                                case 2: printf("OBS:\n 0 = inicio\n 1 = final\n");
                                        printf("Lado da insercao: %d\n", insercao);

                                        if (insercao == 0) {
                                            aux_rotas = nova_rota();
                                            inserir_lista_rota_pelo_inicio(&lista_rotas, aux_rotas);;
                                        }

                                        if (insercao == 1) {
                                            aux_rotas = nova_rota();
                                            inserir_lista_rota_pelo_final(&lista_rotas, aux_rotas);
                                        }

                                        if (insercao != 0 && insercao != 1) {
                                             printf("Tipo de insercao nao compativel!\n");

                                        }
                                        break;
                                
                                case 0: printf("Voltando!\n");
                        }
                    } while(opc1 != FIM);
                    break;

            case 2: do {
                        opc1 = LISTAGENS_AERONAVES();

                        switch (opc1) {
                                case 1: 
                                        break;
                                
                                case 2: 
                                        break;

                                case 3: 
                                        break;

                                case 4: 
                                        break;

                                case 5: 
                                        break;

                                case 6: listar_aeronaves_cadastradas(lista_aeronaves);
                                        break;

                                case 0: printf("Voltando!\n");
                                        break;
                        }
                    } while(opc1 != FIM);
                    break;


            case 3: do {
                        opc1 = LISTAGEM_ROTAS();

                        switch (opc1) {
                                case 1: 
                                        break;
                                
                                case 2: 
                                        break;

                                case 3: 
                                        break;

                                case 4: 
                                        break;

                                case 5: listar_rotas_cadastradas(lista_rotas);
                                        break;

                                case 0: printf("Voltando!\n");
                                        break;                               
                        }
                    } while(opc1 != FIM);
                    break;

            case 4: do {
                        opc1 = PERCENTUAIS();
                         
                        switch (opc1){
                                case 1: 
                                        break;

                                case 2: 
                                        break;

                                case 0: printf("Voltando!\n");
                                        break;        
                        }
                    } while(opc1 != FIM);
                    break;

            case 5: 
                    break;

            case 6: 
                    break;

            case 7: 
                    break;

            case 8: 
                    break;

            case 0: printf("Fechando!\n");

        }

    } while(opc != FIM);


    return 0;
}



/*
void INSERIR_LISTA_AERONAVE(dados_aeronave_t **lista, dados_aeronave_t *nova_aeronave)
{
    unsigned int insercao = 2;

    printf("  0 = inicio\n");
    printf("  1 = final\n")
    printf("lado desejado da insercao: %d\n", insercao);

    if (insercao == 0) {
        aux_aeronave = nova_aeronave();
        inserir_lista_aeronave_pelo_inicio(&lista, nova_aeronave);       
    }

    if (insercao == 1) {
        aux_aeronave = nova_aeronave();
        inserir_lista_aeronave_pelo_final(&lista, nova_aeronave);
    }

    if (insercao > 1 || insercao < 1) {
        printf("Tipo de insercao nao compativel!\n");
    }
}
*/