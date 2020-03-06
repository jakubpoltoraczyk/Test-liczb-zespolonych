#include "zesp.h" // dolaczenie klasy Liczba oraz funkcji sprawdzajacych poprawnosc argumentow wywolania programu i poprawnosc pliku

/* Metoda sprzezajaca liczbe zespolona */
Liczba Liczba::operator~(void)
{
    img=-img; // odwrocenie znaku czesci urojonej
    return(*this); // zwrocenie obiektu wywolujacego
}

/* Metoda dodajaca dwie liczby zespolone */
Liczba Liczba::operator+(const Liczba & l)const
{
    Liczba obiekt(real+l.real,img+l.img); // stworzenie nowego obiektu za pomoca konstruktora
    return(obiekt); // zwrocenie nowego obiektu
}

/* Metoda odejmujaca od siebie dwie iczby zespolone */
Liczba Liczba::operator-(const Liczba & l)const
{
    Liczba obiekt(real-l.real,img-l.img); // stworzenie nowego obiektu za pomoca konstruktora
    return(obiekt); // zwrocenie nowego obiektu
}

/* Metoda mnozaca dwie liczby zepsolone */
Liczba Liczba::operator*(const Liczba & l)const
{
    Liczba obiekt(real*l.real,img*l.img); // stworzenie nowego obiektu za pomoca konstruktora
    return(obiekt); // zwrocenie nowego obiektu
}

/* Metoda dzielaca dwie liczby zepsolone */
Liczba Liczba::operator/(Liczba l)const
{
    Liczba obiekt; // stworzenie obiektu tymczasowego
    /* Wykorzystanie metody mnozacej dwie liczby zespolone, metody sprzezajacej liczbe zespolona i automatycznie generowanego przez kompilator przeciazenia operatora przypisania */
    obiekt=*this*~l;
    double dzielnik=pow(l.real,2)+pow(l.img,2); // stworzenie dzielnika z drugiej liczby zespolonej
    obiekt.real/=dzielnik; // obliczenie skladowej rzeczywistej
    obiekt.img/=dzielnik; // obliczenie skladowej urojonej
    return(obiekt); //zwrocenie nowego obiektu
}

/* Metoda porownujaca ze soba dwie liczby zespolone */
bool Liczba::operator==(const Liczba & l)const
{
    if(real==l.real&&img==l.img) // porownanie obu skladowych
        return(true); // zwrocenie prawdy jesli rowne
    else
        return(false); // zwrocenie falszu jesli rozne
}

/* Metoda przeciazajaca operator << dla liczby zepsolonej */
std::ostream & operator<<(std::ostream & o,const Liczba & l)
{
    if(l.get_img()<0) // jesli czesc urojona jest ujemna
        o << "(" << l.get_real() << l.get_img() << "i)";
    if(l.get_img()>=0) // jesli czesc urojona jest >= 0
        o << "(" << l.get_real() << "+" << l.get_img() << "i)";
    return(o); // zwrocenie obiektu klasy ostream
}
/* Metoda przeciazajaca operator >> dla liczby zespolonej i sprawdzajca poprawnosc jej zapisu */
std::istream & operator >> (std::istream & i, Liczba & l)
{
    double re,im;
    char znak;
    while(i.peek()=='\n'||i.peek()==' ') // jesli sa znaki biale
        i.get(); // pobranie ich
    if(i.peek()=='~') // jesli wystepuje sprzezenie
        i.get(znak); // pobranie znaku sprzezenia w celu jego pozniejszego wykonania
    if(i.get()!='(') // jesli kolejny znak nie jest '('
        i.setstate(std::ios::failbit); // ustawienie flagi bledu
    i >> re; // pobranie liczby typu double
    i >> im; // pobranie liczby typu double
    if(i.get()!='i') // jesli kolejny znak nie jest 'i'
        i.setstate(std::ios::failbit); // ustawienie flagi bledu
    if(i.get()!=')') // Jesli kolejny znak nie jest '('
        i.setstate(std::ios::failbit); // ustawienie flagi bledu
    if(i.peek()=='\n'||i.peek()==' ') // jesli sa znaki biale
        i.get(); // pobranie ich
    if(!i.fail()) // jesli nie ustawiono flagi bledu
    {
        if(znak=='~') // jesli wykonano sprzezenie
            l=Liczba(re,-im); // stworzenie liczby za pomoca konstruktora
        else // bez sprzezenia
            l=Liczba(re,im); //stworzenie liczby za pomoca konstruktora
    }
    return(i); // zwrocenie obiektu klasy istream
}

/* Funkcja sprawdzajaca poprawnosc argumentow wywolania programu oraz poprawnosc pliku*/
void sprawdzenie_argumentow(const int & n, char *tab[], std::ifstream & plik)
{
    std::string napis;
    if(n<2) lista_bledow(1); // jesli za malo argumentow wywolania
    if(n>2) lista_bledow(2); // jesli za duzo argumtentow wywolania
    napis=argv[1]; // zapisanie nazwy pliku
    napis+=".txt"; // dodanie rozszerzenia '.txt'
    plik.open(napis); // otwarcie pliku
    if(!plik.is_open) // sprawdzenie poprawnosci otwarcia pliku
        lista_bledow(3); // blad otwarcia
    return(0); // zero w przypadku poprawnosci sprawdzenia argumentow
}

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
        cerr << "Blad zapisu. Wyrazenie zostalo pominiete" << endl; break; // komunikat
    }
}