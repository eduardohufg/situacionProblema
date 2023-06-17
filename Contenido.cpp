#include "Contenido.h"
#include "Episodio.h"
#include "Pelicula.h"
#include "Video.h"

Contenido::Contenido(vector<Video *> vec)
{
    this->vec = vec;
}

void Contenido::contenidoPorCalificacion(double calif)
{
    for (int i = 0; i < vec.size(); i++)
    {
        Episodio *apuntS = dynamic_cast<Episodio *>(vec[i]);
        Pelicula *apuntP = dynamic_cast<Pelicula *>(vec[i]);
        if (apuntS != 0)
        {
            apuntS->mostrarPorCalificacion(calif);
        }
        else
        {
            apuntP->mostrarPorCalificacion(calif);
        }
    }
}

void Contenido::contenidoPorGenero(string genero)
{
    for (int i = 0; i < vec.size(); i++)
    {
        Episodio *apuntS = dynamic_cast<Episodio *>(vec[i]);
        Pelicula *apuntP = dynamic_cast<Pelicula *>(vec[i]);
        if (apuntS != 0)
        {
            apuntS->mostrarPorGenero(genero);
        }
        else
        {
            apuntP->mostrarPorGenero(genero);
        }
    }
}

void Contenido::mostrarEpisodiosSerie(string serie)
{
    for (int i = 0; i < vec.size(); i++)
    {
        Episodio *apuntS = dynamic_cast<Episodio *>(vec[i]);
        if (apuntS != 0)
        {
            if (apuntS->getNombreVideo() == serie)
            {
                apuntS->mostrarDatos();
            }
        }
    }
}

void Contenido::peliculaPorCalificacion(double calif)
{
    for (int i = 0; i < vec.size(); i++)
    {
        Pelicula *apuntP = dynamic_cast<Pelicula *>(vec[i]);
        if (apuntP != 0)
        {
            apuntP->mostrarPorCalificacion(calif);
        }
    }
}

void Contenido::calificarContenido(int calif, string conte)
{
    for (int i = 0; i < vec.size(); i++)
    {
        Pelicula *apuntP = dynamic_cast<Pelicula *>(vec[i]);
        Episodio *apuntE = dynamic_cast<Episodio *>(vec[i]);
        if (apuntE != 0)
        {
            apuntE->calificar(calif, conte);
        }
        else
        {
            apuntP->calificar(calif, conte);
        }
    }
}

void Contenido::calcularPromedioSerie(string serie)
{
    int contasize = 0;
    double contacalificacion=0;
    for (int i = 0; i < vec.size(); i++)
    {

        Episodio *apuntE = dynamic_cast<Episodio *>(vec[i]);
        if (apuntE != 0)
        {
            if (apuntE->getNombreVideo() == serie)
            {
                contacalificacion = contacalificacion + apuntE->getCalificacion();
                contasize++;
            }
        }
    }
    cout<<"El promedio de calificacion de "<<serie<<" es: "<<(contacalificacion/contasize)<<endl;
}

void Contenido::cambiarArchivo(vector<Video *> vec)
{
    this -> vec = vec;
}
