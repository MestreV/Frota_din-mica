#include "../include/menus.h"

int menu(void)
{
    int opc;

    printf("1.Cadastros\n");
    printf("2.Listagens (aeronaves)\n");
    printf("3.Listagens (rotas)\n");
    printf("4.Percentuais\n");
    printf("5.Relatorio de aeronaves\n");
    printf("6.Busca de aeronave por matricula\n");
    printf("7.Consultar rota por data\n");
    printf("8.Consumo total de combustivel (intervalo_data)\n");
    printf(" 0.Sair do programa\n");
    printf(": : : :");
    scanf("%i", &opc);

    return opc;
}


int CADASTROS(void)
{
    int opc;
    printf("  CADASTROS:\n");
    printf("  1.Cadastrar nova aeronave\n");
    printf("  2.Cadastrar nova rota\n");
    printf("  0.Voltando!\n");
    printf("  : : : :");
    scanf("%i", &opc);
    
    return opc;
}

int PERCENTUAIS(void)
{
    int opc;

    printf("  PERCENTUAIS:\n");
    printf("  1.Percentual de voos (destino_intervaloData\n");
    printf("  2.Percentual de voos (aeronave)\n");
    printf("  0.Voltando!\n");
    printf("  : : : :");
    scanf("%i", &opc);
    
    return opc;
}

int LISTAGENS_AERONAVES(void)
{
    int opc;

    printf("  LISTAGENS DE AERONAVES:\n");
    printf("  1.Listagem de aeronave (fabricante)\n");
    printf("  2.Listagem de aeronave (tipo de aviao)\n");
    printf("  3.Listagem de aeronave (modelo)\n");
    printf("  4.Listagem de aeronave (ano)\n");
    printf("  5.Listagem de aeronave (situacao)\n");   
    printf("  0.Voltando!\n");
    printf("  : : : :");
    scanf("%i", &opc);

    return opc;
}

int LISTAGEM_ROTAS(void)
{
    int opc;

    printf("  LISTAGENS DE ROTAS:\n");
    printf("  1.Listagem de rotas (destino)\n");
    printf("  2.Listagem de rotas (origem)\n");
    printf("  3.Listagem de rotas (maior_passageiros)\n");
    printf("  4.Listagem de rotas (menor_passageiros)\n");
    printf("  0.Voltando!\n");
    printf("  : : : :");
    scanf("%i", &opc);

    return opc;
}