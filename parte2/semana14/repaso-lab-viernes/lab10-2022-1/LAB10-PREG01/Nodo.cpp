/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Nodo.cpp
 * Author: gkerath
 * 
 * Created on June 27, 2023, 11:52 PM
 */

#include "Nodo.h"
#include <iostream>
Nodo::Nodo() {
    ped = nullptr;
    sig = nullptr;
    ant = nullptr;
}

Nodo::Nodo(const Nodo& orig) {
}

Nodo::~Nodo() {
}

