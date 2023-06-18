/*
Autor: Eduardo Chavez Martin A01799595
Main del programa donde se genera el menu y se implementan todas las funciones
*/

//librerias necesarias
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

using namespace std;

//vectores para guardar los videos en general obtenidos del csv
vector<Video *> videos;
vector<Video *> videos2;

//funcion para separar cada renglon del csv
vector<string> separar(string linea);

//main
int main(int argc, char const *argv[])
{
    try{ //try para validar el ingreso del csv
    ifstream entrada;


    entrada.open("DatosPeliculas.csv");

    string linea;
    //bucle que lee el archivo
    while (getline(entrada, linea))
    {

        vector<string> datos = separar(linea); //llama a funcion 

        if (datos.size() == 6)
        {

            Pelicula *pelis = new Pelicula(datos); //creamos objeto dinamico tipo pelicula
            videos.push_back(pelis); //guardamos en el vector tipo Video
        }
        else
        {
            Episodio *epis = new Episodio(datos); //creamos objeto dinamico tipo Episodio
            videos.push_back(epis); //guardamos en el vector tipo Video
        }
    }

    if(videos.empty()) //si el vector esta vacio, significa que no se leyo el csv, por lo tanto manda un error
        throw "NO SE ENCONTRO EL ARCHIVO, EL PROGRAMA FINALIZARA";

    videos.erase(videos.begin()); //eliminamos cabecera del archivo
    
    entrada.close(); //cerramos archivo
    }

    catch(const char *error){ //atrapa el error y acaba el programa
        cout<<endl<<error<<endl;
        system("pause");
        return -1;
    }

    Contenido contenido(videos); //creamos objeto tipo Contenido que almacenara todos los videos obtenidos

    char caso; //variable para el switch

    while (true)
    {
        //menu
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
        cin.ignore();
        //variables que se ocuparon en el codigo
        string genero;
        string inputserie;
        string archivo;
        ifstream entradaArch;
        string lineaArch;
        int lin = 0;
        char entrada;

        //casos
        switch (caso)
        {
        case '1':
            //el caso 1 se ingresa un nuevo archivo que actualiza los videos disponibles
            system("cls");
            cout << "--------------------------------------------------------------" << endl;
            cout << "                       Cargar archivo" << endl<<endl;
            cout << "Asegurate que el archivo que quieres cargar este en formato .csv" << endl;
            cout << "Asegurese que el archivo este en la misma carpeta que este programa" << endl;
            cout << "En caso de que no se encuentre en la misma carpeta, especifica la ruta" << endl<< endl;

            cout << "Escriba el nombre del archivo: ";

            cin >> archivo;
            
            try{ //try para validar el ingreso del csv
            
            //se hace el mismo proceso para leer el archivo
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
            if(videos2.empty()) //si el vector esta vacio, significa que no se leyo el csv, por lo tanto manda un error
                throw "ERROR, ARCHIVO NO ENCONTRADO, SE MANTIENE EL ARCHIVO ANTERIOR";

            videos2.erase(videos2.begin()); //elimina cabecera
            entradaArch.close(); //cierra el archivo
            }

            catch(const char *error){ //atrapa el error y se regresa al menu, se queda el archivo anterior
                cout<<endl<<error<<endl;
                system("pause");
                break;
            }
            contenido.cambiarArchivo(videos2); //se llama al metodo del objeto para cambiar el contenido
            cout << "Listo!!" << endl;
            system("pause");
            break;

        case '2':

            //caso 2 que muestra los videos en general depende de su calificacion o genero
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
            int opcion;

            //si es la opcion 1, muestra por calificacion
            if (entrada == '1')
            {
                cout<< "**Asegurese de solo ingresar numeros**"<<endl;
                cout << "Calificacion deseada: ";
                cin >> opcion;
                system("cls");
                cout << "Lista de contenido que coinciden con la referencia: " << endl
                     << endl;
                contenido.contenidoPorCalificacion(opcion); //se llama al metodo que muestra el contenido depende la calificacion
            }
            //si es la opcion 2, muestra contenido depende del genero
            else if (entrada == '2')
            {
                cout << "Teclee el genero deseado(Iniciando con mayuscula): ";
                cin >> genero;
                system("cls");
                cout << "Lista de contenido que coinciden con la referencia: " << endl<< endl;
                contenido.contenidoPorGenero(genero);//llama al metodo de la clase que muestra el contenido por genero
            }
            else
            {
                break; //regresa al menu
            }

            system("pause");

            break;

        case '3':
            //caso 3 que muestra todos los episodios de una serie determinada
            system("cls");
            cout << "--------------------------------------------------------------" << endl;
            cout << "        Buscador de series" << endl<< endl;
            cout << "**Escriba el nombre iniciando con mayuscula cada palabra**"<<endl<<endl;
            cout << "Escriba el nombre de la serie deseada: ";
            getline(cin, inputserie); //ingreso del nombre de la serie
            system("cls");
            cout << "--------------------------------------------------------------" << endl;
            cout << "Lista de contenido que coinciden con la referencia: " << endl<< endl;
            contenido.mostrarEpisodiosSerie(inputserie); //llama al metodo de la clase que muestra los episodios
            system("pause");
            break;

        case '4':
            //caso 4 que muestra solo las peliculas de cierta calificacion o mayor
            system("cls");
            cout << "--------------------------------------------------------------" << endl;
            cout << "        Mostrar peliculas por calificacion" <<endl<<endl;
            cout<< "**Asegurese de solo ingresar numeros**"<<endl;
            cout << "Ingresa la calificacion deseada: ";
            int entrada2; 
            cin >> entrada2; //entada de la calificacion
            system("cls");
            cout << "--------------------------------------------------------------" << endl;
            cout << "Lista de contenido que coinciden con la referencia: " << endl<< endl;
            contenido.peliculaPorCalificacion(entrada2); //se llama al metodo de la clse que muestra las peliculas por calificacion
            system("pause");
            break;

        case '5':
            //caso 5 que califica contenido en general
            system("cls");
            cout << "--------------------------------------------------------------" << endl;
            cout << "                 Calificar video" << endl<<endl;
            cout << "Ingresa el nombre de la pelicula o capitulo que deseas calificar: ";
            getline(cin, inputserie); //entrada del nombre del video
            cout << "Ingresa la calificacion: ";
            cin >> entrada2; //entrada de la calificacion
            system("cls");
            contenido.calificarContenido(entrada2, inputserie); //se llama al metodo de la clase que califica el video
            system("pause");
            break;

        case '6':
            //caso 6 que muestra el promedio de una serie
            system("cls");
            cout << "---------------------------------------------------------------" << endl;
            cout << "          Ver promedio de duracion de serie" << endl<< endl;
            cout << "Ingresa el nombre de la serie del que deseas saber el promedio: ";
            getline(cin, inputserie); //entrada del nombre de la serie
            system("cls");
            cout << "---------------------------------------------------------------" << endl<<endl;
            contenido.calcularPromedioSerie(inputserie); //se llama al metodo de la clase que calcula el promedio
            system("pause");
            break;
        case '7':
            //caso 7 se acaba el programa
            return 0;

        default:
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