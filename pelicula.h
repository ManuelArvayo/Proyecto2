//#ifndef PELICULA_H_INCLUDED
//#define PELICULA_H_INCLUDED
#include <iostream>
#include <string>
#include "Actor.h"

using namespace std;

class pelicula{
    public:
        pelicula();
        int getNumPeli() {return numPeli;};
        int getAnio() {return anio;};
        int getDuracion() {return duracion;};
        string getTitulo() {return titulo;};
        string getGenero() {return genero;};
        void setNumPeli(int numP) {numPeli =numP;};
        void setAnio(int a) {anio=a;};
        void setDuracion(int d) {duracion=d;};
        void setTitulo(string t) {titulo=t;};
        void setGenero(string g) {genero=g;};
        actor getListaActor(int);
        int getCantActores() {return cantActores;};
        bool addActor(actor);
        void muestra();
    private:
        int numPeli, anio, duracion, cantActores;
        string titulo, genero;
        actor listaActores[10];
};


pelicula :: pelicula()
{
numPeli=0;
anio=0;
duracion=0;
cantActores=0;
titulo="N/A";
genero="N/A";
actor a0;
for(int i=0; i<10; i++)
    listaActores[i] = a0;
}

actor pelicula::getListaActor(int indice)
{
    return listaActores[indice];
}

void pelicula :: muestra(){

cout<<"Titulo: "<<titulo<<endl<<"   Anio: "<<anio<<endl<<"   Duracion: ";
cout<<duracion<<endl<<"   Numero de Pelicula: "<<numPeli<<endl<<"   Genero: "<<genero<<endl;
for(int i=0;i<cantActores;i++)
{
    cout<<"   "<<listaActores[i].getNombre()<<endl;
}

}

bool pelicula::addActor(actor Ac)
{
if(cantActores==10) //checamos que el numero de actores no sea mayor de 10
    return false;
int i=0;
while(i<10)
    {
    if(listaActores[i]==Ac) // checamos que el actor no este ya en el arreglo
        return false;
    i++;
    }
actor a0;
i=0;
bool chequeo;
do{
    chequeo = listaActores[i]==a0;
    i++;
}while(chequeo==false);
i--;
listaActores[i]=Ac;
cantActores++;
return true;
}


//#endif // PELICULA_H_INCLUDED
