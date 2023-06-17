/*
Autor: Eduardo Chavez Martin A01799595
Descripcion: Interfaz con las funciones que hara cada clase
*/

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>

using namespace std;


class Funciones{
    public:
        virtual void mostrarPorCalificacion(double calif)=0;
        virtual void mostrarPorGenero(string gene)=0;
        virtual void calificar(double calif, string nom)=0;
};

#endif