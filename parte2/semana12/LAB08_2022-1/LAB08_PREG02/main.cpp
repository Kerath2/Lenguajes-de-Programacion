/*
 *  */

#include "Tienda.h"
#include <cstdlib>
using namespace std;

/*
 *
 */
int main(int argc, char **argv) {
  Tienda tien;
  tien.carga();
  tien.actualiza(20);
  tien.muestra();
  return 0;
}
