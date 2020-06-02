#include "wirnik.hh"
Wirnik::Wirnik(Wektor3D& wekPrzesuniecia):Graniastoslup(){
    wektorPrzesunieciaUkladu = wekPrzesuniecia;
    for(Wektor3D& elem : _wierzcholki){
        _ukladGlobalny.push_back(elem + wektorPrzesunieciaUkladu);
    }
}

void Wirnik::powrotDoUkladuLok(){
    for(int i = 0; i < this->ilosc(); i++){
        _ukladGlobalny[i] = (*this)[i];
    }
}

void Wirnik::obracaj(const int& kat){
    katZmianyUkladu += kat;
    double katRad = katZmianyUkladu;
    katRad *= M_PI / 180;
    Wektor3D wekDoMacierzy[3];
    wekDoMacierzy[0] = Wektor3D(cos(katRad), 0, sin(katRad));
    wekDoMacierzy[1] = Wektor3D(0, 1, 0);
    wekDoMacierzy[2] = Wektor3D(-sin(katRad), 0, cos(katRad));
    Macierz3D macierzZmian = Macierz3D(wekDoMacierzy[0], wekDoMacierzy[1], wekDoMacierzy[2]);

    
    //wraca do poczatkowego ukladu wspolrzednych
    (*this).powrotDoUkladuLok();
    for(Wektor3D& elem : _ukladGlobalny){
        elem = macierzZmian * elem;
        elem = elem + wektorPrzesunieciaUkladu;
    }
}