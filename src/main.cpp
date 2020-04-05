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
  //UkladRownanLiniowych   UklRown;   // To tylko przykladowe definicje zmiennej
  double **tab = new double*[2];// = {{3,2,1},{7,2,1},{9,6,9}};
for(int i=0; i<2; i++)
{
  tab[i] = new double[2];
  for(int j=0; j<2; j++)
    tab[i][j] = i/(i+j+3)*2.5;  
}
  Macierz Pom(tab, 2,2);
  cout << Pom << endl;
  


  double det = Pom.Wyznacznik_Gaussa();
  cout << "Wyznacznik " << det << endl;

  
  //cin >> Pom;
  //cout << Pom <<endl;
  /*
  Wektor W1(3);
  cin >> W1;
  cout << W1 << endl;
  Wektor W4[3] = {W1,W2,W3};
  Macierz M1(W4,3,3);
  double det = M1.Wyznacznik_Gaussa();
  cout << "Wyznacznik " << det << endl;
  //cout << "Wektor 2 " << M1[1] << endl;
  //cout << "Wektor 3 " << M1[2] << endl;
  //double det;
  //det = M1.Wyznacznik_Gaussa();
  //cout << det << endl;
  
  //cout << endl << " Start programu " << endl << endl;
  */
}
