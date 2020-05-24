#include <iomanip>
#include "menu.hh"


using namespace std;


int main()
{
  PzG::LaczeDoGNUPlota  Lacze;
  char c;

  system("clear");
  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.

  otworzMenu(Lacze);

  cin >> noskipws >> c;
}
