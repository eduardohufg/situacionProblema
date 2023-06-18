//librerias necesarias
#include "Contenido.h"
#include "Episodio.h"
#include "Pelicula.h"
#include "Video.h"

//constructor que asigna al atributo el vector ingresado como parametro
Contenido::Contenido(vector<Video *> vec)
{
    this->vec = vec;
}

//Metodo que muestra el contenido en general(peliculas y episodios)
//depende de la calificacion deseada
void Contenido::contenidoPorCalificacion(double calif)
{
    for (int i = 0; i < vec.size(); i++)
    {
        Episodio *apuntS = dynamic_cast<Episodio *>(vec[i]); //downcasting de Video a Episodio
        Pelicula *apuntP = dynamic_cast<Pelicula *>(vec[i]); //downcasting de Video a Pelicula
        if (apuntS != 0) //si existe Episodio, entonces
        {
            apuntS->mostrarPorCalificacion(calif); //muestra los episodios por calificacion
        }
        else //si no, es una Pelicula
        {
            apuntP->mostrarPorCalificacion(calif); //muestra las peliculas por calificacion
        }
    }
}

//metodo que muestra contenido en general (episodios y peliculas) depende el genero
void Contenido::contenidoPorGenero(string genero)
{
    for (int i = 0; i < vec.size(); i++)
    {
        Episodio *apuntS = dynamic_cast<Episodio *>(vec[i]); //downcasting de Video a Episodio
        Pelicula *apuntP = dynamic_cast<Pelicula *>(vec[i]); //downcasting de Video a Pelicula
        if (apuntS != 0) //si existe Episodio, entonces
        {
            apuntS->mostrarPorGenero(genero); //muestra los episodios por genero
        }
        else //si no, es una Pelicula
        {
            apuntP->mostrarPorGenero(genero); //muestra las peliculas por genero
        }
    }
}

//Metodo que muestra todos los episodios de una serie
void Contenido::mostrarEpisodiosSerie(string serie)
{
    for (int i = 0; i < vec.size(); i++)
    {
        Episodio *apuntS = dynamic_cast<Episodio *>(vec[i]); //downcasting de Video a Episodio
        if (apuntS != 0) //si existe Episodio, entonces
        {
            if (apuntS->getNombreVideo() == serie) //valida que el capitulo sea de la serie ingresada
            {
                apuntS->mostrarDatos(); //muestra los datos
            }
        }
    }
}

//metodo que solo muestra las peliculas depende su calificacion
void Contenido::peliculaPorCalificacion(double calif)
{
    for (int i = 0; i < vec.size(); i++)
    {
        Pelicula *apuntP = dynamic_cast<Pelicula *>(vec[i]);//downcasting de Video a Pelicula
        if (apuntP != 0) //si existe Pelicula, entonces
        {
            apuntP->mostrarPorCalificacion(calif); //muestra datos depende la calificacion
        }
    }
}

//metodo para calificar contenido en general
void Contenido::calificarContenido(int calif, string conte)
{
    for (int i = 0; i < vec.size(); i++)
    {
        Pelicula *apuntP = dynamic_cast<Pelicula *>(vec[i]); //downcasting de Video a Pelicula
        Episodio *apuntE = dynamic_cast<Episodio *>(vec[i]); //downcasting de Video a Episodio
        if (apuntE != 0) //si existe Episodio, entonces
        {
            apuntE->calificar(calif, conte); //califica el video
        }
        else //si no, es una Pelicula
        {
            apuntP->calificar(calif, conte); //califica el video
        }
    }
}

//metodo que calcula el promedio de calificacion de una serie
void Contenido::calcularPromedioSerie(string serie)
{
    int contasize = 0; //contador para saber cuantos capitulos son
    double contacalificacion=0; //contador para guardar la calificacion
    for (int i = 0; i < vec.size(); i++)
    {

        Episodio *apuntE = dynamic_cast<Episodio *>(vec[i]); //downcasting de Video a Episodio
        if (apuntE != 0) //si existe Episodio, entonces
        {
            if (apuntE->getNombreVideo() == serie) //valida que el nombre de la serie sea igual al del video
            {
                contacalificacion = contacalificacion + apuntE->getCalificacion(); //acumula la calificacion
                contasize++; //aumenta contador
            }
        }
    }
    //calcula el promedio y lo muestra
    cout<<"El promedio de calificacion de "<<serie<<" es: "<<(contacalificacion/contasize)<<endl;
}

//metodos para actualizar el contenido de videos
void Contenido::cambiarArchivo(vector<Video *> vec)
{
    this -> vec = vec; //asigna al atributo el vector ingresado
}
