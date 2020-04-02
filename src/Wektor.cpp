#include "Wektor.hh"

Wektor::Wektor(int n)
{
    Wymiar = n;
    dane = new double[Wymiar];
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

double & Wektor::operator[] (int indeks)
{
    return this->dane[indeks];
}

const double & Wektor::operator[] (int indeks) const
{
    return this->dane[indeks];
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

double & Wektor::operator *(Wektor W2)
{
    double suma = 0;
    for (int i=0; i < Wymiar; i++)
    {
        W2[i] += W2[i]*(*this)[i];
    }
    return suma;
}

const Wektor & Wektor::operator +(const Wektor W2) const
{
    if(W2.Wymiar == this->Wymiar)
    {
        Wektor dodaj(W2.Wymiar);

        for(int i=0; i<Wymiar; i++)
        {
            dodaj[i] = 0;
            dodaj[i] = W2[i] + (*this)[i]; 
        }
    return dodaj;
    }
    else
    {
        std::cout << "Wektory o innych wymiarach" << std::endl;
        exit(1);
    }
}

const Wektor & Wektor::operator -(const Wektor W2) const
{
    if(W2.Wymiar == this->Wymiar)
    {
        Wektor odejmij(Wymiar);

        for(int i=0; i<Wymiar; i++)
        {
            odejmij[i] = 0;
            odejmij[i] = W2[i] - (*this)[i]; 
        }
    return odejmij;
    }
    else
    {
        std::cout << "Wektory o innych wymiarach" << std::endl;
        exit(1);
    }
}

int const & Wektor::Jaki_Wymiar()const
{
    return this->Wymiar;
}