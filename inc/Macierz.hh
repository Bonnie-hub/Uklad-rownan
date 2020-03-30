#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Macierz { //wierszowa
	Wektor tab[Rozmiar];
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  public:
	
	Macierz();
	Macierz(/*9 double*/);
	Macierz(/*3 wektory*/);
	
	const Macierz & operator +(const Macierz & W)const;
	const Macierz & operator -(const Macierz & W)const;
	const Macierz & operator *(const Macierz & W)const;
	
	const Wektor & operator *(const Wektor & W)const;
	
	const Macierz & transpozycja(const Macierz & W)const;
	void transpozycja();
	
	double Wyznacznik() const;
	//Gauss, Laplace, Sarrus
	
	const double & operator[] (int indeks) const; //odnoszenie się do poszczególnych pól
	double & operator[] (int indeks);
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */    
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, Macierz &Mac);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);


#endif
