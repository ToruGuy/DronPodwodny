#include "graniastoslup.hh"

Graniastoslup::Graniastoslup(){
    Wektor3D tmp;
    int i = 0;

    std::ifstream Strm(GRANIASTOLUP);
    if (Strm.fail()) std::cerr<<"BLAD WCZYTYWANIA GRANIASTSLUPU!"<<std::endl;

    while(!Strm.eof()){
        Strm>>tmp;
        i++;

        _wierzcholki.push_back(tmp);
        _napis += tmp.napis();
        if(i % 4 == 0){
            _napis += "\n"; 
        }
    }
}

Graniastoslup::Graniastoslup(Wektor3D& wekPrzesuniecia){
    Wektor3D tmp;
    int i = 0;

    std::ifstream Strm(GRANIASTOLUP);
    if (Strm.fail()) std::cerr<<"BLAD WCZYTYWANIA GRANIASTSLUPU!"<<std::endl;

    while(!Strm.eof()){
        Strm>>tmp;
        tmp = tmp + wekPrzesuniecia;
        i++;

        _wierzcholki.push_back(tmp);
        _napis += tmp.napis();
        if(i % 4 == 0){
            _napis += "\n"; 
        }
    }
}