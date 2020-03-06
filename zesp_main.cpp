#include <iostream>
#include <fstream>
#include "zesp.h"

int main(int argc, char *argv[])
{   
    using std::endl;
    using std::cout;
    using std::cin;
    std::ifstream plik;
    Liczba one,two,answer,result;
    char znak;
    std::string napis;
    double razem=0,poprawne=0;
    sprawdzenie_argumentow(argc,argv);
    napis=argv[1];
    napis+=".txt";
    plik.open(napis);
    if(!plik.is_open())
        lista_bledow(3);
    while (plik.peek()!=EOF)
    {
        plik >> one >> znak >> two;
        if(!plik.fail())
        {
            switch(znak)
            {
                case '+':
                result=one+two; break;
                case '-':
                result=one-two; break;
                case '*':
                result=one*two; break;
                case '/':
                result=one/two; break;
            }
            cout << ":? Podaj wynik operacji: ";
            cout << one << " " << znak << " " << two << endl;
            cout << "   Twoja odpowiedz: ";
            cin >> answer;
            for(int n=0;cin.fail()&&n<2;++n)
            {
                cin.clear();
                cin.ignore(10000,'\n');
                cout << "Blad zapisu. Sprobuj jeszcze raz: " << endl;
                cout << "   Twoja odpowiedz: ";
                cin >> answer;
            }
            if(answer==result)
            {
                cout << ":) Odpowiedz poprawna" << endl;
                poprawne++;
            }
            else
                cout << ":( Blad. Prawidlowym wynikiem jest: " << result << endl;
            cout << endl;
            razem++;
        }
        else
        {
            plik.clear();
            plik.ignore(10000,'\n');
            lista_bledow(4);
        }
    }
    cout << "Koniec testu" << endl << endl;
    cout << "Ilosc dobrych odpowiedzi: " << poprawne << endl;
    cout << "Ilosc blednych odpowiedzi: " << razem << endl;
    cout << "Wynik procentowy poprawnych odpowiedzi : " << (poprawne/razem)*100 << "%" << endl;
    plik.close();
    return(0);
}
