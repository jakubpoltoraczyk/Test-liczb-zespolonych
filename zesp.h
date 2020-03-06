#ifndef ZESP_H
#define ZESP_H
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

class Liczba
{
private:
    double real;
    double img;
public:
    Liczba(const double & r=0.0, const double & i=0.0): real(r), img(i) {}
    double get_real(void)const{return(real);}
    double get_img(void)const{return(img);}
    Liczba operator~(void);
    Liczba operator+(const Liczba & l)const;
    Liczba operator-(const Liczba & l)const;
    Liczba operator*(const Liczba & l)const;
    Liczba operator/(Liczba l)const;
    bool operator==(const Liczba &l)const;
};
std::ostream & operator << (std::ostream & o, const Liczba & l);
std::istream & operator >> (std::istream & i, Liczba & l);
void sprawdzenie_argumentow(const int &, char*[]);
void lista_bledow(const int &);

#endif // ZESP_H
