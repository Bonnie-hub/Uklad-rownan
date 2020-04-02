#ifndef WEKTOR_HH
#define WEKTOR_HH


#include <cmath>
#include <iostream>



class Wektor {

	int Wymiar;
  	double *dane;
  	public:

	Wektor(int Wymiar); //konstruktor tworzący pustą tablicę z wymiarem podanym jako argument
	Wektor(double *tab, int Wymiar); //konstruktor tworzy nowy wektor wartościach w tablicy i wymiarach podanych
	Wektor(); //domyśnly wektor
	~Wektor();

	double dlugosc() const; //zwraca dlugość wektora jako liczbe

	double operator *(const Wektor & W2)const; //Iloczyn skalarny, zwraca double
	const Wektor operator +(const Wektor & W2)const; //Zwraca wektor który jest sumą dwóch
	const Wektor operator -(const Wektor & W2)const; //Zwraca wektor który jest różnicą dwóch
	
	const double & operator[] (int indeks)const; //odnoszenie się do poszczególnych pól
	double & operator[] (int indeks);
	int const & Pobierz_Wymiar() const; //zwraca rozmiar tablicy
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
