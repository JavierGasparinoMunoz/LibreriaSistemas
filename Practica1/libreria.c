#include <stdio.h>
#include <string.h>
#include "libreria.h"
#include <err.h>
#include <stdlib.h>

int buscarNuevoMenor(char **lineasLongLines, int n);

// Metodo head, este cogera las n primeras lineas y las mostrara
int head(int N)
{
    // Variables con el contador del bucle y el buffer de entrada de datos
    int count;
    count = 0;
    char buffer[1024];
    // Si el valor de n es mayor que 0 se mostrara las n primeras lineas
    if (N > 0)
    {
        while ((count < N) && (fgets(buffer, 1024, stdin) != NULL))
        {
            printf("%s", buffer);
            count++;
        }
        // En caso en el que se diga que muestre más lineas de las que en verdad hay se mostraran las lineas y se avisara de que solo se han podido mostrar count lineas
        if (count < N)
        {
            printf("Solo se han podido mostrar %d lineas", count);
        }
        // Si n = 0, se mostrara un pequeño mensaje avisando de que no hay lineas que mostrar
    }
    else if (N == 0)
    {
        printf("No hay ninguna linea que mostrar");
        // Si el valor introducido es negativo, saldrá un error ya que n no puede ser negativo
    }
    else
    {
        errx(1, "n no puede ser un numero negativo");
    }
    return 0;
}

// Metodo tail
int tail(int N)
{
    int indice;
    //Se reserva memoria con un array estatico y un dinamico
    char *lineasTail[N];
    for (size_t i = 0; i < N; i++)
    {
        lineasTail[i] = (char *)malloc(1024 * sizeof(char));
    }

    // Si el valor de n es mayor que 0 se mostrara las n ultimas lineas
    if (N > 0)
    {
        indice = 0;
        char buffer[1024];
        //Se va copiando el contenido de buffer en las lineas mientras se introducen hasta que llegas a N
        while (fgets(buffer, 1024, stdin) != NULL)
        {
            strcpy(lineasTail[indice],buffer);
            if (indice < N-1)
            {
                indice++;
            }
            else
            {
                indice = 0;
            }
        }
        //A partir de donde se quedo el indice se va imprimiendo
        printf("Resultado: \n");
        for (size_t i = 0; i < N; i++)
        {
            printf("%s", lineasTail[indice]);
            if (indice < N-1)
            {
                indice++;
            }
            else
            {
                indice = 0;
            }
        }
        // Si n = 0, no se mostrara ninguna linea, en este caso se muestra un mensaje.
    }
    else if (N == 0)
    {
        printf("No hay ninguna linea que mostrar \n");
    }
    // Si el valor introducido es negativo, saldrá un error ya que n no puede ser negativo
    else
    {
        errx(1, "n no puede ser un numero negativo \n");
    }
    //Se libera memoria dinamica
    for (size_t i = 0; i < N; i++)
    {
        free(lineasTail[i]);
    }
    
    return 0;
}

// Metodo longlines
int longlines(int N)
{
    //Se reserva memoria con un array estatico y un dinamico
    char *lineasLongLines[N];
    for (size_t i = 0; i < N; i++)
    {
        lineasLongLines[i] = (char *)malloc(1024 * sizeof(char));
    }
    if (N> 0)
    {
        int count;
        count = 0;
        char buffer[1024];
        //Bucle encargado de introducir las lineas de texto
        while (fgets(buffer, 1024, stdin) != NULL)
        {
            //Se introduciran las N lineas sin nunguna condicion
            if (count < N-1)
            {
                strcpy(lineasLongLines[count], buffer);
                count++;
            }
            //En este else se introde una linea en el array si y solo si la linea que se introduce
            //en la entrada es mayor al menor almacenado
            else
            {
                //longitudBuffer almacena la longitd de la linea de texto pasada,
                //menor almacena donde se encuentra la linea menor
                int longitudBuffer, menor;
                longitudBuffer = strlen(buffer);
                menor = buscarNuevoMenor(lineasLongLines, N);
                //Se va sustituyendo el valor de buffer en la linea con menor longitud
                if (longitudBuffer > strlen(lineasLongLines[menor]))
                {
                    strcpy(lineasLongLines[menor],buffer);
                }
            }
        }
        //Algoritmo de la burbuja, algoritmo tipico para la ordenacion de un array
        char texto[1024];
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < N -1; j++)
            {
                if (strlen(lineasLongLines[j + 1]) > strlen(lineasLongLines[j]))
                {
                    strcpy(texto ,lineasLongLines[j]);
                    strcpy(lineasLongLines[j],lineasLongLines[j + 1]);
                    strcpy(lineasLongLines[j + 1],texto);
                }
            }
        }
        //Se recorre lineas longLines y se van imprimiendo los N mayores 
        printf("Resultado: \n");
        for (size_t i = 0; i < N; i++)
        {
            printf("%s", lineasLongLines[i]);
        }
    }
    else if (N == 0)
    {
        printf("No hay ninguna linea que mostrar \n");
    }
    // Si el valor introducido es negativo, saldrá un error ya que n no puede ser negativo
    else
    {
        errx(1, "n no puede ser un numero negativo \n");
    }
    //Se libera memoria dinamica
    for (size_t i = 0; i < N; i++)
    {
        free(lineasLongLines[i]);
    }
    return 0;
}

// Metodo encargado de encontrar la línea que tiene menor longitud
int buscarNuevoMenor(char **lineasLongLines, int n)
{
    //valor tendra el valor de la longitd menor
    //indice tendra el indice del array
    int valor, indice;
    valor = 1024;
    indice = 0;
    //Se recorre el array pasado y se va guardando en valor el de longitd menor y 
    //en indice la posicion de esta linea, con esto siempre te quedas con el menor
    for (size_t i = 0; i < n; i++)
    {
        if (strlen(lineasLongLines[i]) < valor)
        {
            valor = strlen(lineasLongLines[i]);
            indice = i;
        }
    }
    return indice;
}