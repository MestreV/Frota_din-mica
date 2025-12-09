#include "../include/complementos.h"
#include <string.h>
#include <ctype.h>

void retirar_enter(char* str)
{
    *(str+strlen(str)-1) = '\0';
}

void formatar_maiuculo(char* str)
{
    for (int i = 0; i < strlen(str); i++) {
        *(str+i) = toupper(*(str+i));
    }
}

void msg(string_msg msg)
{
    printf("%s\n", msg);
    getchar();
}
