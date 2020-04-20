#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"


class Macierz { //wierszowa
	static const int Wiersz = ROZMIAR;
	Wektor tab[ROZMIAR];

  
  public:
	
	Macierz();
	Macierz(Wektor *tab);
	~Macierz();
	
	Macierz operator +(const Macierz & M)const; //Dodawanie macierzy
	Macierz operator -(const Macierz & M)const; //Odejmowanie macierzy
	Macierz operator *(const Macierz & M)const; //Mnożenie macierzy
	
	Wektor operator *(const Wektor W)const; //Mnożenie macierzy prze wektor
	
	Macierz transponowanie()const;
	void transponowanie();
	Macierz MacierzTrojk();
	//void inverse();
	
	double Wyznacznik_Gaussa() const;
	//Gauss, Laplace, Sarrus

	const Wektor Pobierz_Wektor(int indeks) const;
	int Pobierz_Wiersz() const; //Pobranie rozmiaru macierzy

	const Wektor & operator[] (int indeks) const; //odnoszenie się do poszczególnych pól
	Wektor & operator[] (int indeks);   
};

std::istream& operator >> (std::istream &Strm, Macierz &Mac); //Wpisywanie

std::ostream& operator << (std::ostream &Strm, const Macierz &Mac); //Odczyt


#endif
