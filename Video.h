/*
Autor: Eduardo Chavez Martin
Declaramos la clase base Video(metodos y atributos)
*/
#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <vector>

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
        //ID,Nombre Pelicula/Serie,Duración,Género,Calificación,Fecha Estreno,ID Episodio,Nombre Episodio,Temporada,Num Episodio
        Video();
        Video(vector<string> vec);
        Video(string ID,string nombre,string duracion,string genero,string calificacion,string fecha);

        virtual void mostrarDatos() = 0;
        string getId();
        string getNombreVideo();
        string getGenero();
        double getCalificacion();
        void setCalificacion(string calificacion);
        string getDuracion();
        string getFecha();
        vector<string> getMultiGenero();
        
};
#endif