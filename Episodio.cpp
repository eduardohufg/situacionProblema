//librerias necesarias
#include "Episodio.h"
#include <vector>
#include <algorithm>

//Constructor que recibe un vector, va separando cada elemento del vector y lo asigna 
//al constructor de Video e inicializa los atributos propios
Episodio::Episodio(vector<string> vec) : Video(vec[0],vec[1],vec[2],vec[3],vec[4],vec[5])
{
    //asigna a cada atributo el elemento del vector que le corresponde
    IDEpisodio = vec[6];
    nombreEpisodio =vec[7];
    temporadaEpisodio = vec[8];
    numeroEpisodio = vec[9];
    
}

//getter
string Episodio::getIDEpisodio()
{
    return IDEpisodio;
}
//getter
string Episodio::getNombreEpisodio()
{
    return nombreEpisodio;
}
//getter(transforma de string a int)
int Episodio::getTemporadaEpisodio()
{
    return stoi(temporadaEpisodio);
}
//getter(transforma de string a int)
int Episodio::getNumeroEpisodio()
{
    return stoi(numeroEpisodio);
}

//Se redefine el metodo de mostrar datos. Muestra todos los datos necesarios 
//del capitulo guardado
void Episodio::mostrarDatos()
{
    cout << "---------------------------------------------------------------" << endl;
    cout<<"Nombre de la serie: "<<Video::getNombreVideo()<<"\n"
    <<"Nombre del episodio: "<<nombreEpisodio<<"\n"
    <<"Temporada: "<<temporadaEpisodio<<"\n"
    <<"Numero de Episodio: "<<numeroEpisodio<<"\n"
    <<"Duracion: "<<Video::getDuracion()<<"\n"
    <<"Genero: "<<Video::getGenero()<<"\n"
    <<"Calificacion: "<<Video::getCalificacion()<<"\n"
    <<"Fecha de estreno: "<<Video::getFecha()<<endl;
    cout<<endl;
}

//redefinimos el metodo, si la calificacion del capitulo es mayor o igual
//a la ingresada en el parametro, muestra los datos
void Episodio::mostrarPorCalificacion(double calif)
{
    if (Video::getCalificacion() >= calif)
    { 
        mostrarDatos();
    }
}

//redefinimos el metodo, guarda en un vector los generos por separado generados
//por el metodo getMultiGenero de la clase Video, si el string ingredado existe
//en el vector, muestra los datos
void Episodio::mostrarPorGenero(string gene)
{
    vector<string> vec = Video::getMultiGenero();

    if (find(vec.begin(), vec.end(), gene) != vec.end()) //si existe el elemento en el vector, retorna un true
    {
        mostrarDatos();
    }
}

//se redefine el metodo para calificar, si el nombre del capitulo es igual
//al string ingresado, llama a setCalificacion y le asigna el valor double
//ingresado en el parametro
void Episodio::calificar(double calif, string nom)
{
    if (nombreEpisodio == nom)
    {
        Video::setCalificacion(calif);
        cout << "---Guardado---" << endl;
    }
}
