#include "./include/menus.h"
#include "./include/cadastros.h"
#include "./include/listagens.h"
#include "./include/consultas.h"
#include "./include/types.h"
#include "./include/percentuais.h"
#include "./include/main.h"
#include "./include/complementos.h"
#include "./include/arquivos.h"
#include "./include/consultas.h"
#include <stdio.h>


int main()
{   
    dados_aeronave_t *lista_aeronaves = NULL, *aux_aeronave = NULL;
    dados_rota_t *lista_rotas = NULL, *aux_rotas = NULL;
    int opc, opc1, opc2, ano_desejado, maior_passageiros, menor_passageiros, inicio, fim, comeco, final, combustivel_total;
    string fabricante_desejado, modelo_desejado, destino_desejado, destino_determinado, origem_desejada, prefixo_desejado, matricula_percentual; 
    tipo_t C_P;
    situacao_t O_M;
    data_hora_t data_desejada, data_inicio, data_termino, data_comeco, data_terminado; 


    ler_registros_aeronave_arquivo_binario("aeronaves_frota.bin", &lista_aeronaves);
    ler_registros_rotas_arquivo_binario("rotas_frota.bin", &lista_rotas);

    do {
        opc = menu();
            
        switch (opc) {
            case 1: do {
                        opc1 = CADASTROS();

                        switch (opc1) {
                                case 1: do {
                                            opc2 = INSERIR_AERONAVE();

                                            switch (opc2) {
                                                case 0: printf("Voltando!\n");
                                                        break;

                                                case 1: aux_aeronave = nova_aeronave();
                                                        inserir_lista_aeronave_pelo_inicio(&lista_aeronaves, aux_aeronave);
                                                        break;

                                                case 2: 
                                                        aux_aeronave = nova_aeronave();
                                                        inserir_lista_aeronave_pelo_final(&lista_aeronaves, aux_aeronave);  
                                                        break;                                             
                                            }
                                        } while(opc2 != 0);
                                        break;
                                
                                case 2: do {
                                            opc2 = INSERIR_ROTA();
                                            
                                            switch (opc2) {
                                                case 0: printf("Voltando!\n");
                                                        break;

                                                case 1: aux_rotas = nova_rota();
                                                        inserir_lista_rota_pelo_inicio(&lista_rotas, aux_rotas);
                                                        break;

                                                case 2: 
                                                        aux_rotas = nova_rota();
                                                        inserir_lista_rota_pelo_final(&lista_rotas, aux_rotas);      
                                                        break;                                         
                                            }
                                        } while(opc2 != 0);
                                        break;
                                
                                case 0: printf("Voltando!\n");
                        }
                    } while(opc1 != FIM);
                    break;

            case 2: do {
                        opc1 = LISTAGENS_AERONAVES();

                        switch (opc1) {
                                case 1: printf("LISTAGEM DE AERONAVE POR FABRICANTE\n");
                                        printf("Fabricante desejado:");
                                        getchar();
                                        fgets(fabricante_desejado, T_STR, stdin);
                                        retirar_enter(fabricante_desejado);
                                        formatar_maiuculo(fabricante_desejado);
                                        listar_aeronave_fabricante(fabricante_desejado, lista_aeronaves);
                                        break;
                                
                                case 2: printf("LISTAGEM DE AERONAVE POR TIPO DE AVIAO\n");
                                        printf("Tipo procurado:");
                                        scanf("%d", &C_P);
                                        listar_aeronave_por_tipo(C_P, lista_aeronaves);  
                                        break;

                                case 3: printf("LISTAGEM DE AERONAVE POR MODELO DE AVIAO\n");
                                        printf("Modelo procurado:");
                                        getchar();
                                        fgets(modelo_desejado, T_STR, stdin);
                                        retirar_enter(modelo_desejado);
                                        formatar_maiuculo(modelo_desejado);
                                        listar_aeronave_por_modelo(modelo_desejado, lista_aeronaves);     
                                        break;

                                case 4: printf("LISTAGEM DE AERONAVE POR ANO DE FABRICACAO\n");
                                        printf("Ano procurado:");
                                        scanf("%i", &ano_desejado);
                                        listar_aeronave_por_ano(ano_desejado, lista_aeronaves);    
                                        break;

                                case 5: 
                                        printf("LISTAGEM DE AERONAVE POR SITUACAO\n");
                                        printf("Situacao procurada:");
                                        scanf("%i", &O_M);
                                        listar_aeronave_por_situacao(O_M, lista_aeronaves); 
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
                                case 1: printf("LISTAGEM DE ROTA POR DESTINO\n");
                                        printf("Destino procurado:");
                                        getchar();
                                        fgets(destino_desejado, T_STR, stdin);
                                        retirar_enter(destino_desejado);
                                        formatar_maiuculo(destino_desejado);
                                        listar_rotas_por_destino(destino_desejado, lista_rotas);
                                        break;
                                
                                case 2: printf("Origem procurada:");
                                        getchar();
                                        fgets(origem_desejada, T_STR, stdin);
                                        retirar_enter(origem_desejada);
                                        formatar_maiuculo(origem_desejada);
                                        listar_rotas_por_origem(origem_desejada, lista_rotas);
                                        break;

                                case 3: maior_passageiros = achar_maior_numero_de_passageiros();
                                        printf("A(as) rota com maior numero de passageiros eh:\n");
                                        listar_rotas_maior_passageiros(maior_passageiros, lista_rotas);
                                        break;

                                case 4: menor_passageiros = achar_menor_numero_de_passageiros();
                                        printf("A(as) rota com menor numero de passageiros eh:\n");
                                        listar_rotas_menor_passageiros(menor_passageiros, lista_rotas);
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
                                case 1: printf("PERCENTUAL DE VOOS PARA UM DESTINO EM UM INTERVALO DE DATAS\n");
                                        printf("Determinar destino:");
                                        getchar();
                                        fgets(destino_determinado, T_STR, stdin);
                                        retirar_enter(destino_determinado);
                                        formatar_maiuculo(destino_determinado);

                                        printf("Colocar apenas dia e mes.\nData inicial: ");
                                        scanf("%d/%d", &data_inicio.dia, &data_inicio.mes);
                                        printf("Data final: ");
                                        scanf("%d/%d", &data_termino.dia, &data_termino.mes);
                                        getchar();

                                        inicio = data_inicio_intervalo_em_horas(data_inicio);
                                        fim = data_final_intervalo_em_horas(data_termino);

                                        percentual_voos_destino_intervalo_datas(destino_determinado, inicio, fim, lista_rotas);
                                        break;

                                case 2: printf("PERCENTUAL DE VOOS REALIZADOS POR AERONAVE\n");
                                        printf("Matricula da aeronave:");
                                        fgets(matricula_percentual, T_STR, stdin);
                                        retirar_enter(matricula_percentual);
                                        formatar_maiuculo(matricula_percentual);
                                        percentual_voos_realizados_por_aeronave(matricula_percentual, lista_rotas, lista_aeronaves);
                                        break;

                                case 0: printf("Voltando!\n");
                                        break;        
                        }
                    } while(opc1 != FIM);
                    break;

            case 5: 
                    printf("CONSUMO DE COMBUSTIVEL POR INTERVALO DE DATA\n");

                    printf("Colocar apenas dia e mes.\nData inicial:");
                    scanf("%d/%d", &data_comeco.dia, &data_comeco.mes);
                    printf("Data final: ");
                    scanf("%d/%d", &data_terminado.dia, &data_terminado.mes);
                    getchar();

                    inicio = data_inicio_intervalo_em_horas(data_comeco);
                    fim = data_final_intervalo_em_horas(data_terminado);

                    combustivel_total = combustivel_total_por_intervalo(comeco, final, lista_rotas);
                    printf("O total de combustivel consumido foi: %dL\n\n", combustivel_total);
                    break;

            case 6: printf("CONSULTA DE ROTA POR DATA\n");
                    printf("Data da rota: ");
                    scanf("%d/%d>", &data_desejada.dia, &data_desejada.mes);
                    getchar();
                    consultar_rota_data(data_desejada, lista_rotas);   
                    break;

            case 0: printf("Fechando!\n");
                    salvar_registros_aeronave_arquivo_binario("aeronaves_frota.bin", lista_aeronaves);
                    salvar_registros_rotas_arquivo_binario("rotas_frota.bin", lista_rotas);   
                    break;                
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