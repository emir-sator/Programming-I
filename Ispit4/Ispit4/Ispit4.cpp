//Poštujući sve faze procesa programiranje, napisati program će odrediti i ispisati zadnje tri cifre broja x^ n.Unos brojeva x i n vršiti
//u glavnoj funkciji uz uslov 10 < x < 100 i 2 < n < 10, a funkciju za određivanje zadnje tri cifre napraviti zasebno.
//	Primjer izlaza :
//Unesite brojeve x i n : 64 i 5
//Zadnje tri cifre broja su : 824

/*
#include <iostream>
using namespace std;

int triZadnje(int, int);

void main()
{
	int x, n;
	do{

		cout << "Unesite x" << endl;
		cin >> x;
	} while (x <= 10 || x >= 100);

	do {
		cout << "Unesite n" << endl;
		cin >> n;
	} while (n <= 2 || n >= 10);

	cout << "Tri zadnje cifre su: " << triZadnje(x, n) << endl;



	system("pause>0");
}



int triZadnje(int x, int n){

	int broj = pow(x, n);
	int zadnje3cifre = broj % 1000;

	return zadnje3cifre;
}

*/


//----------------------------------------------------------------------------------------------------------------

//Napisati program koji će učitati prirodni broj n ≤ 10, a zatim n prirodnih trocifrenih brojeva koje treba pospremiti
//u odgovarajući niz.Taj niz brojeva treba sortirati uzlazno po srednjoj cifri.Nakon sortiranja treba ispisati dobiveni niz.
//Za sortiranje koristiti zasebnu funkciju kojoj se proslijeđuje nesortiran niz.

/*
#include <iostream>
using namespace std;

void sortiranje(int[], int);
int srednjaCif(int);
int broj_cifara(int);
void ispis(int[], int);

void main(){
	int n;
	int niz[10];
	cout << "Unesite  prirodan broj n" << endl;

	do{
		cin >> n;
	} while (n  >=11 || n < 0);

	for (int  i = 0; i <n ; i++)
	{
		cin >> niz[i];
		if (niz[i] < 100 || niz[i]>1000){
			i--;
		}
	}

	cout << "Prije sortiranja" << endl;

	ispis(niz, n);
	cout << "Nakon sortiranja" << endl;
	sortiranje(niz, n);
	ispis(niz, n);

	system("pause>0");
}

int broj_cifara(int broj){
	int brojac = 0;
	while (broj > 0){
		broj /= 10;
		brojac++;
	}
	return brojac;
}

int srednjaCif(int broj){
	int brojacCif = broj_cifara(broj);
	if (brojacCif % 2 == 0){
		int prvi = broj / pow(10, (brojacCif / 2));
		int drugi = broj / pow(10, ((brojacCif / 2) - 1));
		return ((prvi % 10 + drugi % 10) / 2)+0.5;
	}
	else{
		int srednja = broj / pow(10, brojacCif / 2);
		return srednja % 10;
	}
}

void sortiranje(int niz[], int n)
{
	bool promjena = true;
	int privremeni;

	while (promjena)
	{
		promjena = false;
		for (int i = 0; i<n - 1; i++)

		{

			if (srednjaCif(niz[i])>srednjaCif(niz[i + 1]))
			{
				privremeni = niz[i];
				niz[i] = niz[i + 1];
				niz[i + 1] = privremeni;
				promjena = true;
			}

		}
		n--;
	}

}





void ispis(int niz[], int n){

	for (size_t i = 0; i <n ; i++)
	{
		cout << " " << niz[i];
	}
	cout<<endl;
}

*/



//------------------------------------------------------------------------------------------------------------------------ -


//Napisati program koji će omogućiti :
//•	Unos 2D niza od 10x10 elemanata vodeći računa da su svi elementi dvocifreni(ukoliko unos nekog elementa
//	ne zadovoljava uslov, ponavljati unos tog elementa dok se ne zadovolji uslov) – Koristiti funkciju unos
//	•	Izvršiti transpoziciju niza tako što će se zamjeniti redovi i kolone – Koristiti funkciju transpose, a zatim na osnovu izmijenjenog 2D niza :
//•	Izračunati aritmetičku sredinu svih prostih brojeva ispod sporedne dijagonale – Koristiti dvije funkcije :
//aritmeticka i prost_broj(pozivati će se iz funkcije aritmeticka)
//•	Napisati funkciju simpatican koja će provjeriti da li su brojevi iznad sporedne dijagonale simpatični * .
//Obavezno koristiti navedene funkcije, a parametre i eventualne povratne vrijednosti definisati prema potrebi.
//U main() funkciji napisati testni program koji će omogućiti izvršenje svih funkcija navedenim redoslijedom.

/*
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

const int vel = 10;
void unos(int[][vel]);
void transpose(int[][vel]);
float aritmeticka(int[][vel]);
bool prost(int);
bool isSimpatican(int);
void simpatican(int[][vel]);
void ispis(int[][vel]);
void ispisProstih(int[][vel]);

void main(){

	int niz[vel][vel];


	unos(niz);
		cout << "Elementi niza su" << endl;
		ispis(niz);
		cout << "Transponovana matrica izgleda ovako" << endl;
		transpose(niz);
		ispis(niz);
		cout << "Prosti brojevi ispod sporedne dijagonale su" << endl;
		ispisProstih(niz);
		cout << "Aritmeticka sredina svih prostih broejva ispod sporedne dijagonale iznosi: " << aritmeticka(niz) << endl;

		cout << "Simpaticni brojevi iznad sporedne dijagonale su:" << endl;
		simpatican(niz);

	system("pause>0");
}

void unos(int niz[][10]){


	for (int  i = 0; i <vel ; i++)
	{
		for (int j = 0; j < vel; j++){

			niz[i][j] = rand() % 99 + 1;
			if (niz[i][j] < 10)
				j--;
		}
	}
}

void ispis(int niz[][10]){

	for (size_t i = 0; i <vel ; i++)
	{
		for (int j = 0; j < vel; j++){

			cout << setw(5) << niz[i][j];
		}
		cout << endl;
	}

}

void transpose(int niz[][10]){

	int temp = 0;
	for (size_t i = 0; i <vel ; i++)
	{
		for (int j = 0; j < vel; j++){

			if (j > i){
				temp = niz[i][j];
				niz[i][j] = niz[j][i];
				niz[j][i] = temp;
			}
		}
	}

}

bool prost(int broj){


	for (int i = 2; i <broj/2 ; i++)
	{
		if (broj%i == 0)
			return false;


	}
	return true;
}
void ispisProstih(int niz[][10]){

	for (size_t i = 0; i <vel; i++)
	{
		for (int j = 0; j < vel; j++){
			if (i + j>vel - 1 && prost(niz[i][j]))
			cout << setw(5) << niz[i][j];
		}
		cout << endl;
	}

}

float aritmeticka(int niz[][10]){
	float s = 0;
	int brojac = 0;
	for (int  i = 0; i <vel ; i++)
	{
		for (int j = 0; j < vel; j++){

			if ((i + j)>(vel - 1) && prost(niz[i][j])){
				s += niz[i][j];
				brojac++;
			}
		}
	}
	return (float)s / brojac;
}

bool isSimpatican(int broj){
	int kvadrat = broj*broj;
	int zbirKvadrata = 0;
	int zbirBroj = 0;
	while (kvadrat > 0){
		zbirKvadrata += kvadrat % 10;
		kvadrat /= 10;
	}
	while (broj > 0){
		zbirBroj += broj % 10;
		broj /= 10;
	}
	zbirBroj *= 2;
	if (zbirKvadrata == zbirBroj)
		return true;
	else
		return false;


}

void simpatican(int niz[][vel]){

	for (int i = 0; i <vel ; i++)
	{
		for (int j = 0; j < vel; j++){
			if (i + j < vel - 1 && isSimpatican(niz[i][j]))
				cout << "Simpatican broj je: " << niz[i][j] << endl;

		}
	}

}
*/