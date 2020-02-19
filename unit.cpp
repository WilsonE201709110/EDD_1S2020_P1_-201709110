#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <fstream> //para edidar archivos
#include <string> //para usar system 
#include <stdexcept> //para manejo de errores 

//si usamos getch()
//#define TECLA_ARRIBA 72
//#define TECLA_ABAJO 80
//#define ENTER 13

////si usamos getch2()
#define LETRA_X 'x'

#define NUMERO_UNO 49
#define NUMERO_DOS 50
#define NUMERO_TRES 51
#define NUMERO_CUATRO 52 
#define NUMERO_CINCO 53 
#define NUMERO_SEIS 54 
#define NUMERO_SIETE 55 
#define NUMERO_OCHO 56
#define NUMERO_NUEVE 57
#define ENTER 13

#define CONTROL_X 24
#define CONTROL_W 23
#define CONTROL_C 3
#define CONTROL_S 19

using namespace std;
//***************************************************************************************************************************
//estructura para nodo circular simple
struct nodoCir{
	string dato;
	nodoCir* siguiente;
} *primeroCir, *ultimoCir;
//ESTRUCTURA PARA NODO DOBLE ENZADO
struct nodo{
	char dato;
	nodo* siguiente;
	nodo* atras;
} *primero, *ultimo;

//Estructura para pila
struct nodoPila{
	char dato;
	nodo* siguiente;
} *primeroPila;

//*************************LISTA DOBLE
void insertarNodo();
void desplegarListaPU();
void modificarNodo();
void eliminarNodo();
void buscarNodos();

//Lista circualr
void insertarNodoCircular(string);
void desplegarListaCircular();
//pila
void push();
void pop();
void verPila();
//*******************************************************************************************************************************
void vaciarLista();

//*****************************
char caracter;
int lis=0;
int g=0; //variable indica en q posicion se encontrara el apuntador 
string Archivos[10];
int fila = 0;
//******************************/

void menu_principal();
void crearArchivo();
void abrirArchivo();
void recientesArchivo();

//**FUNCIONES DE CREAR ARCHIVO

void reportes();
void reporteLista();
void Guardar();

//FUNCION DE ARCHIVOS RECIENTES
void abrirARchivoDeRecientes(string);
//**GRAFICAS
void graficarLista(string);
void GenerarGrafica();
//*
void aniadir(char , int, int, bool, bool,bool);

int menu(const char *opciones[], int n);
void gotoxy2(int x,int y);
char getch2 ();


int main()
{
	system("COLOR 1E");
	menu_principal();

	cin.get();
	cin.get();

	return 0;
}

void menu_principal()
{
	bool repite = true;
	int opcion;

	//titulo y opciones
	//const char *titulo = "MENU ";
    const char *opciones[] = {"Crear Archivo", "Abrir Arcguivo", "Archivos Recientes", "salir"};
	int n = 4; //numero de opciones

	do{
		
		system("cls");
		gotoxy2(10,1);
		//EL TITULO DEL MENU
		cout<<"\n\tUNIVERSIDAD DE SAN CARLOS DE GUATEMALA";
		cout<<"\n\tFACULTADE DE INGENIERIA";
		cout<<"\n\tESTRUCTURA DE DATOS" ;
		cout<<"\n\tPRACTICA 1";
		cout<<"\n\t[WILSON EDUARDO PEREZ ECHEVERRIA]";
		cout<<"\n\t[201709110]" ;

		//IMPRIME LAS OPCIONES
		for(int i=0; i<n ;i++){
			gotoxy2(10,9+i); cout <<  i+1 <<"> "<<opciones[i];
		}
		//LEER LA OPCION ELEGIDA POR EL USUARIO
		cout<<"\n\tOPCION:";
		cin>>opcion;
		
		//ALTERNATIVA
		switch(opcion){
			case 1:
				crearArchivo();
				break;
			case 2:
				abrirArchivo();	
				break;
			case 3:
				recientesArchivo();
				break;
			case 4:
				repite = false;
				break;
		}

	}while(repite);
}

//*************creAR ARCHIVO
void crearArchivo()
{
	bool repite = true;
	int opcion;
	
	int tecla;
	char buscar[10];
	char reemplazar[10];

	//titulo y opciones
    const char *opciones[] = {"^W(Buscar y Reemplazar)", "^C(Reportes)", "^S(Guardar)","\t^X(Regresar)"};
	int n = 4; //numero de opciones


	do{
		system("cls");
		desplegarListaPU();
		//IMPRIME LAS OPCIONES
		for(int i=0; i<n ;i++){
			gotoxy2(9,5+i); cout <<"(^n^) --> "<<opciones[i];
		}
		//LEER LA OPCION ELEGIDA POR EL USUARIO
		
		do{
			g++;
			gotoxy2(0+g,0);
			insertarNodo();
			//caracter= getche();
			if(caracter==ENTER){
				
			}	//tecla = getch2(); //captura la tecla presionada por el usuario
		}while(caracter != ENTER);
		
		//g=0;
		
		gotoxy2(12,2);
		cout<<"\n\tCTrl+->:";
		opcion = getch2();
		
		
		//ALTERNATIVA
		//system("cls");
		switch(opcion){
			case CONTROL_W:
				system("cls");
					
				modificarNodo(); //llamar al metodo para modificar
            	system("pause>nul");
            	//desplegarListaPU();
			    break;
			case CONTROL_C:
				system("cls");
				
				reportes();
					system("pause>nul");
				break;
			case CONTROL_S:
				system("cls");
				Guardar();
				
				system("pause>nul");
				
				break;
					
					
			case CONTROL_X:
				repite = false;
					break;
		}

	}while(repite);
}

 void gotoxy2(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }
 
 char getch2 ()
{
   char c=0;
   DWORD modo, contador;
   HANDLE ih = GetStdHandle(STD_INPUT_HANDLE);
 
   // Desactivamos escritura en terminal
   SetConsoleMode (ih, modo & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));
 
   ReadConsoleA (ih, &c, 1, &contador, NULL);
 
   if (c == 0) {
      ReadConsoleA (ih, &c, 1, &contador, NULL);
   }
 
   SetConsoleMode (ih, modo); // Devolvemos control normal
 
   return c;
}

//------**Funciones DE CREAR ARCHIVO**************
void reportes(){
	bool repite = true;
	int opcion;

	do{
		
		system("cls");
		gotoxy2(5,1);
		//EL TITULO DEL MENU
		cout<<"\n REPORTE:";
		cout<<"\n\t1) Lista";
		cout<<"\n\t2) Palabras Buscadas";
		cout<<"\n\t3) Palabras Ordenadas";
		cout<<"\n\t4) Regresar";
		//LEER LA OPCION ELEGIDA POR EL USUARIO
		cout<<"\n\tOPCION:";
		cin>>opcion;
		
		//ALTERNATIVA
		switch(opcion){
			case 1:
				reporteLista();
				
				break;
				case 2:
					//menu_resta();
					break;
					case 3:
						//menu_multi();
					break;
					case 4:
						repite = false;
					break;

		}

	}while(repite);
}

void Guardar(){
	system("cls");
	nodo* actual = new nodo();
	actual = primero;

///
	ofstream archivo;
    string nombreArchivo, frase;
    

	if(primero!=NULL){
		while(actual!=NULL){
			
			frase+=actual->dato;
			actual = actual->siguiente;
		}
		
	}else{
		cout << "\n La listas se encuentra Vacia\n\n";
	}
	
    cout<<"Digite el nombre del archivo; ";
    //getline(cin, nombreArchivo);
	cin>>nombreArchivo;
	
    archivo.open(nombreArchivo.c_str(),ios::out); //ABRIENDO EL ARCHIVO

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        //exit(1); //para salir del programa
    }
    
   insertarNodoCircular(nombreArchivo);

    archivo<<frase<<endl; //escribir en archivo

    archivo.close(); //cerrar el archivo
	
	////
		
}
//*********GRficar lista doble

void reporteLista(){
	nodo* actual = new nodo();
	actual = primero;
	if(primero!=NULL){
		int ap1=0, ap2=1;
		while(actual!=NULL){
			
			//cout<<"\n"<<actual->dato;
			aniadir(actual->dato, ap1,ap2,true,true,false);
			actual = actual->siguiente;
			ap1++; ap2++;
		}
		aniadir('c', ap1,ap2,false,false,true);
	}else{
		cout << "\n La listas se encuentra Vacia\n\n";
	}
	
	graficarLista("lista");
}
void graficarLista(string nombre){
	system("cls");
	string comando;
	cout<<"Favor ingrese el siguiente guiente comando:\n ";
	cout<<"dot -Tpng "<<nombre<<".txt -o "<<nombre<<".png\n";
	try{
	
	comando="dot -Tpng "+nombre+".txt -o "+nombre+".png";
	//getline(cin, comando);
		system(comando.c_str());
		
		cout<<"reporte lista ya esta lista";
		system("pause");
	}catch(std::exception& e){
		cout<<"Reporte GRaficado. \n";
	}
}

void aniadir(char caracter, int ap1, int ap2, bool nodo, bool apuntador, bool final){
   ofstream archivo;
  try{
  
	archivo.open("lista.txt",ios::app);//ABRIENDO EL ARCHIVO EN MODO AÑADIEMDO

    	if(archivo.fail()){
        	cout<<"No se pudo abrir el archivo";
        	exit(1);
    	}

	if(nodo){
		archivo<<"nodo"<<ap1<<"[label=\""<<caracter<<"\"];"<<endl;
	}
	if(apuntador){
		archivo<<"nodo"<<ap1<<"->nodo"<<ap2<<";"<<endl;
		archivo<<"nodo"<<ap2<<"->nodo"<<ap1<<";"<<endl;
	}
    if(final){
    	archivo<<"nodo"<<ap1<<"[label=\"NULL\"];"<<endl;
    	archivo<<"}";
	}
	
	nodo = apuntador=final=false;
    archivo.close(); //cerramos el archivo
}catch(std::exception& e){
	cout<<"Nodos Agragados";
}
     

}

//-*****************************Opcion 2 abrir un archivo
void abrirArchivo(){
	system("cls");
	vaciarLista();
	ifstream archivo;
	string nombre, texto;
	
	cout<<"Ruta o nombre del archivo a buscar: ";
	cin>>nombre;

    archivo.open(nombre.c_str(),ios::in); //ABRIMOS EL ARCHIVO EN MODO LECTURA

    if(archivo.fail()){
        cout<<"nose pudo abrir el archivo";
        exit(1);
    }
	insertarNodoCircular(nombre);
	
    while(!archivo.eof()){ //MIENTRAS NO SEA EL FINAL DEL ARCHIVO
        getline(archivo,texto);
        
    	int c = texto.length();
    	//cout<<c<<endl;
    	for(int i=0; i<c;i++){
    		nodo* actual = new nodo(); //instanciamos la structura nodo para colocar ahi los caracteres
    		actual->dato=texto[i];
    		
    		if(primero==NULL){
    		//cout<<texto[i]<<"if\n";
				primero = actual;
				primero->siguiente = NULL;
				primero->atras = NULL;
				ultimo = primero;
			}else{
				ultimo->siguiente = actual;
				actual->siguiente = NULL;
				actual->atras = ultimo;
				ultimo = actual;
			}
			
			g++; //incrementar el valor de variabe g
		}
        

		
    }

	
	//system("pause");
	crearArchivo();
	archivo.close(); //CERRAMOS EL ARCHIVO
    
} 

//***********************opcion 3 ver archivos recientes
void recientesArchivo(){
	bool repite = true;
	int opcion;
	string nombreArchivo;
	do{
		system("cls");
		cout<<"\n\n\n\t\tARCHIVOS RECIENTES\n";
		desplegarListaCircular();
		gotoxy(16,21);
		cout<<"X. GENERAR REPORTE DE ARCHIVOS\n";
		cout<<"\tCTRL+X REgresar \n";
		gotoxy2(21,16);
		cout<<"\n\tR//: ";
		opcion = getch2();
		
		
		//ALTERNATIVA
		//system("cls");
		switch(opcion){
			case LETRA_X:
				system("cls");
				GenerarGrafica(); //llamar metodo para graficar
            	system("pause>nul");
            	
			    break;

			case NUMERO_UNO:
				nombreArchivo = Archivos[0];
				abrirARchivoDeRecientes(nombreArchivo);
				break;
			case NUMERO_DOS:
				nombreArchivo = Archivos[1];
				abrirARchivoDeRecientes(nombreArchivo);
				break;
			case NUMERO_TRES:
				nombreArchivo = Archivos[2];
				abrirARchivoDeRecientes(nombreArchivo);
				break;
			case NUMERO_CUATRO:
				nombreArchivo = Archivos[3];
				abrirARchivoDeRecientes(nombreArchivo);
				break;
			case NUMERO_CINCO:
				nombreArchivo = Archivos[4];
				abrirARchivoDeRecientes(nombreArchivo);
				break;	
			case NUMERO_SEIS:
				nombreArchivo = Archivos[5];
				abrirARchivoDeRecientes(nombreArchivo);
				break;
			case NUMERO_SIETE:
				nombreArchivo = Archivos[6];
				abrirARchivoDeRecientes(nombreArchivo);
				break;
			case NUMERO_OCHO:
				nombreArchivo = Archivos[7];
				abrirARchivoDeRecientes(nombreArchivo);
				break;	
					
			case CONTROL_X:
				repite = false;
					break;
		}

	}while(repite);
	
	system("pause");
	
}
void abrirARchivoDeRecientes(string nombre){
	ifstream archivo;
	string texto;
	vaciarLista(); //Vaciar la lista que estaba anteriormente

    archivo.open(nombre.c_str(),ios::in); //ABRIMOS EL ARCHIVO EN MODO LECTURA

    if(archivo.fail()){
        cout<<"nose pudo abrir el archivo";
        exit(1);
    }
	
    while(!archivo.eof()){ //MIENTRAS NO SEA EL FINAL DEL ARCHIVO
        getline(archivo,texto);
        
    	int c = texto.length();
    	//cout<<c<<endl;
    	for(int i=0; i<c;i++){
    		nodo* actual = new nodo(); //instanciamos la structura nodo para colocar ahi los caracteres
    		actual->dato=texto[i];
    		
    		if(primero==NULL){
    		//cout<<texto[i]<<"if\n";
				primero = actual;
				primero->siguiente = NULL;
				primero->atras = NULL;
				ultimo = primero;
			}else{
				ultimo->siguiente = actual;
				actual->siguiente = NULL;
				actual->atras = ultimo;
				ultimo = actual;
			}
			
			g++; //incrementar el valor de variabe g
		}
        
    }
	
	
	//system("pause");
	
	crearArchivo();
	archivo.close(); //CERRAMOS EL ARCHIVO
    
}
//*********************************************************************
///****GRAFICAR LISCA CIRCULAR**
void GenerarGrafica(){

	ofstream archivo; //nombre del archivo
	nodoCir* actual = new nodoCir();
	
	actual = primeroCir;
	if(primeroCir!=NULL){
		int ap1 =0, ap2=1;
		archivo.open("listaCircular.txt",ios::app);//ABRIENDO EL ARCHIVO EN MODO AÑADIEMDO
		do{
			try{
  
			

    		if(archivo.fail()){
        		cout<<"No se pudo abrir el archivo";
        		//exit(1);
    		}

				archivo<<"nodo"<<ap1<<"[label=\""<<actual->dato<<"\"];"<<endl;
			    archivo<<"nodo"<<ap1<<"->nodo"<<ap2<<";"<<endl;
				ap1++; ap2++;
			}catch(std::exception& e){
				cout<<"Nodos Agragados";
			}
			
    		
			actual = actual->siguiente;
		}while(actual!=primeroCir);
		
		archivo<<"nodo"<<ap1<<"->nodo"<<0<<";"<<endl;
    	archivo<<"}";
		archivo.close(); //cerramos el archivo
		
	}else{
		cout << "\n La listas se encuentra Vacia\n\n";
	}
	
	graficarLista("listaCircular");
}

//***
//****************************************
//LISTA DOBLE ENLAZADA
//****************************************************************************************************************************
void insertarNodo(){
	//int g=1;
	nodo* nuevo = new nodo();
	gotoxy2(g,0);
    nuevo->dato=caracter=getche();

	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		primero->atras = NULL;
		ultimo = primero;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		nuevo->atras = ultimo;
		ultimo = nuevo;
	}
	
}

void desplegarListaPU(){
	
	nodo* actual = new nodo();
	actual = primero;
	if(primero!=NULL){
		
		while(actual!=NULL){
			lis++;
			gotoxy2(0+lis,1); //donde colocar el caracter
			cout <<actual->dato;
			actual = actual->siguiente;
		}

	}else{
		//cout << "\n La listas se encuentra Vacia\n\n";
	}
	lis=0;
}



void modificarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	nodo* actual2 = new nodo(); //nodo para buscar
	nodo* anterior = new nodo();  //para eliminar elnodo
	anterior = NULL;
	nodo* base = new nodo();
	
	bool encontrado = false;
	string nodoBuscado="";
	char nodoReemplazar[15];
	string SnbAux = "";
	
	cout << "\n Buscar: ";
	cin >> nodoBuscado;
	cout<<"\n Reemplazar: "; 
	cin>> nodoReemplazar;	
	
	if(primero!=NULL){
		
		while(actual!=NULL && encontrado!=true){
			
			actual2 = actual; //funciona como nodo auxiliar
			base = actual;
			int k=0;
			for(int i =0; i<nodoBuscado.length();i++){
				
				SnbAux+=actual2->dato; //asignar el valor del dato actual2
				
				if(SnbAux==nodoBuscado){ //comparacion de cadenas
					cout << "\n 1. Palabra Afectada ^v^";
					actual=actual2;
					for(int j=k;j>=0;j--){
							actual->dato=nodoReemplazar[j];
				
						
						actual=actual->atras;
					}	
				    
					encontrado = true;
					
				}
					k++;
					actual2=actual2->siguiente;
					
				}
				SnbAux="";
				anterior = base;
				actual = base->siguiente;
				
				if(actual->siguiente==NULL){
					//cout<<"perro";
					encontrado = true;
					
				}
				
			}
			//cout<<"\nEste es para mi el dia mas triste";
			if(!encontrado){
				cout << "\n Nodo no Encontrado\n\n";
		}
			}
			else{
				cout << "\n La listas se encuentra Vacia\n\n";
	}

}

void vaciarLista(){
	system("cls");
	nodo* actual = new nodo();
	actual = primero;
	//nodo* anterior = new nodo();
	//anterior = NULL;

	if(primero!=NULL){
		//cout<<primero->dato;
		while(actual!=NULL){
			
				if(actual==primero){
					//cout<<"\n"<<actual->dato;
					primero = primero->siguiente;
					primero->atras = NULL;
				}/*else if(actual==ultimo){
					cout<<"\n"<<actual->dato;
					anterior->siguiente = NULL;
					ultimo = anterior;
				}else{
					cout<<"\n"<<actual->dato;
					anterior->siguiente = actual->siguiente;
					actual->siguiente->atras = anterior;
				}*/
		
			//anterior = actual;
			primero=NULL;
			actual = actual->siguiente;
			//cout<<"Puto";
		}
			
	}else{
		//cout << "\n La listas se encuentra Vacia\n\n";
	}
}

//**************************************************************************************************************************
//LISTA CIRCULAR SIMPLE
//******************************************************************
void insertarNodoCircular(string datos){
	nodoCir* nuevo = new nodoCir();
	
	nuevo->dato=datos;

	if(primeroCir==NULL){
		primeroCir = nuevo;
		primeroCir->siguiente = primeroCir;
		ultimoCir = primeroCir;
	}else{
		ultimoCir->siguiente = nuevo;
		nuevo->siguiente = primeroCir;
		ultimoCir = nuevo;
	}
}


void desplegarListaCircular(){
	int numero=1;
	nodoCir* actual = new nodoCir();
	actual = primeroCir;
	if(primeroCir!=NULL){
		do{
			cout << "\n "<<numero<<". " << actual->dato<<endl;
			Archivos[fila] = actual->dato;
			fila++;
			actual = actual->siguiente;
			numero++;
		}while(actual!=primeroCir);
	}else{
		cout << "\n La lista se encuentra vacia\n\n";
	}
}
//*********************************************
//PILA
void push(){
	nodoPila* nuevo = new nodoPila();
	cout << " Ingrese el dato que contendra el nuevo Nodo: ";
	cin >> nuevo->dato;
	nuevo->siguiente = primeroPila;
	primeroPila = nuevo;
	cout << endl << " Nodo Ingresado " << endl << endl;
}
void pop(){
	nodoPila* actual = new nodoPila();
	actual = primeroPila;

	if(primeroPila!=NULL){
		
		while(actual!=NULL){
			
				
				if(actual == primeroPila){
					primeroPila = primeroPila->siguiente;
				}
			
			actual = actual->siguiente;
		}
		
	}	
}

void verPila(){
	nodoPila* actual = new nodoPila();
	actual = primeroPila;
	if(primeroPila!=NULL){
		while(actual!=NULL){
			cout << endl << " " << actual->dato; 
			actual = actual->siguiente;
		}
	}else{
		cout << endl << " La Pila se encuentra vacia" << endl << endl;
	}
}

//*************************************************************************************************************************************************************

