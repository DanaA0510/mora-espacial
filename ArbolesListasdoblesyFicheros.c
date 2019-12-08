#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pacientes{
    int NSS;
	char nombre[30];
	char curp[18];
	//char fecha_nac[15];
	//int edad;
	//float peso;
	//float altura;
	//char alergias[40];
	//char sangre [2];
};

struct medicos{
	char cedula[10];
	char nombre[30];
	//char horario[11];
	//int consultorio;
	//char especialidad[20];
	//char sexo;
	//char area[20];
	//char fecha_nac[15];
};

struct Elemento{
	struct pacientes paciente;
	struct Elemento *ant;
	struct Elemento *sig;
};

struct Nodo{
struct medicos medico;
struct elemento *inicio;
struct elemento *fin;
struct nodo *der;
struct nodo *izq;
};

///Arbol
struct medicos capturarDoctores(struct Nodo *raiz);
int insertarRecursivo(struct Nodo **raiz,struct medicos dato);
void imprimirMedico(struct medicos ejemplo);
void recorrer_InOrden(struct Nodo *raiz);
int buscar(struct Nodo *raiz,char cedula[]);

///Listas
struct pacientes capturarPacientes();
int insertarInicio(struct Elemento **inicio,struct Elemento **fin,struct Elemento *nuevo);
int insertarFinal(struct Elemento **inicio,struct Elemento **fin,struct Elemento *nuevo);
void InsertarPaciente(struct Elemento **inicio,struct Elemento **fin, struct pacientes Npaciente);
int insertardespues(struct Elemento **Nlista,struct Elemento *nuevo);
void imprimirPaciente(struct pacientes p);
int BuscarPaciente(struct Elemento **inicio,struct Elemento *Nlista,struct paciente Npaciente);

void imprimirMedicoPacientes(struct medicos ejemplo,struct Elemento *inicio);

int main()
{
    int pruebaIns,i,opc;
    struct medicos DocAux;
    struct Nodo *raiz=NULL;
    struct pacientes np1,np2;
    char cedula[10];

    for(i=0;i<1;i++){
    DocAux=capturarDoctores(raiz);

    pruebaIns=insertarRecursivo(&raiz,DocAux);
    if(pruebaIns==1){
    printf("\nEl doctor se guardo satisfactoriamente!");
    }else{
    printf("\nNo se pudo guardar el doctor! :c");
    }

                np1=capturarPacientes();
                InsertarPaciente(&raiz->inicio,&raiz->fin,np1);
                np1=capturarPacientes();
                InsertarPaciente(&raiz->inicio,&raiz->fin,np2);
    }
    printf("NN\n");
    recorrer_InOrden(raiz);

    return 0;
}

struct medicos capturarDoctores(struct Nodo *raiz){
    struct medicos medico;
    int valid1,valid2;
    valid1=0;
    valid2=0;
    printf("Capturando Medico\n");
    printf("\nCedula:");
    fflush(stdin);
    scanf("%s", medico.cedula);
    printf("Nombre del medico: ");
    fflush(stdin);
    scanf("%[^\n]", medico.nombre);
   /* printf("Fecha de nacimiento [DD/MM/AA]: ");
    fflush(stdin);
    scanf("%[^\n]", medico.fecha_nac);
    printf("Sexo: ");
    fflush(stdin);
    scanf("%c", &medico.sexo);
    printf("Area: ");
    fflush(stdin);
    scanf("%[^\n]", medico.area);
    printf("Especialidad:");
    fflush(stdin);
    scanf("%[^\n]", medico.especialidad);
    printf("Consultorio: ");
    fflush(stdin);
    scanf("%d", &medico.consultorio);
    printf("Horario: ");
    fflush(stdin);
    scanf("%[^\n]", medico.horario);*/
    return medico;
}

void imprimirMedico(struct medicos ejemplo){
printf("------------------------------------------");
printf("\nNombre: %s",ejemplo.nombre);
printf("\nCedula: %s",ejemplo.cedula);
/*printf("\nFecha de nacimiento: %s",ejemplo.fecha_nac);
printf("\nSexo: %c",ejemplo.sexo);
printf("\nArea: %s",ejemplo.area);
printf("\nEspecialidad: %s",ejemplo.especialidad);
printf("\nConsultorio: %d",ejemplo.consultorio);
printf("\nHorario: %s",ejemplo.horario);
*/
printf("\n------------------------------------------");
}


void imprimirMedicoPacientes(struct medicos ejemplo,struct Elemento *inicio){
printf("------------------------------------------");
printf("\nNombre: %s",ejemplo.nombre);
printf("\nCedula: %s",ejemplo.cedula);
/*printf("\nFecha de nacimiento: %s",ejemplo.fecha_nac);
printf("\nSexo: %c",ejemplo.sexo);
printf("\nArea: %s",ejemplo.area);
printf("\nEspecialidad: %s",ejemplo.especialidad);
printf("\nConsultorio: %d",ejemplo.consultorio);
printf("\nHorario: %s",ejemplo.horario);
*/
printf("\n----------------Pacientes-----------------");
mostrar(inicio);
printf("\n------------------------------------------");
}


int insertarRecursivo(struct Nodo **raiz,struct medicos dato){
	if(*raiz==NULL){
		struct Nodo *nuevo;
        nuevo=(struct Nodo*)malloc(sizeof(struct Nodo));
	if(nuevo==NULL){
		printf("no hay memoria :c");
		return 0;
	}
	nuevo->medico=dato;
	nuevo->inicio=NULL;
	nuevo->fin=NULL;
	nuevo->izq=NULL;
	nuevo->der=NULL;
	*raiz=nuevo;
	return 1;
	}
	if(dato.nombre<(*raiz)->medico.nombre){
		return insertarRecursivo(&((*raiz)->izq),dato);
	}else{
		if(dato.nombre>(*raiz)->medico.nombre){
		return insertarRecursivo(&((*raiz)->der),dato);
		}
		return -1;
	}
}

void recorrer_InOrden(struct Nodo *r){
    struct Nodo *raiz=r;
	if(r!=NULL){
		recorrer_InOrden(raiz->izq);
        imprimirMedicoPacientes(raiz->medico,raiz->inicio);
		recorrer_InOrden(raiz->der);
	}
}


///ARREGLADO
int buscar(struct Nodo *raiz,char *cedula){
	if(raiz==NULL){
		printf("\nNo existe esa cedula: %d",cedula);
		return 0;
	}
	if(strcmp(raiz->medico.cedula,cedula)==0){
		printf("\nSi existe ese medico: %d",raiz->medico.cedula);
		return 1;
	}
	if(cedula<raiz->medico.cedula){
		return buscar(raiz->izq,cedula);
	}else{
		return buscar(raiz->der,cedula);
	}
}


///Listas
struct pacientes capturarPacientes(){
    struct pacientes paciente;
    printf("\n\nIngresa los datos del paciente\n");
    printf("\nNumero de seguro(NSS): ");
    scanf("%d%*c",&paciente.NSS);
    printf("\nNombre del paciente: ");
    scanf("%[^\n]%*c", paciente.nombre);
    printf("\nCURP: ");
    scanf("%s%*c", &paciente.curp);
   /* printf("\nFecha de nacimiento [DD/MM/AA]: ");
    scanf("%s%*c", paciente.fecha_nac);
    printf("\nEdad: ");
    scanf("%d%*c", &paciente.edad);
    printf("\nPeso: ");
    scanf("%f%*c", &paciente.peso);
    printf("\nAltura:");
    scanf("%f%*c", &paciente.altura);
    printf("\nAlergias: ");
    scanf("%[^\n]%*c", paciente.alergias);
    printf("\nTipo de sangre: ");
    scanf("%s%*c", paciente.sangre);*/

    return paciente;
}

int insertarInicio(struct Elemento **inicio,struct Elemento **fin,struct Elemento *nuevo){
    nuevo->ant=NULL;
    if(*inicio==NULL){
        nuevo->sig=NULL;
    }else{
        nuevo->sig=*inicio;
        (*inicio)->ant=nuevo;
    }
    *inicio=nuevo;
    return 1;
}

int insertarFinal(struct Elemento **inicio,struct Elemento **fin,struct Elemento *nuevo){
    nuevo->sig=NULL;
    if(*inicio==NULL){
        nuevo->ant=NULL;
        *inicio=nuevo;

    }else{
      nuevo->ant=*fin;
      (*fin)->sig=nuevo;
    }
    *fin=nuevo;
    return 1;

}


