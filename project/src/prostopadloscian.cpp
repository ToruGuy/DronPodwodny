#include "prostopadloscian.hh"

Prostopadloscian::Prostopadloscian(){
    Wektor3D tmp;
    int i = 0;

    std::ifstream Strm(PROSTOPADLOSCIAN);
    if (Strm.fail()) std::cerr<<"BLAD WCZYTYWANIA PROSTOPADLOSCIANU!"<<std::endl;

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