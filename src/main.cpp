#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{

UkladRownanLiniowych Rownanie;
cin >> Rownanie;
cout << "Równanie liniowe postaci: " << endl << Rownanie << endl;
Wektor WektorWynik = Rownanie.Solve();
cout << "Rozwiązanie: " << endl << WektorWynik << endl;
Wektor WektorBledu = Rownanie.GetMatrix()*WektorWynik - Rownanie.GetVector();
cout << "Wektor błędu: " << endl << WektorBledu << endl;
cout << "Długość wektora błędu: " << endl <<  WektorBledu.dlugosc() << endl;
}
