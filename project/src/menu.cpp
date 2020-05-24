#include "menu.hh"
void wypiszOpcje(){
    std::cout<<"r - zadaj ruch na wprost"<<std::endl;
    std::cout<<"o - zadaj zmiane orientacji"<<std::endl;
    std::cout<<"m - wyswietl menu"<<std::endl<<std::endl;
    std::cout<<"k - koniec dzialania programu"<<std::endl;
}
bool otworzMenu(PzG::LaczeDoGNUPlota  Lacze){
    char wpisanyZnak;
    int przemieszczenie = 1;
    Wektor3D *po =new Wektor3D(-40, -40, 0);
    Wektor3D *ko =new Wektor3D(100, 100, 100);

    Scena *scena = new Scena(*po, *ko);
    Dron *dron = new Dron();

    while(wpisanyZnak != 'k'){
        przemieszczenie = 1;
        std::cout<<"Twoj wybor, m - menu> ";
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

            std::cout<<"Podaj wartosc odleglosci, na ktora ma sie przemiescic dron."<<std::endl;
            std::cout<<"Wartosc odleglosci> ";
            std::cin>>odleglosc;
            if(std::cin.fail()){
                std::cerr<<"Wczytywanie odleglosci nie powiodlo sie!"<<std::endl;
                return false;
            }
            std::cout<<std::endl<<std::endl;
            
            for(int i = 0; i < odleglosc; i++){
                Scena *scena = new Scena(*po, *ko);

                (*dron).ruchNaWprost(katGoraDol, przemieszczenie);
                (*dron).dronPozaMapa(*po, *ko);
                (*scena).generujSceneDoPliku();
                (*dron).generujDronaDoPliku();
                
                //podczas kontatku z dnem program konczy dzialanie 
                if((*dron).wykrywanieKolizjiZDnem()){return false;}

                //podczas kontaktu z powierzchnia wody dron ma uniemozliwione dalsze wznoszenie sie
                if((*dron).wykrywanieKolizjiZWoda()){
                    katGoraDol == 90 ? przemieszczenie = 0:0;
                    katGoraDol>0 ? katGoraDol = 0:0;
                }
                generujPlikGNU(*dron, *scena);
                obslugaGNUplota(*po, *ko, Lacze);
                usleep(SLEEP);

                delete scena;
            }
            
            
            std::cout<<"Aktualna ilosc obiektow Wektor3D> "<<(*po).ileTeraz()<<std::endl;
            std::cout<<"Laczna ilosc obiektow> "<<(*po).ileWszystkie()<<std::endl;            
            break;

        case 'o':
            double obrot;
            

            std::cout<<std::endl<<"Podaj wartosc kata obrotu w stopniach."<<std::endl;
            std::cout<<"Podaj kat obrotu: ";
            std::cin>>obrot;
            if(std::cin.fail()){
                std::cerr<<"Wczytywanie obrotu nie powiodlo sie!"<<std::endl;
                return false;
            }
            
            if(obrot < 0){
                obrot *= -1;
                for(int i = 0; i < obrot; i++){
                    Scena *scena = new Scena(*po, *ko);

                    (*dron).obrotWokolOZ(-1);
                    (*scena).generujSceneDoPliku();
                    (*dron).generujDronaDoPliku();
                    generujPlikGNU(*dron, *scena);
                    obslugaGNUplota(*po, *ko, Lacze);
                    usleep(SLEEP);

                    delete scena;
                }
            }else{ 
                for(int i = 0; i < obrot; i++){
                    Scena *scena = new Scena(*po, *ko);

                    (*dron).obrotWokolOZ(1);
                    (*scena).generujSceneDoPliku();
                    (*dron).generujDronaDoPliku();
                    generujPlikGNU(*dron, *scena);
                    obslugaGNUplota(*po, *ko, Lacze);
                    usleep(SLEEP);
        
                    delete scena;
                }
            }
            
            
            std::cout<<"Aktualna ilosc obiektow Wektor3D> "<<(*po).ileTeraz()<<std::endl;
            std::cout<<"Laczna ilosc obiektow> "<<(*po).ileWszystkie()<<std::endl;
            
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
    delete dron;
    delete po;
    delete ko;

    std::cout<<"Aktualna ilosc obiektow Wektor3D> "<<(*po).ileTeraz()<<std::endl;
    std::cout<<"Laczna ilosc obiektow> "<<(*po).ileWszystkie()<<std::endl<<std::endl;
    return true;
}

void generujPlikGNU(const Dron& dron, const Scena& scena){
    std::ofstream Strm(PLIKGNU);
    if (Strm.fail()) std::cerr<<"Zapis glownego pliku GNUplota sie nie powiodl!"<<std::endl;

    Strm<<scena.napis()<<dron.napis();
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