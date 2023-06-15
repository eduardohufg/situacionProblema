#include "Serie.h"

Serie::Serie(vector<Video*> vec)
{
    for(int i =0; i<vec.size(); i++){
        this -> vec[i] = vec[i];
    }

    if(vec.empty()){
        nombreSerie = "No hay serie asignada";
    }

    nombreSerie = vec[0]->getNombreVideo();

}

void Serie::mostrarEpisodios()
{
    for(int i = 0; i< vec.size(); i++){
        cout<<"--------------------------------------------------"<<endl;
        vec[i]->mostrarDatos();
    }

}
