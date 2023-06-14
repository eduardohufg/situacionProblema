#include "Video.h"

Video::Video(): Video("tt0000000","Sin nombre", "Sin genero", 0,0,"01/01/0000")
{
}

Video::Video(string ID, string nombre, string genero, string calificacion, string duracion, string fecha)
{
    this -> ID = ID;
    this -> nombre = nombre;
    this -> genero = genero;
    this -> calificacion = calificacion;
    this -> duracion = duracion;
    this -> fecha = fecha;
}

string Video::getId()
{
    return ID;
}

string Video::getNombreVideo()
{
    return nombre;
}

string Video::getGenero()
{
    return genero;
}

string Video::getCalificacion()
{
    return calificacion;
}

void Video::setCalificacion(string calificacion)
{
    this -> calificacion = calificacion;
}

string Video::getDuracion()
{
    return duracion;
}

string Video::getFecha()
{
    return fecha;
}
