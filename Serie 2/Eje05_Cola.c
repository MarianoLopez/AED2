/* 
	En una clínica la secretaria hace un listado con los nombres y apellidos de los pacientes que van llegando para luego ser atendidos en ese orden. 
	El medico atiende un máximo de 20 pacientes por día. 
	Se solicita: generar un listado de todos los pacientes que van a ser atendidos en el día, 
	conocer si hay turnos disponibles, 
	y realizar una función para borrar de la lista los pacientes a medida que son atendidos
	(utilizar la implementación con frente móvil).
	
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define max 20

typedef char String[50];/*nuevo tipo de dato "String" a partir de array de char 50*/
typedef String Cola [max]; /*nuevo tipo de dato "Cola" a partir del tipo de dato String*/

/*prototipos*/
void crearColaVacia();
bool colaVacia(); 
bool colaLlena();
void agregarPaciente(String);
void atenderPaciente();
void listadoPacientesPorAtender();
int turnosDisponibles();
void menu();
void imprimirColaEstado();

/*variables globales*/
Cola cola;
int frente, final;

int main(){
	crearColaVacia();	
	menu();
	return 0;
}

void crearColaVacia(){
	frente = -1;	
	final = -1;	
}

bool colaVacia(){
	if ((frente == -1) && (final == -1))
		return true;
	else
		return false;
}

bool colaLlena(){
	return (final == (max-1));
}

void agregarPaciente(String pElemento){
	if (!colaLlena()){/*verificar que haya lugar*/
		final += 1;/*incrementar final en 1*/
		strcpy(cola[final], pElemento);/*copiar pElemento a cola[final]*/
		printf("Paciente %s insertado!\n", cola[final]);
		/*significa que es el primer elemento*/
		if (final == 0 ){frente = 0;}
	}else{
		printf("No hay lugar!\n");
	}
	imprimirColaEstado();
}

void atenderPaciente(){
	if (!colaVacia()){/*verificar que no este vacía*/
		printf("Paciente %s atendido!!!\n",cola[frente]);	
		strcpy(cola[frente], "");/*poner en cero o vacio el elemento del frente*/	
		/*si frente y final son iguales significa que elimine el ultimo*/
		if (frente == final){
			frente = -1;
			final = -1;
		}else{
			frente += 1;					
		}
	}else{
		printf("No hay pacientes para atender!!!\n");
	}
	imprimirColaEstado();
}

void listadoPacientesPorAtender(){
	int i;
	for (i = frente; i <= final; i++){printf("%s ", cola[i]);}
	printf("\n\n");	
}

int turnosDisponibles(){
	return colaLlena() ? 0 :(max-1)-final; /*if else + return en la misma línea*/
}

void imprimirColaEstado(){
	printf("Frente: %d - Final: %d\n",frente,final);
}
void menu(){	
	int opcion;
	String elem;
	printf("*** Opciones disponibles ***\n");	
	printf("\t1- Agregar Paciente\n\t2- Atender Paciente");
	printf("\n\t3- Listado Pacientes por atender \n\t4- Cola Vacia? \n\t5- Cola Llena? \n\t6-Turnos disponibles \n\t0- Salir \n");	
	printf("Opcion: ");
	scanf("%d", &opcion); fflush(stdin);
	switch (opcion){
		case 1:
		 	printf("Nombre del paciente (0 para cambiar de opcion): ");
			scanf("%s", &elem);
			while (strcmp(elem, "0") != 0 ){/* 0 = strings iguales*/															
				agregarPaciente(elem);
				printf("Nombre del paciente (0 para cambiar de opcion): ");
				scanf("%s", &elem); fflush(stdin);
			}
			printf("\n");
			menu();	
		    break;
		case 2:		    
		    atenderPaciente();
			printf("\n");
			menu();	
			break;		
		case 3:		 
			printf("*** Pacientes por atender ***\n");									
			listadoPacientesPorAtender();
			menu();	
			break;
		case 4:
			printf("Cola vacia? %s\n", colaVacia() ? "si" : "no");
			menu();	
			break;
		case 5:
			printf("Cola llena? %s\n", colaLlena() ? "si" : "no");
			menu();	
			break;
		case 6:
			printf("Turnos disponibles: %d\n",turnosDisponibles());
			menu();	
			break;									
		case 0:
			printf("\n");			
			break;
		default:
			printf("Opcion incorrecta\n");
			menu();
			break;
	}
}

