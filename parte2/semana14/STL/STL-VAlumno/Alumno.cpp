/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: cueva
 * 
 * Created on 10 de junio de 2023, 08:23 PM
 */
#include <iomanip>
#include <cstring>
#include <iomanip>
#include "Alumno.h"

using namespace std;

Alumno::Alumno() {
    codigo=0;
    nombre=nullptr;
    escala=0;
    total=0;
    creditos=0;
}

Alumno::Alumno(const Alumno& orig) {
    char cad[100];
    nombre=nullptr;
   // *this=orig; A los alumnos le dio flojera y no quieren sobrecargar
    codigo = orig.GetCodigo();
    escala = orig.GetEscala();
    creditos = orig.GetCreditos();
    orig.GetNombre(cad);
    this->SetNombre(cad);
}

Alumno::~Alumno() {
}

void Alumno::SetTotal(double total) {
    this->total = total;
}

double Alumno::GetTotal() const {
    return total;
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetNombre(char* cad) {
    if(nombre!=nullptr) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void Alumno::GetNombre(char* cad) const {
    strcpy(cad,nombre);
}


void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}
/*
S,202123703,GAMARRA/TABORI/PAUL-RONAL,5,20,30
P,202119153,MENDOZA/ARIAS/HENRY,4,19.5,10
P,202113758,SOMA/INGA/DIALY,1,21,10
 */
void Alumno::lee(ifstream &arch){
    char cad[100],c;
    int esc;
    double cred;
    
    
    arch >>c;
    if(arch.eof()) return;
    arch >> c >> codigo;
    arch.get();
    arch.getline(cad,100,',');
    this->SetNombre(cad);
    arch >> esc >> c >> cred;
    escala = esc;
    creditos = cred;
}

void Alumno::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double Alumno::GetCreditos() const {
    return creditos;
}

void Alumno::imprime(ofstream&arch) {
    char cad[100];

    this->GetNombre(cad);

    arch << setw(20) << this->GetCodigo() << setw(40) << cad
            << setw(10) << this->GetEscala() << setw(10) << this->GetCreditos() << endl;
    
    
}

bool Alumno::operator <(const Alumno& alu){
    return codigo > alu.GetCodigo();   
    
}
bool Alumno::operator >(const Alumno& alu){
    return codigo > alu.GetCodigo();   
    
}