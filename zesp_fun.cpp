#include "zesp.h"

Liczba Liczba::operator~(void)
{
    img=-img;
    return(*this);
}

Liczba Liczba::operator+(const Liczba & l)const
{
    Liczba obiekt;
    obiekt.real=real+l.real;
    obiekt.img=img+l.img;
    return(obiekt);
}

Liczba Liczba::operator-(const Liczba & l)const
{
    Liczba obiekt;
    obiekt.real=real-l.real;
    obiekt.img=img-l.img;
    return(obiekt);
}

Liczba Liczba::operator*(const Liczba & l)const
{
    Liczba obiekt;
    obiekt.real=real*l.real-img*l.img;
    obiekt.img=real*l.img+img*l.real;
    return(obiekt);
}

Liczba Liczba::operator/(Liczba l)const
{
    Liczba obiekt;
    obiekt=*this*~l;
    double dzielnik=pow(l.real,2)+pow(l.img,2);
    obiekt.real/=dzielnik;
    obiekt.img/=dzielnik;
    return(obiekt);
}

bool Liczba::operator==(const Liczba & l)const
{
    if(real==l.real&&img==l.img)
        return(true);
    else
        return(false);
}

std::ostream & operator<<(std::ostream & o,const Liczba & l)
{
    if(l.get_img()<0)
        o << "(" << l.get_real() << l.get_img() << "i)";
    if(l.get_img()>=0)
        o << "(" << l.get_real() << "+" << l.get_img() << "i)";
    return(o);
}

std::istream & operator >> (std::istream & i, Liczba & l)
{
    double re,im;
    char znak;
    while(i.peek()=='\n'||i.peek()==' ')
        i.get();
    if(i.peek()=='~')
        i.get(znak);
    if(i.get()!='(')
        i.setstate(std::ios::failbit);
    i >> re;
    i >> im;
    if(i.get()!='i')
        i.setstate(std::ios::failbit);
    if(i.get()!=')')
        i.setstate(std::ios::failbit);
    if(i.peek()=='\n'||i.peek()==' ')
        i.get();
    if(!i.fail())
    {
        if(znak=='~')
            l=Liczba(re,-im);
        else
            l=Liczba(re,im);
    }
    return(i);
}

void sprawdzenie_argumentow(const int & n, char *tab[])
{
    if(n<2) lista_bledow(1);
    if(n>2) lista_bledow(2);
}

void lista_bledow(const int & n)
{
    using std::cerr;
    using std::endl;
    switch (n)
    {
        case 1:
        cerr << "Nie podano poziomu testu" << endl; exit(0);
        case 2:
        cerr << "Zbyt duza liczba argumentow wywolania programu" << endl; exit(0);
        case 3:
        cerr << "Nie znaleziono pliku" << endl; exit(0);
        case 4:
        cerr << "Blad zapisu. Wyrazenie zostalo pominiete" << endl; break;
    }
}