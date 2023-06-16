#include "Video.h"
#include <vector>
#include <fstream>
#include <sstream> // para string-stream
#include <iostream>
Video::Video()
{
    ID = "TT0000000";
    nombre = "Sin nombre";
    genero = "Sin genero";
    calificacion = "0";
    duracion ="0";
    fecha = "01/01/0000";
    numElementos;
}
//ID,Nombre Pelicula/Serie,Duración,Género,Calificación,Fecha Estreno,ID Episodio,Nombre Episodio,Temporada,Num Episodio
Video::Video(vector<string> vec)
{
    ID = vec[0];
    nombre = vec[1];
    duracion =vec[2];
    genero = vec[3];
    calificacion = vec[4];
    fecha = vec[5];
    numElementos = vec.size();
    
}



Video::Video(string ID, string nombre, string duracion, string genero, string calificacion, string fecha)
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

double Video::getCalificacion()
{
    double calif = stod(calificacion);
    return calif;
}


void Video::setCalificacion(int calificacion)
{
    string calif = to_string(calificacion);

    this -> calificacion = calif;
}

int Video::getDuracion()
{
    return stoi(duracion);
}

string Video::getFecha()
{
    return fecha;
}

void Video::setDuracion(int duracion)
{
    this -> duracion = to_string(duracion);
}

vector<string> Video::getMultiGenero()
{
    string gene;
    vector<string> vec;
    string cadena = genero; // La cadena que vamos a separar
    stringstream inputt(cadena);                    // Convertir la cadena a un stream
    while (getline(inputt, gene, '&'))
    {
        vec.push_back(gene);
    }
    return vec;

}

int Video::getNumElementos()
{
    return numElementos;
}
