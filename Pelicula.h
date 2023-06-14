/*
Autor: Eduardo Chavez Martin
Declaramos la clase hija Pelicula(metodos y atributos)
*/
#ifndef PELICULA_H
#define PELICULA_H

#include <iostream>
#include "Video.h"

using namespace std;

class Pelicula: public Video
{

    public:

    Pelicula(string ID, string nombre, string genero, string calificacion, string duracion, string fecha);
    void mostrarDatos();

};


#endif