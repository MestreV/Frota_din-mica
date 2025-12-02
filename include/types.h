#define T_STR   100
#define FIM     0



typedef char string[T_STR];

typedef enum {CARGA = 1, PASSAGEIRO = 2} tipo_t;

typedef enum {OPERACAO = 1, MANUTENCAO = 2} situacao_t;

typedef struct data_hora {
    unsigned int dia;
    unsigned int mes;
    unsigned int ano;
    unsigned int hora;
    unsigned int minutos;
} data_hora_t;

typedef struct trip_necessaria{
    unsigned int pilotos;
    unsigned int comissarias_de_bordo;
    unsigned int total;
}tripulacao_necessaria_t;

typedef struct dados_aeronave{
    unsigned int identificacao;
    string modelo;
    string fabricante;
    string matricula;
    unsigned int ano_fabricacao;
    tipo_t tipo;
    unsigned int num_passageiros;
    situacao_t situacao;
    tripulacao_necessaria_t tripulacao;
}dados_aeronave_t;

typedef struct dados_rota{
    unsigned int codigo;
    data_hora_t data_hora;
    string local_partida;
    string local_destino;
    data_hora_t tempo_estimado;
    unsigned int combustivel_necessario;
    unsigned int qtd_passageiros;
    unsigned int qtd_carga;
    stringao nomes;
    string matricula_alocada;
}dados_rota_t;