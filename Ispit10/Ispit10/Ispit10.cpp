//////////////////////////////////////////// INTEGRALNI ISPIT (8.9.2017)  GRUPA : B //////////////////////////////////////////////

//Poštujući sve faze procesa programiranja, kreirati program koji će pronaći i ispisati sve brojeve od X do Y(uključujući granične vrijednosti)
//koji su deljivi svim svojim ciframa.Na primjer, broj 36 je djeljiv sa brojevima 3 i 6. (36 / 6 = 6 i 36 / 3 = 12).Brojeve X i Y unosi korisnik
//i moraju biti u opsegu od 10 do 6000. Obavezno koristiti bar jednu funkciju.

//Unesite granice intervala : 32 37
//Brojevi u navedenom opsegu koji zadovoljavaju uslov su : 33, 36.

/*
#include <iostream>
using namespace std;

bool provjera(int broj){
	int temp = broj;
	int ostatak;
	while (temp > 0){
		ostatak = temp % 10;   //BROJEVI DJELJIVI SA SVIM SVOJIM CIFRAMA
		if (ostatak == 0 || broj % ostatak != 0){
			return false;
		}
		temp /= 10;
	}
	return true;

}
void main()
{
	int n, y;

	cout << "Unesite granice intervala: ";
	do{
		cin >> n >> y;
	} while ((n < 10 || n>6000 | y < 10 || y>6000) && n > y);

	cout << "Brojevi koji u zadanom intervalu zadovaljaju uslov su: ";
	for (int i = n; i <= y; i++)
	{
		if (provjera(i))
			cout << "  " << i;
	}

	system("pause>0");

}
*/

//----------------------------------------------------------------------------------------------------------------

//Napisati program koji na osnovu unesenog cijelog broja N formira i ispisuje broj sastavljen od istih cifara u opadajućem poretku uzimajući
//samo parne cifre.Za sortiranje cifara koristiti pomoćni niz od najviše 10 elemenata.

//Unesite cijeli broj N : 4513982
//Broj sa sortiranim ciframa : 842

//Unesite cijeli broj N : 689225
//Broj sa sortiranim ciframa : 8622

/*
#include <iostream>
using namespace std;


void funckija(int broj, int n[], int v){
	int pozicija = 0;
	int ostatak;
	int kopija = broj;
	int neparni = 0;
	while (kopija > 0){
		ostatak = kopija % 10;
		kopija /= 10;
		if (ostatak % 2 == 0){// ostatak%2==0 za parne cifre

			n[pozicija] = ostatak;
			pozicija++;
			neparni++;
		}
	}
	bool sorted = true;
	while (sorted) {
		sorted = false;
		for (int i = 0; i < neparni - 1; i++) {

			if (n[i] <n[i + 1]) {// < znaci od najveceg ka najmanjem
				int temp = n[i];
				n[i] = n[i + 1];
				n[i + 1] = temp;
				sorted = true;
			}
		}
	}
	cout << endl << endl;
	cout << "Broj sa sortiranim ciframa: ";
	for (size_t i = 0; i < neparni; i++)
	{
		cout << "   " << n[i];
	}
}

void main()
{
	const int velicina = 10;
	int niz[velicina];
	int n;
	cout << "Unesite cijeli broj" << endl;
	cin >> n;
	cout << "Nakon sortiranja" << endl;
	funckija(n, niz, velicina);


	system("pause>0");
}
*/

//-------------------------------------------------------------------------------------------------------------------- -

//Napisati funkciju koja kao parametar prima rečenicu(niz od najviše 200 karaktera) i iz nje uklanja svaku riječ koja počinje
//malim ili velikim slovom „s“(S i s).Pored toga, funkcija treba da prebroji ukupan broj riječi u rečenici poslije izmjene.
//Koristiti sljedeći prototip funkcije : int ukloniRijeci(char[]).
//Npr.ako je data rečenica :
//"Stari most u Mostaru spaja obale rijeke Neretve."
//funkcija je treba pretvoriti u :
//"most u Mostaru obale rijeke Neretve."
//Funkcija vraća broj riječi u završnoj rečenici(poslije odsijecanja ostalih riječi).Radi jednostavnosti rješenja,
//pretpostavite da je riječ bilo koji niz znakova razdvojen znakom razmak.


/*
#include<iostream>
using namespace std;

int ukloniRijeci(char Niz[200]){
	int brojac = 0;
	int pozicija;
	for (int i = 0; i < strlen(Niz); i++){
		if (i == 0 && (Niz[i] == 's' || Niz[i] == 'S') || (Niz[i] == 's' || Niz[i] == 'S') && Niz[i - 1] == ' '){
			pozicija = i;
			for (int j = i; j < strlen(Niz); j++){
				if (Niz[j] == ' ')
					break;
				Niz[j] = ' ';
			}
		}
	}
	for (int i = 0; i < strlen(Niz); i++){
		if ((Niz[i] >= 65 && Niz[i] <= 90 || Niz[i] >= 97 && Niz[i] <= 122) && Niz[i - 1] == ' ' ||
			(i == 0 && Niz[0] >= 65 && Niz[0] <= 90) || (i == 0 && Niz[0] >= 97 && Niz[0] <= 122))
			brojac++;
	}
	return brojac;
}

void main(){
	char Niz[200] = { "Stari most emir  semir Sarajejvo u Mostaru spaja obale rijeke Neretve." };
	cout << Niz << endl;
	cout <<"Broj riejci u recenici je: "<< ukloniRijeci(Niz) << endl;
	cout << Niz << endl;
	system("pause>0");
}
*/

//------------------------------------------------------------------------------------------------------------------ -

/*
#include <iostream>
#include <ctime>
using namespace std;
const int igr = 11, ut = 12;
void unos(int[][ut]);
float prosjekIgraca(int[]);
void ispis(int[][ut]);
int najprosjek(int[][ut]);
void najvise(int[][ut]);

float iznad(int niz[][ut]);

void  main()
{
	int klub[igr][ut];

	cout << "Unesite igrace i golove " << endl;
	unos(klub);

	cout << endl;

	ispis(klub);
	int izb;

	cout << "Unesite igraca za racunanje prosjeka" << endl;
	do {
		cin >> izb;
	} while (izb < 0 || izb>13);

	cout << prosjekIgraca(klub[izb]) << endl;
	cout << "Igrac sa najboljim prosjekom je: " << najprosjek(klub) << endl;
	najvise(klub);


	system("pause>0");
}
void unos(int n[][ut]) {

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 12; j++) {

			n[i][j] = rand() % 5;


		}
	}
}


float prosjekIgraca(int n[]) {
	float s = 0;
	for (int i = 0; i < 12; i++)
	{
		s += n[i];
	}
	return s / 12;
}

void ispis(int n[][ut]) {

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 12; j++) {

			cout << " " << n[i][j];


		}
		cout << endl;
	}

}
int najprosjek(int vratnik[][ut]) {
	float maxprosjek = prosjekIgraca(vratnik[0]);
	int najigrac = 0;
	for (int i = 1; i < ut; i++)
	{

		if (prosjekIgraca(vratnik[i])>maxprosjek)
		{
			maxprosjek = prosjekIgraca(vratnik[i]);
			najigrac = i;
		}
	}
	return najigrac + 1;
}
void najvise(int n[][ut])
{
	int naj = 0, brojac = 0, utakmica = 0;

	for (int i = 0; i < igr; i++)
	{
		for (int j = 0; j < ut; j++)
		{
			if (n[i][j] > naj)
			{
				naj = n[i][j];
				brojac = i;
				utakmica = j;
			}
		}
	}
	cout << "Najveci broj golova na utakmici iznosi " << naj << endl;
	cout << "Igrac koji je dao najveci broj golova na utakmici " << utakmica + 1 << " je " << brojac + 1 << endl;

}


void ispismatrice(int niz[][igr])
{
	for (int i = 0; i < igr; i++)
	{
		for (int j = 0; j < igr; j++)
		{
			cout << " " << niz[i][j];
		}
		cout << endl;
	}

}
*/




//----------------------------------------------------------------------------------------------------------------------------