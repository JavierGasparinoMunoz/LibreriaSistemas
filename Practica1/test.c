#include <stdio.h>
#include <string.h>
#include "libreria.h"

int comprobarArgumentos(int argc, char *argv[]){
    int lineas;
    if ((argc==0) || (argc > 2)) {
        printf(stderr,"Se han pasado %d argumentos, se tiene que especificar al menos la función",argc);
    } else {
        if (!isdigit(*argv[0]) && ((strcmp(*argv[0],"head")) || (strcmp(*argv[0],"tail")) || (strcmp(*argv[0],"longlines")))){
            if (argc==1){
                lineas=10;
            } else {
                lineas=*argv[1];
            }
        } else {
             printf(stderr,"El primer argumento debe ser una de las funciones definidas");
        }
    }
 return lineas;
}

int main(int argc, char *argv[]){
    int n;
    n = comprobarArgumentos(argc,argv);
    if (*argv[0]){
        
    }
}

