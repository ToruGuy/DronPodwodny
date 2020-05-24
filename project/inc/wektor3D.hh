#ifndef WEKTOR3D_HH
#define WEKTOR3D_HH

//#include "lzespolona.hh"
#include "wektor.hh"


/**
 * Klasa dziedziczona od szablonu wektor, tworzy wektor o 3 wspolczynnikach typu double.
 */
class Wektor3D: public Wektor<double, 3>{
    /**
     * Pole zawierajace wartosci wszystkich utworzonych wektorow3D.
     */
    static int iloscWszystkie;

    /**
     * Pole zawierajace wartosci wszystkich usunietych/zniszczonych wektorow3D.
     */
    static int iloscZniszczone;

public:
    /**
     * Funkcja zwraca ilosc wszystkich utworzonych wektorow3D.
     * 
     * @return int
     */
    int ileWszystkie() const {return iloscWszystkie;}

    /**
     * Funkcja zwraca ilosc wektorow3D wyswietlonych na ekranie.
     * 
     * @return int
     */
    int ileTeraz()     const {return iloscWszystkie - iloscZniszczone;}

    /**
     * Konstruktor pustego wektora3D.
     */
    Wektor3D() : Wektor<double, 3>() {iloscWszystkie++;}

    /**
     * Konstruktor kopujacy wektora3D.
     */
    Wektor3D(const Wektor3D &w){(*this) = w; iloscWszystkie++;}

    /**
     * Konstruktor parametryczny wektora3D.
     */
    Wektor3D(double x, double y, double z) : Wektor<double, 3>() {(*this)(0)= x; (*this)(1)= y; (*this)(2)= z; iloscWszystkie++;}

    /**
     * Konstruktor kopiujacy wektora3D.
     */
    Wektor3D(const Wektor<double, 3> &m) : Wektor<double, 3>(m) {iloscWszystkie++;}

    /**
     * Destruktor wektora3D.
     */
    ~Wektor3D(){iloscZniszczone++;}

    /**
     * Zwracanie wektora w postaci stringa.
     * 
     * @return string.
     */
    std::string napis() const;
};


#endif