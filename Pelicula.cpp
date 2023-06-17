#include "Pelicula.h"
#include <vector>
#include <algorithm>

using namespace std;

Pelicula::Pelicula(vector<string> vec) : Video(vec[0], vec[1], vec[2], vec[3], vec[4], vec[5])
{
}

void Pelicula::mostrarDatos()
{
    cout << "---------------------------------------------------------------" << endl;
    cout << "Nombre de la pelicula: " << Video::getNombreVideo() << "\n"
         << "Genero: " << Video::getGenero() << "\n"
         << "Calificacion: " << Video::getCalificacion() << "\n"
         << "Duracion: " << Video::getDuracion() << "\n"
         << "Fecha de estreno: " << Video::getFecha() << endl;
    cout << endl;
}

void Pelicula::mostrarPorCalificacion(double calif)
{
    if (Video::getCalificacion() >= calif)
    {
        
        mostrarDatos();
     
    }
}

void Pelicula::mostrarPorGenero(string gene)
{
    vector<string> vec = Video::getMultiGenero();

    if (find(vec.begin(), vec.end(), gene) != vec.end())
    {
        mostrarDatos();
    }
}

void Pelicula::calificar(double calif, string nom)
{
    if (Video::getNombreVideo() == nom)
    {

        Video::setCalificacion(calif);
        cout << "---Guardado---" << endl;
    }
}
