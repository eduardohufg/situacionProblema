/*
Autor: Eduardo Chavez Martin
Declaramos la clase base Video(metodos y atributos)
*/
#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>

using namespace std;

class Video{

    private:
        string ID;
        string nombre;
        string genero;
        int calificacion;
        int duracion;
        string fecha;

    public:

        void mostrarDatos();
        string getId();
        string getNombrePelicula();
        string getGenero();
        int getCalificacion();
        void setCalificacion();
        int getDuracion();
        






};





#endif