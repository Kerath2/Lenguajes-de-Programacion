#include <iostream>
#include <iomanip>

using namespace std;

void separaCadenas(char *cadena,char * cad1,char *cad2);
int main(){
  char cadena[100] ="GERARDO_MIGUEL_TACAY_TERRAZOS_INGINFORMATICA";
  char cadena1[100], cadena2[100];
  separaCadenas(cadena,cadena1,cadena2);
  cout << cadena1 << " " << cadena2 << endl;
  
  return 0;
}

void separaCadenas(char *cadena,char * cad1,char *cad2){
  int longitudTotal;
  for (int i = 0 ; cadena[i] != '\0'; i++){
    longitudTotal = i;
  }
  longitudTotal++;
  
  int posGuion;

  for (int i = longitudTotal; i > 0 ; i--){
    if(cadena[i] == '_'){
      posGuion = i;
      break;
    }
  }
  
  for (int i = 0 ; i < posGuion; i++){
    cad1[i] = cadena[i];
  }
  cad1[posGuion] = 0;
  
  int posFinal;
  for (int i = posGuion + 1 , j=0 ; i < longitudTotal ; i++ ,j++){
    cad2[j] = cadena[i]; 
    posFinal  = j;
  }
  cad2[posFinal+1] = 0;
}
