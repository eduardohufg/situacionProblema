//librerias necesarias
#include "Pelicula.h"
#include <vector>
#include <algorithm>

//namespace
using namespace std;

//constructor que recibe como parametro un vector, asigna el valor de cada vector a su atributo 
//correspondiente del constructor de la clase Video
Pelicula::Pelicula(vector<string> vec) : Video(vec[0], vec[1], vec[2], vec[3], vec[4], vec[5])
{
}

//Se redefine el metodo de mostrar datos. Muestra todos los datos necesarios 
//de la pelicula guardada
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

//redefinimos el metodo, si la calificacion de la pelicula es mayor o igual
//a la ingresada en el parametro; muestra los datos
void Pelicula::mostrarPorCalificacion(double calif)
{
    if (Video::getCalificacion() >= calif)
    {
        mostrarDatos();
    }
}

//redefinimos el metodo, guarda en un vector los generos por separado retornados
//por el metodo getMultiGenero de la clase Video, si el string ingredado existe
//en el vector, muestra los datos
void Pelicula::mostrarPorGenero(string gene)
{
    vector<string> vec = Video::getMultiGenero();

    if (find(vec.begin(), vec.end(), gene) != vec.end())//si existe el elemento en el vector, retorna un true
    {
        mostrarDatos();
    }
}

//se redefine el metodo para calificar, si el nombre de la pelicula es igual
//al string ingresado, llama a setCalificacion y le asigna el valor double
//ingresado en el parametro
void Pelicula::calificar(double calif, string nom)
{
    if (Video::getNombreVideo() == nom)
    {

        Video::setCalificacion(calif);
        cout << "---Guardado---" << endl;
    }
}
