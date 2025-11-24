#include <stdio.h>
#include <time.h> //Garantiza diferentes secuencias de numeros aleatorios
#include <stdlib.h>// Agrega la funcion rand() para generar numeros aleatorios
#include <conio.h>
#include <string.h>
#include <windows.h>


#define total 30
#define generar 10


void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void centrarTexto(int fila, const char *texto){
    int ancho = 80;
    int largo = strlen(texto);
    int x =(ancho-largo) / 2;

    gotoxy(x, fila);
    printf("%s",texto);
}

//Funcion para evitar que se repitan preguntas en una sesión
void barajar(int *array, int n){ //
    for(int i = n - 1; i >0; i--){
        int j = rand() %(i+1);
        int temp = array[i];//Se intercambian valores de i y j en el arreglo
        array[i] = array[j];//de modo que el valor de i se mueve a la posición j
        array[j] = temp;    //y el valor j se mueve a la posicion i.

    }
}

int evaluarRespuesta(char res, int indice){
    static char respuestas[]={
        'A','B','B','A','C','C','A','B','A','C', //comillas simples para los char
        'B','A','C','C','A','A','B','C','A','C',
        'B','A','A','B','A','B','B','C','C','C'
    };
    if(res == respuestas[indice]){
            gotoxy(35,11);
            printf("respuesta correcta");
            return 1;
    }else{
        gotoxy(35,11);
        printf("respuesta incorrecta");
        return 0;
    }
}

void presentarPreguntas(int indice){
    static char *preguntas[] = { //se usa static para no borrar el arreglo
        " Pregunta 1"," Pregunta 2"," Pregunta 3"," Pregunta 4"," Pregunta 5"," Pregunta 6",
        " Pregunta 7"," Pregunta 8"," Pregunta 9"," Pregunta 10"," Pregunta 11"," Pregunta 12",
        " Pregunta 13"," Pregunta 14"," Pregunta 15"," Pregunta 16"," Pregunta 17"," Pregunta 18",
        " Pregunta 19"," Pregunta 20"," Pregunta 21"," Pregunta 22"," Pregunta 23"," Pregunta 24",
        " Pregunta 25"," Pregunta 26"," Pregunta 27"," Pregunta 28"," Pregunta 29"," Pregunta 30",
    };
    static char *opciones[] = {
        "A)",
        "B)",
        "C)"

    };
    centrarTexto(4, preguntas[indice]);
    centrarTexto(5, opciones[0]);
    centrarTexto(6, opciones[1]);
    centrarTexto(7, opciones[2]);

}

//Función principal
int main(){
    srand(time(NULL));//Inicializa el generador de numeros aleatorios

    int numeros[total];
    char nombre[50];
    for(int cont = 0;cont < 3;cont++){
        system("cls");

        gotoxy(35,6);
        printf("Ingresa tu nombre: ");
        fgets(nombre,50, stdin);

        for(int i = 0; i<total; i++){
            numeros[i] = i +1;
        }

        barajar(numeros,total);
        int progreso = 1;
        float porcentaje = 0.0;
        gotoxy(35, 3);
        printf("Preguntas:");
        int correctas = 0;
        for(int i = 0; i<generar; i++){
            char res;
            system("cls");
            int indice = numeros[i]-1;
            for(;;){
                system("cls");
                if(porcentaje > 0){
                    gotoxy(50, 5);
                    printf("Porcentaje de aciertos: %2.f%%", porcentaje);
                }
                gotoxy(50,3);
                printf("%i / 10",progreso);
                presentarPreguntas(indice);
                gotoxy(35,9);
                scanf(" %c", &res);
                if(res != 'A' && res != 'B' && res!= 'C'){//Comillas simples para caracteres
                    gotoxy(35,10);
                    printf("Opcion no valida, ingresa A,B o C");
                    getch();
                }else{
                    correctas += evaluarRespuesta(res,indice); //la funcion regresa 1 o 0 sumando eso a la variable correctas
                    porcentaje = (correctas*100.0)/10.0;
                    progreso+=1;
                    break;
                }
            }
            gotoxy(50, 5);
            printf("Porcentaje de aciertos: %2.f%%", porcentaje);
            getch();
            system("cls");
        }
        gotoxy(35, 15);
        printf("%s, Presiona cualquier tecla para continuar.", nombre);
        getch();


    }

    return 0;
}
