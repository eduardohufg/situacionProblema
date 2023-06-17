/*
Autor: Eduardo Chavez Martin
Declaramos la clase hija Pelicula(metodos y atributos)
*/
#ifndef PELICULA_H
#define PELICULA_H

#include <iostream>
#include "Video.h"
#include <vector>
#include "Funciones.h"

using namespace std;

class Pelicula: public Video, public Funciones
{
    public:
    Pelicula(vector<string> vec);

    void mostrarDatos();
    void mostrarPorCalificacion(double calif);
    void mostrarPorGenero(string gene);
    void calificar(double calif,string nom);
  
};


#endif