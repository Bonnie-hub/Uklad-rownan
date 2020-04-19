#include "Wektor.hh"

Wektor::Wektor()
{
    for(int i=0; i<Wymiar; i++)
        dane[i] = 0.00;
}

Wektor::Wektor(double const *tab)
{
    for(int i=0; i<Wymiar; i++)
    {
        dane[i] = tab[i];
    }
}

Wektor::~Wektor()
{}

const double & Wektor::operator[] (unsigned int indeks) const
{
    if(indeks <= Wymiar)
        return dane[indeks];
    else
    {
        std::cerr << "Indeks wykracza poza tablicę" << std::endl;
        exit(1);
    }
}

double & Wektor::operator[] (unsigned int indeks)
{
    if(indeks <= Wymiar)
        return dane[indeks];
    else
    {
        std::cerr << "Indeks wykracza poza tablicę" << std::endl;
        exit(1);
    }
}

double Wektor::dlugosc() const
{
    double suma = 0;
    for(int i=0; i<Wymiar; i++)
    {
        suma += pow(dane[i],2);
    }

    return sqrt(suma);
}

double Wektor::operator *(const Wektor & W2)const
{
    double skalar = 0.00;
    for (int i=0; i < Wymiar; i++)
    {
        skalar += W2[i]*dane[i];
    }
    return skalar;
}

Wektor Wektor::operator *(const double & stala)const
{
    Wektor mnozenie;
    for(int i=0; i<Wymiar; i++)
    {
        mnozenie[i] = stala * dane[i];
    }
    return mnozenie;
}

Wektor Wektor::operator +=(const Wektor & W2)
{
    *this = *this + W2;
    return *this;
}

Wektor Wektor::operator +(const Wektor & W2)const
{
    if(W2.Wymiar == Wymiar)
    {
        double *dodaj = new double[Wymiar];

        for(int i=0; i<Wymiar; i++)
        {
            dodaj[i] = 0;
            dodaj[i] = W2[i] + dane[i]; 
        }
    return Wektor(dodaj);
    }
    else
    {
        std::cout << "Wektory o innych wymiarach" << std::endl;
        exit(1);
    }
}

Wektor Wektor::operator -=(const Wektor & W2)
{
    *this = *this - W2;
    return *this;
}

Wektor Wektor::operator -(const Wektor & W2)const
{
    if(W2.Wymiar == Wymiar)
    {
        double *odejmij = new double[Wymiar];

        for(int i=0; i<Wymiar; i++)
        {
            odejmij[i] = 0;
            odejmij[i] = dane[i] - W2[i]; 
        }
    return Wektor(odejmij);
    }
    else
    {
        std::cout << "Wektory o innych wymiarach" << std::endl;
        exit(1);
    }
}

int Wektor::Pobierz_Wymiar()const
{
    return Wymiar;
}

const double & Wektor::Pobierz_dane() const
{
    return *dane;
}

std::istream& operator >> (std::istream &Strm, Wektor &Wek)
{
    for(int i=0; i<Wek.Pobierz_Wymiar(); i++)
    {
        Strm >> Wek[i];
    }
    return Strm;
}

std::ostream& operator << (std::ostream &Strm, const Wektor &Wek)
{
    Strm << "|";
    for(int i=0; i<Wek.Pobierz_Wymiar(); i++)
    {
        if(i != Wek.Pobierz_Wymiar()-1)
            Strm << Wek[i] << " ";
        else
            Strm << Wek[i];
        
    }   
    Strm << "|";
    return Strm;
}