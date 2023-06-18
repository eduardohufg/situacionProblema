/*
Autor: Eduardo Chavez Martin
Declaramos la clase hija Episodio(metodos y atributos)
*/
//si no esta definida la clase, definela
#ifndef EPISODIO_H
#define EPISODIO_H

//librerias
#include <iostream>
#include "Video.h"
#include <vector>
#include "Funciones.h"

//namespace
using namespace std;

//clase Episodio que hereda de Video(clase base) y Funciones(Interfaz)
class Episodio: public Video, public Funciones
{
    //atributos propios de la clase Episodio
    private:
        string IDEpisodio;
        string nombreEpisodio;
        string temporadaEpisodio;
        string numeroEpisodio;

    public:
        //constructor de la clase que recibe un vector tipo string
        Episodio(vector<string> vec);
        //getters de la clase
        string getIDEpisodio();
        string getNombreEpisodio();
        int getTemporadaEpisodio();
        int getNumeroEpisodio();
        //se sobre escriben los metodos heredados de la clase base e interfaz
        void mostrarDatos();
        void mostrarPorCalificacion(double calif);
        void mostrarPorGenero(string gene);
        void calificar(double calif,string nom);
        
};


#endif