#ifndef POWIERZCHNIA_HH
#define POWIERZCHNIA_HH

#include <vector>
#include <consts.h>
#include "wektor3D.hh"

/**
 * Plik zawiera definicje klasy Powierzchnia.
 * Jest to najmniejszy element graficzny. 
 */
class Powierzchnia{
protected:
    /**
     * Pole wierzcholki, zawiera dane o wierzcholkach powierzchni.
     */
    std::vector <Wektor3D> _wierzcholki;
    /**
     * Pole wierzcholki, zawiera dane o wierzcholkach powierzchni w formie gotowej do wypisania.
     */
    std::string _napis = "";

public:
    /**
     * Przeciazenie operatora [], udostepniajace odczytanie pola wierzcholki.
     * 
     * @return Wektor3D
     */
    Wektor3D operator [] (unsigned int i) const { return _wierzcholki[i]; }

    /**
     * Przeciazenie operatora [], udostepniajace zmiane pola wierzcholki.
     * 
     * @return Wektor3D
     */
    Wektor3D & operator [] (unsigned int i) {return _wierzcholki[i];}

    /**
     * Funkcja zwraca ilosc utworzonych wierzcholkow.
     * 
     * @return int
     */
    int ilosc() const {return _wierzcholki.size();}

    /**
     * Pozwala odczytac pole napis.
     * 
     * @return std::string
     */
    std::string napis() const {return _napis;}
};

#endif