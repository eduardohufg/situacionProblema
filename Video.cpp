#include "Video.h"
#include <vector>

Video::Video()
{
    ID = "TT0000000";
    nombre = "Sin nombre";
    genero = "Sin genero";
    calificacion = "0";
    duracion ="0";
    fecha = "01/01/0000";
}

Video::Video(vector<string> vec)
{
    ID = vec[0];
    nombre = vec[1];
    genero = vec[2];
    calificacion = vec[3];
    duracion =vec[4];
    fecha = vec[5];
    
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
