/*
Autor: Eduardo Chavez Martin
Declaramos la clase hija Pelicula(metodos y atributos)
*/
#ifndef SERIE_H
#define SERIE_H

#include <iostream>
#include "Video.h"
#include <vector>
#include "Episodio.h"

using namespace std;

class Serie{
    private:
        vector<Video*> vec;

        int duracion;
        string nombreSerie;





    public:
        Serie(vector<Video*> vec);
        
        void mostrarEpisodios();














};



#endif