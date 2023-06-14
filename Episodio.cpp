#include "Episodio.h"

Episodio::Episodio(string ID, string nombre, string genero, string calificacion, string duracion, string fecha,
 string IDEpisodio, string nombreEpisodio, int temporadaEpisodio, int numeroEpisodio) : Video(ID, nombre, genero, calificacion, duracion, fecha)
{
    this -> IDEpisodio = IDEpisodio;
    this -> nombreEpisodio = nombreEpisodio;
    this -> temporadaEpisodio = temporadaEpisodio;
    this -> numeroEpisodio = numeroEpisodio;

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
    return temporadaEpisodio;
}

int Episodio::getNumeroEpisodio()
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
