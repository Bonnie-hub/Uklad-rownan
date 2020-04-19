#include "UkladRownanLiniowych.hh"

UkladRownanLiniowych::UkladRownanLiniowych()
{
    macierz = Macierz();
    wektor = Wektor();
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

Wektor UkladRownanLiniowych::Solve()
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



/*
Wektor UkladRownanLiniowych::Solve()
{
    Macierz kopiaM = macierz;
    Wektor kopiaW = wektor;
    for(int k=0; k<kopiaM.Pobierz_Wiersz()-1; k++)
    {
        if(fabs(kopiaM[k][k]) < E) 
        {
            std::cerr << "Dzielenie przez zero" << std::endl;
            exit(1);
        }
        for(int i=k+1; i<kopiaM.Pobierz_Wiersz(); i++)
        kopiaM[i][k] /= kopiaM[k][k];

        for(int i=k+1; i<kopiaM.Pobierz_Wiersz(); i++)
        {
        for(int j=k+1; j< kopiaM.Pobierz_Wiersz(); j++)
            kopiaM[i][j] -= kopiaM[i][k] * kopiaM[k][j];
        }
    }
    double stala = 0;
    Wektor X;
    X[0] = wektor[0];

    for(int i=1; i<kopiaM.Pobierz_Wiersz(); i++)
    {
        for(int j=0; j<i; j++)
        stala += kopiaM[i][j] * X[j];

        X[i] = wektor[i] - stala;
    }

    if(fabs(kopiaM[kopiaM.Pobierz_Wiersz()-1][kopiaM.Pobierz_Wiersz()-1]) < E )
    {
        std::cerr << "" << std::endl;
        exit(1);
    }
    X[kopiaM.Pobierz_Wiersz()-1] /=
    kopiaM[kopiaM.Pobierz_Wiersz()-1][kopiaM.Pobierz_Wiersz()-1];

    for(int i = kopiaM.Pobierz_Wiersz()-2; i >= 0; i--)
    {
        stala = 0;

        for(int j=i+1; j<kopiaM.Pobierz_Wiersz(); j++)
            stala += kopiaM[i][j] * X[j];

        if(fabs(kopiaM[i][i]) < E)
        {
            std::cerr << "" << std::endl;
            exit(1);
        }
        X[i] = (X[i] - stala) / kopiaM[i][i];
    }
    return X;
}
*/