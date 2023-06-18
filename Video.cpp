//librerias necesarias
#include "Video.h"
#include <vector>
#include <fstream>
#include <sstream> // para string-stream
#include <iostream>

//constructor por default
Video::Video()
{
    ID = "TT0000000";
    nombre = "Sin nombre";
    genero = "Sin genero";
    calificacion = "0";
    duracion ="0";
    fecha = "01/01/0000";

}
//constructor que recibe el vector
Video::Video(vector<string> vec)
{
    //para cada atributo le asignamos el elemento del vector correspondinte
    ID = vec[0];
    nombre = vec[1];
    duracion =vec[2];
    genero = vec[3];
    calificacion = vec[4];
    fecha = vec[5]; 
}
//constructor que recibe los parametros
Video::Video(string ID, string nombre, string duracion, string genero, string calificacion, string fecha)
{
    this -> ID = ID;
    this -> nombre = nombre;
    this -> genero = genero;
    this -> calificacion = calificacion;
    this -> duracion = duracion;
    this -> fecha = fecha;
}
//getter
string Video::getId()
{
    return ID;
}
//getter
string Video::getNombreVideo()
{
    return nombre;
}
//getter
string Video::getGenero()
{
    return genero;
}
//getter que retorna un double(transforma de string a double)
double Video::getCalificacion()
{
    return stod(calificacion);
}

//setter
void Video::setCalificacion(double calificacion)
{
    
    this -> calificacion = to_string(calificacion);
}

//getter(transforma de string a int)
int Video::getDuracion()
{
    return stoi(duracion);
}

//getter
string Video::getFecha()
{
    return fecha;
}

//metodo que nos separa los generos y retorna el vector
vector<string> Video::getMultiGenero()
{
    string gene; //variable donde almacenaremos el elemento separado
    vector<string> vec; //vector donde almacenaremos cada variable separada
    string cadena = genero; // La cadena que vamos a separar
    stringstream inputt(cadena); // Convertir la cadena a un stream
    while (getline(inputt, gene, '&')) //mientras haya elementos
    {
        vec.push_back(gene); //ingresa al vector cada elemento
    }
    return vec; //retorna el vector

}

