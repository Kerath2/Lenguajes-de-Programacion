#include <iostream>
#include <cstdlib>

using namespace std;

int comp(const void *a, const void *b){
  double *val1 = (double*)a;
  double *val2 = (double*)b;
  if(*val1>*val2) return 1;
  if(*val1<*val2) return -1;
  if(*val1==*val2) return 0;
  return 0;
}

int main(){
  int n = 5;
  double arreglo[5] = {2.3,4.5,3.6,3.6,12.4};
  qsort(arreglo, n, sizeof(double), comp);
  for (int i = 0 ; i < n ; i++){
    cout << arreglo[i] << " ";
  }
  cout << endl;

  return 0;
}
