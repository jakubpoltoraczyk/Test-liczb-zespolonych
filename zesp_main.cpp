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
    Liczba one,two,answer,result; // stworzenie potrzebnych obiektow klasy Liczba
    Statystyka dane;
    Operator znak; // zmienna do przechowywania znaku operacji do wykonania
    sprawdzenie_argumentow(argc,argv,plik); // sprawdzenie poprawnosci argumentow wywolania programu oraz poprawnosci pliku
    while (plik.peek()!=EOF) // jesli nie wykryto znaku konca pliku
    {
        plik >> one >> znak >> two; // wczytanie dwoch liczb i znaku operacji
        plik.get();
        if(!plik.fail()) // jesli nie wykryto flagi bledu
        {
            switch(znak) // rozpozanie znaku operacji do wykonania
            {
                case plus: // dodawanie
                result=one+two; break; // przypisanie wyniku do obiektu result
                case minus: // odejmowanie
                result=one-two; break; // przypisanie wyniku do obiektu result
                case mnoz: // mnozenie
                result=one*two; break; // przypisanie wyniku do obiektu result
                case dziel: // dzielenie
                result=one/two; break; // przypisanie wyniku do obiektu result
            }
            cout << ":? Podaj wynik operacji: ";
            cout << one << " " << znak << " " << two << endl; // wyswietlenie dzialania
            cout << "   Twoja odpowiedz: ";
            cin >> answer; // pobranie odpowiedzi od uzytkownika
            for(int n=0;cin.fail()&&n<2;++n) // jesli jest ustawiona flaga bledu z powodu niepoprawanego zapisu oraz licznych prob mniejszy od 3 prob
            {
                cin.clear(); // wyczyszczenie flagi bledu
                cin.ignore(10000,'\n'); // zignorowanie pozostalosci linii pliku
                cout << "Blad zapisu. Sprobuj jeszcze raz: " << endl;
                cout << "   Twoja odpowiedz: ";
                cin >> answer; // ponowne podanie odpowiedzi
            }
            if(answer==result) // jesli odpowiedz jest poprawna
            {
                cout << ":) Odpowiedz poprawna" << endl;
                dane.dodaj_pop(); // zaktualizowanie licznika poprawnych odpowiedzi
            }
            else // jesli odpowiedz jest bledna
                cout << ":( Blad. Prawidlowym wynikiem jest: " << result << endl;
            cout << endl;
            dane.dodaj_suma(); // zaktualizowanie liczby wszystkich odpowiedzi
        }
        else // jesli wykryto flage bledu
        {
            plik.clear(); // wyczyszczenie flagi bledu
            plik.ignore(10000,'\n'); // zignorowanie pozostalosci linii pliku
            lista_bledow(4); // wyswietlenie komunikatu o zignorowaniu danej linii
        }
    }
    cout << "Koniec testu" << endl << endl;
    cout << "Ilosc dobrych odpowiedzi: " << dane.get_pop() << endl;
    cout << "Ilosc blednych odpowiedzi: " << dane.get_zle() << endl; 
    cout << "Wynik procentowy poprawnych odpowiedzi : " << dane.get_procent() << "%" << endl; 
    plik.close(); // zamkniecie pliku
    return 0;
}
