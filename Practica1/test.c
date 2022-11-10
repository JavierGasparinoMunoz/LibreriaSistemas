#include <stdio.h>
#include <string.h>
#include "libreria.h"
#include <err.h>

//Metodo encargado de comprobar que el numero y el tipo de los argumentos es valido
int comprobarArgumentos(int argc, char *argv[]){
    //Variable que contendra el numero de lineas
    int lineas;
    //Si se reciben 0 argumentos o más de 2 argumentos se mostrara un mensaje de error
    if ((argc==0) || (argc > 2)) {
        errx(1, "Se han pasado %d argumentos, se tiene que especificar al menos la función",argc); 
    //Si se reciben 1 o 2 argumentos entrara en el ese     
    } else { 
        // El primer argumento debe ser el metodo a elegir, por lo que se comprueba que este no sea un numero y sea head, tail o lonlines.
        if (!isdigit(*argv[0]) && ((strcmp(*argv[0],"head")) || (strcmp(*argv[0],"tail")) || (strcmp(*argv[0],"longlines")))){
            // En el caso en el que solo se reciba el metodo elegido como argumento, lineas va a valer 10 por defecto
            if (argc==1){
                lineas=10;
            // En el caso en el que si se reciba el numero de lineas por argumento, la variable lineas valdra el valor introducido
            } else {
                lineas= atoi(*argv[1]);
            }
        // Si el primer argumento no es el metodo valido que se pueda realizar saltara un mensaje de error
        } else {
             errx(1, "El primer argumento debe ser una de las funciones definidas");
        }
    }
//Se devuelve el valor de la variable lineas
 return lineas;
}

//Metodo encargado de comprobar que metodo se ha elegido
int comprobarStrings(char *argv[]){
    if (strcmp(*argv[0],"head")){
        return 1;
    }else if (strcmp(*argv[0],"tail")){
        return 2;
    }else if (strcmp(*argv[0],"longlines")){
        return 3;
    }else{
        errx(1, "Error"); 
    }
    
    
}

//Metodo main del programa
int main(int argc, char *argv[]){
    //Variable cuyo valor va a ser el numero de lineas
    int n;
    //n se inicializa
    n = comprobarArgumentos(argc,argv);
    
    switch(comprobarStrings(argv)){
        case 1:
            head(n);
            break;
        case 2:
            tail(n);
            break;
        case 3:
            longlines(n);
            break;
        default:
            break;
    }
}

