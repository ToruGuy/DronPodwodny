#include "scena.hh"
Scena::Scena(Wektor3D& zakresP, Wektor3D& zakresK){
    woda = new Woda(zakresP, zakresK);
    dno = new Dno(zakresP, zakresK); 
    Wektor3D tmp = Wektor3D(7,20,0); 
    
    std::shared_ptr<Blok> blok = std::make_shared<Blok>(tmp);
    przeszkody.push_back((*blok));
    
    tmp = Wektor3D(-10,15,0);
    std::shared_ptr<Sciana> sciana = std::make_shared<Sciana>(tmp);
    przeszkody.push_back((*sciana));

    tmp = Wektor3D(-5,-20,0);
    std::shared_ptr<Pret> pret = std::make_shared<Pret>(tmp);
    przeszkody.push_back((*pret));
}

void Scena::aktualizujScene(Wektor3D& zakresP, Wektor3D& zakresK){
    int liczbaPrzeszkod = przeszkody.size();
    Wektor3D tmp;
    zakresP = dron[0]; zakresK = dron[0];
    
    //zakresy za oraz przed dronem
    zakresP(0) -= 70; zakresP(1) -= 70;
    zakresK(0) += 70; zakresK(1) += 70;

    delete woda;
    delete dno;

    this->woda = new Woda(zakresP, zakresK);
    this->dno = new Dno(zakresP, zakresK);

    przeszkody.remove_if([zakresK, zakresP](Przeszkoda elem){
        return (elem.zakresPoczatku()(0) > zakresK(0) || elem.zakresKonca()(0) < zakresP(0)) ||\
                elem.zakresPoczatku()(1) > zakresK(1) || elem.zakresKonca()(1) < zakresP(1); });
    
    for(int i = 0; i < liczbaPrzeszkod - int(przeszkody.size()); i++){
        tmp = Wektor3D(zakresK(0)-rand()%100+2, zakresP(1)+rand()%100+2, rand()%35+2);
        std::shared_ptr<Blok> blok = std::make_shared<Blok>(tmp);
        przeszkody.push_back((*blok));
    }

    this->generujSceneDoPliku();
}

std::string Scena::generujSceneDoPliku(){    
    std::ofstream Strm(PLIKGNU);
    if (Strm.fail()) std::cerr<<"Zapis Sceny do pliku się nie powiodl!"<<std::endl;
    
    //czysci napis
    _napis = "";

    _napis += (*this).woda->napis();
    _napis += "#\n\n";
    _napis += (*this).dno->napis();
    _napis += "#\n\n";
    _napis += (*this).dron.napis();
    _napis += "#\n\n";
    for(Przeszkoda& elem : przeszkody){
        _napis += elem.napis();
        _napis += "#\n\n";
    }
    

    Strm<<_napis;
    return _napis;
}