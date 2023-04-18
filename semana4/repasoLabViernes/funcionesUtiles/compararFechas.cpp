#include <iostream>
#include <iomanip>

using namespace std;

int  compruebaVencido(int dd,int mm,int aa,int ddV,int mmV,int aaV);
int main(){
  int dd,mm,aa,ddV, mmV, aaV;
  int vencido;
  cin >> dd >> mm >> aa;
  cin >> ddV >> mmV >> aaV;
  
  vencido = compruebaVencido(dd,mm,aa,ddV,mmV,aaV);

  if(vencido){
    cout << "VENCIDO" << endl;
  }else{
    cout << "VIGENTE" << endl;
  }
  return 0;
}


int  compruebaVencido(int dd,int mm,int aa,int ddV,int mmV,int aaV){
  int vencido = 0;
  if (aa > aaV){
    vencido = 1;
  }else if (aa == aaV && mm > mmV){
    vencido = 1;
  }else if (aa == aaV && mm == mmV && dd > ddV){
    vencido = 1;
  } 
  return vencido;
}
