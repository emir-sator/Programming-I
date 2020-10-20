/////////////////////////////////////////// PARCIJALNI ISPIT (28.1.2017) ///////////////////////////////////////////////////

//Napisati program, poštujući sve faze procesa programiranja, koji na osnovu ulaznih vrijednosti x i n izračunava vrijednost sljedećeg izraza :
//S = (Fib(0) + x) / x + (Fib(1) + x) / 〖(x + 1)〗 ^ 2 + (Fib(2) + x) / 〖(x + 2)〗 ^ 3 + ⋯ + (Fib(n) + x) / 〖(x + n)〗 ^ (n + 1)
//
//Fib(n) – n - ti element Fibonaccijevog niza.Fibonaccijev niz je niz brojeva koji počinje brojevima 0 i 1,
//a svaki sljedeći broj u nizu dobije se zbrajanjem prethodna dva : F0 = 0, F1 = 1; Fn = FN - 1 + Fn – 2.
//Za potrebe pronalska n - tog člana Fibonaccijevog niza kreirati zasebnu funkciju koja će se pozivati u
//glavnom programu gdje se vrši kalkukacija i ispis konačne sume.


/*
#include<iostream>
#include<iomanip>
#include <cmath>

using namespace std;

int Fib(int);

int main()
{
	double x, suma = 0;
	int n;

	cout << "Unesite x: ";
	cin >> x;
	cout << "Unesite n: ";
	cin >> n;

	for (int i = 0; i <= n; i++)
	{
		suma += (Fib(i) + x) / pow(x + i, i + 1);
	}

	cout << "Vrijednost sume: " << fixed << setprecision(2) << suma << endl;
	system("pause");
	return 0;
}

int Fib(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
	{
		int naredni, prvi = 0, drugi = 1;
		for (int i = 2; i <= n; i++)
		{
			naredni = prvi + drugi;
			prvi = drugi;
			drugi = naredni;
		}

		return naredni;
	}

}


*/


//----------------------------------------------------------------------------------------------------------------

//Napraviti program koji u niz sprema trocifrene brojeve koji su jednaki zbiru kubova svojih cifara(ukupno su četiri takva broja).Zatim napraviti sljedeće funkcije :
//-sortiraj – koja će poredati vrijednosti elemenata niza od najvećeg prema najmanjem
//- medij – koja nalazi medijan tj.srednji član u sortiranom nizu(budući da se u nizu nalaze četiri elementa, medijan je aritmetička sredina od srednja dva člana).
//U glavnom programu je potrebno ispisati sortiran niz te njegov medijan.

/*
#include <iostream>
using namespace std;

bool provjera(int);
void sortiraj(int[], int);
float medij(int[]);

void main(){
	const int vel = 1000;
	int brojac = 0;
	int niz[vel];
	for (int  i = 100; i < vel; i++)
	{
		if (provjera(i)){
			niz[brojac] = i;
			brojac++;
		}
	}
	for (int i = 0; i < brojac; i++)
	{
		cout << "  " << niz[i]<< endl;
	}

	cout << endl;
	sortiraj(niz, brojac);

	for (int i = 0; i < brojac; i++)
	{
		cout << "  " << niz[i] << endl;
	}
	cout << "Srednji clan u sortiranom nizu je: " << medij(niz);


	system("pause>0");
}

bool provjera(int broj){
	int a, b, c;
	a = broj / 100;
	b = broj / 10 % 10;
	c = broj % 10;
	int suma = (pow(a, 3) + pow(b, 3) + pow(c, 3));
	if (suma == broj)
		return true;
	else
		return false;

}

void sortiraj(int n[], int v){

	bool prolaz = true;
	int temp = 0;

	while (prolaz){
		prolaz = false;
		for (int i = 0; i <v-1 ; i++)
		{
			if (n[i]>n[i + 1]){
				temp = n[i];
				n[i] = n[i + 1];
				n[i + 1] = temp;
				prolaz = true;
			}
		}
		v--;
	}


}

float medij(int niz[])
{
	return (niz[1] + niz[2]) / 2.0;
}
*/




//------------------------------------------------------------------------------------------------------------------------

/*
#include <iostream>
#include <iomanip>
using namespace std;



const int red = 4;
const int kol = 4;

int srednjaCif(int);
void unos(int[][kol]);
int broj_cifara(int);
void ispis(int[][kol], bool);
int max_element(int[][kol]);

void main() {
	char izbor;
	int niz[red][kol];



	cout << "Unesite elemente 2D niza" << endl;
	unos(niz);

	cout << "Unesite izbor y za ispis elemennata koje je korisnik unio ili n za ispis citavog 2d niza " << endl;
	do
	{
		cin >> izbor;
	} while (!(izbor == 'y' || izbor == 'n'));
	izbor == 'y' ? izbor = true : izbor = false;

	ispis(niz, izbor);

	cout << "Element koji ima najvise cifara je " << max_element(niz) << endl;


	system("pause>0");


}
int broj_cifara(int broj) {
	int brojac = 0;
	while (broj > 0) {
		broj /= 10;
		brojac++;
	}
	return brojac;
}
int srednjaCif(int broj) {
	int brojacCif = broj_cifara(broj);
	if (brojacCif % 2 == 0) {
		int prvi = broj / pow(10, (brojacCif / 2));
		int drugi = broj / pow(10, ((brojacCif / 2) - 1));
		return ((prvi % 10 + drugi % 10) / 2);
	}
	else {
		int pom = broj / pow(10, brojacCif / 2);
		return pom % 10;
	}
}

void unos(int n[][kol]) {

	for (int i = 0; i < red; i += 2)
	{
		for (int j = 0; j < kol; j++) {


			cin >> n[i][j];

			n[i + 1][j] = srednjaCif(n[i][j]);

		}
	}
}
void ispis(int n[][kol], bool izbor) {

	for (int i = 0; i < red; izbor ? i += 2 : i++)
	{
		for (int j = 0; j < kol; j++)
		{
			cout << setw(5) << n[i][j];

		}
		cout << endl;
	}
}

int max_element(int n[][kol]) {
	int najveci = n[0][0];
	for (int i = 0; i < red; i += 2)
	{
		for (int j = 0; j < kol; j++) {
			if (broj_cifara(najveci) < broj_cifara(n[i][j])) {
				najveci = n[i][j];
			}
		}
	}

	return najveci;
}
*/