#include <stdio.h>

// Metodo head, este cogera las n primeras lineas y las mostrara
int head(int n){
    //Variables con el contador del bucle y el buffer de entrada de datos
    int count;
    count = 0;
    char buffer[1024];

    if (n > 0){
        while((count < n) && (fgets(buffer, 1024, stdin) != NULL)){
		        printf("%s", buffer);
		        count++;
	        }
    
        if (count < n){
            printf("Solo se han podido mostrar %d lineas", count);
        }
    } else if (n==0){
        printf("No hay ninguna linea que mostrar");
    } else {
        printf("n no puede ser un numero negativo");
    }
}

int fail(int n){

}