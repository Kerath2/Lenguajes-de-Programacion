#include <iostream>
using namespace std;
int suma(int a ,int b){
  return a + b;
}
int resta(int a ,int b){
  return a - b;
}
int division(int a ,int b){
  return a / b;
}
int multiplicacion(int a ,int b){
  return a * b;
}

int main(){
  int (*operacion)(int , int);
  operacion= resta;
  int a = 10, b = 5;
  cout << operacion(a,b) << endl;
}
