/*
Autor: Eduardo Chavez Martin
Declaramos la clase hija Episodio(metodos y atributos)
*/
#ifndef EPISODIO_H
#define EPISODIO_H

#include <iostream>
#include "Video.h"

using namespace std;

class Episodio: public Video
{
    private:
        string IDEpisodio;
        string nombreEpisodio;
        int temporadaEpisodio;
        int numeroEpisodio;

    public:

        Episodio(string ID, string nombre, string genero, string calificacion, string duracion, string fecha, string IDEpisodio
        ,string nombreEpisodio,int temporadaEpisodio,int numeroEpisodio);
        string getIDEpisodio();
        string getNombreEpisodio();
        int getTemporadaEpisodio();
        int getNumeroEpisodio();
        void mostrarDatos();
};


#endif