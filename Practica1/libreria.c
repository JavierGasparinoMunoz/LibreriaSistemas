#include <stdio.h>

// Metodo head, este cogera las n primeras lineas y las mostrara
int head(int n){
    //Variables con el contador del bucle y el buffer de entrada de datos
    int count;
    count = 0;
    char buffer[1024];
    //Si el valor de n es mayor que 0 se mostrara las n primeras lineas
    if (n > 0){
        while((count < n) && (fgets(buffer, 1024, stdin) != NULL)){
		        printf("%s", buffer);
		        count++;
	        }
        //En caso en el que se diga que muestre más lineas de las que en verdad hay se mostraran las lineas y se avisara de que solo se han podido mostrar count lineas
        if (count < n){
            printf("Solo se han podido mostrar %d lineas", count);
        }
    //Si n = 0, se mostrara un pequeño mensaje avisando de que no hay lineas que mostrar
    } else if (n==0){
        printf("No hay ninguna linea que mostrar");
    //Si el valor introducido es negativo, saldrá un error ya que n no puede ser negativo
    } else {
        errx(1, "n no puede ser un numero negativo");
    }
}

//Metodo tail
int tail(int n){

}

//Metodo longlines
int longlines(int n){

}