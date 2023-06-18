/*
Autor: Eduardo Chavez Martin A01799595
Descripcion: Interfaz con las funciones que hara cada clase
*/

#ifndef FUNCIONES_H //si no esta definida la clase, definela
#define FUNCIONES_H

#include <iostream> //librerias

using namespace std; //declaracion del namespace


class Funciones{
    public:
        //metodos abstractos puros(interfaces para los metodos heredados)
        virtual void mostrarPorCalificacion(double calif)=0;
        virtual void mostrarPorGenero(string gene)=0;
        virtual void calificar(double calif, string nom)=0;
};

#endif