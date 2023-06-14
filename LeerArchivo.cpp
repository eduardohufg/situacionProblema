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
using namespace std;



vector<Episodio> episodios;
vector<Pelicula> peliculas;
vector<Video*> videos;



vector<string> separar(string linea);

int main(int argc, char const *argv[]){

    ifstream entrada;
    entrada.open("DatosPeliculas.csv");
    string linea;
    int numeroDeLinea =1;
    int contaPelis =0;
    int contaEpis =0;
    
    while (getline (entrada, linea)){
        //cout<<(numeroDeLinea++)<<":"<<linea<<endl;
        vector<string> datos = separar(linea);
        //cout<<numeroDeLinea++<<" ";
        if (datos.size()== 6){
            //cout <<"pelicula";      
            Pelicula* pelis = new Pelicula(datos);
            videos.push_back(pelis);    
            //cout<<hola.getFecha();
            //stoi
        }
        else{
           // cout<<"episodio";
           Episodio* epis = new Episodio(datos);
           videos.push_back(epis);
        }
        //cout<<endl;
    
    }
    videos.erase(videos.begin());
    
    //int co = videos.size();
    
   // for (int n = 0; n <co;n++){


       // cout<<videos[n]->getNombreVideo()<<endl;
   // }
    entrada.close();

    int caso;

    while(true){
        //menu
        system("cls");
        cout<<"--------------------------------------------------------------"<<endl;
        cout<<"                     Servicio streaming"<<endl<<endl;
        cout<<"Ingresa la opcion deseada"<<endl;

        cout<<endl<<"1. Cargar archivo de datos"<<endl;
        cout<<"2. Buscar contenido por calificacion o genero"<<endl;
        cout<<"3. Mostrar episodios de una serie"<<endl;
        cout<<"4. Buscar peliculas por calificacion"<<endl;
        cout<<"5. Calificar contenido"<<endl;
        cout<<"6. Mostrar promedio de calificacion de una serie"<<endl;
        cout<<"7. Salir"<<endl;
        cout<<"--------------------------------------------------------------"<<endl;

        cin>>caso;
        cin.ignore();
        
        switch (caso)
        {
        case 1:

            system("cls");
            cout<<"Aun no impelentado"<<endl;
            system("pause");
            break;

        case 2:
            system("cls");
            cout<<"Aun no impelentado"<<endl;
            system("pause");



            break;

        case 3:

            system("cls");
            cout<<"Aun no impelentado"<<endl;
            system("pause");



            break;

        case 4:
            system("cls");
            cout<<"Aun no impelentado"<<endl;
            system("pause");




            break;

        case 5:
            system("cls");
            cout<<"Aun no impelentado"<<endl;
            system("pause");




            break;

        case 6:
            system("cls");
            cout<<"Aun no impelentado"<<endl;
            system("pause");




            break;

        case 7:
            return 0;


            break;
        
        default:
            break;
        }

    }

    return 0;

}







//Funciones------------------------------------------------------------------------------------------------------
vector<string> separar(string linea){

    vector<string> tokens; //componentes de la linea
    stringstream entrada(linea); //flujo de datos a partir de una cadena
    string dato;  //token individual
    int numeroTokens = 0;
    while ( getline(entrada, dato, ','))
    {
        //cout<<dato<<endl;
        if (dato != ""){
            tokens.push_back(dato);
            numeroTokens++;
        }
    }
    //cout<< "tokens: "<< numeroTokens<<endl<<endl;
    return tokens;
}
