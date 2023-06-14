#include "Pelicula.h"

Pelicula::Pelicula(string ID, string nombre, string genero, string calificacion, string duracion, string fecha): Video(ID, nombre, genero, calificacion, duracion, fecha)
{
}

void Pelicula::mostrarDatos()
{
    cout<<"Nombre de la pelicula: "<<Video::getNombreVideo()<<"\n"
    <<"Genero: "<<Video::getGenero()<<"\n"
    <<"Calificacion: "<<Video::getCalificacion()<<"\n"
    <<"Fecha de estreno: "<<Video::getFecha()<<endl;
}