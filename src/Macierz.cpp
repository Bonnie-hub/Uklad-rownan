#include "Macierz.hh"

Macierz::Macierz()
{
        for(int i=0; i<Wiersz; i++)
        {
            tab[i] = Wektor();
        }
}

Macierz::Macierz(Wektor *Nowy)
{
    for(int k=0; k < Wiersz; k++)
    {
        tab[k] = Nowy[k];
    }
}

Macierz::~Macierz()
{
    //delete[] tab;
}

const Wektor & Macierz::operator[] (int indeks)const
{
    if(indeks <= Wiersz)
        return tab[indeks];
    else
    {
        std::cerr << "Indeks wykracza poza tablicę" << std::endl;
        exit(1);
    }
    
}

Wektor & Macierz::operator[] (int indeks)
{
    if(indeks <= Wiersz)
        return tab[indeks];
    else
    {
        std::cerr << "Indeks wykracza poza tablicę" << std::endl;
        exit(1);
    }
}

Macierz Macierz::operator +(const Macierz & M)const
{
    if(Wiersz == M.Wiersz && 
    tab[0].Pobierz_Wymiar() == M[0].Pobierz_Wymiar())
    {

        Macierz dodaj;
        for(int i=0; i<Wiersz; i++)
        {
            dodaj[i] = tab[i] + M[i];    
        }
        return dodaj;
    }
    else
    {
        std::cout << "Macierze różnych rozmiarów" << std::endl;
        exit(1);
    }
}

Macierz Macierz::operator -(const Macierz & M)const
{
    if(Wiersz == M.Wiersz && 
    tab[0].Pobierz_Wymiar() == M[0].Pobierz_Wymiar())
    {
        Macierz odejmij;
        for(int i=0; i<Wiersz; i++)
        {
            odejmij[i] = tab[i] - M[i];
        }
        return odejmij;
    }
    else
    {
        std::cout << "Macierze różnych rozmiarów" << std::endl;
        exit(1);
    }
}

Macierz Macierz::operator *(const Macierz & M)const
{
    Macierz mnozenie;
    if(tab[0].Pobierz_Wymiar() == M.Wiersz)
    {
        for(int i=0; i<M.Wiersz; i++)
        {
            for(int j=0; j<M[0].Pobierz_Wymiar(); j++)
            {
                mnozenie[i][j] = tab[i] * M.Pobierz_Wektor(j);
            }
        }
        return mnozenie;
    }
    else
    {
        std::cerr << "Niezgodne wymiary macierzy" << std::endl;
        exit(1);
    }
}

Wektor Macierz::operator *(const Wektor W)const
{
    if(Wiersz == W.Pobierz_Wymiar())
    {
        Wektor mnozenie;
        for(int i=0; i<Wiersz; i++)
        {
            mnozenie[i] = tab[i]*W;
        }
        return mnozenie;
    }
    else
    {
        std::cerr << "Nieprawidłowe rozmiary" << std::endl;
        exit(1);
    }
    
}

const Wektor Macierz::Pobierz_Wektor(unsigned int indeks) const
{
    if(indeks <= tab[0].Pobierz_Wymiar()){
        double *Pom = new double[Wiersz];
        for(int i=0; i<Wiersz; i++)
        {
            Pom[i] = tab[i][indeks];
        }
        return Wektor(Pom);
    }
    else
    {
        std::cerr << "Indeks wykracza poza tablicę" << std::endl;
        exit(1);
    }
}

int Macierz::Pobierz_Wiersz() const
{
    return Wiersz;
}

void Macierz::transponowanie()
{
    Macierz Pom = *this;
    for(int i=0; i<tab[i].Pobierz_Wymiar(); i++)
    {
        tab[i] = Pom.Pobierz_Wektor(i);
    }
}

Macierz Macierz::transponowanie()const
{
    Macierz transpozycja;
    for(int i=0; i<tab[0].Pobierz_Wymiar(); i++)
    {
        transpozycja[i] = (*this).Pobierz_Wektor(i);
    }
    return transpozycja;
}

Macierz Macierz::MacierzTrojk()
{
    Macierz kopia = *this;
    for(int i=0; i<Wiersz; i++)//Przestawianie wierszy
        {
            if(fabs(kopia.tab[i][i]) < E)
            {
                int j;
                for(j=i; j<Wiersz; j++)
                {

                    if(fabs(kopia.tab[j][i]) > E)
                    {
                        Wektor Pom = kopia.tab[i]; 
                        kopia.tab[i] = kopia.tab[j];
                        kopia.tab[j] = Pom;
                        break;
                    }
                }
                if(j == Wiersz)
                    {
                        std::cerr << "Wyznacznik macierzy rowny zero" << std::endl;
                        exit(1);
                    }
            }
            for(int j=i+1; j<Wiersz; j++)
            {
                if(fabs(kopia.tab[j][i]) < E)
                    continue;
                double wielokrotnosc = kopia.tab[j][i]/kopia.tab[i][i];
                kopia.tab[j] -= kopia.tab[i] * wielokrotnosc;
                
            }
        }
    return kopia;
}

double Macierz::Wyznacznik_Gaussa() const
{
    double det = 1.0;
    Macierz M = *this;
    if(Wiersz != tab[0].Pobierz_Wymiar())
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
        return tab[0][0] * tab[1][1] - tab[0][1] * tab[1][0];
    }
    else
    {
        for(int i=0; i<M.Wiersz; i++)//Przestawianie wierszy
        {
            if(fabs(M.tab[i][i]) < E)
            {
                int j;
                for(j=i; j<M.Wiersz; j++)
                {

                    if(fabs(M.tab[j][i]) > E)
                    {
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
                M.tab[j] -= M.tab[i] * wielokrotnosc;
                
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
        for(int j=0; j<Mac[0].Pobierz_Wymiar(); j++)
        {
            if(j < Mac[0].Pobierz_Wymiar() - 1)
            Strm << Mac[i][j] << ", ";
            else
            Strm << Mac[i][j];
        }
        Strm << " |" << std::endl;
    }
    return Strm;
}