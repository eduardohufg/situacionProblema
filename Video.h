/*
Autor: Eduardo Chavez Martin
Declaramos la clase base Video(metodos y atributos)
*/
// si no esta definida la clase, definela
#ifndef VIDEO_H
#define VIDEO_H

// librerias
#include <iostream>
#include <vector>

// namespace
using namespace std;

// clase base Video
class Video
{

private:
    // atributos generales de un video
    string ID;
    string nombre;
    string genero;
    string calificacion;
    string duracion;
    string fecha;

public:
    //Constructor por default
    Video();
    //constructor que recibe un vector tipo string
    Video(vector<string> vec);
    //constructor que recibe parametro por parametro
    Video(string ID, string nombre, string duracion, string genero, string calificacion, string fecha);
    //metodo abstracto mostrar datos que se redefinira en las clases hijas
    virtual void mostrarDatos() = 0;
    //getters
    string getId();
    string getNombreVideo();
    string getGenero();
    double getCalificacion();
    int getDuracion();
    string getFecha();
    //setter
    void setCalificacion(double calificacion);
    //metodo que genera un vector con todos los generos de un video
    vector<string> getMultiGenero();
};
#endif