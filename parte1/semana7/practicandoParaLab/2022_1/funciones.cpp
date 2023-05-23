#include <cstring>
#include <iostream>
#include <iomanip>
#include "funciones.h"
#include <fstream>
#include <cstring>
using namespace std;

void CargaDeClientes (int *&cli_DNI,char **& cli_Nombre, char *&cli_Categoria){
  ifstream arch("./Clientes.csv",ios::in);
  if(!arch){
    cout << "Error en la apertura del archivo clientes.csv" << endl;
    exit(1);
  }
  

  int buffDNI[200];
  char *auxNombre[200];
  char auxCat[200];
  int telefono;
  char * cad  ,car ;
  
  int cont = 0;
  while(1){
    arch >> buffDNI[cont];
    if(arch.eof()) break;
    arch >> car;
    leerCadena(arch,cad);
    int tam = strlen(cad);
    if(cad[tam-2] ==' '){
      auxCat[cont] = cad[tam-1];
      cad[tam-2] = 0;
    }else{
      auxCat[cont] = '-';
    }
    auxNombre[cont] = cad;
    arch >> telefono;
    cont ++;
  }

  cli_DNI = new int[cont];
  cli_Categoria = new char[cont];
  cli_Nombre = new char*[cont];
  
  for (int i = 0 ; i < cont ; i++){
    cli_DNI[i] =  buffDNI[i]; 
    cli_Categoria[i] = auxCat[i];
    cli_Nombre[i] = auxNombre[i];
  }

  cli_DNI[cont] = -1;
  

} 
void leerCadena(ifstream& arch,char *&cad){
  char buff[200];
  arch.getline(buff,200,',');
  cad = new char[strlen(buff)+1];
  strcpy(cad,buff);
}


void ReporteDeClientes (int *cli_DNI, char ** cli_Nombre,char * cli_Categoria){
  int i = 0;
  while(cli_DNI[i]!=-1){
    cout << cli_DNI[i] << setw(40) << cli_Nombre[i] << setw(12) << cli_Categoria[i] << endl;
    i++;
  }
}
void   CargaDePedidosYProductos(int *cli_DNI, int *&pro_Codigo, char **&pro_Descripcion,
  double *& pro_Descuento,double *& pro_Precio, int **& cli_CodigoProFechaPedido, double **& cli_CantidadPedido){
  ifstream arch("./Pedidos.csv",ios::in);
  if(!arch){
    cout << "Error en la apertura del archivo Pedidos.csv" << endl;
    exit(1);
  }
  int codigo, dni, dd , mm , aa;
  char *cad, car ;
  double descuento,precio, cantidad;
  
  int cont = 0, contS=0;  
  int auxCod[200] ;
  char *auxDescipcion[200];
  double auxDesc[200], auxPrecio[200];
  

  int numClientes = 0;
  for (int i = 0 ; cli_DNI[i] != -1 ; i++)
    numClientes++;
  
  int numPedC[numClientes];
  for (int i = 0 ; i < numClientes ; i++)
    numPedC[i] = 0;

  int *buffCodFecha[numClientes]; 
  double *buffCantidad[numClientes];


  while(1){
    arch >> codigo;
    if(arch.eof())  break;
    arch >> car;
    leerCadena(arch,cad);
    arch >> cantidad;
    if (arch.fail()){
      arch.clear();
      arch >> car >> descuento >> car >> cantidad;
    }else{
      descuento = 0;
    }
    arch >> car >> precio >> car >> dni >> car >> dd >> car >> mm >> car >> aa;
    int fecha  = aa*10000 + mm*100 + dd;
    cargaCodFechaCantidad(cli_DNI,dni,buffCodFecha,buffCantidad,numClientes,numPedC,codigo,fecha,cantidad);
    if (!esta(codigo,auxCod)){
      auxCod[contS] =  codigo;
      auxDescipcion[contS] = cad;
      auxDesc[contS] = descuento;
      auxPrecio[contS] = precio;
      contS++;
    }
    cont ++;
  }

  // Le damos el tamano exacto 

  cli_CodigoProFechaPedido = new int*[numClientes];
  cli_CantidadPedido = new double*[numClientes];

  for (int i = 0 ; i < numClientes ;i++){
    cli_CodigoProFechaPedido[i] = new int[numPedC[i] +1 ]; // para el -1
    cli_CantidadPedido[i] = new double[numPedC[i] +1 ];

    //punteros para bajarle el nivel al buffer
    int *puntBuffCodFecha  = buffCodFecha[i];
    double *puntBuffCantidad = buffCantidad[i];
    //punteros para bajarle el nivel a nuestros arrelogs
    int *auxCodFecha ;
    auxCodFecha = cli_CodigoProFechaPedido[i];
    double *auxCant; 
    auxCant = cli_CantidadPedido[i];
    for (int j = 0 ; j < numPedC[i]*2; j++){
     auxCodFecha[j] = puntBuffCodFecha[j];
    }
    for (int j = 0 ; j < numPedC[i] ; j++){
      auxCant[j] = puntBuffCantidad[j];
    }
  }
  
  //agregamos el -1 afuera
  //por alguna razon extrana no funciona agregar el -1 afuera
  for (int i = 0; i < numClientes ;i++){

    int *auxCodfecha  = cli_CodigoProFechaPedido;
  }

  cout << "una chiqui: " << endl;
  cout << "lo que se tiene en la pos 12 es : " << cli_CodigoProFechaPedido[0][12] << endl;
  // cout << "La direccion de memoria que quiero modificar es :" << &cli_CodigoProFechaPedido[0][12] << endl;

  auxCod[contS] = -1;
  contS++;
  
  pro_Codigo = new int[contS];
  pro_Descripcion = new char*[contS];
  pro_Descuento = new double[contS];
  pro_Precio = new double[contS];

  for (int i = 0 ; i < contS ;i++){
    pro_Codigo[i] = auxCod[i];
    pro_Descripcion[i] = auxDescipcion[i];
    pro_Descuento[i] = auxDesc[i];
    pro_Precio[i] = auxPrecio[i];
  }
  

}

int esta(int codigo,int * auxCod){
  for (int i = 0 ; i < 200 ; i++){
    if (codigo == auxCod[i])
      return 1;
  }
  return 0;
}

void ReporteDePedidosYProductos(int *cli_DNI, int *pro_Codigo, char ** pro_Descripcion,
  double * pro_Descuento, double * pro_Precio, int ** cli_CodigoProFechaPedido, double ** cli_CantidadPedido){
  int i = 0;
  cout << "REPORTE DE PRODUCTOS" <<  endl;
  while(pro_Codigo[i]!=-1){
    cout << pro_Codigo[i] << setw(40) << pro_Descripcion[i] << setw(12) << pro_Descuento[i] << setw(12) << pro_Precio[i] << endl;
    i++;
  }
  
  cout << "REPORTE DE PEDIDOS" << endl;
  i = 0;
  while(i<20){
    cout << cli_CodigoProFechaPedido[0][i] << " " ;
    i++;
  }  

}
    
void cargaCodFechaCantidad(int * cli_DNI,int dni,int **buffCodFecha,double **buffCantidad,int numClientes,int *numPedC,int codigo,int fecha,double cantidad){
  int pos;
  for (int i = 0 ; cli_DNI[i]!=-1; i++){
    if (cli_DNI[i] == dni){
      pos = i;
    }
  }
  
  if (numPedC[pos] == 0){
    //Le creamos memoria
    buffCodFecha[pos] = new int[400];
    buffCantidad[pos] = new double[200];
  }

  //Llenamos donde corresponde, como no podemos usar matrices usamos un puntero auxiliar
  //SI que si
  int *auxCodFecha = buffCodFecha[pos];
  double *auxCantidad  = buffCantidad[pos];

  auxCodFecha[numPedC[pos]*2] = codigo;
  auxCodFecha[numPedC[pos]*2+1] = fecha;
  
  auxCantidad[numPedC[pos]] = cantidad;
  numPedC[pos]++;
}
