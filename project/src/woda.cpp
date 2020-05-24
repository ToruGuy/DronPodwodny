#include "woda.hh"

Woda::Woda(Wektor3D& poczatek, Wektor3D& koniec){
    Wektor3D tmp;
    for (int x = poczatek(0);  x <= koniec(0); x += KROK_SIATKI) {
        for (int y = poczatek(1);  y <= koniec(1); y += KROK_SIATKI) {
            if(x % 2 == 0){
                _wierzcholki.push_back(Wektor3D(x,y,WODA_MAX));
                _napis += (_wierzcholki.back()).napis();
            }
            else{
                _wierzcholki.push_back(Wektor3D(x,y,WODA_MIN));
                _napis += (_wierzcholki.back()).napis();
            }
        }
        _napis+="\n";
    }
}
