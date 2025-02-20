/**************************
Autores:
- Leonardo Velázquez Colín  
- Juan David Torres Chaparro  

Descripción:
El objetivo de este proyecto es desarrollar una aplicación en C++ que permita gestionar la nómina de los empleados de una empresa que requiere calcular los salarios de sus empleados en función de su nivel educativo, años de experiencia y número de certificaciones. Además, la aplicación debe permitir la gestión de empleados (agregar, actualizar, consultar) y generar reportes de nómina y tablas comparativas.

***************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct Empleado{
  string tipoDoc; 
  long int numDoc;
  string nombre;
  string apellido;
  string niveldeEdu;
  int experiencia;
  int numCert;
};


void clearCin();

Empleado *Adicionar(Empleado *empleados, int *tam);


Empleado *Ordenar_doc(Empleado *empleados, int *tam);
Empleado *Ordenar_nombre(Empleado *empleados, int *tam);
Empleado *Ordenar_experiencia(Empleado *empleados, int *tam);
Empleado *Ordenar_salario(Empleado *empleados, int *tam);

void Consultar_informacion(Empleado *empleados, int *tam);

void tablas(Empleado *empleados, int *tam);


Empleado *Actualizar(Empleado *empleados, int *tam);

float salario(Empleado empleado);

void ArchivoEmpleados(Empleado *empleados, int *tam);
void ArchivoReporte(Empleado *empleados, int *tam);


int main() {

  
  unsigned char opcion;
  int numero_empleados = 0;
  Empleado *arregloEmpleados;
  Empleado nuevo_empleado;

  
  
  do{ 
    opcion = '6';
    cout << "\n\t\t\tMenu";
    cout << "\n1) Adicionar un empleado";
    cout << "\n2) Actualizar información del empleado";
    cout << "\n3) Generar reportes de nómina";
    cout << "\n4) Consultar información de los empleados";
    cout << "\n5) Crear tablas comparativas";
    cout << "\n6) Salir";
    cout << "\n\n   Ingrese la opcion que desea: ";
    do{
      if (!isdigit(opcion) || opcion != '6'){
     cout<<"\n\nVALOR INCORRECTO, INGRESE UNA OPCIÓN VÁLIDA: ";
    }
    cin >> opcion;
      
    }while(!isdigit(opcion));
    system("clear");
   switch (opcion){
     case '1':
       arregloEmpleados = Adicionar(arregloEmpleados,&numero_empleados);
       ArchivoEmpleados(arregloEmpleados,&numero_empleados);
        
     break;
     case '2':
       arregloEmpleados = Actualizar(arregloEmpleados,&numero_empleados);
     break;
     case '3':
       ArchivoReporte(arregloEmpleados,&numero_empleados);
     break;
     case '4':
       Consultar_informacion(arregloEmpleados,&numero_empleados);
     break;
     case '5':
       tablas(arregloEmpleados,&numero_empleados);
     break;
     case '6':
       cout << "\nHasta Pronto\n";
       return 0;
     break;
     default:
       cout << "\nvalor ingresado incorrecto\n";
     break;
  } 
  } while (opcion != '6');
  
  
}//Fin del Main



Empleado Crear_empleado(){
  Empleado empleado;
  clearCin();
  cout << "\nIngrese el nombre del empleado: ";
  getline(cin,empleado.nombre);
  //clearCin();
  cout << "\nIngrese el apellido del empleado: ";
  getline(cin,empleado.apellido);
  cout << "\nIngrese el tipo de documento del empleado: ";
  cin>> empleado.tipoDoc;
  cout << "\nIngrese el numero de documento del empleado: ";
  cin>> empleado.numDoc;
  cout << "\nIngrese el nivel educativo del empleado: ";
  cin>> empleado.niveldeEdu;
  cout << "\nIngrese los años de experiencia del empleado: ";
  cin>> empleado.experiencia;
  cout << "\nIngrese el numero de certificados del empleado: ";
  cin>> empleado.numCert;
  
  return empleado;
  }
Empleado *Adicionar(Empleado *empleados, int *tam){
  Empleado empleado;
  Empleado *CopiaPtr = empleados;
  empleados = new Empleado[*tam+1];

  for(int i=0; i<*tam ; i++){
    (*(empleados +i)).tipoDoc = (*(CopiaPtr +i)).tipoDoc;
    (*(empleados +i)).numDoc = (*(CopiaPtr +i)).numDoc;
    (*(empleados +i)).nombre = (*(CopiaPtr +i)).nombre;
    (*(empleados +i)).apellido = (*(CopiaPtr +i)).apellido;
    (*(empleados +i)).niveldeEdu = (*(CopiaPtr +i)).niveldeEdu;
    (*(empleados +i)).experiencia = (*(CopiaPtr +i)).experiencia;
    (*(empleados +i)).numCert = (*(CopiaPtr +i)).numCert;
  }

  empleado = Crear_empleado();
  
  (*(empleados + *tam)).tipoDoc = empleado.tipoDoc;
  (*(empleados + *tam)).numDoc = empleado.numDoc;
  (*(empleados + *tam)).nombre = empleado.nombre;
  (*(empleados + *tam)).apellido = empleado.apellido;
  (*(empleados + *tam)).niveldeEdu = empleado.niveldeEdu;
  (*(empleados + *tam)).experiencia = empleado.experiencia;
  (*(empleados + *tam)).numCert = empleado.numCert;

  *tam += 1;
  
  //delete[] CopiaPtr;
  return empleados;
}

Empleado *Actualizar(Empleado *empleados, int *tam ){
  int numDoc;
  cout << "Ingrese el número de documento: ";
  cin >> numDoc;
  
  for(int i=0; i<*tam ; i++){
    if((*(empleados +i)).numDoc == numDoc){
      clearCin();
      cout << "\nIngrese el nuevo nombre del empleado: ";
      getline(cin,(*(empleados +i)).nombre);
      cout << "\nIngrese el nuevo apellido del empleado: ";
      getline(cin,(*(empleados +i)).apellido);
      cout << "\nIngrese el nuevo tipo de documento del empleado: ";
      cin>> (*(empleados +i)).tipoDoc;
      cout << "\nIngrese el nuevo numero de documento del empleado: ";
      cin>> (*(empleados +i)).numDoc;
      cout << "\nIngrese el nivel educativo del empleado: ";
      cin>> (*(empleados +i)).niveldeEdu;
      cout << "\nIngrese los años de experiencia del empleado: ";
      cin>> (*(empleados +i)).experiencia;
      cout << "\nIngrese el numero de certificados del empleado: ";
      cin>> (*(empleados +i)).numCert;
    }
  }
  return empleados;
}
Empleado *Ordenar_doc(Empleado *empleados, int *tam){
  Empleado aux;
  
  for(int i = 0; i < *tam; i++){
			for(int j=i+1; j < *tam; j++){
				if((*(empleados +i)).numDoc > (*(empleados +j)).numDoc){
          
					aux.numDoc = empleados[i].numDoc;
					empleados[i].numDoc = empleados[j].numDoc;
					empleados[j].numDoc = aux.numDoc;

          aux.nombre = empleados[i].nombre;
          empleados[i].nombre = empleados[j].nombre;
          empleados[j].nombre = aux.nombre;

          aux.apellido = empleados[i].apellido;
          empleados[i].apellido = empleados[j].apellido;
          empleados[j].apellido = aux.apellido;

          aux.tipoDoc = empleados[i].tipoDoc;
          empleados[i].tipoDoc = empleados[j].tipoDoc;
          empleados[j].tipoDoc = aux.tipoDoc;

          aux.niveldeEdu = empleados[i].niveldeEdu;
          empleados[i].niveldeEdu = empleados[j].niveldeEdu;
          empleados[j].niveldeEdu = aux.niveldeEdu;

          aux.experiencia = empleados[i].experiencia;
          empleados[i].experiencia = empleados[j].experiencia;
          empleados[j].experiencia = aux.experiencia;

          aux.numCert = empleados[i].numCert;
          empleados[i].numCert = empleados[j].numCert;
          empleados[j].numCert = aux.numCert;
				}
			}
    }

  return empleados;
}
Empleado *Ordenar_nombre(Empleado *empleados, int *tam){
  Empleado aux;
  
  for(int i = 0; i < *tam; i++){
			for(int j=i+1; j < *tam; j++){
				if((*(empleados +i)).nombre > (*(empleados +j)).nombre){
          
					aux.numDoc = empleados[i].numDoc;
					empleados[i].numDoc = empleados[j].numDoc;
					empleados[j].numDoc = aux.numDoc;

          aux.nombre = empleados[i].nombre;
          empleados[i].nombre = empleados[j].nombre;
          empleados[j].nombre = aux.nombre;

          aux.apellido = empleados[i].apellido;
          empleados[i].apellido = empleados[j].apellido;
          empleados[j].apellido = aux.apellido;

          aux.tipoDoc = empleados[i].tipoDoc;
          empleados[i].tipoDoc = empleados[j].tipoDoc;
          empleados[j].tipoDoc = aux.tipoDoc;

          aux.niveldeEdu = empleados[i].niveldeEdu;
          empleados[i].niveldeEdu = empleados[j].niveldeEdu;
          empleados[j].niveldeEdu = aux.niveldeEdu;

          aux.experiencia = empleados[i].experiencia;
          empleados[i].experiencia = empleados[j].experiencia;
          empleados[j].experiencia = aux.experiencia;

          aux.numCert = empleados[i].numCert;
          empleados[i].numCert = empleados[j].numCert;
          empleados[j].numCert = aux.numCert;
				}
			}
    }

  return empleados;
}
Empleado *Ordenar_experiencia(Empleado *empleados, int *tam){
  Empleado aux;
  
  for(int i = 0; i < *tam; i++){
			for(int j=i+1; j < *tam; j++){
				if((*(empleados +i)).experiencia > (*(empleados +j)).experiencia){
          
					aux.numDoc = empleados[i].numDoc;
					empleados[i].numDoc = empleados[j].numDoc;
					empleados[j].numDoc = aux.numDoc;

          aux.nombre = empleados[i].nombre;
          empleados[i].nombre = empleados[j].nombre;
          empleados[j].nombre = aux.nombre;

          aux.apellido = empleados[i].apellido;
          empleados[i].apellido = empleados[j].apellido;
          empleados[j].apellido = aux.apellido;

          aux.tipoDoc = empleados[i].tipoDoc;
          empleados[i].tipoDoc = empleados[j].tipoDoc;
          empleados[j].tipoDoc = aux.tipoDoc;

          aux.niveldeEdu = empleados[i].niveldeEdu;
          empleados[i].niveldeEdu = empleados[j].niveldeEdu;
          empleados[j].niveldeEdu = aux.niveldeEdu;

          aux.experiencia = empleados[i].experiencia;
          empleados[i].experiencia = empleados[j].experiencia;
          empleados[j].experiencia = aux.experiencia;

          aux.numCert = empleados[i].numCert;
          empleados[i].numCert = empleados[j].numCert;
          empleados[j].numCert = aux.numCert;
				}
			}
    }

  return empleados;
}
Empleado *Ordenar_salario(Empleado *empleados, int *tam){
  Empleado aux;
  
  for(int i = 0; i < *tam; i++){
			for(int j=i+1; j < *tam; j++){
				if(salario((*(empleados +i))) > salario((*(empleados +j)))){
          
					aux.numDoc = empleados[i].numDoc;
					empleados[i].numDoc = empleados[j].numDoc;
					empleados[j].numDoc = aux.numDoc;

          aux.nombre = empleados[i].nombre;
          empleados[i].nombre = empleados[j].nombre;
          empleados[j].nombre = aux.nombre;

          aux.apellido = empleados[i].apellido;
          empleados[i].apellido = empleados[j].apellido;
          empleados[j].apellido = aux.apellido;

          aux.tipoDoc = empleados[i].tipoDoc;
          empleados[i].tipoDoc = empleados[j].tipoDoc;
          empleados[j].tipoDoc = aux.tipoDoc;

          aux.niveldeEdu = empleados[i].niveldeEdu;
          empleados[i].niveldeEdu = empleados[j].niveldeEdu;
          empleados[j].niveldeEdu = aux.niveldeEdu;

          aux.experiencia = empleados[i].experiencia;
          empleados[i].experiencia = empleados[j].experiencia;
          empleados[j].experiencia = aux.experiencia;

          aux.numCert = empleados[i].numCert;
          empleados[i].numCert = empleados[j].numCert;
          empleados[j].numCert = aux.numCert;
				}
			}
    }

  return empleados;
}

void ArchivoEmpleados(Empleado *empleados, int *tam){
  ofstream archivo;
  empleados = Ordenar_doc(empleados,tam);
	archivo.open("empleados.txt",ios::out);
	if(archivo.fail()){
		cout <<"No se pudo abrir el archivo de empleados";
		exit(1);
	}	
	for(int i =0; i<*tam;i++){
    archivo<<(*(empleados +i)).tipoDoc<<" "<<(*(empleados +i)).numDoc<<" "<<(*(empleados +i)).nombre<<" "<<(*(empleados +i)).apellido<<" "<<(*(empleados +i)).niveldeEdu<<" "<<(*(empleados +i)).experiencia<<" "<<(*(empleados +i)).numCert<<endl;
  }
	archivo.close();
}

void ArchivoReporte(Empleado *empleados, int *tam){
   ofstream archivo;
   char opcion;
  empleados = Ordenar_doc(empleados,tam);
	archivo.open("reporte.txt",ios::out);
	if(archivo.fail()){
		cout <<"No se pudo abrir el archivo de empleados";
		exit(1);
	}	
archivo << left <<setw(5)<<"Tipo"<<setw(16)<<"# Documento"<<setw(20)<<"Nombre"<<setw(20)<<"Apellido"<<setw(20)<<"Nivel educativo"<<setw(15)<<"Experiencia"<<setw(15)<<"Certificados"<<setw(18)<<"Salario a pagar"<<setw(20)<<"Salario mínimo"<<setw(6)<<right<<"Moneda"<<endl;

  opcion = '4';
    cout << "\n¿Cómo desea organizar el reporte?"<<endl;
  cout << "1.Numero de documento"<<endl;
  cout << "2.Nombre"<<endl;
  cout << "3.Años de experiencia"<<endl;
  cout << "4.Salario mínimo"<<endl;
    do{
      if (!isdigit(opcion) || opcion != '4'){
     cout<<"\n\nVALOR INCORRECTO, INGRESE UNA OPCIÓN VÁLIDA: ";
    }
    cin >> opcion;
    }while(!isdigit(opcion));
    system("clear");
  cout << left <<setw(5)<<"Tipo"<<setw(16)<<"# Documento"<<setw(20)<<"Nombre"<<setw(20)<<"Apellido"<<setw(20)<<"Nivel educativo"<<setw(15)<<"Experiencia"<<setw(15)<<"Certificados"<<setw(18)<<"Salario a pagar"<<setw(20)<<"Salario mínimo"<<setw(6)<<right<<"Moneda"<<endl;
   switch (opcion){
     case '1':
        empleados = Ordenar_doc(empleados,tam);
       	for(int i =0; i<*tam;i++){
        float total = salario((*(empleados +i)));
        string dinero;
        if ((*(empleados+i)).tipoDoc == "CC"){dinero = "COP";}
        else{dinero="USD";}
          if ((*(empleados +i)).tipoDoc == "CE"){total=total/4467;}
        archivo<< left <<setw(5)<<(*(empleados +i)).tipoDoc<<setw(16)<<(*(empleados+i)).numDoc<<setw(20)<<(*(empleados+i)).nombre<<setw(20)<<(*(empleados+i)).apellido<<setw(20)<<(*(empleados+i)).niveldeEdu<<setw(15)<<(*(empleados+i)).experiencia<<setw(15)<<(*(empleados+i)).numCert<<setw(18)<<total<<setw(20)<<(total/1000000)<<setw(6)<<right<<dinero<<endl;
            cout<< left <<setw(5)<<(*(empleados +i)).tipoDoc<<setw(16)<<(*(empleados+i)).numDoc<<setw(20)<<(*(empleados+i)).nombre<<setw(20)<<(*(empleados+i)).apellido<<setw(20)<<(*(empleados+i)).niveldeEdu<<setw(15)<<(*(empleados+i)).experiencia<<setw(15)<<(*(empleados+i)).numCert<<setw(18)<<total<<setw(20)<<(total/1000000)<<setw(6)<<right<<dinero<<endl;
        }
     break;
     case '2':
        empleados = Ordenar_nombre(empleados,tam);
       	for(int i =0; i<*tam;i++){
        float total = salario((*(empleados +i)));
        string dinero;
        if ((*(empleados+i)).tipoDoc == "CC"){dinero = "COP";}
        else{dinero="USD";}
          if ((*(empleados +i)).tipoDoc == "CE"){total=total/4467;}
        archivo<< left <<setw(5)<<(*(empleados +i)).tipoDoc<<setw(16)<<(*(empleados+i)).numDoc<<setw(20)<<(*(empleados+i)).nombre<<setw(20)<<(*(empleados+i)).apellido<<setw(20)<<(*(empleados+i)).niveldeEdu<<setw(15)<<(*(empleados+i)).experiencia<<setw(15)<<(*(empleados+i)).numCert<<setw(18)<<total<<setw(20)<<(total/1000000)<<setw(6)<<right<<dinero<<endl;
            cout<< left <<setw(5)<<(*(empleados +i)).tipoDoc<<setw(16)<<(*(empleados+i)).numDoc<<setw(20)<<(*(empleados+i)).nombre<<setw(20)<<(*(empleados+i)).apellido<<setw(20)<<(*(empleados+i)).niveldeEdu<<setw(15)<<(*(empleados+i)).experiencia<<setw(15)<<(*(empleados+i)).numCert<<setw(18)<<total<<setw(20)<<(total/1000000)<<setw(6)<<right<<dinero<<endl;
        }
     break;
     case '3':
        empleados = Ordenar_experiencia(empleados,tam);
       	for(int i =0; i<*tam;i++){
        float total = salario((*(empleados +i)));
        string dinero;
        if ((*(empleados+i)).tipoDoc == "CC"){dinero = "COP";}
        else{dinero="USD";}
          if ((*(empleados +i)).tipoDoc == "CE"){total=total/4467;}
        archivo<< left <<setw(5)<<(*(empleados +i)).tipoDoc<<setw(16)<<(*(empleados+i)).numDoc<<setw(20)<<(*(empleados+i)).nombre<<setw(20)<<(*(empleados+i)).apellido<<setw(20)<<(*(empleados+i)).niveldeEdu<<setw(15)<<(*(empleados+i)).experiencia<<setw(15)<<(*(empleados+i)).numCert<<setw(18)<<total<<setw(20)<<(total/1000000)<<setw(6)<<right<<dinero<<endl;
                  cout<< left <<setw(5)<<(*(empleados +i)).tipoDoc<<setw(16)<<(*(empleados+i)).numDoc<<setw(20)<<(*(empleados+i)).nombre<<setw(20)<<(*(empleados+i)).apellido<<setw(20)<<(*(empleados+i)).niveldeEdu<<setw(15)<<(*(empleados+i)).experiencia<<setw(15)<<(*(empleados+i)).numCert<<setw(18)<<total<<setw(20)<<(total/1000000)<<setw(6)<<right<<dinero<<endl;
        }
     break;
     case '4':
        empleados = Ordenar_salario(empleados,tam);
       	for(int i =0; i<*tam;i++){
        float total = salario((*(empleados +i)));
        string dinero;
        if ((*(empleados+i)).tipoDoc == "CC"){dinero = "COP";}
        else{dinero="USD";}
          if ((*(empleados +i)).tipoDoc == "CE"){total=total/4467;}
        archivo<< left <<setw(5)<<(*(empleados +i)).tipoDoc<<setw(16)<<(*(empleados+i)).numDoc<<setw(20)<<(*(empleados+i)).nombre<<setw(20)<<(*(empleados+i)).apellido<<setw(20)<<(*(empleados+i)).niveldeEdu<<setw(15)<<(*(empleados+i)).experiencia<<setw(15)<<(*(empleados+i)).numCert<<setw(18)<<total<<setw(20)<<(total/1000000)<<setw(6)<<right<<dinero<<endl;
                  cout<< left <<setw(5)<<(*(empleados +i)).tipoDoc<<setw(16)<<(*(empleados+i)).numDoc<<setw(20)<<(*(empleados+i)).nombre<<setw(20)<<(*(empleados+i)).apellido<<setw(20)<<(*(empleados+i)).niveldeEdu<<setw(15)<<(*(empleados+i)).experiencia<<setw(15)<<(*(empleados+i)).numCert<<setw(18)<<total<<setw(20)<<(total/1000000)<<setw(6)<<right<<dinero<<endl;
        }
     break;
     default:
     break;
   }
  archivo.close();
}
  

void Consultar_informacion(Empleado *empleados, int *tam){
  int opcion, a_experiencia,numCertificaciones;
  string nombre, apellido,nivelE;
  
  cout << "\nCómo desea cosultar la informacion? "<<endl;
  cout << "1.Nombre"<<endl;
  cout << "2.Apellido"<<endl;
  cout << "3.Nivel educativo"<<endl;
  cout << "4.Años de experiencia"<<endl;
  cout << "5.Numero de certificaciones"<<endl;
  cout << "Ingrese: ";
  cin>>opcion;
  
  switch(opcion){
    case 1: 
      cout << "\nIngrese el nombre por el cual desea buscar: ";
      cin>>nombre;
      cout << left <<setw(5)<<"Tipo"<<setw(16)<<"# Documento"<<setw(20)<<"Nombre"<<setw(20)<<"Apellido"<<setw(20)<<"Nivel educativo"<<setw(15)<<"Experiencia"<<setw(15)<<"Certificados"<<endl;
      for(int i =0; i<*tam;i++){
        if((*(empleados +i)).nombre == nombre){
            cout << left <<setw(5)<<(*(empleados +i)).tipoDoc<<setw(16)<<(*(empleados +i)).numDoc<<setw(20)<<(*(empleados +i)).nombre<<setw(20)<<(*(empleados +i)).apellido<<setw(20)<<(*(empleados +i)).niveldeEdu<<setw(15)<<(*(empleados +i)).experiencia<<setw(15)<<(*(empleados +i)).numCert<<endl;
        }
      }
    break;
    case 2:
      cout << "\nIngrese el apellido por el cual desea buscar: ";
      cin>>apellido;
      cout << left <<setw(5)<<"Tipo"<<setw(16)<<"# Documento"<<setw(20)<<"Nombre"<<setw(20)<<"Apellido"<<setw(20)<<"Nivel educativo"<<setw(15)<<"Experiencia"<<setw(15)<<"Certificados"<<endl;
      for(int i =0; i<*tam;i++){
        if((*(empleados +i)).apellido == apellido){
            cout << left <<setw(5)<<(*(empleados +i)).tipoDoc<<setw(16)<<(*(empleados +i)).numDoc<<setw(20)<<(*(empleados +i)).nombre<<setw(20)<<(*(empleados +i)).apellido<<setw(20)<<(*(empleados +i)).niveldeEdu<<setw(15)<<(*(empleados +i)).experiencia<<setw(15)<<(*(empleados +i)).numCert<<endl;
        }
      }
    break;
    case 3:
      cout << "\nIngrese el nivel educativo por el cual desea buscar: ";
      cin>>nivelE;
      cout << left <<setw(5)<<"Tipo"<<setw(16)<<"# Documento"<<setw(20)<<"Nombre"<<setw(20)<<"Apellido"<<setw(20)<<"Nivel educativo"<<setw(15)<<"Experiencia"<<setw(15)<<"Certificados"<<endl;
      for(int i =0; i<*tam;i++){
        if((*(empleados +i)).niveldeEdu == nivelE){
            cout << left <<setw(5)<<(*(empleados +i)).tipoDoc<<setw(16)<<(*(empleados +i)).numDoc<<setw(20)<<(*(empleados +i)).nombre<<setw(20)<<(*(empleados +i)).apellido<<setw(20)<<(*(empleados +i)).niveldeEdu<<setw(15)<<(*(empleados +i)).experiencia<<setw(15)<<(*(empleados +i)).numCert<<endl;
        }
      }
    break;
    case 4:
      cout << "\nIngrese la cantidad de anhos de experiencia por el cual desea buscar: ";
      cin>>a_experiencia;
      cout << left <<setw(5)<<"Tipo"<<setw(16)<<"# Documento"<<setw(20)<<"Nombre"<<setw(20)<<"Apellido"<<setw(20)<<"Nivel educativo"<<setw(15)<<"Experiencia"<<setw(15)<<"Certificados"<<endl;
      for(int i =0; i<*tam;i++){
        if((*(empleados +i)).experiencia == a_experiencia){
            cout << left <<setw(5)<<(*(empleados +i)).tipoDoc<<setw(16)<<(*(empleados +i)).numDoc<<setw(20)<<(*(empleados +i)).nombre<<setw(20)<<(*(empleados +i)).apellido<<setw(20)<<(*(empleados +i)).niveldeEdu<<setw(15)<<(*(empleados +i)).experiencia<<setw(15)<<(*(empleados +i)).numCert<<endl;
        }
      }
    break;
    case 5:
      cout << "\nIngrese el numero de certificaciones por el cual desea buscar: ";
      cin>>numCertificaciones;
      cout << left <<setw(5)<<"Tipo"<<setw(16)<<"# Documento"<<setw(20)<<"Nombre"<<setw(20)<<"Apellido"<<setw(20)<<"Nivel educativo"<<setw(15)<<"Experiencia"<<setw(15)<<"Certificados"<<endl;
      for(int i =0; i<*tam;i++){
        if((*(empleados +i)).numCert == numCertificaciones){
            cout << left <<setw(5)<<(*(empleados +i)).tipoDoc<<setw(16)<<(*(empleados +i)).numDoc<<setw(20)<<(*(empleados +i)).nombre<<setw(20)<<(*(empleados +i)).apellido<<setw(20)<<(*(empleados +i)).niveldeEdu<<setw(15)<<(*(empleados +i)).experiencia<<setw(15)<<(*(empleados +i)).numCert<<endl;
        }
      }
    break;
    default:
      cout << "\nIngreso incorrectamente"<<endl;
    break;
    
  }
}

void tablas (Empleado *empleados, int *tam){
  int tabla1[3][4] = {0};

  for (int i=0; i<*tam;i++){
    //fila 1
    if(((*(empleados +i)).niveldeEdu == "EB")&&((*(empleados +i)).experiencia == 0)){
      tabla1[1][0] += 1;
    }
    if(((*(empleados +i)).niveldeEdu == "EB")&&((*(empleados +i)).experiencia >= 1 && (*(empleados +i)).experiencia <= 3)){
      tabla1[0][1] += 1;
    }
    if(((*(empleados +i)).niveldeEdu == "EB")&&((*(empleados +i)).experiencia >= 4 && (*(empleados +i)).experiencia <= 7)){
      tabla1[0][2] += 1;
    }
    if(((*(empleados +i)).niveldeEdu == "EB ")&&((*(empleados +i)).experiencia >= 8)){
      tabla1[0][3] += 1;
    }
//Fila 2
    if(((*(empleados +i)).niveldeEdu == "EM")&&((*(empleados +i)).experiencia == 0)){
      tabla1[1][0] += 1;
    }
    if(((*(empleados +i)).niveldeEdu == "EM")&&((*(empleados +i)).experiencia >= 1 && (*(empleados +i)).experiencia <= 3)){
      tabla1[1][1] += 1;
    }
    if(((*(empleados +i)).niveldeEdu == "EM")&&((*(empleados +i)).experiencia >= 4 && (*(empleados +i)).experiencia <= 7)){
      tabla1[1][2] += 1;
    }
    if(((*(empleados +i)).niveldeEdu == "EM")&&((*(empleados +i)).experiencia >= 8)){
      tabla1[1][3] += 1;
    }

    //Fila 3
    if(((*(empleados +i)).niveldeEdu == "ES")&&((*(empleados +i)).experiencia == 0)){
      tabla1[2][0] += 1;
    }
    if(((*(empleados +i)).niveldeEdu == "ES")&&((*(empleados +i)).experiencia >= 1 && (*(empleados +i)).experiencia <= 3)){
      tabla1[2][1] += 1;
    }
    if(((*(empleados +i)).niveldeEdu == "ES")&&((*(empleados +i)).experiencia >= 4 && (*(empleados +i)).experiencia <= 7)){
      tabla1[2][2] += 1;
    }
    if(((*(empleados +i)).niveldeEdu == "ES")&&((*(empleados +i)).experiencia >= 8)){
      tabla1[2][3] += 1;
    }
  }

      cout << "\n Tabla de comparativa de empleados entre nivel educativo y años de experiencia"<<endl;

  cout<<"    0   "<<left<<setw(5)<<"1-3"<<setw(5)<<"4-7"<<right<<setw(5) <<"8"<<endl;
  cout<<left;
  for (int i=0; i<3;i++){
    if(i == 0){
      cout<<"EB ";
    }
    if(i == 1){
      cout<<"EM ";
    }
    if(i == 2){
      cout<<"ES ";
    }
    for (int j=0; j<4;j++){
      cout<<setw(5)<<tabla1[i][j];
    }
    cout<<endl;
  }
  
}

float salario(Empleado empleado){
  float salario_minimo = 1000000, salario_total;

  if(empleado.niveldeEdu == "EB"){
    salario_total = salario_minimo;
  }
  if(empleado.niveldeEdu == "EM"){
    salario_total = salario_minimo*1.5;
  }
  if(empleado.niveldeEdu == "ES"){
    salario_total = salario_minimo*2.5;
  }

  if(empleado.experiencia >= 1 && empleado.experiencia <= 3){
    salario_total += (salario_minimo*0.15);
  }
  if(empleado.experiencia >= 4 && empleado.experiencia <= 7){
    salario_total += (salario_minimo*0.25);
  }
  if(empleado.experiencia >= 8){
    salario_total += (salario_minimo*0.4);
  }

  if(empleado.numCert >= 1 && empleado.numCert <= 3){
    salario_total += (salario_minimo*0.15);
  }
  if(empleado.numCert >= 2 && empleado.numCert <= 4){
    salario_total += (salario_minimo*0.1);
  }
  if(empleado.numCert >= 5){
    salario_total += (salario_minimo*0.35);
  }
  
  return salario_total;
}

void clearCin(){
    std::cin.clear();
    std::cin.ignore( 1000, '\n' );
}