#include <iostream>
#include <cstdlib>

using namespace std;

int comp(const void *a, const void *b){
  int *val1 = (int*)a;
  int *val2 = (int*)b;
  return (*val1)-(*val2);
}

int main(){
  int n = 5;
  int arreglo[5] = {12,3,14,15,9};
  qsort(arreglo, n, sizeof(int), comp);
  for (int i = 0 ; i < n ; i++){
    cout << arreglo[i] << " ";
  }
  cout << endl;

  return 0;
}
