#include <iostream>
#include "pelicula.h"
#include "funcion.h"
#include <fstream>
#include <string>

using namespace std;

int main()
{
int idTemp, cont=0;
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
            {
                temp=false;
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


int funcionesD,sala, hr, minut,z=0;
string cveFuncion;
cout<<"Cuantas funciones habra disponibles?"<<endl;
cin>>funcionesD;
temp=false;
for(int k=0;k<funcionesD;k++)
{
    cout<<"Ingrese la clave de la funcion #"<<k+1<<endl;
    cin>>cveFuncion;
    do{
        z=0;
        cout<<"Ingrese el numero de pelicula de la funcion #"<<k+1<<endl;
        cin>>numPel;
            arrFunciones[k].setCveFuncion(cveFuncion);

        do
        {
            if(arrPeliculas[z].getNumPeli()!=numPel)
            {
                temp=false;
            }
            else
            {
                arrFunciones[k].setNombrePeli(arrPeliculas[z].getTitulo());
                temp=true;
            }
        z++;
        }while(temp==false && z<20);
    }while(temp!=true);


    cout<<"Ingrese la sala de la funcion #"<<k+1<<endl;
    cin>>sala;
    do
    {
        cout<<"Ingrese hora (0-24) de la funcion #"<<k+1<<endl;
        cin>>hr;
    }while(hr<0 || hr>24);

    do
    {
        cout<<endl<<"Ingrese minutos (0-59) de la funcion #"<<k+1<<endl;
        cin>>minut;
    }while(minut<0 || minut>59);
    hora h1(hr,minut);
    arrFunciones[k].setNumPeli(numPel);
    arrFunciones[k].setSala(sala);
    arrFunciones[k].setHora(h1);

}


char resp;
do{
cout<<"Ingrese A para Consultar Actores "<<endl;
cout<<"Ingrese B para Consultar Peliculas "<<endl;
cout<<"Ingrese C para Consultar Funciones "<<endl;
cout<<"Ingrese D para Consultar Funciones por Hora "<<endl;
cout<<"Ingrese E para Consultar Funciones por Clave "<<endl;
cout<<"Ingrese F para Consultar Peliculas por Actor"<<endl;
cout<<"Ingrese G para Terminar"<<endl;
cin>>resp;
resp=tolower(resp);

if(resp=='a')
{
   for(int j=0;j<iActores;j++)
    arrActores[j].muestra();
}
if(resp=='b')
{
for(int g=0;g<iPeliculas;g++)
    arrPeliculas[g].muestra();
}
if(resp=='c')
{
for(int h=0;h<funcionesD;h++)
    arrFunciones[h].muestra();
}
if(resp=='d')
{
do
{
    cout<<"Ingrese hora (0-24): ";
    cin>>hr;
}while(hr<0 || hr>24);

do
{
    cout<<endl<<"Ingrese minutos (0-59): ";
    cin>>minut;
}while(minut<0 || minut>59);

hora hConsulta(hr,minut);

        for(int y=0;y<funcionesD;y++)
        {

            if(arrFunciones[y].getHora()==hConsulta)
            {
                cout<<"Titulo: "<<arrFunciones[y].getNombrePeli()<<endl<<"  Sala: "<<arrFunciones[y].getSala()<<endl;
            }

        }
}
if(resp=='e')
{
do{
cout<<"Ingrese la clave de Funcion ";
cin>>cveFuncion;
temp=false;
for(int o=0;o<funcionesD;o++)
{
    if(arrFunciones[o].getCveFuncion()==cveFuncion)
    {
        temp=true;
        cout<<"Titulo: "<<arrFunciones[o].getNombrePeli()<<endl;
        cout<<"  Sala: "<<arrFunciones[o].getSala()<<endl;
        cout<<"  Hora: ";
        arrFunciones[o].getHora().muestra();
        cout<<endl;
        for(int v=0;v<iPeliculas;v++)
        {
            if(arrPeliculas[v].getNumPeli()==arrFunciones[o].getNumPeli())
            {
                cout<<"  Duracion: "<<arrPeliculas[v].getDuracion()<<endl;
                cout<<"  Genero: "<<arrPeliculas[v].getGenero()<<endl;
                cout<<"  Actores: "<<endl;
                for(int f=0;f<arrPeliculas[v].getCantActores();f++)
                {
                    cout<<"  "<<arrPeliculas[v].getListaActor(f).getNombre()<<endl;
                }
            }

        }

    }
}
if(temp==false)
    cout<<"Clave no Existente"<<endl;
}while(temp==false);
}
if(resp=='f')
{
do{
    cout<<"Ingrese el Id de Actriz/Actor "<<endl;
    cin>>idTemp;
    bool idExiste;
    cont=0;
do{
if(arrActores[cont].getId()==idTemp)
    temp=true;
else
    temp=false;
cont++;
}while(temp==false && cont<iActores);
}while(temp==false);
for(int u=0;u<iPeliculas;u++)
{
    for(int e=0;e<arrPeliculas[u].getCantActores();e++)
    {
        if(arrPeliculas[u].getListaActor(e).getId()==idTemp)
            cout<<arrPeliculas[u].getTitulo()<<"  "<<arrPeliculas[u].getAnio()<<endl;

    }
}
}

if(resp=='g')
{
return 0;
}
if(resp!='a' &&resp!='b' &&resp!='c' &&resp!='d' &&resp!='e' &&resp!='f' &&resp!='g' )
{
    cout<<"Error, Opcion no valida"<<endl;
}
}while(resp!='g');
}


