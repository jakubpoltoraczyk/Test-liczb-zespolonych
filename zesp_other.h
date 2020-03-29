/* Deklaracja klasy Statystyka oraz elementow i funkcji obslugi programu */
#ifndef ZESP_OTHER_H
#define ZESP_OTHER_H
#include <iostream>
#include <string>
#include <fstream>
#include "zesp_fun.h"

/* Typ wyliczeniowy dla rodzaju operacji do wykonania */
enum Operator {plus,minus,dziel,mnoz};

/* Funkcje zwiazane bezposrednio z typem wyliczeniowym Operator */
std::ostream & operator << (std::ostream & o, const Operator & op);
std::istream & operator >> (std::istream & i, Operator & op);

/* Funkcje odpowiedzialne za obsluge pliku oraz programu*/
void sprawdzenie_argumentow(const int &, char*[], std::ifstream &); // sprawdzenie poprawnosci argumentow wywolania programu
void lista_bledow(const int &); // wyswietlenie komunikatu o bledzie programu oraz ewentualne jego zamkniecie
void czysc(std::istream & i); // czyszczenie dowolnego strumienia 

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
    int get_zle()const{return suma-pop;} // metoda zwracajaca liczbe niepoprawnych odpowiedzi
    double get_procent()const{return (double(pop)/double(suma))*100;} // metoda zwracajaca procentowa poprawnosc odpowiedzi
};

/* Funkcje zwiazane bezposrednio z klasa Statystyka */
std::ostream & operator << (std::ostream & o, const Statystyka & stat); // przeciazenie operatora << dla klasy Statystyka

/*Deklaracja klasy dla wyrazen w programie */
class Pytanie
{
private:
    Liczba zesp_1, zesp_2; // dwie liczby skladajace sie na pelne wyrazenie
    Operator op; // rodzaj znaku operacji
public:
    Pytanie(): zesp_1(Liczba()), zesp_2(Liczba()), op(plus) {} // konstruktor domyslny wykorzystujacy domyslne konstruktory klasy Liczba
    Pytanie(const Liczba & z_1, const Liczba & z_2, const Operator & o_p): zesp_1(z_1), zesp_2(z_2), op(o_p) {} // konstruktor z trzema konkretnymi argumentami, tworzacy pelne poprawne wyrazenie
    const Liczba & get_zesp_1()const{return zesp_1;} // zwrocenie pierwszego skladnika wyrazenia
    const Liczba & get_zesp_2()const{return zesp_2;} // zwrocenie drugiego skladnika wyrazenia
    const Operator & get_op()const{return op;} // zwrocenie znaku rodzaju operacji
    Liczba get_answer()const; // zwrocenie poprawnej odpowiedzi wyrazenia
    bool check_answer(const Liczba & l)const; // sprawdzenie odpowiedzi z podana w argumencie
};

/* Funkcje bezposrednio zwiazane z klasa Pytanie */
std::ostream & operator << (std::ostream & o, const Pytanie & pyt); // przeciazenie operatora << dla klasy Pytanie
std::istream & operator >> (std::istream & i, Pytanie & pyt); // przeciazenia operatora >> dla klasy Pytanie

#endif // ZESP_OTHER_H