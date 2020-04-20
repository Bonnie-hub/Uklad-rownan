#include "UkladRownanLiniowych.hh"

UkladRownanLiniowych::UkladRownanLiniowych()
{
    Macierz M;
    Wektor W;
    macierz = M;
    wektor = W;
}

UkladRownanLiniowych::UkladRownanLiniowych(const Macierz & M1, const Wektor & W1)
{
    macierz = M1;
    wektor = W1;
}

UkladRownanLiniowych::~UkladRownanLiniowych ()
{

}

Wektor & UkladRownanLiniowych::GetVector()
{
    return wektor;
}
Macierz & UkladRownanLiniowych::GetMatrix()
{
    return macierz;
}

Wektor UkladRownanLiniowych::Solve() const
{
    Macierz kopiaM = macierz;
    Wektor kopiaW = wektor;
    for(int i=0; i<kopiaM.Pobierz_Wiersz(); i++)//Zerowanie macierzy poniżej przekątnej
    {
        if(fabs(kopiaM[i][i]) < E)
        {
            int j;
            for(j=i; j<kopiaM.Pobierz_Wiersz(); j++)
            {

                if(fabs(kopiaM[j][i]) > E)
                {
                    Wektor Pom = kopiaM[i]; 
                    double liczba = kopiaW[i];
                    kopiaM[i] = kopiaM[j];
                    kopiaW[i] = kopiaW[j];
                    kopiaM[j] = Pom;
                    kopiaW[j] = liczba;
                    break;
                }
            }
            if(j == kopiaM.Pobierz_Wiersz())
                {
                    std::cerr << "Wyznacznik macierzy rowny zero" << std::endl;
                    exit(1);
                }
        }
        for(int j=i+1; j<kopiaM.Pobierz_Wiersz(); j++)
        {
            if(fabs(kopiaM[j][i]) < E)
                continue;
            double wielokrotnosc = kopiaM[j][i]/kopiaM[i][i];
            kopiaM[j] -= kopiaM[i] * wielokrotnosc;
            kopiaW[j] -= kopiaW[i] * wielokrotnosc;
        }
    }
    for(int i = kopiaM.Pobierz_Wiersz()-1; i>=0; i--)//Zerowanie macierzy powyżej przekątnej
    {
        for(int j=i-1; j>=0; j--)
        {
            if(fabs(kopiaM[j][i]) < E)
                continue;
            double wielokrotnosc = kopiaM[j][i]/kopiaM[i][i];
            kopiaM[j] -= kopiaM[i] * wielokrotnosc;
            kopiaW[j] -= kopiaW[i] * wielokrotnosc;
        }
    }
    for(int i=0; i<kopiaM.Pobierz_Wiersz(); i++)//Zerowanie przekątnej
    {
        double wielokrotnosc = 1/kopiaM[i][i];
        kopiaM[i][i] = kopiaM[i][i] * wielokrotnosc;
        kopiaW[i] = kopiaW[i] * wielokrotnosc;
    }
    return kopiaW;
}

std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown)
{
    if(UklRown.GetMatrix().Pobierz_Wiersz() == UklRown.GetVector().Pobierz_Wymiar())
    {
        Strm >> UklRown.GetVector();
        Strm >> UklRown.GetMatrix();
        return Strm;
    }
    else
    {
        std::cerr << "Niezgodne rozmiary" << std::endl;
        exit(1);
    }
}

std::ostream& operator << ( std::ostream &Strm, UkladRownanLiniowych &UklRown)
{
    int modulo = 0;
    if(UklRown.GetMatrix().Pobierz_Wiersz()%2 == 1)
        modulo = UklRown.GetMatrix().Pobierz_Wiersz()/2 + 1;
    else
        modulo = UklRown.GetMatrix().Pobierz_Wiersz()/2;
    //Strm << modulo << std::endl;
    for(int i=0; i<UklRown.GetMatrix().Pobierz_Wiersz(); i++)
    {
        if(i+1 != modulo)
        {
            Strm << UklRown.GetMatrix()[i] << " |X" << i+1 << "|" 
            << "   " << "|" << UklRown.GetVector()[i] << "|"
            << std::endl;
        }
        else
        {
            Strm << UklRown.GetMatrix()[i] << " |X" << i+1 << "|" 
            << " = " << "|" << UklRown.GetVector()[i] << "|"
            << std::endl;
        }

    }
    return Strm; 
}