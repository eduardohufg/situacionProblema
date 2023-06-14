#include "Pelicula.h"
#include <vector>

Pelicula::Pelicula(vector<string> vec): Video(vec[0],vec[1],vec[2],vec[3],vec[4],vec[5])
{
}

void Pelicula::mostrarDatos()
{
    cout<<"Nombre de la pelicula: "<<Video::getNombreVideo()<<"\n"
    <<"Genero: "<<Video::getGenero()<<"\n"
    <<"Calificacion: "<<Video::getCalificacion()<<"\n"
    <<"Fecha de estreno: "<<Video::getFecha()<<endl;
}