/* Deklaracja klasy Liczba oraz prototypy funkcji bezposrednio z nia zwiazanych */
#ifndef ZESP_FUN_H
#define ZESP_FUN_H
#include <iostream>

/* Deklaracja klasy dla liczb zespolonych */
class Liczba
{
private: // prywatne dwie skladowe: czesc rzeczywista i czesc urojona
    double real;
    double img;
public:
    Liczba(const double & r=0.0, const double & i=0.0): real(r), img(i) {} // konstruktor przyjumjacy czesc rzeczywista i zespolona
    const double & get_real(void)const{return real;} // metoda zwracajaca czesc rzeczywista
    const double & get_img(void)const{return img;} // metoda zwracajaca czesc urojona
    double get_modul()const{return real*real+img*img;} // metoda zwracajaca modul liczby zespolonej
    Liczba operator~(void)const; // metoda tworzaca sprzezenie liczby zespolonej
    Liczba operator+(const Liczba & l)const; // metoda dodawania dwoch liczb zespolonych
    Liczba operator-(const Liczba & l)const; // metoda odejmowania dwoch liczb zespolonych
    Liczba operator*(const Liczba & l)const; // metoda mnozenia dwoch liczb zespolonych
    Liczba operator/(const Liczba & l)const; // metoda dzielenia dwoch liczb zespolonych
    Liczba operator/(const double & n)const; // metoda dzielenia liczbe zespolonej przez liczby typu double
    bool operator==(const Liczba & l)const; // metoda porownania rownosci dwoch liczb zespolonych
    bool operator!=(const Liczba & l)const; // metoda sprawdzania roznosci dwoch liczb zespolonych
};

/* Funkcje bezposrednio zwiazane z klasa Liczba */
std::ostream & operator << (std::ostream & o, const Liczba & l); // przeciazany operator << dla liczby zespolonych klasy Liczba
std::istream & operator >> (std::istream & i, Liczba & l); // przeciazany operator << dla liczby zespolonej klasy Liczba, sprawdzajacy poprawnosc jej zapisu

#endif // ZESP_FUN_H
