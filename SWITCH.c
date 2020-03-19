#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>


void MACrandom();


struct computadoras{
		int puerto;
		char mac[12];
	}computadoras[24];


struct Trama_Emisor{
	char macD[12];
	char macO[12];
	int puerto;
}tramaE;


struct Trama_Receptor{
	char macD[12];
	char macO[12];
	int puerto;
}tramaR;


struct tabla{
	int puerto;
	char mac[12];
}tabla[24];


int main(){

	int i=0, j=0, k=0, d=0, f=0, g=0, m=0, origen, destino, igual=0, resp=0, coincidencia=0, cargaVerificada[24], cargaVerificadaII[24];
	
	srand(time(NULL));
	
	for(i=0;i<24;i++){
		tabla[i].puerto=25;
		cargaVerificada[i]=0;
	}
	
	MACrandom(i ,j);
	
	while(resp==0){
		i=0, j=0, k=0, d=0, f=0, g=0, igual=0, resp=0, coincidencia=0;
		
		for(i=0;i<24;i++){
		
		for(m=0;m<24;m++){
		cargaVerificada[m]=0;
	}
		
		
			tramaR.puerto = 0 + rand () % (24);			//
			tramaE.puerto = 0 + rand () % (24);         //
			while(tramaR.puerto==tramaE.puerto){        // genera la trama, origen y destino, para ingresar al switch.
				tramaE.puerto = 0 + rand () % (24);     //	
			}    										//
	
			printf("________________________________________________PUERTOS Y MACS__________________________________________________________\n\n");
    		for (d=0;d<24;d++){
    			if(computadoras[d].puerto<10){
				printf("%d:   ",computadoras[d].puerto);	
				}else{
				printf("%d:  ",computadoras[d].puerto);	
				}
				for(j=0;j<12;j++){
				printf("%c",computadoras[d].mac[j]);
			}
		Sleep(20);
		printf("   ");
	}
	printf("\n________________________________________________________________________________________________________________________\n");
	
	strcpy(tramaE.macD, computadoras[tramaR.puerto].mac);
	strcpy(tramaE.macO, computadoras[tramaE.puerto].mac);
	strcpy(tramaR.macD, computadoras[tramaE.puerto].mac);
	strcpy(tramaR.macO, computadoras[tramaR.puerto].mac);
	
	
	if(i+1<10){
		printf("\n\nTrama %d:  (MAC Destino: ", i+1);
	for(j=0;j<12;j++){
		printf("%c", computadoras[tramaR.puerto].mac[j]);
	}
	//printf(", Puerto Destino: %d", computadoras[tramaR.puerto].puerto);
	printf(", MAC Origen: ");
	for(j=0;j<12;j++){
		printf("%c", computadoras[tramaE.puerto].mac[j]);
	}
	printf(", Puerto Origen: %d)\n", computadoras[tramaE.puerto].puerto);
	
		Sleep(50);
	}
	
	else{
		printf("\nTrama %d: (MAC Destino: ", i+1);
	for(j=0;j<12;j++){
		printf("%c", computadoras[tramaR.puerto].mac[j]);
	}
	//printf(", Puerto Destino: %d", computadoras[tramaR.puerto].puerto);
	printf(", MAC Origen: ");
	for(j=0;j<12;j++){
		printf("%c", computadoras[tramaE.puerto].mac[j]);
	}
	printf(", Puerto Origen: %d)\n", computadoras[tramaE.puerto].puerto);
		Sleep(50);
	}
	
	fflush(stdout);
	igual=0;
	for(j=0;j<24;j++){
		if(tabla[j].puerto==tramaR.puerto){
			igual=1;
		}
	}
	if(igual==0){
		tabla[k].puerto=tramaR.puerto;
		for(j=0;j<12;j++){
			tabla[k].mac[j] = computadoras[tramaR.puerto].mac[j];
			}
		k++;
		}
		
	igual=0;
	for(j=0;j<24;j++){
		if(tabla[j].puerto==tramaE.puerto){
			igual=1;
		}
	}
	if(igual==0){
		tabla[k].puerto=tramaE.puerto;
		for(j=0;j<12;j++){
			tabla[k].mac[j] = computadoras[tramaE.puerto].mac[j];
			}
		k++;
		}
		
	printf("\n\n---------------------------------------------TABLA MAC DEL SWITCH-------------------------------------------------------\n\n");
	for(f=0;f<24;f++){
		if(tabla[f].puerto<24){
			if((tabla[f].puerto != tramaR.puerto)&&(cargaVerificada[f]==0)){
				if(tabla[f].puerto<10){
			printf("%d: ",tabla[f].puerto);
			}
				else{
			printf("%d: ",tabla[f].puerto);
			}
		}

		for(j=0;j<12;j++){
			printf("%c",tabla[f].mac[j]);
		}
		printf("   ");
		Sleep(50);	
	}
}
		printf("\n\n------------------------------------------------------------------------------------------------------------------------\n\n");
		Sleep(55);
		printf("ESPERANDO RESPUESTA...     \n\n");
		Sleep(2050);
		printf("PULSE UNA TECLA PARA CONTINUAR.     ");
		getch();
		/*for(g=0;g<24;g++){
			if(computadoras[g].mac==tramaR.macO){
				coincidencia=1;
			}	
		}*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
			//if(coincidencia==1){
			system("cls");
			printf("________________________________________________PUERTOS Y MACS__________________________________________________________\n\n");
    		for (d=0;d<24;d++){
				if(computadoras[d].puerto<10){
				printf("%d:   ",computadoras[d].puerto);	
				}else{
				printf("%d:  ",computadoras[d].puerto);	
				}
				for(j=0;j<12;j++){
				printf("%c",computadoras[d].mac[j]);
			}
		Sleep(20);
		printf("   ");
	}
	printf("\n________________________________________________________________________________________________________________________\n");

		if(i+1<10){
		printf("\n\nTrama %d:  (MAC Destino: ", i+1);
	for(j=0;j<12;j++){
		printf("%c", computadoras[tramaR.puerto].mac[j]);
	}
	//printf(", Puerto Destino: %d", computadoras[tramaR.puerto].puerto);
	printf(", MAC Origen: ");
	for(j=0;j<12;j++){
		printf("%c", computadoras[tramaE.puerto].mac[j]);
	}
	printf(", Puerto Origen: %d)\n", computadoras[tramaE.puerto].puerto);

		Sleep(50);
	}

	else{
		printf("\nTrama %d: (MAC Destino: ", i+1);
	for(j=0;j<12;j++){
		printf("%c", computadoras[tramaR.puerto].mac[j]);
	}
	//printf(", Puerto Destino: %d", computadoras[tramaR.puerto].puerto);
	printf(", MAC Origen: ");
	for(j=0;j<12;j++){
		printf("%c", computadoras[tramaE.puerto].mac[j]);
	}
	printf(", Puerto Origen: %d)\n", computadoras[tramaE.puerto].puerto);
		Sleep(50);
	}
	if(i+1<10){
		printf("\nRespuesta a Trama %d:  (MAC Destino: ", i+1);
	for(j=0;j<12;j++){
		printf("%c", computadoras[tramaE.puerto].mac[j]);
	}
	//printf(", Puerto Destino: %d", computadoras[tramaE.puerto].puerto);
	printf(", MAC Origen: ");
	for(j=0;j<12;j++){
		printf("%c", computadoras[tramaR.puerto].mac[j]);
	}
	printf(", Puerto Origen: %d)\n", computadoras[tramaR.puerto].puerto);
	
		Sleep(50);
	}

	else{
		printf("\n\nRespuesta a Trama %d: (MAC Destino: ", i+1);
	for(j=0;j<12;j++){
		printf("%c", computadoras[tramaE.puerto].mac[j]);
	}
	//printf(", Puerto Destino: %d", computadoras[tramaE.puerto].puerto);
	printf(", MAC Origen: ");
	for(j=0;j<12;j++){
		printf("%c", computadoras[tramaR.puerto].mac[j]);
	}
	printf(", Puerto Origen: %d)\n\n", computadoras[tramaR.puerto].puerto);
		Sleep(50);
	}

	printf("\n\n---------------------------------------------TABLA MAC DEL SWITCH-------------------------------------------------------\n\n");                                    //
	for(f=0;f<24;f++){
			if(tabla[f].puerto<24){
				
				if(tabla[f].puerto<10){
			printf("%d: ",tabla[f].puerto);
			}
			
			else{
			printf("%d: ",tabla[f].puerto);
			}	
			
			if(tabla[f].puerto == tramaR.puerto){
				cargaVerificada[f]=1;
			}
		}
		
		for(j=0;j<12;j++){
			printf("%c",tabla[f].mac[j]);
		}
		printf("   ");
		Sleep(50);
	}
		
	printf("\n\n------------------------------------------------------------------------------------------------------------------------\n\n");
	printf("PULSE UNA TECLA PARA CONTINUAR.     ");
	getch();
	if(i==23){
		resp=1;
	}else{
		resp=0;
	}
	
	
//	}
	system("cls");		
}
	
}
	printf("PULSE UNA TECLA PARA SALIR.\n\nTrabajo Ingtegrador de Programacion Estructurada: Elias Machuanin.\n");
}


void MACrandom(int i, int j){
	for (i=0;i<24;i++){
		computadoras[i].puerto = i;
		for (j=0;j<12;j++){
			if((0 + rand() % 2)==0){
			computadoras[i].mac[j] = (48 + rand() % ((57)-48));	
			}
			else{
				computadoras[i].mac[j] = (65 + rand() % ((71)-65));
			}
		}
	}
}



/*if(i+1<10){
		printf("\nRespuesta a Trama %d:  (MAC Destino: ", i+1);
	for(j=0;j<12;j++){
		printf("%c", computadoras[tramaE.puerto].mac[j]);
	}
	printf(", Puerto Destino: %d", computadoras[tramaE.puerto].puerto);
	printf(", MAC Origen: ");
	for(j=0;j<12;j++){
		printf("%c", computadoras[tramaR.puerto].mac[j]);
	}
	printf(", Puerto Origen: %d)\n", computadoras[tramaR.puerto].puerto);
	
		Sleep(50);
	}
	
	else{
		printf("\n\nRespuesta a Trama %d: (MAC Destino: ", i+1);
	for(j=0;j<12;j++){
		printf("%c", computadoras[tramaE.puerto].mac[j]);
	}
	printf(", Puerto Destino: %d", computadoras[tramaE.puerto].puerto);
	printf(", MAC Origen: ");
	for(j=0;j<12;j++){
		printf("%c", computadoras[tramaR.puerto].mac[j]);
	}
	printf(", Puerto Origen: %d)\n\n", computadoras[tramaR.puerto].puerto);
		Sleep(50);
	}*/
