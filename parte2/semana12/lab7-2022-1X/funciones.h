/*
 * Gerardo Miguel Tacay Terrazos
 * codigo: 20193503
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "medico.h"
#include "paciente.h"

void llenarMedicos(medico * arrMedicos);
void llenaPacientes(paciente *arrPacientes);
void llenaCitasPacientes(paciente * arrPacientes,medico *arrMedicos);
int devuelveIndicePaciente(int dni, paciente * arrPacientes);
void actualizarTarifas(paciente * arrPacientes);
void imprimePacientes(paciente *arrPacientes);
#endif /* FUNCIONES_H */

