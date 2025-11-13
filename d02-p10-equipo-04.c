#include <stdio.h>
#include <time.h> //Garantiza diferentes secuencias de numeros aleatorios
#include <stdlib.h>// Agrega la funcion rand() para generar numeros aleatorios
#include <conio.h>


#define total 30
#define generar 10

//Funcion para evitar que se repitan preguntas en una sesión
void barajar(int *array, int n){ //
    for(int i = n - 1; i >0; i--){
        int j = rand() %(i+1);
        int temp = array[i];//Se intercambian valores de i y j en el arreglo
        array[i] = array[j];//de modo que el valor de i se mueve a la posición j
        array[j] = temp;    //y el valor j se mueve a la posicion i.

    }
}
//Función principal
int main(){
    srand(time(NULL));//Inicializa el generador de numeros aleatorios

    int numeros[total];
    char nombre[50];
    for(int i = 0;i < 3;i++){
        system("cls");

        printf("Ingresa tu nombre: ");
        fgets(nombre,50, stdin);

        for(int i = 0; i<total; i++){
        numeros[i] = i +1;
        }

        barajar(numeros, total);

        printf("10 numeros aleatorios unicos generados: \n\n");
        for(int i = 0; i<generar; i++){
            printf("%d\n", numeros[i]);
        }
        printf("\n");
        printf("%s\nPresiona cualquier tecla para continuar.", nombre);
        getch();

    }

    return 0;
}
