#include "zesp_fun.h" // dolaczenie klasy Liczba oraz funkcji z nia zwiazanych

/* Metoda sprzezajaca liczbe zespolona */
Liczba Liczba::operator~(void)const
{
    Liczba obiekt(real,-img);
    return obiekt;
}

/* Metoda dodajaca dwie liczby zespolone */
Liczba Liczba::operator+(const Liczba & l)const
{
    Liczba obiekt(real+l.real,img+l.img); // stworzenie nowego obiektu za pomoca konstruktora
    return obiekt; // zwrocenie nowego obiektu
}

/* Metoda odejmujaca od siebie dwie iczby zespolone */
Liczba Liczba::operator-(const Liczba & l)const
{
    Liczba obiekt(real-l.real,img-l.img); // stworzenie nowego obiektu za pomoca konstruktora
    return obiekt; // zwrocenie nowego obiektu
}

/* Metoda mnozaca dwie liczby zepsolone */
Liczba Liczba::operator*(const Liczba & l)const
{
    Liczba obiekt(real*l.real-img*l.img,real*l.img+img*l.real); // stworzenie nowego obiektu za pomoca konstruktora
    return obiekt; // zwrocenie nowego obiektu
}

/* Metoda dzielaca dwie liczby zepsolone */
Liczba Liczba::operator/(const Liczba & l)const
{
    Liczba obiekt=*this*~l;
    if(l.get_modul()!=0)
        obiekt=obiekt/l.get_modul();
    else
    {
        std::cerr << "Proba wykonania niedozwolonej operacji dzielenia przez zero - zamykam program\n";
        exit(0);
    }
    return obiekt; //zwrocenie nowego obiektu
}

/* Metoda dzielaca liczbe zepsolona przez liczbe typu double */
Liczba Liczba::operator/(const double & n)const
{
    Liczba obiekt(real/n,img/n);
    return obiekt;
}
/* Metoda porownujaca ze soba rownosc dwoch liczb zespolone */
bool Liczba::operator==(const Liczba & l)const
{
    double min = 0.00000001; // okreslenie dokladnosci porownania ze wzgledu na brak precyzji w dzialaniach dla liczb zmiennoprzecinkowych
    if(std::abs(real-l.real)<min&&std::abs(img-l.img)<min) // porownanie obu skladowych(czy sa rowne)
        return true; // zwrocenie prawdy jesli rowne
    else
        return false; // zwrocenie falszu jesli rozne
}

bool Liczba::operator!=(const Liczba &l)const
{
    return !(*this==l); // wykorzystanie operatora == do sprawdzenia czy sa rozne
}

/* Metoda przeciazajaca operator << dla liczby zespolonej */
std::ostream & operator<<(std::ostream & o,const Liczba & l)
{
    o << "(" << l.get_real() << std::showpos << l.get_img() << std::noshowpos << "i)"; // wypisanie liczby zespolonej
    return o; // zwrocenie obiektu klasy ostream
}

/* Metoda przeciazajaca operator >> dla liczby zespolonej i sprawdzajca poprawnosc jej zapisu */
std::istream & operator >> (std::istream & i, Liczba & l)
{
    double re,im;
    char znak; // zmienna do przechowywania znaku sprzezenia
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
    if(i.get()!=')') // Jesli kolejny znak nie jest ')'
        i.setstate(std::ios::failbit); // ustawienie flagi bledu
    if(!i.fail()) // jesli nie ustawiono flagi bledu
    {
        if(znak=='~') // jesli wykonano sprzezenie
            l=Liczba(re,-im); // stworzenie liczby za pomoca konstruktora
        else // bez sprzezenia
            l=Liczba(re,im); //stworzenie liczby za pomoca konstruktora
    }
    return i; // zwrocenie obiektu klasy istream
}