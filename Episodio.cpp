#include "Episodio.h"
#include <vector>
#include <algorithm>

//ID,Nombre Pelicula/Serie,Duración,Género,Calificación,Fecha Estreno,ID Episodio,Nombre Episodio,Temporada,Num Episodio
Episodio::Episodio(vector<string> vec) : Video(vec[0],vec[1],vec[2],vec[3],vec[4],vec[5])
{
    IDEpisodio = vec[6];
    nombreEpisodio =vec[7];
    temporadaEpisodio = vec[8];
    numeroEpisodio = vec[9];
    
}

string Episodio::getIDEpisodio()
{
    return IDEpisodio;
}

string Episodio::getNombreEpisodio()
{
    return nombreEpisodio;
}

int Episodio::getTemporadaEpisodio()
{
    return stoi(temporadaEpisodio);
}

int Episodio::getNumeroEpisodio()
{
    return stoi(numeroEpisodio);
}

void Episodio::mostrarDatos()
{
    cout << "---------------------------------------------------------------" << endl;
    cout<<"Nombre de la serie: "<<Video::getNombreVideo()<<"\n"
    <<"Nombre del episodio: "<<nombreEpisodio<<"\n"
    <<"Temporada: "<<temporadaEpisodio<<"\n"
    <<"Numero de Episodio "<<numeroEpisodio<<"\n"
    <<"Duracion: "<<Video::getDuracion()<<"\n"
    <<"Genero: "<<Video::getGenero()<<"\n"
    <<"Calificacion: "<<Video::getCalificacion()<<"\n"
    <<"Fecha de estreno: "<<Video::getFecha()<<endl;
    cout<<endl;
}

void Episodio::mostrarPorCalificacion(double calif)
{
    if (Video::getCalificacion() >= calif)
    {
        
        mostrarDatos();
        
    }
}

void Episodio::mostrarPorGenero(string gene)
{
    vector<string> vec = Video::getMultiGenero();

    if (find(vec.begin(), vec.end(), gene) != vec.end())
    {
        mostrarDatos();
    }
}

void Episodio::calificar(double calif, string nom)
{
    if (nombreEpisodio == nom)
    {
        Video::setCalificacion(calif);
        cout << "---Guardado---" << endl;
    }
}
