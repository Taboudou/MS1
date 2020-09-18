#pragma hdrstop
#pragma argsused
#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <sstream>
#include <ctime>
#include "SNAfficheur.h"
#include  "SNLigne.h"


using namespace std;

int saisirBinaire()
{
   char bin[100];
   int nb = 0;
   cin>>bin;
   for(int i=0;i<strlen(bin);i++)
   {
	   nb = nb*2+(bin[i]-'0');
   }
   return nb;
}
string EntierVersChaineEnBinaire(int nb)
{
	ostringstream oss;
	bool copie = false;
	for(int i=31;i>=0;i--)
	{
		if(((nb>>i)&1)==1)
		{
			copie = true;
		}
		if(copie == true)
		{
			oss<<((nb>>i)&1);
		}
	}
	return oss.str();
}


int _tmain(int argc, _TCHAR* argv[])
{
	float val1;
	float val2;
	char operateur;
	float resultat;
	float k=1;
	int  nb,choix;
	int base;
	char fonction[10];
	char phrase[200];
	SNAfficheur aff;
	SNLigne lg;

    char buffer[256];
    time_t timestamp = time(NULL);

	strftime(buffer, sizeof(buffer), "%A %d %B %Y - %X.", localtime(&timestamp));




	cout << " Calcul(1),Trigo(2),Conversion(3)";
	cin >> choix;
	if (choix == 1)
	{
		cout << " saisir le calcul :";
		cin >> val1 >> operateur >> val2;
		if (operateur == '+')
		{
			resultat = val1 + val2;
		}
		if (operateur == '-')
		{
			resultat = val1 - val2;
		}
		if (operateur == '*')
		{
			resultat = val1 * val2;
		}
		if (operateur == '/')
		{
			  resultat = val1 / val2;

		}
		sprintf(phrase,"%.3f %c %.3f = %.3f" ,val1, operateur, val2, resultat);
		cout << buffer << phrase  ;
        cin.get();    cin.get();cin.get();
	}
	if (choix == 2)
	{
		cout << "Menu Trigo" << endl;
		cout << "Voulez-vous le resultat en degres (0) ou en radian (1)";
		cin >> choix;
		if (choix == 0)
		{
			k=3.14159265359/180;
		}
		cout <<"Saisir l'operation: ";
		cin >> fonction >> val1;
		val1=val1*k;
		if (strcmp (fonction,"cos") == 0)
		{
			resultat = cos(val1);
		}
		if (strcmp (fonction,"sin") == 0)
		{
			resultat = sin(val1);
		}
		if (strcmp (fonction,"tan") == 0)
		{
			resultat = tan(val1);
		}
		sprintf(phrase,"%s(%.3f) = %.3f" , fonction, val1, resultat);
		cout<<buffer<<phrase ;
        cin.get();    cin.get();cin.get();
	}
	if (choix == 3)
	{
		cout << "choix de la base: Decimal(1),Hexa(2),Binaire(3)";
		cin >> base;
		cin.get();
		cout <<"Saisir un nombre entier";
		if (base==1 )
		{

			 cin>>dec>>nb;

		}

	   if (base==2 )
		{

			 cin >>hex>>nb;

		}
		if (base==3 )
		{

			 nb = saisirBinaire();

		}

		cout<<"Choix de la base d'affichage:Decimal(1),Hexa(2),Binaire(3)";
		cin>>base;
		cin.get();
		if (base==1 )
		{
			cout<<nb<<dec;
			sprintf(phrase,"%d = %d ",nb,nb);
			cout<<phrase;
		}
		if (base==2 )
		{
		   cout<<nb<<hex;


			cout<<phrase;
		}
        if (base==3 )
		{
		   cout<< EntierVersChaineEnBinaire(nb)<< endl;

		}
	}

	 aff.ModifierAdresseIPDuServeurUDP("172.20.182.57");
	 aff.ModifierPortDuServeurUDP(4321);
	 lg.ModifierMessage(phrase);
	 aff.EnvoyerLigneEnUDP(lg);


	cin.get(); cin.get(); cin.get(); cin.get();cin.get();
	return 0;
}

