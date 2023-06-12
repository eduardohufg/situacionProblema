/*
Autor: Eduardo Chavez Martin 
Leer el archivo de texto en c++
*/

#include <iostream>
#include <fstream>
#include <sstream> // para string-stream
#include <vector>
using namespace std;



vector<string> separar(string linea);

int main(int argc, char const *argv[]){

    ifstream entrada;
    entrada.open("DatosPeliculas.csv");

    string linea;

    int numeroDeLinea =1;
    while (getline (entrada, linea)){

        //cout<<(numeroDeLinea++)<<":"<<linea<<endl;

        vector<string> datos = separar(linea);

        cout<<numeroDeLinea++<<" ";
        if (datos.size()== 6){
            cout <<"pelicula";
            //new Pelicula(datos)

        }
        else{
            cout<<"episodio";

        }
        cout<<endl;
    
    }

    entrada.close();




    return 0;

}


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
