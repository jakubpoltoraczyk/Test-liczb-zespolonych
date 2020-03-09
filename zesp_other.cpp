#include "zesp_other.h" // Dolaczenie klasy Statystyka oraz funkcji i elementow zwiazanych z obsluga programu

/* Funkcja przeciazajaca operator << dla typu wyliczeniowego Operator */
std::ostream & operator << (std::ostream & o, const Operator & op)
{
    switch(op) // wybor rodzaju znaku do wyswietlenia
    {
        case plus:
        o << "+"; break;
        case minus:
        o << "-"; break;
        case mnoz:
        o << "*"; break;
        case dziel:
        o << "/"; break;
    }
    return(o); // zwrocenie obiektu klasy ostream
}

/* Funkcja przeciazajaca operator >> dla typu wyliczeniowego Operator */
std::istream & operator >> (std::istream & i, Operator & op)
{
    while(i.peek()=='\n'||i.peek()==' ') // jesli sa znaki biale
        i.get(); // pobranie ich
    char znak; // zmienna do przechowania wczytywanego znaku
    i >> znak; // wczytanie znaku
    switch(znak) // rozpoznanie znaku i ustawienie odpowiedniego enuma
    {
        case '+':
        op=plus; break;
        case '-':
        op=minus; break;
        case '*':
        op=mnoz; break;
        case '/':
        op=dziel; break;
        default: 
        i.setstate(std::ios::failbit); // ustawienie flagi bledu
    }
    return(i); // zwrocenie obiektu klasy istream
}

/* Funkcja sprawdzajaca poprawnosc argumentow wywolania programu oraz poprawnosc pliku*/
void sprawdzenie_argumentow(const int & n, char *tab[], std::ifstream & plik)
{
    std::string napis;
    if(n<2) lista_bledow(1); // jesli za malo argumentow wywolania
    if(n>2) lista_bledow(2); // jesli za duzo argumtentow wywolania
    napis=tab[1]; // zapisanie nazwy pliku
    napis+=".txt"; // dodanie rozszerzenia '.txt'
    plik.open(napis); // otwarcie pliku
    if(!plik.is_open()) // sprawdzenie poprawnosci otwarcia pliku
        lista_bledow(3); // blad otwarcia
}

/* Funkcja wyswietlajaca komunikaty o bledach i ewentualnie zamykajaca program */
void lista_bledow(const int & n)
{
    using std::cerr;
    using std::endl;
    switch (n) // rozroznienie rodzaju bledu
    {
        case 1:
        cerr << "Nie podano poziomu testu" << endl; exit(0); // komunikat + wyjscie
        case 2:
        cerr << "Zbyt duza liczba argumentow wywolania programu" << endl; exit(0); // komunikat + wyjscie
        case 3:
        cerr << "Nie znaleziono pliku" << endl; exit(0); // komunikat + wyjscie
        case 4:
        cerr << "Blad zapisu. Wyrazenie zostalo pominiete" << endl << endl; break; // komunikat
    }
}