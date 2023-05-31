/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   medico.cpp
 * Author: gkerath
 * 
 * Created on May 31, 2023, 11:51 AM
 */

#include "medico.h"

medico::medico() {
}

medico::medico(const medico& orig) {
}

medico::~medico() {
}

void medico::SetTarifa(double tarifa) {
    this->tarifa = tarifa;
}

double medico::GetTarifa() const {
    return tarifa;
}

void medico::SetNombre(char* nombre) {
    this->nombre = nombre;
}

char* medico::GetNombre() const {
    return nombre;
}

void medico::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int medico::GetCodigo() const {
    return codigo;
}

