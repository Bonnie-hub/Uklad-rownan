#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Macierz { //wierszowa
	int Wiersz, Kolumna;
	Wektor *tab;

  
  public:
	
	//Macierz(Wektor W1, Wektor W2, Wektor W3);
	Macierz(int Wiersz ,int Kolumna);
	Macierz(double **tab, int const wiersz, int const kolumna);
	~Macierz();
	
	const Macierz & operator +(const Macierz & M)const;
	const Macierz & operator -(const Macierz & M)const;
	const Macierz & operator *(const Macierz & M)const;
	
	const Wektor & operator *(const Wektor M)const;
	
	const Macierz & transponowanie(const Macierz & M)const;
	void transponowanie();
	
	double Wyznacznik_Gaussa() const;
	//Gauss, Laplace, Sarrus

	const Wektor Pobierz_Wektor(int indeks) const;
	int Pobierz_Wiersz() const;
	int Pobierz_Kolumne() const;

	const Wektor & operator[] (int indeks) const; //odnoszenie się do poszczególnych pól
	Wektor & operator[] (int indeks);
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
