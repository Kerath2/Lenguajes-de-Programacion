#ifndef FUNCIONES
#define FUNCIONES
#include <fstream>
using namespace std;

void CargaDeClientes (int *&cli_DNI,char **& cli_Nombre, char *&cli_Categoria); 
void leerCadena(ifstream& arch,char *&cad);
void ReporteDeClientes (int *cli_DNI, char ** cli_Nombre,char * cli_Categoria); 
void   CargaDePedidosYProductos(int *cli_DNI, int *&pro_Codigo, char **&pro_Descripcion,
double *& pro_Descuento,double *& pro_Precio, int **& cli_CodigoProFechaPedido, double **& cli_CantidadPedido);
int esta(int codigo,int * auxCod);
void ReporteDePedidosYProductos(int *cli_DNI, int *pro_Codigo, char ** pro_Descripcion,
  double * pro_Descuento, double * pro_Precio, int ** cli_CodigoProFechaPedido, double ** cli_CantidadPedido);
void cargaCodFechaCantidad(int * cli_DNI,int dni,int **buffCodFecha,double **buffCantidad,int numClientes,int *numPedC,int codigo,int fecha,double cantidad);
#endif // !FUNCIONES

