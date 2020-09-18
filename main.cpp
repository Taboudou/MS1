#include "SNLigne.h"
#include "SNAfficheur.h"
#include <iostream>
using namespace std;


 main()
{
	char phrase [100];
	SNAfficheur aff;
	SNLigne lg;

	aff.ModifierAdresseIPServeurUDP("172.20.182.57");
	aff.ModifierPortServeurUDP(4321);
	lg.ModifierMessage(phrase);
	aff.EnvoyerLigneEnUDP(lg);
	return 0;
}
