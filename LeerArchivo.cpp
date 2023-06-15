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
#include <algorithm>
#include <string>
#include <typeinfo>
#include <typeinfo.h>

#include "Serie.h"

using namespace std;



vector<Episodio> episodios;
vector<Pelicula> peliculas;
vector<Video*> videos;


//vector<Serie> hacerSeries(vector<Video*> vecVideo);
vector<string> separar(string linea);
bool existeVector(vector<string> vec, string busqueda);
bool esEpisodio(Video* video);

int main(int argc, char const *argv[]){

    ifstream entrada;
    //Excepcipones
    entrada.open("DatosPeliculas.csv");

    //manejo normal del error
    //if(entrada.fail()){
       // cout<<"error, no puedo leer el archivo..."<<endl;
        //return -1; //Error
    //}
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
    
    //for (int n = 0; n <co;n++){


        //cout<<videos[n]->getNombreVideo();
        //cout<<endl;
   //}
   
    entrada.close();

    int caso;

    while(true){
        //menu
        system("cls");
        cout<<"--------------------------------------------------------------"<<endl;
        cout<<"                     Servicio streaming"<<endl;
        cout<<"--------------------------------------------------------------"<<endl<<endl;
        cout<<"Ingresa la opcion deseada"<<endl;

        cout<<endl<<"1. Cargar archivo de datos"<<endl;
        cout<<"2. Buscar contenido por calificacion o genero"<<endl;
        cout<<"3. Mostrar episodios de una serie"<<endl;
        cout<<"4. Buscar peliculas por calificacion"<<endl;
        cout<<"5. Calificar contenido"<<endl;
        cout<<"6. Mostrar promedio de calificacion de una serie"<<endl;
        cout<<"7. Salir"<<endl;
        cout<<"--------------------------------------------------------------"<<endl;
        cout<<"Entrada: ";
        cin>>caso;
        cin.ignore();
        string generoi;
        string seri;
        string arch;
        ifstream entradaArch;
        string lineaArch;
        int lin =0;
        int entrada2;
        switch (caso)
        {
        case 1:

            system("cls");
            cout<<"--------------------------------------------------------------"<<endl;
            cout<<"Asegurate que el archivo que quieres cargar este en formato .csv"<<endl;
            cout<<"Asegurese que el archivo este en la misma carpeta que este programa"<<endl;
            cout<<"En caso de que no se encuentre en la misma carpeta, especifica la ruta"<<endl<<endl;

            cout<<"Escriba entre comillas el nombre del archivo: ";
            
            cin>>arch;
            
            entradaArch.open(arch);
            

                //while (getline (entradaArch, lineaArch)){
                //numeroDeLinea++;
            //}
            
            while (getline (entradaArch, lineaArch)){
                //cout<<(numeroDeLinea++)<<":"<<linea<<endl;
                vector<string> datos = separar(lineaArch);
                //cout<<numeroDeLinea++<<" ";
                if (datos.size()== 6){
                    //cout <<"pelicula";      
                    Pelicula* pelis = new Pelicula(datos);
                    videos[lin] = pelis;
                    lin++;
                    //videos.push_back(pelis);    
                    //cout<<hola.getFecha();
                    //stoi
                }
                else{
                // cout<<"episodio";
                Episodio* epis = new Episodio(datos);
                videos[lin] = epis;
                lin++;
                //videos.push_back(epis);

                }
                //cout<<endl;
    
            }
            videos.erase(videos.begin());
            entradaArch.close();

            cout<<"Lito!!"<<endl;
            system("pause");
            break;

        case 2:
        
            system("cls");
            cout<<"--------------------------------------------------------------"<<endl;
            cout<<"Seleccione la opcion deseada"<<endl<<endl;
            int entrada;
            cout<<"1. Mostrar contenido con calificacion mayor o igual a la ingresada"<<endl;
            cout<<"2. Mostrar contenido por genero"<<endl;
            cout<<"3. Regresar al menu principal"<<endl;
            cout<<"--------------------------------------------------------------"<<endl;
            cout<<"Ingresa el numero de la opcion que deseas: ";
            
            cin>>entrada;
            cout<<endl;
            int opcion;
            
            if (entrada ==1){
                cout<<"Calificacion deseada: ";
                cin>>opcion;
                system("cls");
                cout<<"Lista de contenido que coinciden con la referencia: "<<endl<<endl;
                for(int i =0; i< videos.size();i++){
                    
                    if(videos[i]->getCalificacion() >= opcion){
                        cout<<"--------------------------------------------------------------"<<endl;
                        videos[i]->mostrarDatos();
                        cout<<endl;
                    }
                }
            }
            else if(entrada ==2){
                cout<<"Teclee el genero deseado(Iniciando con mayuscula): ";
                cin>>generoi;
                system("cls");
                cout<<"Lista de contenido que coinciden con la referencia: "<<endl<<endl;

                for(int i =0; i< videos.size();i++){
                    if(existeVector(videos[i]->getMultiGenero(),generoi)){
                        cout<<"--------------------------------------------------------------"<<endl;
                        videos[i]->mostrarDatos();
                        cout<<endl;
                    }
                    //else{
                        //system("cls");
                        //cout<<"--------------------------------------------------------------"<<endl;
                        //cout<<"No se encontraron refrencias, asegurese de escribir bien el genero"<<endl;
                    //}
                }


            }
            else{
                break;
            }

            cout<<"No se encontraron refrencias, asegurese de escribir bien el genero"<<endl;
            system("pause");



            break;

            

        case 3:

            system("cls");
            cout<<"--------------------------------------------------------------"<<endl;
            cout<<"Buscador de series"<<endl<<endl;
            cout<<"Escriba el nombre de la serie deseada: "<<endl;

            getline(cin,seri);
            
            //cout<<seri<<endl;
            //cout<<videos[0]->getNombreVideo();
            //system("cls");

                cout<<"Lista de contenido que coinciden con la referencia: "<<endl<<endl;

                
                for(int i =0; i< videos.size();i++){
                    
                    if(esEpisodio(videos[i])){
                        //Serie* apuntS = dynamic_cast<Serie*> (videos[i]);
                        //cout<<seri<<endl;
                        //videos[i]->getNombreVideo();
                        //cout<<videos[i]->getNombreVideo()<<"          "<<seri<<endl;
                        if(videos[i]->getNombreVideo() == seri){
                            cout<<"--------------------------------------------------------------"<<endl;
                            videos[i]->mostrarDatos();
                            cout<<endl;
                        }
                        
                    }
                }

            
            cout<<"Aun no impelentado"<<endl;
            system("pause");



            break;

        case 4:
            system("cls");
            cout<<"--------------------------------------------------------------"<<endl;
            cout<<"Mostrar peliculas por calificacion"<<endl;
            cout<<"Ingresa la calificacion deseada: "<<endl;
            int entrada2;
            cin>>entrada2;
            for(int i =0; i<videos.size(); i++){
                
            Pelicula* apuntP = dynamic_cast<Pelicula*> (videos[i]);
            if(apuntP != 0){
                if(apuntP->getCalificacion()>= entrada2){
                    cout<<"---------------------------------------------------------------"<<endl;
                    apuntP->mostrarDatos();
            }
            }
            
            }
            cout<<"Aun no impelentado"<<endl;
            system("pause");





            break;

        case 5:
            system("cls");
            cout<<"--------------------------------------------------------------"<<endl<<endl;
            cout<<"Calificar video"<<endl;
            cout<<"Ingresa el nombre de la pelicula o capitulo que deseas calificar: ";
            getline(cin,arch);

            for(int i=0; 1<videos.size();i++){
                Episodio* apuntE = dynamic_cast<Episodio*> (videos[i]);
                if(apuntE != 0){
                    if(apuntE->getNombreEpisodio() == arch){
                        cout<<"---------------------------------------------------------------"<<endl;
                        cout<<"Ingresa la calificacion";
                        cin>>entrada2;

                        apuntE->setCalificacion(entrada2);

                        cout<<"Guardado"<<endl;
                        system("pause");
                        break;
            }
            }
            else if(videos[i]->getNombreVideo() ==arch){
                        cout<<"---------------------------------------------------------------"<<endl;
                        cout<<"Ingresa la calificacion";
                        cin>>entrada2;

                        videos[i]->setCalificacion(entrada2);

                        cout<<"Guardado"<<endl;
                        system("pause");
                        break;
            }

            }

        
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


bool existeVector(vector<string> vec, string busqueda) {
    return find(vec.begin(), vec.end(), busqueda) != vec.end();
}

bool esEpisodio(Video* video){

    if (video->getNumElementos() == 6){
        return false;
    }
    else{
        return true;
    }
}

//vector<Serie> hacerSeries(vector<Video*> vecVideo){
    // vector<Serie> series;
    // for(Video* dato : vecVideo){
        
    
    //     if(tipo.find("Episodio")==1)
    //     {
    //         Video *t = (Video*)(dato);
    //         series.push_back(t);
    //     }
    // }

    //return series;



//}