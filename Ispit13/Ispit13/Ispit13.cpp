/////////////////////////////////////////// SA ISPITA (27.1.2018) //////////////////////////////////////////////

//Napisati program koji će učitati niz od 50 integer vrijednosti.Napisati funkciju koja će provjeriti da li se u nizu nalazi
//sekvenca od minimalno 4 uzastopna broja.Funkcija treba da provjeri i prebroji koliko takvih sekvenci postoji u nizu i da ispise broj takvih sekvenci.
//Npr. 256, 985, 321, 322, 323, 324, 456, 457, 458, 503, 201, 202, 203, 204, 658....
//1 sekvenca			                   2 sekvenca .............

/*
#include <iostream>

using namespace std;

const int n = 15;

int sekvencija(int niz[]);

void main()
{
	int niz[n];

	for (int i = 0; i < n; i++)
		cin >> niz[i];

	cout <<"U nizu imaju " << sekvencija(niz)<<" sekvence od minimalno 4 uzastopna broja" << endl;

	system("pause>0");

}

int sekvencija(int niz[])
{
	int brojac = 1, brojac_sek = 0;
	bool sekvenca = false;
	for (int i = 0; i <= n - 1; i++)
	{
		if (!sekvenca)
			brojac = 1;

		if (niz[i] == niz[i + 1] - 1)
		{
			brojac++;
			sekvenca = true;
		}
		else
		{
			sekvenca = false;
		}

		if (!sekvenca && brojac >= 4)
			brojac_sek++;
	}

	return brojac_sek;

}
*/

//--------------------------------------------------------------------------------------------------------------------

//Poštujući sve faze procesa programiranja, napisati program koji će se za uneseni prirodni broj n računati :
//S = 1 / (n + 1) - 2 / (n + 2!) + 3 / (n + 3!) - 4 / (n + 4!) + ⋯ + 〖(-1)〗 ^ (n - 1) (n / (n + n!))

//10 < n <= 100
//Obavezno koristiti ispravne tipove podataka i optimizirati code.

/*
#include <iostream>
using namespace std;

float suma(int);
int fact(int);

void main() {

	int n;
	cout << "Unesite jedan prirodan broj" << endl;
	do {
		cin >> n;
	} while (n < 10 || n>101);

	cout << "Suma izraza iznosi: " << suma(n) << endl;

	system("pause>0");
}

int fact(int broj) {
	int f = 1;
	for (int i = 0; i <= broj; i++)
	{
		f *= i;
	}

	return f;


}

float suma(int broj) {

	float s = 0;
	for (int i = 1; i <= broj; i++)
	{
		s += pow(-1, i - broj) * i / (broj + fact(i));
	}
	return s;

}
*/

//------------------------------------------------------------------------------------------------------ -

//Napisati program koji će omogućiti korisniku unos dva minimalno trocifrena prirodna broja m i n(n > m, m > 100, n < 500).Zatim napraviti
//funkciju koja će vratiti aritmeticku sredinu svih srednjih cifara svih brojeva u rangu od m do n.Također ta funkcija treba ispisati
//najveću srednju cifru navedenog ranga.
//Napomena: Po želji kreirati dodatne funkcije da se olakša rješavanje zadatka(npr funkcija int srednjaCifra(int))


/*
#include <iostream>
using namespace std;

int srednja(int);
float aritmeticka(int, int);

void main() {

	int prvi, drugi;

	cout << "Unesite dva minimalno trocifrena broja" << endl;
	do {
		cin >> prvi >> drugi;
	} while (prvi > drugi || prvi < 100 || drugi>500);

	cout << srednja(prvi) << endl;

	cout << "Aritmeticka sredina svih srednjih cifara brojeva u rangu od " << prvi << " do " << drugi << " je: " << aritmeticka(prvi, drugi) << endl;

	system("pause>0");
}

int srednja(int broj) {
	int srednjaCif = 0;
	broj /= 10;
	srednjaCif = broj % 10;

	return srednjaCif;
}

float aritmeticka(int m, int n) {

	float s = 0;
	int najveca = 0;
	int pomocna;

	for (int i = m; i < n; i++)
	{
		s += srednja(i);
		pomocna = srednja(i);
		if (pomocna > najveca)
		{
			najveca = pomocna;

		}


	}
	cout << "Najveca srednja cifra brojeva je " << najveca << endl;
	return (float)s / n;


}
*/

//---------------------------------------------------------------------------------------------------------------------- -

//U main funkciji kreirati niz karaktera veličine 200 (char recenica[200]) sa slijedećim inicijaliziranim vrijednostima
//„Most u Mostaru je Stari most a pored njega je jos jedan most“.Također, dat je niz karaktera veličine 4 (char rijec[4])
//koji je inicijaliziran vrijednostima „most“. (Nije potrebno praviti funkciju za unos.Možete odmah pri deklaraciji inicijalizirati
//nizove navedenim karakterima) Potrebno je napraviti funkciju koja će primiti pomenute nizove kao argumente te pronaći i prebrojati
//koliko puta se ponavlja sekvenca karaktera iz niza rijec u nizu recenica.Voditi računa da se rječju
//smatra bilo koji niz karaktera odvojen space - om sa obje strane.Program u main funkciji treba ispisati broj pronađenih riječi.

/*
#include <iostream>
using namespace std;
const int vel = 200, vel2 = 4;

void ispis(char[]);
void broj_rijeci(char[], char[]);

int main()
{
	char recenica[vel] = { "Most u Mostaru je Stari most a pored njega se nalazi jos jedan most " };
	char 	rijec[vel2] = { 'm', 'o', 's', 't' };

	ispis(recenica);
	cout << endl;

	broj_rijeci(recenica, rijec);

	system("pause>0");
	return 0;
}

void ispis(char recenica[])
{
	cout << endl << "Recenica:";
	for (int i = 0; i < vel; i++)
	{
		cout << recenica[i];
	}
}


void broj_rijeci(char recenica[], char rijec[])
{
	int brojac = 0, brojac1 = 0;

	for (int i = 0; i < vel; i++)
	{
		if ((recenica[i] >= 'a' && recenica[i] <= 'z') || (recenica[i] >= 'A' && recenica[i] <= 'Z') || recenica[i] == ' ')
			brojac1++;
	}

	for (int i = 0; i < brojac1 - 3; i++)
	{
		if (recenica[i - 1] == ' ' && recenica[i] == 'm' || recenica[i] == 'M' && recenica[i + 1] == 'o' &&
			recenica[i + 2] == 's' && recenica[i + 3] == 't' && recenica[i + 4] == ' ')

			brojac++;
	}
	cout << "Rijec most u recenici se pojavljuje " << brojac << " puta. " << endl;
}
*/


//------------------------------------------------------------------------------------------------------------------------

//Napisati program koji će omogućiti unos elemenata tipa integer u matricu dimenzija 10x10 te izvršiti
//transponovanje matrice(zamjeniti redove i kolone kao na slici).
//Zatim napraviti funkciju koja će izračunati aritmetičku sredinu svih parnih brojeva iznad glavne dijagonale i aritmetičku sredinu svih neparnih brojeva iznad
//sporedne dijagonale transponovane matrice.Provjeriti koja aritmetička sredina je veća i ispisati odgovarajuću poruku i dobivenu vrijednost u main programu.

/*
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
const int vel = 5;

void unos(int[][vel]);
void ispis(int[][vel]);
void transpose(int[][vel]);
float aritmetickeSr(int[][vel]);

void main(){

	int niz[vel][vel];

	unos(niz);
	cout << endl;
	cout << "Elementi matrice su" << endl;
	ispis(niz);
	cout << "Transponovana matrica izgleda ovako" << endl;
	transpose(niz);
	cout << "Veca aritmeticka sredina je " << aritmetickeSr(niz) << endl;

	system("pause>0");
}

void unos(int n[][vel]){


	for (size_t i = 0; i <vel ; i++){



		for (size_t j = 0; j <vel ; j++)
		{
			n[i][j] = rand() % 20 + 1;
		}
	}
}

void ispis(int n[][vel]){

	for (size_t i = 0; i < vel; i++){



		for (size_t j = 0; j < vel; j++)
		{
			cout <<setw(7)<< n[i][j];
		}
		cout << endl;

	}

}

void transpose(int n[][vel]){

	for (size_t i = 0; i < vel; i++){
		int temp;


		for (size_t j = 0; j < vel; j++)
		{
			if (j > i){
				temp = n[i][j];
				n[i][j] = n[j][i];
				n[j][i] = temp;

			}
			cout << setw(7) << n[i][j];
		}
		cout << endl;

	}

}

float aritmetickeSr(int n[][vel]){
	float s1=0, s2=0;
	int brojac1 = 0, brojac2 = 0;
	float ar1, ar2;

	for (size_t i = 0; i < vel; i++){



		for (size_t j = 0; j < vel; j++)
		{
			if (n[i][j] % 2 == 0 && i < j)
			{
				s1 += n[i][j];
				brojac1++;
				ar1 = s1 / brojac1;
			}
			if (n[i][j] % 2 != 0 && i + j < vel - 1){
				s2 += n[i][j];
				brojac2++;
				ar2 = s2 / brojac2;
			}

		}

	}
	cout << "Aritmeticka sredina parnih elemenata iznad glave dijagonale je " << ar1 << endl;
	cout << "Aritmeticka sredina neparnih elemenata iznad sporedne dijagonale je " << ar2 << endl;
	if (ar1 > ar2)
		return ar1;
	else if (ar1 < ar2)
		return ar2;
	else
		cout << "Obe aritmeticke sredine su jednake" << endl;

}
*/