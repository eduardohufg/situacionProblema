/*
Autor: Eduardo Chavez Martin
Declaramos la clase Contenido (metodos y atributos)
Esta clase contendra los metodos que mostraran o haran lo que necesita el programa
*/

//si no esta definida la clase, definela
#ifndef CONTENIDO_H
#define CONTENIDO_H

//librerias necesarias
#include <iostream>
#include "Video.h"
#include <vector>

using namespace std;

class Contenido{
    //Tiene como atributo un vector tipo video donde estaran todos
    //los videos en general (peliculas y capitulos)
    private:
        vector<Video*> vec;

    public:
        //cosntructor que recibe al vector tipo video
        Contenido(vector<Video*> vec);

        //metodos que haran todas las funciones necesarias para 
        //usar en el main
        void contenidoPorCalificacion(double calif);
        void contenidoPorGenero(string genero);
        void mostrarEpisodiosSerie(string serie);
        void peliculaPorCalificacion(double calif);
        void calificarContenido(int calif, string conte);
        void calcularPromedioSerie(string serie);
        void cambiarArchivo(vector<Video*> vec);

};



#endif