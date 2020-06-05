#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include "powierzchnia.hh"
/**
 * Klasa modelujaca przeszkode.
 * Przeszkoda powinna byc ustawiana pod katem zerowym, wzgledem 
 * ukladu wspolrzednych X, Y, Z
 */
class Przeszkoda:public Powierzchnia{
    /**
     * Pole modelujace wektor poczatkowy przeszkody statycznej.
     */
    Wektor3D zPoczatku;

    /**
     * Pole modelujace wektor koncowy przeszkody statycznej.
     */
    Wektor3D zKonca;
public:
    /**
     * Metoda ustalajaca najmniejszy wektor istniejacy w przeszkodzie.
     *
     * @return Wektor3D 
     */
    Wektor3D& zakresPoczatku();

    /**
     * Metoda ustalajaca najwiekszy wektor istniejacy w przeszkodzie.
     *
     * @return Wektor3D 
     */
    Wektor3D& zakresKonca();

    /**
     * Przeciarzenie operatora [] pozwalajace na dostep do wierzcholkow przeszkody.
     *
     * @param[in] - int
     * @return Wektor3D 
     */
    Wektor3D operator[](unsigned int i) const {return _wierzcholki[i];}
};
#endif