#include "Macierz.hh"

/*
Macierz::Macierz(Wektor W1, Wektor W2, Wektor W3)
{
    tab = new Wektor []
   if(W1.Jaki_Wymiar == W2.Jaki_Wymiar && W1.Jaki_Wymiar == W3.Jaki_Wymiar)
   tab[0] = &W1;
   tab[1] = &W2;
   tab[2] = &W3;
}//troszkę zabawny konstruktor
*/
Macierz::Macierz(int wiersz, int Wymiar)
{
    Wiersz = wiersz;
    tab = new Wektor [Wiersz];
    //Wektor W1(Wymiar), W2(Wymiar), W3(Wymiar);
        for(int i=0; i<Wiersz; i++)
        {
            Wektor W(Wymiar);
            tab[i] = W;
        }
}

Macierz::~Macierz()
{
    delete[] tab;
}

const Wektor & Macierz::operator[] (int indeks) const
{
    return this->tab[indeks];
}

const Macierz & Macierz::operator +(const Macierz M)const
{
    Macierz dodaj(Wiersz, M[0].Jaki_Wymiar());
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<M[0].Jaki_Wymiar(); j++)
        {
            dodaj[i][j] = M[i][j] + (*this)[i][j];
        }
    }
    return dodaj;
}

const Macierz & Macierz::operator -(const Macierz M)const
{
    Macierz odejmij(Wiersz, M[0].Jaki_Wymiar());
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<M[0].Jaki_Wymiar(); j++)
        {
            odejmij[i][j] = M[i][j] - (*this)[i][j];
        }
    }
    return odejmij;
}

const Macierz & Macierz::transpozycja(const Macierz M)const
{
    Macierz transpozycja(M[0].Jaki_Wymiar(), Wiersz);
    for(int i=0; i<M[0].Jaki_Wymiar(); i++)
    {
        for(int j=0; j<Wiersz; j++)
        {
            transpozycja[j][i] = M[i][j];
        }
    }
    return transpozycja;
}

