#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED
#include "hora.h"

class funcion{
public:
    void setHora(hora h) { hora=h;};
    void setNumPeli(int nP) {numPeli=nP;};
    void setSala(int s) {sala=s;};
    void setCveFuncion(string cF) {cveFuncion=cF;};
    hora getHora() {return hora;};
    int getNumPeli() {return numPeli;};
    int getSala() {return sala;};
    string getCveFuncion() {return cveFuncion;};
    void muestra();
private:
    hora hora;
    int numPeli, sala;
    string cveFuncion;
};

void funcion::muestra()
{
cout<<"Hora : ";
hora.muestra();
cout<<" Numero Pelicula: "<<numPeli<<" Sala: "<<sala<<" Clave: "<<cveFuncion<<endl;
}

#endif // FUNCION_H_INCLUDED
