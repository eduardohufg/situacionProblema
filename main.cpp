/*
Autor: Eduardo Chavez Martin
Leer el archivo de texto en c++
*/

#include <iostream>
#include <fstream>
#include <sstream> // para string-stream
#include <vector>
#include "Video.h"
#include "Pelicula.h"
#include "Episodio.h"
#include "Contenido.h"
#include <algorithm>
#include <string>
#include <stdlib.h>

using namespace std;

vector<Video *> videos;
vector<Video *> videos2;

vector<string> separar(string linea);

int main(int argc, char const *argv[])
{


    try{
    ifstream entrada;


    entrada.open("DatosPeliculas.csv");
    
    string linea;
    int numeroDeLinea = 1;
    int contaPelis = 0;
    int contaEpis = 0;

    while (getline(entrada, linea))
    {

        vector<string> datos = separar(linea);

        if (datos.size() == 6)
        {

            Pelicula *pelis = new Pelicula(datos);
            videos.push_back(pelis);
        }
        else
        {

            Episodio *epis = new Episodio(datos);
            videos.push_back(epis);
        }
    }
    if(videos.empty())
        throw "NO SE ENCONTRO EL ARCHIVO, EL PROGRAMA FINALIZARA";
    
    
    videos.erase(videos.begin());
            
    entrada.close();
    }
    catch(const char *error){
        cout<<endl<<error<<endl;
        system("pause");
        return -1;
    }
    Contenido contenido(videos); 
    char caso;
    
    while (true)
    {
        system("cls");
        cout << "--------------------------------------------------------------" << endl;
        cout << "                     Servicio streaming" << endl;
        cout << "--------------------------------------------------------------" << endl
             << endl;
        cout << "Ingresa la opcion deseada" << endl;

        cout << endl
             << "1. Cargar archivo de datos" << endl;
        cout << "2. Buscar contenido por calificacion o genero" << endl;
        cout << "3. Mostrar episodios de una serie" << endl;
        cout << "4. Buscar peliculas por calificacion" << endl;
        cout << "5. Calificar contenido" << endl;
        cout << "6. Mostrar promedio de calificacion de una serie" << endl;
        cout << "7. Salir" << endl<<endl;
        cout<< "**Nota: El programa ya tiene un archivo cargado por default**"<<endl;
        cout << "--------------------------------------------------------------" << endl;
        cout << "Entrada: ";
        cin >> caso;
        
        string genero;
        string inputserie;
        string archivo;
        ifstream entradaArch;
        string lineaArch;
        int lin = 0;
        char entrada;
        try{
        switch (caso)
        {
        case '1':

            system("cls");
            cout << "--------------------------------------------------------------" << endl;
            cout << "                       Cargar archivo" << endl<<endl;
            cout << "Asegurate que el archivo que quieres cargar este en formato .csv" << endl;
            cout << "Asegurese que el archivo este en la misma carpeta que este programa" << endl;
            cout << "En caso de que no se encuentre en la misma carpeta, especifica la ruta" << endl<< endl;

            cout << "Escriba el nombre del archivo: ";

            cin >> archivo;
            
            try{
            entradaArch.open(archivo);

            while (getline(entradaArch, lineaArch))
            {

                vector<string> datos = separar(lineaArch);

                if (datos.size() == 6)
                {

                    Pelicula *pelis = new Pelicula(datos);
                    videos2.push_back(pelis);
                }
                else
                {
                    Episodio *epis = new Episodio(datos);
                    videos2.push_back(epis);
                }
            }
            
            if(videos2.empty())
                throw "ERROR, ARCHIVO NO ENCONTRADO, SE MANTIENE EL ARCHIVO ANTERIOR";
            videos2.erase(videos2.begin());
            entradaArch.close();
            }
            catch(const char *error){
                cout<<endl<<error<<endl;
                system("pause");
                break;
            }
            contenido.cambiarArchivo(videos2);
            cout << "Lito!!" << endl;
            system("pause");
            break;

        case '2':

            system("cls");
            cout << "--------------------------------------------------------------" << endl;
            cout << "Seleccione la opcion deseada" << endl<< endl;
            cout << "1. Mostrar contenido con calificacion mayor o igual a la ingresada" << endl;
            cout << "2. Mostrar contenido por genero" << endl;
            cout << "3. Regresar al menu principal" << endl;
            cout << "--------------------------------------------------------------" << endl;
            cout << "Ingresa el numero de la opcion que deseas: ";

            cin >> entrada;
            cout << endl;
            double opcion;

            if (entrada == '1')
            {
                cout << "Calificacion deseada: ";
                cin >> opcion;
                system("cls");
                cout << "Lista de contenido que coinciden con la referencia: " << endl
                     << endl;
                contenido.contenidoPorCalificacion(opcion);
            }
            else if (entrada == '2')
            {
                cout << "Teclee el genero deseado(Iniciando con mayuscula): ";
                cin >> genero;
                system("cls");
                cout << "Lista de contenido que coinciden con la referencia: " << endl
                     << endl;
                contenido.contenidoPorGenero(genero);
            }
            else
            {
                break;
            }

            system("pause");

            break;

        case '3':
            system("cls");
            cout << "--------------------------------------------------------------" << endl;
            cout << "        Buscador de series" << endl<< endl;
            cout << "Escriba el nombre de la serie deseada: ";
            getline(cin, inputserie);
            system("cls");
            cout << "--------------------------------------------------------------" << endl;
            cout << "Lista de contenido que coinciden con la referencia: " << endl<< endl;
            contenido.mostrarEpisodiosSerie(inputserie);
            system("pause");
            break;

        case '4':
            system("cls");
            cout << "--------------------------------------------------------------" << endl;
            cout << "        Mostrar peliculas por calificacion" <<endl<<endl;
            cout << "Ingresa la calificacion deseada: ";
            int entrada2;
            cin >> entrada2;
            system("cls");
            cout << "--------------------------------------------------------------" << endl;
            cout << "Lista de contenido que coinciden con la referencia: " << endl<< endl;
            contenido.peliculaPorCalificacion(entrada2);
            system("pause");
            break;

        case '5':
            system("cls");
            cout << "--------------------------------------------------------------" << endl;
            cout << "                 Calificar video" << endl<<endl;
            cout << "Ingresa el nombre de la pelicula o capitulo que deseas calificar: ";
            getline(cin, inputserie);
            cout << "Ingresa la calificacion";
            cin >> entrada2;
            system("cls");
            contenido.calificarContenido(entrada2, inputserie);
            system("pause");
            break;

        case '6':
            system("cls");
            cout << "---------------------------------------------------------------" << endl;
            cout << "          Ver promedio de duracion de serie" << endl<< endl;
            cout << "Ingresa el nombre de la serie del que deseas saber el promedio: ";
            getline(cin, inputserie);
            system("cls");
            cout << "---------------------------------------------------------------" << endl<<endl;
            contenido.calcularPromedioSerie(inputserie);
            system("pause");
            break;
        case '7':
            return 0;

        default:
            break;
        }
        }
        catch(std::string &error){
            cout<<endl<<"ERROR, OPCION NO VALIDA"<<endl;
            system("pause");
            break;

        }

    }

    

    return 0;
}



//-------------------------Funciones---------------------------------------
vector<string> separar(string linea)
{
    vector<string> tokens;       // componentes de la linea
    stringstream entrada(linea); // flujo de datos a partir de una cadena
    string dato;                 // token individual
    int numeroTokens = 0;
    while (getline(entrada, dato, ','))
    {
        if (dato != "")
        {
            tokens.push_back(dato);
            numeroTokens++;
        }
    }
    return tokens;
}