#include "menu.hh"
void wypiszOpcje(){
    std::cout<<"r - zadaj ruch na wprost"<<std::endl;
    std::cout<<"o - zadaj zmiane orientacji"<<std::endl;
    std::cout<<"m - wyswietl menu"<<std::endl<<std::endl;
    std::cout<<"k - koniec dzialania programu"<<std::endl;
}
bool otworzMenu(){
    PzG::LaczeDoGNUPlota Lacze;
    char wpisanyZnak;
    int przemieszczenie = 1;
    Wektor3D *po =new Wektor3D(-40, -40, 0);
    Wektor3D *ko =new Wektor3D(100, 100, 100);

    Scena *scena = new Scena(*po, *ko);

    Lacze.ZmienTrybRys(PzG::TR_3D);
    Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.

    while(wpisanyZnak != 'k'){
        przemieszczenie = JEDNOSTKOWA;
        std::cout<<"Twoj wybor, m - menu > ";
        std::cin>>wpisanyZnak;
        if(std::cin.fail()){
            std::cerr<<"Wczytywanie litery nie powiodlo sie!"<<std::endl;
            return false;
        }

        switch (wpisanyZnak){
        case 'r':
            int katGoraDol, odleglosc;
            std::cout<<std::endl<<"Podaj kat wznoszenia/opadania w stopniach."<<std::endl;
            std::cout<<"Wartosc kata> ";
            std::cin>>katGoraDol;
            if(std::cin.fail()){
                std::cerr<<"Wczytywanie obrotu nie powiodlo sie!"<<std::endl;
                return false;
            }
            while(katGoraDol < KATPIONMIN || katGoraDol > KATPIONMAX){
                std::cerr<<"Kat poza zakresem, podaj kat z zakresu (-90, 90)"<<std::endl;
                std::cin>>katGoraDol;

                if(std::cin.fail()){
                    std::cerr<<"Wczytywanie obrotu nie powiodlo sie!"<<std::endl;
                    return false;
                }
            }
            std::cout<<std::endl<<std::endl;

            std::cout<<"Podaj wartosc przemieszczenia drona."<<std::endl;
            std::cout<<"Wartosc odleglosci > ";
            std::cin>>odleglosc;
            if(std::cin.fail()){
                std::cerr<<"Wczytywanie odleglosci nie powiodlo sie!"<<std::endl;
                return false;
            }
            std::cout<<std::endl<<std::endl;
            
            for(int i = 0; i < odleglosc; i++){
                
                (*scena).ruchDronaNaWprost(katGoraDol, przemieszczenie);
                (*scena).aktualizujScene(*po, *ko);
                obslugaGNUplota(*po, *ko, Lacze);
                usleep(SLEEP);
            }
            
            
            std::cout<<"Aktualna ilosc obiektow Wektor3D> "<<(*po).ileTeraz()<<std::endl;
            std::cout<<"Laczna ilosc obiektow> "<<(*po).ileWszystkie()<<std::endl;            
            break;

        case 'o':
            double obrot;
            
            std::cout<<std::endl<<"Podaj wartosc kata obrotu w stopniach."<<std::endl;
            std::cout<<"Podaj kat obrotu: ";
            std::cin>>obrot;
            std::cout<<std::endl;
            if(std::cin.fail()){
                std::cerr<<"Wczytywanie obrotu nie powiodlo sie!"<<std::endl;
                return false;
            }
            
            if(obrot < 0){
                obrot *= -1;
                for(int i = 0; i < obrot; i++){

                    (*scena).obrotDrona(-1);
                    (*scena).aktualizujScene(*po, *ko);
                    obslugaGNUplota(*po, *ko, Lacze);
                    usleep(SLEEP);
                }
            }else{ 
                for(int i = 0; i < obrot; i++){

                    (*scena).obrotDrona(1);
                    (*scena).aktualizujScene(*po, *ko);
                    obslugaGNUplota(*po, *ko, Lacze);
                    usleep(SLEEP);
                }
            }
            
            
            std::cout<<"Aktualna ilosc obiektow Wektor3D > "<<(*po).ileTeraz()<<std::endl;
            std::cout<<"Laczna ilosc obiektow > "<<(*po).ileWszystkie()<<std::endl;
            
            break;

        case 'm':
            wypiszOpcje();
            break;

        case 'k':
            std::cout<<"Koniec programu"<<std::endl;
            break;

        default:
            std::cout<<"Nie ma takiej opcji!"<<std::endl;
            std::cout<<"Sprobuj ponownie."<<std::endl;
            break;
        }
        std::cout<<std::endl<<std::endl;
    }

    delete scena;
    delete po;
    delete ko;

    std::cout<<"Aktualna ilosc obiektow Wektor3D > "<<(*po).ileTeraz()<<std::endl;
    std::cout<<"Laczna ilosc obiektow > "<<(*po).ileWszystkie()<<std::endl<<std::endl;
    return true;
}


void obslugaGNUplota(const Wektor3D& wektorP, const Wektor3D& wektorK, PzG::LaczeDoGNUPlota  Lacze){

    Lacze.UsunWszystkieNazwyPlikow();
    Lacze.DodajNazwePliku(PLIKGNU);
    
    
    Lacze.UstawZakresX(wektorP(0), wektorK(0));
    Lacze.UstawZakresY(wektorP(1), wektorK(1));
    Lacze.UstawZakresZ(POZ_DNA-10, POZ_WODY+10);
    Lacze.UstawRotacjeXZ(80,80); // Tutaj ustawiany jest widok
    Lacze.Rysuj(); 
}