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
        plik >> wyrazenie;
        if(plik.good()) // jesli nie wykryto flagi bledu
        {
            cout << ":? Podaj wynik operacji: " << wyrazenie << endl << "   Twoja odpowiedz: ";
            cin >> answer;
            for(int n=0;cin.fail()&&n<2;++n)
            {
                czysc(cin);
                cout << "   Blad zapisu - podaj jeszcze raz: ";
                cin >> answer;
            }
            if(cin.good()&&wyrazenie.check_answer(answer))
            {
                cout << ":) Poprawna odpowiedz" << endl << endl;
                dane.dodaj_pop();
            }
            else
            {
                cout << ":( Bledna odpowiedz" << endl;
                cout << "   Poprawna to: " << wyrazenie.get_answer() << endl << endl;
                if(cin.fail())czysc(cin);
            }
            dane.dodaj_suma();
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