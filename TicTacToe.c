
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#define FILAS 3
#define COLUMNAS 3
enum{C_0,C_1,C_2,C_3};
#define ACENTO_A_MINUS 160
#define ACENTO_0_MINUS 162
#define MAX_TURNOS 9

char tablero[FILAS][COLUMNAS];
int turno;

void mostrarTablero();
void turnoJugador(char jugador);
void limpiarTablero();

int main()
{
    limpiarTablero();
    do{
        turnoJugador('X');
        turnoJugador('O');
    }while(C_1);
    return 0;
}

void mostrarTablero(){
    system(CLEAR);
    printf("Juego del gato v1.0\n\n");
    printf(" %c | %c | %c \n",tablero[C_0][C_0],tablero[C_0][C_1],tablero[C_0][C_2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n",tablero[C_1][C_0],tablero[C_1][C_1],tablero[C_1][C_2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n",tablero[C_2][C_0],tablero[C_2][C_1],tablero[C_2][C_2]);
}

void turnoJugador(char jugador){
        int fila,columna;
        char otraPartida,otroJugador;
        mostrarTablero();
        printf("\nEs turno del jugador %c\n",jugador);
        printf("Dime la fila (1 a 3): ");
        scanf("%d",&fila);
        while(fila<C_1 || fila>C_3){
            printf("Seleccione una fila v%clida\n",ACENTO_A_MINUS);
            printf("Dime la fila (1 a 3): ");
            scanf("%d",&fila);
        }
        printf("Dime la columna (1 a 3): ");
        scanf("%d",&columna);
        while(columna<C_1 || columna>C_3){
            printf("Seleccione una columna v%clida\n",ACENTO_A_MINUS);
            printf("Dime la columna (1 a 3): ");
            scanf("%d",&columna);
        }
        if (jugador=='X'){
            otroJugador='O';
        }
        else{
            otroJugador='X';
        }
        while(tablero[fila-C_1][columna-C_1]==jugador ||
              tablero[fila-C_1][columna-C_1]==otroJugador){
            printf("Casilla ocupada dame otra ubicaci%cn\n",ACENTO_0_MINUS);
            printf("Dime la fila (1 a 3): ");
            scanf("%d",&fila);
            while(fila<C_1 || fila>C_3){
                printf("Seleccione una fila v%clida\n",ACENTO_A_MINUS);
                printf("Dime la fila (1 a 3): ");
                scanf("%d",&fila);
            }
            printf("Dime la columna (1 a 3): ");
            scanf("%d",&columna);
            while(columna<C_1 || columna>C_3){
                printf("Seleccione una columna v%clida\n",ACENTO_A_MINUS);
                printf("Dime la columna (1 a 3): ");
                scanf("%d",&columna);
            }
        }
        tablero[fila-C_1][columna-C_1]=jugador;
        turno++;
        if((tablero[C_0][C_0]==tablero[C_0][C_1] && tablero[C_0][C_2]==tablero[C_0][C_1]
            && tablero[C_0][C_1]==jugador )||(tablero[C_1][C_0]==tablero[C_1][C_1] &&
            tablero[C_1][C_2]==tablero[C_1][C_1] && tablero[C_1][C_1]==jugador )||
            (tablero[C_2][C_0]==tablero[C_2][C_1] && tablero[C_2][C_2]==tablero[C_2][C_1] &&
            tablero[C_2][C_1]==jugador)||(tablero[C_0][C_0]==tablero[C_1][C_0] &&
            tablero[C_2][C_0]==tablero[C_1][C_0] && tablero[C_1][C_0]==jugador)||
            (tablero[C_0][C_1]==tablero[C_1][C_1] && tablero[C_2][C_1]==tablero[C_1][C_1] &&
            tablero[C_1][C_1]==jugador)||(tablero[C_0][C_2]==tablero[C_1][C_2] &&
            tablero[C_2][C_2]==tablero[C_1][C_2] && tablero[C_1][C_2]==jugador)||
            (tablero[C_0][C_0]==tablero[C_1][C_1] && tablero[C_2][C_2]==tablero[C_1][C_1] &&
            tablero[C_1][C_1]==jugador)||(tablero[C_2][C_0]==tablero[C_1][C_1] &&
            tablero[C_0][C_2]==tablero[C_1][C_1] && tablero[C_1][C_1]==jugador)){
              mostrarTablero();
              printf("El ganador es el jugador %c\n",jugador);
              printf("Otra partida? (S/N) ");
              getchar();
              scanf("%c",&otraPartida);
              if(otraPartida == 's' || otraPartida == 'S'){
                    turno=C_0;
                    limpiarTablero();
                    system(CLEAR);
              }
              else{
                   exit(0);
              }
        }
        else if (turno==MAX_TURNOS){
            mostrarTablero();
            printf("El resultado es un empate.\n");
            printf("Otra partida? (S/N) ");
            getchar();
            scanf("%c",&otraPartida);
            if(otraPartida == 's' || otraPartida == 'S'){
                turno=C_0;
                limpiarTablero();
                system(CLEAR);
            }
            else{
                exit(0);
            }
        }
        else{
            system(CLEAR);
        }
}

void limpiarTablero(){
    int i,j;
    for(i=C_0;i<FILAS;i++){
        for(j=C_0;j<COLUMNAS;j++){
            tablero[i][j]=' ';
        }
    }
}
