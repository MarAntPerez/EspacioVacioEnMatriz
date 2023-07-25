#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int sinRepetir(int numeroAleatorio, int arreglo[3][3]){
	int i;
	int j;
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			if(numeroAleatorio == arreglo[i][j]){
				return 1;
			}
		}
	}
	
}

int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	int arreglo[3][3];
	int i;
	int j;
	int numeroAleatorio;
	int coordenadaAleatoriaUno;
	int coordenadaAleatoriaDos;
	int espacioVacio = 0;
	int numeroIngresado;
	int numeroGuardado;
	
	//printf("%c", espacioVacio);
	
	for(i = 0; i < 3; i++){
		//printf("|");
		for(j = 0; j < 3; j++){
			while(sinRepetir(numeroAleatorio, arreglo)){
				numeroAleatorio = 1 + rand() % 9;
			}
			arreglo[i][j] = numeroAleatorio;
			//printf("%i", arreglo[i][j]);
		}
		//printf("|");
		//printf("\n");
	}
	
	coordenadaAleatoriaUno = 1 + rand() % 2;
	coordenadaAleatoriaDos = 1 + rand() % 2;
	
	numeroGuardado = arreglo[coordenadaAleatoriaUno][coordenadaAleatoriaDos];
	arreglo[coordenadaAleatoriaUno][coordenadaAleatoriaDos] = espacioVacio;
	//printf("%i", arreglo[coordenadaAleatoriaUno][coordenadaAleatoriaDos]);
	
	printf("La siguiente es una sucesion de numeros del 1 - 9 desordenada: \n");
	
	i = 0;
	j = 0;
	while(numeroGuardado != numeroIngresado){	
	for (i = 0; i < 3; i++){
		printf("|");
		for (j = 0; j < 3; j++){
			if(arreglo[i][j] == 0){
				printf(" - ");
			}else{
				printf(" %i ", arreglo[i][j]);
			}
		}
		printf("|");
		printf("\n");
	}
	
	printf("Ingresa el numero faltante: ");
	scanf("%i", &numeroIngresado);
	
	}
		
	if(numeroGuardado == numeroIngresado){
		arreglo[coordenadaAleatoriaUno][coordenadaAleatoriaDos] = numeroIngresado;
		printf("Correcto.\n");
		for (i = 0; i < 3; i++){
			printf("|");
			for (j = 0; j < 3; j++){
				if(arreglo[i][j] == 0){
					printf("-");
				}else{
					printf(" %i ", arreglo[i][j]);
				}
			}
			printf("|");
			printf("\n");
		}
	}
		
	return 0;
}
