#ifndef WODA_HH
#define WODA_HH

#include "powierzchnia.hh"

/**
 * Klasa jest reprezentacja graficzna wody w programie.
 */
class Woda : public Powierzchnia{
public:
    /**
     * Tworzy powierzchnie wody na zakresie od poczatek do koniec
     * 
     * @param[in] poczatek - wektorowy poczatek zakresu
     * @param[in] koniec - wektorowy koniec zakresu 
     */
    Woda(Wektor3D& poczatek, Wektor3D& koniec);
};

#endif