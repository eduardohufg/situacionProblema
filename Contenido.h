/*
Autor: Eduardo Chavez Martin
Declaramos la clase hija Episodio(metodos y atributos)
*/
#ifndef CONTENIDO_H
#define CONTENIDO_H

#include <iostream>
#include "Video.h"
#include <vector>

using namespace std;

class Contenido{
    private:
        vector<Video*> vec;

    public:
        Contenido(vector<Video*> vec);

        void contenidoPorCalificacion(double calif);
        void contenidoPorGenero(string genero);
        void mostrarEpisodiosSerie(string serie);
        void peliculaPorCalificacion(double calif);
        void calificarContenido(int calif, string conte);
        void calcularPromedioSerie(string serie);
        void cambiarArchivo(vector<Video*> vec);




};



#endif