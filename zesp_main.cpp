#include <iostream>
#include <fstream>
#include "zesp_fun.h" // dolaczenie klasy Liczba oraz funkcji z nia zwiazanych
#include "zesp_other.h" // dolaczenie klasy Statystyka oraz funkcji i elementow zwiazanych z obsluga programu

int main(int argc, char *argv[])
{   
    using std::endl;
    using std::cout;
    using std::cin;
    std::ifstream plik;
    Liczba one,two,answer;
    Statystyka dane;
    Pytanie wyrazenie;
    Operator znak; // zmienna do przechowywania znaku operacji do wykonania
    sprawdzenie_argumentow(argc,argv,plik); // sprawdzenie poprawnosci argumentow wywolania programu oraz poprawnosci pliku
    while (plik.peek()!=EOF) // jesli nie wykryto znaku konca pliku
    {
        plik >> wyrazenie; // pobranie z pliku pelnego wyrazenia
        if(plik.good()) // jesli nie wykryto flagi bledu
        {
            cout << ":? Podaj wynik operacji: " << wyrazenie << endl << "   Twoja odpowiedz: "; // wyswietlenie wyrazenia
            cin >> answer; // pobranie odpowiedzi od uzytkownika
            for(int n=0;cin.fail()&&n<2;++n) // jesli blad zapisu odpowiedzi mozliwosc jej dwukrotnej poprawy
            {
                czysc(cin);
                cout << "   Blad zapisu - podaj jeszcze raz: ";
                cin >> answer;
            }
            if(cin.good()&&wyrazenie.check_answer(answer)) // jesli nie bylo trzykrotnego bledu zapisu i odpowiedz jest poprawna
            {
                cout << ":) Poprawna odpowiedz" << endl << endl;
                dane.dodaj_pop(); // aktualizacja poprawnych odpowiedzi
            }
            else // jesli trzykrotny blad zapisu lub niepoprawna odpowiedz
            {
                cout << ":( Bledna odpowiedz" << endl;
                cout << "   Poprawna to: " << wyrazenie.get_answer() << endl << endl;
                if(cin.fail())czysc(cin); // zapobiegawczw wyczyszczenie strumienia
            }
            dane.dodaj_suma(); // zaktualizowanie liczby wszystkich pytan
        }
        else // jesli wykryto flage bledu
        {
            czysc(plik);
            lista_bledow(4); // wyswietlenie komunikatu o zignorowaniu danej linii
        }
    }
    cout << "Koniec testu" << endl << dane;
    plik.close(); // zamkniecie pliku
    return 0;
}