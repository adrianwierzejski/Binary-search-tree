#include <iostream>
#include <cstdlib>
//#include <fstream>

using namespace std;

struct osoba
{
	long long PESEL; // zmienna typu int nie jest w stanie przechowywac numeru PESEL (11 znaków) Maksymalna wartosc unsigned int 4294967295 (10 znakow)
	string nazwisko;
	string imie;
	double wzrost;
};
struct drzewo_BST
{
	osoba dane;
	drzewo_BST *lewy=NULL;
	drzewo_BST *prawy=NULL;
};
bool kolejnosc(osoba nazwa1, osoba nazwa2)
{
	int size;
	short zwroc=-1;
	if(nazwa1.nazwisko.size()<nazwa2.nazwisko.size())
	{
		size=nazwa1.nazwisko.size();
		zwroc=0;
	}
	else
	if(nazwa1.nazwisko.size()>nazwa2.nazwisko.size())
	{
		size=nazwa2.nazwisko.size();
		zwroc=1;
	}
	for(int i=0; i<size; i++)
		if(nazwa1.nazwisko[i]<nazwa2.nazwisko[i])
		return false;
		else if(nazwa1.nazwisko[i]>nazwa2.nazwisko[i])
		return true;
	if(zwroc>=0)
		return (bool)zwroc;
	if(nazwa1.imie.size()<nazwa2.imie.size())
	{
		size=nazwa1.imie.size();
		zwroc=0;
	}
	else
	if(nazwa1.imie.size()>nazwa2.imie.size())
	{
		size=nazwa2.imie.size();
		zwroc=1;
	}
	for(int i=0; i<size; i++)
		if(nazwa1.imie[i]<nazwa2.imie[i])
		return false;
		else if(nazwa1.imie[i]>nazwa2.imie[i])
		return true;
	return (bool)zwroc;
}
void dodaj_BST(drzewo_BST *&wyjscie, osoba nowy)
{
	// jeśli wiek jest taki sam decyduje kolejność
	// alfabetyczna nazwiska a następnie imienia

	//jeśli osoba jest już w drzewie usun jej dane i dodaj aktualne
	wyjscie=usun_osobe_BST(wyjscie,osoba.nazwisko,osoba.imie);
	drzewo_BST *poprzedni=NULL, *wsk=wyjscie;
    while(wsk!=NULL)
    {
    	poprzedni=wsk;
        if(nowy.PESEL<wsk->dane.PESEL)
       		wsk=wsk->lewy;
       	else
       		if(nowy.PESEL>wsk->dane.PESEL)
       			wsk=wsk->prawy;
       		else
       		    if(!kolejnosc(wsk->dane,nowy))
       		    	wsk=wsk->lewy;
       		    else
       		    	wsk=wsk->prawy;
    }

   	if(poprzedni==NULL)
    {
    	wyjscie=new drzewo_BST;
       	wyjscie->dane=nowy;
   	}
   	else
   	{
   		if(nowy.PESEL<poprzedni->dane.PESEL)
   		{
   			poprzedni->lewy=new drzewo_BST;
       		poprzedni->lewy->dane=nowy;
   		}
      	else
      		if(nowy.PESEL>poprzedni->dane.PESEL)
      		{
    			poprzedni->prawy=new drzewo_BST;
       			poprzedni->prawy->dane=nowy;
       		}
       		else
       		   	if(!kolejnosc(poprzedni->dane,nowy))
       	    	{
       				poprzedni->lewy=new drzewo_BST;
      				poprzedni->lewy->dane=nowy;
       			}
      	    	else
       	    	{
    				poprzedni->prawy=new drzewo_BST;
     				poprzedni->prawy->dane=nowy;
       			}
    }
}
void drukuj_BST(drzewo_BST &wejscie)
{

    if(&wejscie==NULL)
        return;
    drukuj_BST(*wejscie.lewy);
    cout<<wejscie.dane.PESEL<<' '<<wejscie.dane.nazwisko<<' '<<wejscie.dane.imie<<' '<<wejscie.dane.wzrost<<endl;
    drukuj_BST(*wejscie.prawy);
}
drzewo_BST *usun_osobe_BST(drzewo_BST *wyjscie, osoba uosoba)
{
    if(wyjscie==NULL)
        return NULL;

    wyjscie->lewy=usun_osobe_BST(wyjscie->lewy,usunosoba);
    wyjscie->prawy=usun_osobe_BST(wyjscie->prawy,usunosoba);
    if(wyjscie->dane.PESEL==uosoba.PESEL && wyjscie->dane.nazwisko==uosoba.nazwisko && wyjscie->dane.imie==uosoba.imie)
    {
    	drzewo_BST *tmp=NULL;
    	if(wyjscie->lewy!=NULL&& wyjscie->prawy!=NULL)
    	{
    		drzewo_BST *poprzedni=wyjscie;
    		tmp=wyjscie->lewy;
    		while(tmp->prawy!=NULL)
    		{
    			poprzedni=tmp;
    			tmp=tmp->prawy;
    		}
    		if(poprzedni!=wyjscie)
    		{
    			poprzedni->prawy=tmp->lewy;
    			tmp->lewy=wyjscie->lewy;
    		}
    		tmp->prawy=wyjscie->prawy;
    	}
    	else
    	if(wyjscie->lewy==NULL&& wyjscie->prawy!=NULL)
    		tmp=wyjscie->prawy;
    	else
    	if(wyjscie->lewy!=NULL&& wyjscie->prawy==NULL)
    		tmp=wyjscie->lewy;

    	delete wyjscie;
    	return tmp;

   	}
    else
    	return wyjscie;
}
int main()
{
    drzewo_BST *baza=NULL;
    osoba nowy;

    while(true)
    {
    	cout<<"Podaj dane osoby do drzewa.\n";
        cin>>nowy.PESEL>>nowy.nazwisko>>nowy.imie>>nowy.wzrost;
		if(nowy.nazwisko=="Terminator")
			break;
        dodaj_BST(baza,nowy);
        cout<<"Drzewo BST:\n";
    	drukuj_BST(*baza);
    	cout<<endl;
    }
    return 0;
}
