#include <iostream>
#include <fstream>
#include "zesp.h" // dolacznie klasy Liczba oraz funkcji sprawdzajacych poprawnosc argumentow wywolania programu

int main(int argc, char *argv[])
{   
    using std::endl;
    using std::cout;
    using std::cin;
    std::ifstream plik;
    Liczba one,two,answer,result; // stworzenie potrzebnych obiektow klasy Liczba
    char znak; // zmienna do przechowywania znaku operacji do wykonania
    double razem=0,poprawne=0; // zmienne do przechowywnia statystyk odpowiedzi  
    sprawdzenie_argumentow(argc,argv,plik); // sprawdzenie poprawnosci argumentow wywolania programu oraz poprawnosci pliku
    while (plik.peek()!=EOF) // jesli nie jest ustawiona flaga bledu
    {
        plik >> one >> znak >> two; // wczytanie dwoch liczb i znaku operacji
        if(!plik.fail()) // jesli nie wykryto flagi bledu
        {
            switch(znak) // rozpozanie znaku operacji do wykonania
            {
                case '+': // dodawanie
                result=one+two; break; // przypisanie wyniku do obiektu result
                case '-': // odejmowanie
                result=one-two; break; // przypisanie wyniku do obiektu result
                case '*': // mnozenie
                result=one*two; break; // przypisanie wyniku do obiektu result
                case '/': // dzielenie
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
                poprawne++; // zaktualizowanie licznika poprawnych odpowiedzi
            }
            else // jesli odpowiedz jesy bledna
                cout << ":( Blad. Prawidlowym wynikiem jest: " << result << endl;
            cout << endl;
            razem++; // zaktualizowanie liczby wszystkich odpowiedzi
        }
        else // jesli wykryto flage bledu
        {
            plik.clear(); // wyczyszczenie flagi bledu
            plik.ignore(10000,'\n'); // zignorowanie pozostalosci linii pliku
            lista_bledow(4); // wyswietlenie komunikatu o zignorowaniu danej linii
        }
    }
    cout << "Koniec testu" << endl << endl;
    cout << "Ilosc dobrych odpowiedzi: " << poprawne << endl;
    cout << "Ilosc blednych odpowiedzi: " << razem << endl; 
    cout << "Wynik procentowy poprawnych odpowiedzi : " << (poprawne/razem)*100 << "%" << endl; // procentowy wynik poprawnosci odpowiedzi
    plik.close(); // zamkniecie pliku
    return(0);
}
