/*
Autor: Eduardo Chavez Martin
Declaramos la clase hija Episodio(metodos y atributos)
*/
#ifndef EPISODIO_H
#define EPISODIO_H

#include <iostream>
#include "Video.h"
#include <vector>

using namespace std;

class Episodio: public Video
{
    private:
        string IDEpisodio;
        string nombreEpisodio;
        string temporadaEpisodio;
        string numeroEpisodio;

    public:

        Episodio(vector<string> vec);
        string getIDEpisodio();
        string getNombreEpisodio();
        int getTemporadaEpisodio();
        int getNumeroEpisodio();
        void mostrarDatos();
        void mostrarPorCalificacion(double calif);
        void mostrarPorGenero(string gene);
        void calificar(double calif,string nom);
        
};


#endif