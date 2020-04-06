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
    Wiersz = wiersz;
    Kolumna = Wymiar;
    tab = new Wektor[Wiersz];
        for(int i=0; i<Wiersz; i++)
        {
            Wektor Nowy(Wymiar);
            tab[i] = Nowy;
        }
}

Macierz::Macierz(double **tablica, int const wiersz, int const kolumna)
{
    Wiersz = wiersz;
    Kolumna = kolumna;
    tab = new Wektor(Wiersz);
    for (int k=0; k < Wiersz; k++)
    {
        Wektor Nowy(Kolumna);
        tab[k] = Nowy;
    }
}

Macierz::~Macierz()
{
    //delete[] tab;
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

const Wektor Macierz::Pobierz_Wektor(int indeks) const
{
    double *Pom = new double[Wiersz];
    for(int i=0; i<Wiersz; i++)
    {
        Pom[i] = (*this)[i][indeks];
    }
    return Wektor(Pom, Wiersz);
}

const int Macierz::Pobierz_Wiersz() const
{
    return Wiersz;
}

const int Macierz::Pobierz_Kolumne() const
{
    return Kolumna;
}

void Macierz::transponowanie()
{
    Macierz Pom = *this;
    for(int i=0; i<tab[i].Pobierz_Wymiar(); i++)
    {
        (*this)[i] = Pom.Pobierz_Wektor(i);
    }
}

const Macierz Macierz::transponowanie(const Macierz M)const
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

double Macierz::Wyznacznik_Gaussa() const
{
    double det = 1.0;
    Macierz M = *this;
    if(Wiersz != Kolumna)
    {
        std::cerr << "Macierz nie kwadratowa" << std::endl;
        exit(1);
    }
    else if(Wiersz == 1)
    {
        return tab[0][0];
    }
    else if(Wiersz == 2)
    {
        return (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];
    }
    else
    {
        for(int i=0; i<M.Wiersz; i++)//Przestawianie wierszy
        {
            if(fabs(M.tab[i][i]) < E)
            {
                int j=1;
                for(int j; j<M.Wiersz; j++)
                {
                    if(fabs(M.tab[j][i]) > E)
                    {
                        //Wektor Pom(&tab[i].Pobierz_dane(), Kolumna);
                        Wektor Pom = M.tab[i]; 
                        M.tab[i] = M.tab[j];
                        M.tab[j] = Pom;
                        det = -det;
                        break;
                    }
                }
                if(j == Wiersz)
                    {
                        det = 0;
                        return det;
                    }
            }
            for(int j=i+1; j<M.Wiersz; j++)
            {
                if(fabs(M.tab[j][i]) < E)
                    continue;
                double wielokrotnosc = M.tab[j][i]/M.tab[i][i];
                for(int k=i+1; j<M.Wiersz; j++)
                M.tab[j][k] -= wielokrotnosc * M.tab[i][k];
            }
        }
        for(int i=0; i<M.Wiersz; i++)
            det *= M[i][i];
        return det;
    }

}

std::istream& operator >> (std::istream &Strm, Macierz &Mac)
{
    for(int i=0; i<Mac.Pobierz_Wiersz(); i++)
    {
        std::cout << "Wiersz: " << i+1 << std::endl;
        for(int j=0; j<Mac[i].Pobierz_Wymiar(); j++)
        {
            Strm >> Mac[i][j];
        }
    }
    return Strm;
}

std::ostream& operator << (std::ostream &Strm, const Macierz &Mac)
{
    for(int i=0; i<Mac.Pobierz_Wiersz(); i++)
    {
        Strm << "| ";
        for(int j=0; j<Mac[i].Pobierz_Wymiar(); j++)
        {
            Strm << Mac[i][j] << ", ";
        }
        Strm << " |" << std::endl;
    }
    return Strm;
}