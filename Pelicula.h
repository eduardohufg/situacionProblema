/*
Autor: Eduardo Chavez Martin
Declaramos la clase hija Pelicula(metodos y atributos)
*/
//si no esta definida la clase, definela
#ifndef PELICULA_H
#define PELICULA_H

//librerias
#include <iostream>
#include "Video.h"
#include <vector>
#include "Funciones.h"

//namespace 
using namespace std;

//clase Pelicula que hereda de Video(clase base) y Funciones(Interfaz)
class Pelicula: public Video, public Funciones
{
    public:
    //constructor que recibe un vector de tipo string
    Pelicula(vector<string> vec);

    //Metodos sobre escritos de la interfaz y clase base
    void mostrarDatos();
    void mostrarPorCalificacion(double calif);
    void mostrarPorGenero(string gene);
    void calificar(double calif,string nom);
  
};


#endif