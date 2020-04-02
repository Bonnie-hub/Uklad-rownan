#include "Macierz.hh"

/*
Macierz::Macierz(Wektor W1, Wektor W2, Wektor W3)
{
    tab = new Wektor []
   if(W1.Pobierz_Wymiar == W2.Pobierz_Wymiar && W1.Pobierz_Wymiar == W3.Pobierz_Wymiar)
   tab[0] = &W1;
   tab[1] = &W2;
   tab[2] = &W3;
}//troszkę zabawny konstruktor
*/
Macierz::Macierz(int wiersz, int Wymiar)
{
    Wiersz = Wiersz;
    tab = new Wektor[Wiersz];
        for(int i=0; i<Wiersz; i++)
        {
            Wektor Nowy(Wymiar);
            tab[i] = Nowy;
        }
}
/*
Macierz::Macierz(const Wektor *Wektor)
{

}
*/
Macierz::~Macierz()
{
    delete[] tab;
}

const Wektor & Macierz::operator[] (int indeks)const
{
    return tab[indeks];
}

Wektor & Macierz::operator[] (int indeks)
{
    return tab[indeks];
}

const Macierz Macierz::operator +(const Macierz & M)const
{
    if(Wiersz == M.Wiersz && 
    tab[0].Pobierz_Wymiar() == M[0].Pobierz_Wymiar())
    {

        Macierz dodaj(Wiersz, M[0].Pobierz_Wymiar());
        for(int i=0; i<Wiersz; i++)
        {
            for(int j=0; j<M[0].Pobierz_Wymiar(); j++)
            {
                dodaj[i][j] = (*this)[i][j] + M[i][j];
            }
        }
        return dodaj;
    }
    else
    {
        std::cout << "Macierze różnych rozmiarów" << std::endl;
        exit(1);
    }
}

const Macierz Macierz::operator -(const Macierz M)const
{
    if(Wiersz == M.Wiersz && 
    tab[0].Pobierz_Wymiar() == M[0].Pobierz_Wymiar())
    {
        Macierz odejmij(Wiersz, M[0].Pobierz_Wymiar());
        for(int i=0; i<Wiersz; i++)
        {
            for(int j=0; j<M[0].Pobierz_Wymiar(); j++)
            {
                odejmij[i][j] = (*this)[i][j] - M[i][j];
            }
        }
        return odejmij;
    }
    else
    {
        std::cout << "Macierze różnych rozmiarów" << std::endl;
        exit(1);
    }
    
}

const Wektor Macierz::Pobierz_Kolumne(int indeks) const
{
    double Pom[Wiersz];
    for(int i=0; i<Wiersz; i++)
    {
        Pom[i] = (*this)[i][indeks];
    }
    return Wektor(Pom, Wiersz);
}

void Macierz::transpozycja()
{
    Macierz Pom = *this;
    for(int i=0; i<tab[i].Pobierz_Wymiar(); i++)
    {
        (*this)[i] = Pom.Pobierz_Kolumne(i);
    }
}

const Macierz Macierz::transpozycja(const Macierz M)const
{
    Macierz transpozycja(M[0].Pobierz_Wymiar(), Wiersz);
    for(int i=0; i<M[0].Pobierz_Wymiar(); i++)
    {
        for(int j=0; j<Wiersz; j++)
        {
            transpozycja[j][i] = M[i][j];
        }
    }
    return transpozycja;
}