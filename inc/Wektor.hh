#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor {
  double dane[WYMIAR];
  public:
	Wektor();
	Wektro(double x, double y, double z); //kontruktor od kolekcji
	double dlugosc(); const
	double operator *(const Wektor &W2) const; 
	const Wektor & operator +(const Wekror &W2) const;
	const Wektor & operator -(const Wektor &W2) const;
	
	const double & operator[] (int indeks) const; //odnoszenie się do poszczególnych pól
	double & operator[] (int indeks);
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */    
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
