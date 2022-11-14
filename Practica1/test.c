#include <stdio.h>
#include <string.h>
#include "libreria.h"
#include <err.h>
#include <stdlib.h>

// Metodo encargado de comprobar que el numero y el tipo de los argumentos es valido
int comprobarArgumentos(int argc, char *argv[])
{
    // Variable que contendra el numero de lineas
    int lineas;
    // Si se reciben 0 argumentos o más de 2 argumentos se mostrara un mensaje de error
    if ((argc == 0) || (argc > 3))
    {
        errx(1, "Se han pasado %d argumentos, se tiene que especificar al menos la función \n", argc);
        // Si se reciben 1 o 2 argumentos entrara en el ese
    }
    else
    {
        // El primer argumento debe ser el metodo a elegir, por lo que se comprueba que este no sea un numero y sea head, tail o lonlines.
        if (((strcmp(argv[1], "head") == 0) || (strcmp(argv[1], "tail") == 0) || (strcmp(argv[1], "longlines") == 0)))
        {
            // En el caso en el que solo se reciba el metodo elegido como argumento, lineas va a valer 10 por defecto
            if (argc == 2)
            {
                lineas = 10;
                // En el caso en el que si se reciba el numero de lineas por argumento, la variable lineas valdra el valor introducido
            }
            else if (argc == 3)
            {
                lineas = atoi(argv[2]);
            }

            // Si el primer argumento no es el metodo valido que se pueda realizar saltara un mensaje de error
        }
        else
        {
            errx(1, "El primer argumento debe ser una de las funciones definidas \n");
        }
    }
    // Se devuelve el valor de la variable lineas
    return lineas;
}

// Metodo main del programa
int main(int argc, char *argv[])
{
    // Variable cuyo valor va a ser el numero de lineas
    int n, opcion;
    // n se inicializa
    n = comprobarArgumentos(argc, argv);
    
    if (strcmp(argv[1], "head")==0)
    {
        head(n);
    }
    else if (strcmp(argv[1], "tail")==0)
    {
        tail(n);     
    }
    else if (strcmp(argv[1], "longlines")==0)
    {
        longlines(n); 
    }
    else
    {
        errx(1, "Error \n");
    }
    
}
