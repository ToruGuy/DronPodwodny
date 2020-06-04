#include "przeszkoda.hh"
Wektor3D& Przeszkoda::zakresPoczatku() {
    Wektor3D min = _wierzcholki[0];

    for(const Wektor3D elem : _wierzcholki){
        if(elem <= min){
            min = elem;
        }
    }

    zPoczatku = min;
    return zPoczatku;
}

Wektor3D& Przeszkoda::zakresKonca() {
    Wektor3D maxx = _wierzcholki[0];

    for(const Wektor3D elem : _wierzcholki){
        if(elem >= maxx){
            maxx = elem;
        }
        
    }

    zKonca = maxx;
    return zKonca;
}