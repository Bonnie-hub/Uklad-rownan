#ifndef WEKTOR_HH
#define WEKTOR_HH
#define E 0.0000001  
#define ROZMIAR 3

#include <cmath>
#include <iostream>
#include <iomanip>

class Wektor {

	static const int Wymiar = ROZMIAR;
  	double dane[ROZMIAR];
  	public:

	Wektor(); //konstruktor tworzący pustą tablicę z wymiarem podanym jako argument
	Wektor(double const *tab); //konstruktor tworzy nowy wektor wartościach w tablicy i wymiarach podanych
	~Wektor();

	double dlugosc() const; //zwraca dlugość wektora jako liczbe

	double operator *(const Wektor & W2)const; //Iloczyn skalarny, zwraca double
	Wektor operator +=(const Wektor & W2); //Dodanie wektora do wektora
	Wektor operator +(const Wektor & W2)const; //Zwraca wektor który jest sumą dwóch
	Wektor operator -=(const Wektor & W2); //Odjęcie wektora od wektora
	Wektor operator -(const Wektor & W2)const; //Zwraca wektor który jest różnicą dwóch
	Wektor operator *(const double & stala)const; //Wektor razy liczba

	const double & operator[] (int indeks)const; //odnoszenie się do poszczególnych pól
	double & operator[] (int indeks);
	int Pobierz_Wymiar() const; //zwraca rozmiar tablicy
	const double & Pobierz_dane() const; //Zwraca tablicę double
};

std::istream& operator >> (std::istream &Strm, Wektor &Wek);

std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);

#endif
