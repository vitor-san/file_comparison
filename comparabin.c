/*
* Programa que compara dois arquivos binarios e,
* se achar alguma diferenca entre eles, mostra
* ao usuario quais bytes estao diferindo. Se os
* arquivos possuem tamanhos diferentes, o programa
* ira parar a comparacao assim que chegar ao final
* do arquivo mais curto.
*
* Autor: Vitor Santana Cordeiro
* GitHub: vitor-san
* Sao Paulo, Brasil. 2019.
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte; //defino o tipo de dados "byte"

int main(int argc, const char **argv) {
    FILE *fp1, *fp2;
    byte b1, b2;
    int count = 0;  //indexara os bytes lidos
    int difere = 0; //indicara ao programa se os arquivos tiveram alguma diferenca ou nao

    if (argc != 3) {    //se nao foram passados exatos tres argumentos...
        fprintf(stderr, "Formato incorreto!\n");
        fprintf(stderr, "Modo de uso: \"%s {arquivo1} {arquivo2}\"\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fp1 = fopen(argv[1], "rb");
    fp2 = fopen(argv[2], "rb");

    if (fp1 == NULL || fp2 == NULL) {   //erro na abertura dos arquivos
        perror("Erro");
        exit(EXIT_FAILURE);
    }

    b1 = fgetc(fp1);
    b2 = fgetc(fp2);

    while (!feof(fp1) && !feof(fp2)) {  //enquanto nao chegar no final de um dos arquivos
        count++;

        if (b1 != b2) {
            difere = 1;
            printf("%dº byte difere: (%hhu|%hhu)\n", count, b1, b2);
        }

        b1 = fgetc(fp1);
        b2 = fgetc(fp2);
    }

    if (!difere) printf("Arquivos iguais!\n");

    fclose(fp1);
    fclose(fp2);

    return 0;
}
