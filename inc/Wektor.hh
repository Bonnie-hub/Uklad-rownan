#ifndef WEKTOR_HH
#define WEKTOR_HH


#include <cmath>
#include <iostream>



class Wektor {

	int Wymiar;
  	double *dane;
  	public:

	Wektor(int Wymiar);
	Wektor();
	~Wektor();

	double dlugosc() const;

	double & operator *(Wektor W2); //Do metod operatorów spróboj indeksów
	const Wektor & operator +(const Wektor W2) const; //Czyli wpierw napisz TO operato[]
	const Wektor & operator -(const Wektor W2) const;
	
	const double & operator[] (int indeks) const; //odnoszenie się do poszczególnych pól
	double & operator[] (int indeks); 

	int const & Jaki_Wymiar() const;
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
