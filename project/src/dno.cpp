#include "dno.hh"

Dno::Dno(Wektor3D poczatek, Wektor3D koniec){
    Wektor3D tmp;
    for (int x = poczatek(0);  x <= koniec(0); x += KROK_SIATKI) {
        for (int y = poczatek(1);  y <= koniec(1); y += KROK_SIATKI) {
            _wierzcholki.push_back(Wektor3D(x,y,POZ_DNA));
            _napis += (_wierzcholki.back()).napis(); 
        }
        _napis += "\n";
    }
}