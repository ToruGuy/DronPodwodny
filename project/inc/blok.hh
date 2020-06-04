#ifndef BLOK_HH
#define BLOK_HH

#include "przeszkoda.hh"

class Blok:public Przeszkoda{
public:
    Blok(Wektor3D& wekPrzesuniecia);
};
#endif