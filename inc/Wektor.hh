#ifndef WEKTOR_HH
#define WEKTOR_HH
#define E 0.0000001  
#define ROZMIAR 3

#include <cmath>
#include <iostream>
#include <iomanip>

class Wektor {

	static const int Wymiar = ROZMIAR;
  	double dane[Wymiar];
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

	const double & operator[] (unsigned int indeks)const; //odnoszenie się do poszczególnych pól
	double & operator[] (unsigned int indeks);
	int Pobierz_Wymiar() const; //zwraca rozmiar tablicy
	const double & Pobierz_dane() const;
};
//ostream operator << (ostream & strm, const Wektor & W);
//istream operator >> (istream & strm, const Wektor & W);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, Wektor &Wek);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);

#endif
