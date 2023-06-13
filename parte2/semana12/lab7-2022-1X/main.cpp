/*
 Gerardo Miguel Tacay Terrazos
 * codigo : 20193503
 */

#include <iostream>
#include "medico.h"
#include "paciente.h"
#include "cita.h"
#include "funciones.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    medico arrMedicos[200];
    paciente arrPacientes[200];

    llenarMedicos(arrMedicos);
    llenaPacientes(arrPacientes);
    llenaCitasPacientes(arrPacientes,arrMedicos);
    actualizarTarifas(arrPacientes);
    imprimePacientes(arrPacientes);
    return 0;
}

