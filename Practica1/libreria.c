#include <stdio.h>
#include <string.h>
#include "libreria.h"
#include <err.h>
#include <stdlib.h>

int buscarNuevoMenor(char **lineasLongLines, int n);
void Ordenar(char *lineasLongLines[], int n);

// Metodo head, este cogera las n primeras lineas y las mostrara
int head(int n)
{
    // Variables con el contador del bucle y el buffer de entrada de datos
    int count;
    count = 0;
    char buffer[1024];
    // Si el valor de n es mayor que 0 se mostrara las n primeras lineas
    if (n > 0)
    {
        while ((count < n) && (fgets(buffer, 1024, stdin) != NULL))
        {
            printf("%s", buffer);
            count++;
        }
        // En caso en el que se diga que muestre más lineas de las que en verdad hay se mostraran las lineas y se avisara de que solo se han podido mostrar count lineas
        if (count < n)
        {
            printf("Solo se han podido mostrar %d lineas", count);
        }
        // Si n = 0, se mostrara un pequeño mensaje avisando de que no hay lineas que mostrar
    }
    else if (n == 0)
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
int tail(int n)
{
    int indice;
    char **lineasTail;
    lineasTail = (char **)malloc(n * sizeof(char *));
    // Si el valor de n es mayor que 0 se mostrara las n ultimas lineas
    if (n > 0)
    {
        indice = 0;
        char buffer[1024];
        while (fgets(buffer, 1024, stdin) != NULL)
        {
            *lineasTail[indice] = *buffer;
            if (indice < n)
            {
                indice++;
            }
            else
            {
                indice = 0;
            }
        }
        for (size_t i = 0; i < n; i++)
        {
            printf("%s", lineasTail[indice]);
            if ((indice == n - 1) && (i < n - 1))
            {
                indice = 0;
            }
            else
            {
                indice++;
            }
        }
        // Si n = 0, no se mostrara ninguna linea, en este caso se muestra un mensaje.
    }
    else if (n == 0)
    {
        printf("No hay ninguna linea que mostrar");
    }
    // Si el valor introducido es negativo, saldrá un error ya que n no puede ser negativo
    else
    {
        errx(1, "n no puede ser un numero negativo");
    }
    return 0;
}

// Metodo longlines
int longlines(int n)
{
    char **lineasLongLines;
    lineasLongLines = (char **)malloc(n * sizeof(char *));
    if (n > 0)
    {
        int count;
        count = 0;
        char buffer[1024];
        while (fgets(buffer, 1024, stdin) != NULL)
        {
            if (count < n)
            {
                *lineasLongLines[count] = *buffer;
                count++;
            }
            else
            {
                int longitudBuffer, menor;
                longitudBuffer = strlen(buffer);
                menor = buscarNuevoMenor(lineasLongLines, n);
                if (longitudBuffer > strlen(lineasLongLines[menor]))
                {
                    *lineasLongLines[menor] = *buffer;
                }
            }
        }
        Ordenar(lineasLongLines, n);
        for (size_t i = 0; i < n; i++)
        {
            printf("%s",lineasLongLines[i]);
        }
    }
    else if (n == 0)
    {
        printf("No hay ninguna linea que mostrar");
    }
    // Si el valor introducido es negativo, saldrá un error ya que n no puede ser negativo
    else
    {
        errx(1, "n no puede ser un numero negativo");
    }
    return 0;
}
/*
// Metodo de sustituir el antiguo menor por el nuevo
int continuacionLongLines(char *lineasLongLines[], char *buffer, int n)
{
    int longitudBuffer, menor;
    longitudBuffer = strlen(*buffer);
    menor = buscarNuevoMenor(lineasLongLines, n);
    if (longitudBuffer > strlen(*linesLongLines[menor]))
    {
        *lineasLongLines[menor] = *buffer;
    }
}*/

// Metodo encargado de encontrar la línea que tiene menor longitud
int buscarNuevoMenor(char **lineasLongLines, int n)
{
    int valor, indice;
    valor = 1024;
    indice = 0;
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

// Metodo encargado de ordenar el array
void Ordenar(char *lineasLongLines[], int n)
{
    char *texto;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; i < n; i++)
        {
            if (strlen(lineasLongLines[j + 1]) > strlen(lineasLongLines[j]))
            {
                texto = lineasLongLines[j];
                *lineasLongLines[j] = *lineasLongLines[j + 1];
                lineasLongLines[j + 1] = texto;
            }
        }
    }
}

// Metodo encargado de meter las ultimas n lineas de la entrada estandar
int incializarTail(char *lineasTail[], int n)
{
    int count;
    count = 0;
    char buffer[1024];
    while (fgets(buffer, 1024, stdin) != NULL)
    {
        *lineasTail[count] = *buffer;
        if (count < n)
        {
            count++;
        }
        else
        {
            count = 0;
        }
    }
    return count;
}