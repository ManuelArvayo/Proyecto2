#ifndef HORA_H_INCLUDED
#define HORA_H_INCLUDED
#include <iomanip> // lbreria para usar setw y setfill en el metodo muestra
using namespace std;
class hora{

public:
    hora();
    hora(int, int);
    void sethora(int hh) {h = hh;};
    void setminu(int mm) {m = mm;};
    int gethora() {return h;};
    int getminu() {return m;};
    void muestra();
private:
    int h, m;
};

hora::hora()
{
    h=0;
    m=0;
}

hora::hora(int hrs, int minutos)
{
    h=hrs;
    m=minutos;
}

void hora ::muestra(){
std::cout << std::setw(2) << std::setfill('0') << h << ":"<< std::setw(2) << std::setfill('0') << m << std::endl;
}

#endif // HORA_H_INCLUDED
