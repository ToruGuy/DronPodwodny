#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include "powierzchnia.hh"

class Przeszkoda:public Powierzchnia{
    Wektor3D wektorPrzesuniecia;
    Wektor3D zPoczatku;
    Wektor3D zKonca;
public:
    Wektor3D& zakresPoczatku();
    Wektor3D& zakresKonca();
    Wektor3D& operator[](unsigned int i){return _wierzcholki[i];}
};
#endif