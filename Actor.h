//#ifndef ACTOR_H_INCLUDED
//#define ACTOR_H_INCLUDED
#include <iostream>

class actor{

    public:
        actor();
        actor(int i, std::string n);
        int getId() {return id;};
        void setId(int i) { id=i;};
        std::string getNombre() {return nombre;};
        void setNombre(std::string n) {nombre=n;};
        void muestra();
        bool operator==(actor);
    private:
        int id;
        std::string nombre;
};
actor :: actor(){
id=0;
nombre="N/A";
}

actor :: actor(int i, std::string n){
id=i;
nombre=n;
}

void actor :: muestra(){
std::cout<<"Nombre:"<<nombre<<std::endl<<"  Id: "<<id<<std::endl;
}

bool actor::operator==(actor a)
{
    if(id==a.getId() && nombre==a.getNombre())
        return true;
    return false;
}


//#endif // ACTOR_H_INCLUDED
