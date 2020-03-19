/* Deklaracja klasy Statystyka oraz elementow i funkcji obslugi programu */
#ifndef ZESP_OTHER_H
#define ZESP_OTHER_H
#include <iostream>
#include <string>
#include <fstream>

/* Deklaracja klasy dla statystyk w programie */
class Statystyka
{
private:
    int pop; // skladowa do przechowywania poprawnych odpowiedzi
    int suma; // skladowa do przechowywania lacznej liczby pytan
public:
    Statystyka(): pop(0), suma(0) {} // konstruktor ustawiajacy skladowe prywatne na zera
    void dodaj_pop(){++pop;} // metoda aktualizujaca liczbe poprawnych odpowiedzi
    void dodaj_suma(){++suma;} // metoda aktualizujaca liczbe wszystkich pytan
    const int & get_pop()const{return pop;} // metoda zwracajaca liczbe poprawnych odpowiedzi
    const int & get_suma()const{return suma;} // metoda zwracajaca liczbe wszystkich pytan
    const int get_zle()const{return suma-pop;} // metoda zwracajaca liczbe niepoprawnych odpowiedzi
    double get_procent()const{return (double(pop)/double(suma))*100;} // metoda zwracajaca procentowa poprawnosc odpowiedzi
};  

/* Typ wyliczeniowy dla rodzaju operacji do wykonania */
enum Operator {plus,minus,dziel,mnoz};

/* Funkcje zwiazane bezposrednio z typem wyliczeniowym Operator */
std::ostream & operator << (std::ostream & o, const Operator & op);
std::istream & operator >> (std::istream & i, Operator & op);

/* Funkcje sprawdzajace poprawnosc argumentow wywolania programu oraz poprawnosc pliku */
void sprawdzenie_argumentow(const int &, char*[], std::ifstream &); // sprawdzenie poprawnosci argumentow wywolania programu
void lista_bledow(const int &); // wyswietlenie komunikatu o bledzie programu oraz ewentualne jego zamkniecie

#endif // ZESP_OTHER_H