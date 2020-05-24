#ifndef DNO_HH
#define DNO_HH

#include "powierzchnia.hh"

/**
 * Klasa jest reprezentacja graficzna dna w programie.
 */
class Dno:public Powierzchnia{
public:
    /**
     * Tworzy powierzchnie dna na zakresie od poczatek do koniec
     * 
     * @param[in] poczatek - wektorowy poczatek zakresu
     * @param[in] koniec - wektorowy koniec zakresu 
     */
    Dno(Wektor3D poczatek, Wektor3D koniec);
};

#endif