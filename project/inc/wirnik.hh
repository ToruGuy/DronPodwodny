#ifndef WIRNIK_HH
#define WIRNIK_HH

#include "graniastoslup.hh"
#include "macierz3D.hh"

class Wirnik: public Graniastoslup{
    int katZmianyUkladu = 0;
    Wektor3D wektorPrzesunieciaUkladu;
    std::vector <Wektor3D> _ukladGlobalny;
public:
    Wirnik():Graniastoslup(){}
    Wirnik(Wektor3D& wekPrzesuniecia);
     /**
     * Przeciazenie operatora [], udostepniajace odczytanie pola wierzcholki.
     * 
     * @return Wektor3D
     */
    Wektor3D operator () (unsigned int i) const { return _ukladGlobalny[i]; }

    /**
     * Przeciazenie operatora [], udostepniajace zmiane pola wierzcholki.
     * 
     * @return Wektor3D
     */
    Wektor3D & operator () (unsigned int i) {return _ukladGlobalny[i];}
    void powrotDoUkladuLok();
    void obracaj(const int& kat);
};

#endif