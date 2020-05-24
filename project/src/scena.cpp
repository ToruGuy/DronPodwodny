#include "scena.hh"
void Scena::aktualizujScene(Wektor3D zakresP, Wektor3D zakresK){
    woda = new Woda(zakresP, zakresK);
    dno = new Dno(zakresP, zakresK);

    this->generujSceneDoPliku();

    delete woda;
    delete dno;
}

std::string Scena::generujSceneDoPliku(){    
    std::ofstream Strm(DNOIWODA);
    if (Strm.fail()) std::cerr<<"Zapis Sceny do pliku się nie powiodl!"<<std::endl;
    
    _napis += (*this).woda->napis();
    _napis += "#\n\n";
    _napis += (*this).dno->napis();
    _napis += "#\n\n";

    Strm<<_napis;
    return _napis;
}