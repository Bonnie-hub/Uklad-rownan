#include "Wektor.hh"

Wektor::Wektor(int n)
{
    Wymiar = n;
    dane = new double[Wymiar];
    for(int i=0; i<Wymiar; i++)
        dane[i] = 0.00;
}

Wektor::Wektor(double const *tab, int const n)
{
    Wymiar = n;
    dane = new double[Wymiar];
    for(int i=0; i<Wymiar; i++)
    {
        dane[i] = tab[i];
    }
}

Wektor::Wektor()
{
    Wymiar = 0;
    dane = new double[Wymiar];
}

Wektor::~Wektor()
{
    delete[] dane;
}

const double & Wektor::operator[] (int indeks) const
{
    return dane[indeks];
}

double & Wektor::operator[] (int indeks)
{
    return dane[indeks];
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

const Wektor Wektor::operator +(const Wektor & W2)const
{
    if(W2.Wymiar == Wymiar)
    {
        double *dodaj = new double[Wymiar];

        for(int i=0; i<Wymiar; i++)
        {
            dodaj[i] = 0;
            dodaj[i] = W2[i] + dane[i]; 
        }
    return Wektor(dodaj, Wymiar);
    }
    else
    {
        std::cout << "Wektory o innych wymiarach" << std::endl;
        exit(1);
    }
}

const Wektor Wektor::operator -(const Wektor & W2)const
{
    if(W2.Wymiar == Wymiar)
    {
        double *odejmij = new double[Wymiar];

        for(int i=0; i<Wymiar; i++)
        {
            odejmij[i] = 0;
            odejmij[i] = dane[i] - W2[i]; 
        }
    return Wektor(odejmij, Wymiar);
    }
    else
    {
        std::cout << "Wektory o innych wymiarach" << std::endl;
        exit(1);
    }
}

int const & Wektor::Pobierz_Wymiar()const
{
    return Wymiar;
}

double const & Wektor::Pobierz_dane() const
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
    Strm << "[";
    for(int i=0; i<Wek.Pobierz_Wymiar(); i++)
    {
        Strm << Wek[i] << ", ";
    }   
    Strm << "]" << std::endl;
    return Strm;
}