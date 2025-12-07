CC = gcc
SRC = ./src
OBJS = ./objetos
TARGET = super_frota
LIMPAR = rm

all: obj
	$(CC) $(OBJS)/cadastros.o $(OBJS)/menus.o $(OBJS)/listagens.o $(OBJS)/complementos.o $(OBJS)/consultas.o $(OBJS)/percentuais.o $(OBJS)/arquivos.o $(OBJS)/existencia.o $(OBJS)/main.o -o $(TARGET)

obj:
	$(CC) -c $(SRC)/menus.c -o $(OBJS)/menus.o
	$(CC) -c $(SRC)/cadastros.c -o $(OBJS)/cadastros.o
	$(CC) -c $(SRC)/listagens.c -o $(OBJS)/listagens.o
	$(CC) -c $(SRC)/complementos.c -o $(OBJS)/complementos.o
	$(CC) -c $(SRC)/consultas.c -o $(OBJS)/consultas.o
	$(CC) -c $(SRC)/percentuais.c -o $(OBJS)/percentuais.o
	$(CC) -c $(SRC)/arquivos.c -o $(OBJS)/arquivos.o
	$(CC) -c $(SRC)/existencia.c -o $(OBJS)/existencia.o

	$(CC) -c main.c -o $(OBJS)/main.o 

clear:
	$(LIMPAR) $(OBJS)/*.o
	$(LIMPAR) $(TARGET)