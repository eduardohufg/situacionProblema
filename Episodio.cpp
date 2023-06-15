#include "Episodio.h"
#include <vector>

//ID,Nombre Pelicula/Serie,Duración,Género,Calificación,Fecha Estreno,ID Episodio,Nombre Episodio,Temporada,Num Episodio
Episodio::Episodio(vector<string> vec) : Video(vec[0],vec[1],vec[2],vec[3],vec[4],vec[5])
{
    IDEpisodio = vec[6];
    nombreEpisodio =vec[7];
    temporadaEpisodio = vec[8];
    numeroEpisodio = vec[9];
    numElementosEpisodio = vec.size();

}

string Episodio::getIDEpisodio()
{
    return IDEpisodio;
}

string Episodio::getNombreEpisodio()
{
    return nombreEpisodio;
}

string Episodio::getTemporadaEpisodio()
{
    return temporadaEpisodio;
}

string Episodio::getNumeroEpisodio()
{
    return numeroEpisodio;
}

void Episodio::mostrarDatos()
{
    cout<<"Nombre de la serie: "<<Video::getNombreVideo()<<"\n"
    <<"Nombre del episodio: "<<nombreEpisodio<<"\n"
    <<"Temporada: "<<temporadaEpisodio<<"\n"
    <<"Numero de Episodio "<<numeroEpisodio<<"\n"
    <<"Genero: "<<Video::getGenero()<<"\n"
    <<"Calificacion: "<<Video::getCalificacion()<<"\n"
    <<"Fecha de estreno: "<<Video::getFecha()<<endl;
}

int Episodio::getNumElementos()
{
    return numElementosEpisodio;
}
