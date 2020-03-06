#ifndef ZESP_H
#define ZESP_H
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

/* Deklaracja klasy dla liczb zespolonych */
class Liczba
{
private: // prywatne dwie skladowe: czesc rzeczywista i czesc urojona
    double real;
    double img;
public:
    Liczba(const double & r=0.0, const double & i=0.0): real(r), img(i) {} // konstruktor przyjumjacy czesc rzeczywista i zespolona
    double get_real(void)const{return(real);} // metoda zwracajaca czesc rzeczywista
    double get_img(void)const{return(img);} // metoda zwracajaca czesc urojona
    Liczba operator~(void); // metoda tworzaca sprzezenie liczby zespolonej
    Liczba operator+(const Liczba & l)const; // metoda dodawania dwoch liczb zespolonych
    Liczba operator-(const Liczba & l)const; // metoda odejmowania dwoch liczb zespolonych
    Liczba operator*(const Liczba & l)const; // metoda mnozenia dwoch liczb zespolonych
    Liczba operator/(Liczba l)const; // metoda dzielenia dwoch liczb zespolonych
    bool operator==(const Liczba &l)const; // metoda porownania dwoch liczb zespolonych
};

/* Funkcje bezposrednio zwiazane z klasa Liczba */
std::ostream & operator << (std::ostream & o, const Liczba & l); // przeciazany operator << dla liczby zespolonych klasy Liczba
std::istream & operator >> (std::istream & i, Liczba & l); // przeciazany operator << dla liczby zespolonej klasy Liczba, sprawdzajacy poprawnosc jej zapisu

/* Funkcje sprawdzajace poprawnosc argumentow wywolania programu oraz poprawnosc pliku */
void sprawdzenie_argumentow(const int &, char*[]); // sprawdzenie poprawnosci argumentow wywolania programu
void lista_bledow(const int &); // wyswietlenie komunikatu o bledzie programu oraz ewentualne jego zamkniecie

#endif // ZESP_H
