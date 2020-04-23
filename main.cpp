#include <iostream>
#include "pelicula.h"
#include "funcion.h"
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int idTemp;
    string nombreTemp;

pelicula arrPeliculas[20];
funcion arrFunciones[20];
actor arrActores[20];

ifstream arActores;
ifstream arPeliculas;

arActores.open("actores.txt");
int iActores=0;
while(arActores>>idTemp)
{
    arrActores[iActores].setId(idTemp);
    getline(arActores,nombreTemp);
    arrActores[iActores].setNombre(nombreTemp);
    iActores++;
}
arActores.close();



arPeliculas.open("peliculas.txt");
int numPel, anio, duracion, cantActores, iPeliculas=0;
string genero, titulo;
bool temp=false;
while(arPeliculas>>numPel)
{
    arPeliculas>>anio>>duracion>>genero>>cantActores;
    arrPeliculas[iPeliculas].setNumPeli(numPel);
    arrPeliculas[iPeliculas].setAnio(anio);
    arrPeliculas[iPeliculas].setDuracion(duracion);
    arrPeliculas[iPeliculas].setGenero(genero);
    for(int x=1;x<=cantActores;x++)
     {
         int cont=0;
         arPeliculas>>idTemp;
         do{
                if(arrActores[cont].getId()==idTemp)
                    {
                    temp=true;
                    }
                else
                    {temp=false;
                     cont++;
                    }
         }while(temp==false);
         temp = arrPeliculas[iPeliculas].addActor(arrActores[cont]);
     }
    getline(arPeliculas,nombreTemp);
    arrPeliculas[iPeliculas].setTitulo(nombreTemp);
    iPeliculas++;
}
arPeliculas.close();
//int funcionesD,sala, hr, minut;
//string cveFuncion;
//cout<<"cuantas funciones habra disponibles?"<<endl;
//cin>>funcionesD;
//
//for(int k=0;k<funcionesD;k++)
//{
//    cout<<"Ingrese la clave de la funcion #"<<k+1<<endl;
//    cin>>cveFuncion;
//    cout<<"Ingrese el numero de pelicula de la funcion #"<<k+1<<endl;
//    cin>>numPel;
//    cout<<"Ingrese la sala de la funcion #"<<k+1<<endl;
//    cin>>sala;
//    cout<<"Ingrese la hora de la funcion #"<<k+1<<" (hr)"<<endl;
//    cin>>hr;
//    cout<<"Ingrese la hora de la funcion #"<<k+1<<" (min)"<<endl;
//    cin>>minut;
//    hora h1(hr,minut);
//    arrFunciones[k].setCveFuncion(cveFuncion);
//    arrFunciones[k].setNumPeli(numPel);
//    arrFunciones[k].setSala(sala);
//    arrFunciones[k].setHora(h1);
//}

//for(int g=0;g<iPeliculas;g++)
//    arrPeliculas[g].muestra();
for(int j=0;j<iActores;j++)
    arrActores[j].muestra();
}


