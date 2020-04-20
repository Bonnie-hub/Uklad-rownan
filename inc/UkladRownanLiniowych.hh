#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Macierz.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class UkladRownanLiniowych {
  Macierz macierz;
  Wektor wektor;
  public:
  UkladRownanLiniowych ();
  UkladRownanLiniowych (const Macierz & M1, const Wektor & W1);
  ~UkladRownanLiniowych ();

  Wektor & GetVector();
  Macierz & GetMatrix();
  Wektor Solve() const;
};

std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);


std::ostream& operator << ( std::ostream                  &Strm,
                            UkladRownanLiniowych    &UklRown
                          );


#endif
