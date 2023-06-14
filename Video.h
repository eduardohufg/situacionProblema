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
        string calificacion;
        string duracion;
        string fecha;

    public:

        Video();
        Video(string ID, string nombre, string genero, string calificacion, string duracion, string fecha);
        virtual void mostrarDatos() = 0;
        string getId();
        string getNombreVideo();
        string getGenero();
        string getCalificacion();
        void setCalificacion(string calificacion);
        string getDuracion();
        string getFecha();
        
};
#endif