//--------------------------------------------------------------------------------------------------------------------

///////////////////////////////////////////// INTEGRALNI ISPIT (18.2.2017) GRUPA B /////////////////////////////////////////////

//Napišite program koji učitava prirodni broj n.Program treba ispisati najmanji prirodni broj m, veći ili jednak n,
//koji je potencija nekog prirodnog broja, tj.m = k ^ l, gdje su k i l ≥ 2 prirodni brojevi.U glavni program unijet prirodan broj n,
//a u funkciji potencija vršiti provjeru te rezultat vratiti u glavni program.
//
//Primjer, za n = 70, rezultat je m = 81 = 3 ^ 4 = 9 ^ 2.


/*
#include <iostream>
using namespace std;

int potencija(int);

void main(){

	int broj = 0;
	cout << "Unesite jedan prirodan broj" << endl;
	do{
		cin >> broj;
	} while (broj < 0);

	cout << "Broj koji je potencija nekog prirodnog broja je " << potencija(broj) << endl;


	system("pause>0");
}

int potencija(int broj){

	int najblizi = INT_MAX;
	int m;
	int temp;
	for (int  i = 2; i <100 ; i++)
	{
		for (int j = 2; j < 100; j++){
			temp = najblizi;
			m = pow(i, j);
			if (m >= broj)
				najblizi = m;

			if (temp >= broj && temp <= m)
				najblizi = temp;
		}
	}
	return najblizi;


}
*/
/*
#include <iostream>
using namespace std;

void potencije(int broj) {
	int sljed = INT_MAX;
	int powiraj;
	for (int i = 2; i < 10; i++) {
		for (int j = 2; j < 10; j++) {
			powiraj = pow(j, i);
			if (powiraj > broj && powiraj <= sljed) {
				sljed = powiraj;
				cout << powiraj << " " << j << "^" << i << endl;
				break;
			}
		}
	}
}
void  main() {


	int broj = 0;
	cout << "Unesite broj" << endl;
	cin >> broj;

	cout << "Rezultat je:" << endl;
	potencije(broj);
	system("pause>0");
}*/


//-------------------------------------------------------------------------------------------------------------------------------- -

//Napišite program u kojem ćete omogućiti kreiranje niza od 6 cjelobrojnih elemenata.Pretpostavka je da postoji funkcija koja
//omogućava unos brojeva u niz(ne treba ju definirati niti pozivati);
//•	definirati i upotrijebiti funkciju void pronaci(int[], int); koja će pronaći i ispisati dva najveća elementa u nizu;
//•	definirati i upotrijebiti funkciju float suma(int[], int); koja će izračunati sumu recipročnih vrijednosti elemenata niza;
//(Recipročna vrijednost broja n je 1 / n.)
//•	definirati i upotrijebiti funkciju int prebroji(int[], int) koja treba ispisati sve pozitivne elemente niza i njihove indekse,
//te prebrojati koliko takvih elemenata ima;
//Ispis sume recipročnih vrijednosti i broja pozitivnih elemenata vršiti u funkciji main.

/*
#include <iostream>
using namespace std;

const int vel = 6;

void unos(int[], int);
void pronaci(int[], int);
float suma(int[], int);
int  prebroji(int[], int);
void ispis(int[], int);

void main(){

	int niz[vel];

	cout << "Unesite elemente niza" << endl;
	unos(niz, vel);

	cout << "Elementi niza su " << endl;
	ispis(niz, vel);

	cout << "Suma reciprocnih vrijednosti elemenata niza iznosi " << suma(niz, vel) << endl;

	cout<<" Pozitivnih elemenata ima  "<<prebroji(niz, vel);

	pronaci(niz, vel);


	system("Pause>0");
}

void unos(int n[], int vel){

	for (size_t i = 0; i <vel ; i++)
	{
		cin >> n[i];
	}


}

void ispis(int n[], int vel){

	for (size_t i = 0; i <vel; i++)
	{
		cout << n[i] << endl;
	}


}

float suma(int n[], int vel){

	double  s = 0;
	for (size_t i = 0; i < vel; i++)
	{
		s += 1/n[i];
	}

	return s;

}

int prebroji(int n[], int){

	int pozicija =0, brojac = 0;

	for (size_t i = 0; i < vel; i++)
	{
		if (n[i]>0){
			cout << "Pozitivni brojevi su "<< n[i] << " i njegov indeks je " <<i<< endl;
			brojac++;

		}

	}
	return brojac;


}

void pronaci(int n[], int vel){
	int  veci = 0, manji = 0;
	int prvi = 0, drugi = 0;
	for (int k = 0; k <2 ; k++)
	{
		for (int i = 0; i < vel; i++){
			if (k == 0 && n[i] > n[veci]){
				veci = i;
				prvi = n[veci];
			}
			else if (k == 1 && veci != i &&n[i] > n[manji]){
				manji = i;
				drugi = n[manji];
			}

		}
	}
	cout << "Prvi najveci elemnt niza je " << prvi << endl;
	cout << "Drugi najveci elemnt niza je " << drugi << endl;
}
*/


//------------------------------------------------------------------------------------------------------------------------------------

//Napisati program koji će korisniku omogućiti unos pozitivnih neparnih cijelih brojeva za koje će se ispitivati da li im je prva cifra parna(npr. 4993 ili 4999).
//Ukoliko je zadovoljen uslov broj se smješta u niz od 10 elemenata.Unos se ponavlja dok se ne popuni niz od 10 elemenata koji zadovoljavaju uslov unosa.
//Unos se prekida ukoliko korisnik unese vrijednost 0 te se i izvršenje program završava uz poruku „Forsirani prekid“.
//Zatim se za sve elementi niza ispituje da li je broj prost i da li ima samo jednu parnu cifru.Ako  broj nije prost i ako ima više od jedne parne cifre,
//broj se izbacuje iz niza tako što se njegova vrijednost mijenja sa 0. Na kraju niz sortirati od najvećeg ka najmanjem broju te ga ispisati.
//Koristiti odvojene funkcije za provjeru da li je broj prost, za sortiranje i ispis niza.

/*
#include <iostream>
using namespace std;

const int v = 10;

void unos(int[], int);
bool prost(int);
bool jednaParna(int);
bool prvaParna(int);
void ispis(int[], int);
void promjena(int[], int);
void sort(int[], int);

int main() {
	int niz[v] = {};

	cout << "Unesi pozitivne neparne brojeve" << endl;
	unos(niz, v);
	cout << "Elementi su" << endl;
	ispis(niz, v);
	promjena(niz, v);
	cout << "Nakon zamjene" << endl;
	ispis(niz, v);
	sort(niz, v);
	cout << "Nakon sortiranja" << endl;
	ispis(niz, v);

	system("pause>0");
	return 0;
}

void unos(int niz[], int v) {
	cout << "Unesite clanove niza : ";
	for (int i = 0; i < v; i++) {
		cin >> niz[i];
		if (niz[i] == 0)
		{
			cout << "Forsirani prekid " << endl;
			return;
		}
		if (niz[i] % 2 == 0 || prvaParna(niz[i]) || niz[i] < 0)
			i--;
	}
}

bool prvaParna(int x) {
	/*int brojCifri = 0, kopija = x, prva;
	do {

		brojCifri++;
		kopija /= 10;
	} while (kopija > 0);
	prva = x / pow(10, brojCifri - 1);
	if (prva % 2 == 0)
		return false;
	else
		return true;

	int kopija = x;
	while (kopija > 0){
		kopija /= 10;
		kopija % 10;

	}
	if (kopija % 2 == 0)
		return false;
	else
		return true;


}

bool prost(int x) {
	for (int i = 2; i <= x / 2; i++) {
		if (x%i == 0) {
			return false;
		}
	}
	return true;
}

bool jednaParna(int x) {
	int brojacParnih = 0, cifra;
	do {
		cifra = x % 10;
		if (x % 2 == 0)
			return false;
		x /= 10;
	} while (x > 10);

	return true;
}

void ispis(int niz[], int v) {
	for (int i = 0; i < v; i++)
		cout << niz[i] << " ";
	cout << endl;
}

void promjena(int niz[], int v) {
	for (int i = 0; i < v; i++) {
		if (!(jednaParna(niz[i]) && prost(niz[i])))
			niz[i] = 0;

	}
}

void sort(int n[], int vel) {
	bool prolaz = true;
	int temp = 0;
	while (prolaz){
		prolaz = false;
		for (int i = 0; i <vel - 1; i++)
		{
			if (n[i]>n[i + 1])
			{
				temp = n[i];
				n[i] = n[i + 1];
				n[i + 1] = temp;
				prolaz = true;
			}
		}
		vel--;
	}
}
*/


//-------------------------------------------------------------------------------------------------------------------------------------------

//Deklarisati kvadratnu matricu cijelih brojeva proizvoljnih dimenzija, te implementirati sljedeće funkcije :
//•	Funkciju za unos i formiranje elemenata matrice prema sljedećem obrascu : elemente neparnih redova matrice(1., 3., 5. itd.)
//    čine minimalno trocifreni brojevi koje unosi korisnik programa(u slučaju unosa bilo kojeg broja koji ne zadovoljava postavljeni uslov,
//    ponoviti unos); elementi parnih redova matrice se formiraju na osnovu elemenata iz prethodnog reda u istoj koloni matrice
//    i to na način da je svaki novokreirani element matrice zapravo element s obrnutim redoslijedom cifri elementa iznad njega.
//•	Za određivanje broja s obrnutim redoslijedom cifri kreirati zasebnu funkciju obratno, te je pozvati u funkciji unos.
//•	Takvu matricu proslijediti zasebnoj funkciji max koja će formirati novi jednodimenzionalni niz čije članove čine najveći članovi
//	matrice po redovima te ispisati ove članove.
//•	Formirati posebnu funkciju iznad_dijagonala koja će ispisati broj elemenata matrice koji se nalaze iznad glavne i sporedne dijagonale.
//	Ove elemente unutar funkcije spremati u niz čija veličina zavisi od dimenzije matrice.Veličina niza treba biti fiksna i mora odgovarati točnom broju elemenata.
//	Kreirati kratki testni program koji demonstrira funcionalnost kreiranih funkcija.
//	Primjer matrice dimenzija 4x4 i očekivanih rezultata je dat ispod.Elementi iznad obje dijagonale  su : 123, 30452.
//
//	2163	123	30452	671
//	3612	321	25403	176
//	7331	6113	741232	798
//	1337	3116	232147	897
//
//	Funkcija max će ispisati sljedeće brojeve : 30452, 25403, 741232, 232147 jer su to najveći brojevi po redovima.


/*
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

const int vel = 4;

void unos(int[][vel]);
int obrnutiBr(int);
void iznad_glavne_sporedne(int[][vel]);
void unosMax(int[], int[], int);
void max(int[][vel]);
void ispis(int[][vel]);
void ispis1(int[], int);

void main() {

	int niz[vel][vel];

	cout << "Unesite elemente 2d niza" << endl;
	unos(niz);
	cout << "Elementi su" << endl;
	ispis(niz);

	cout << "4 najveca po redovima u u 2d nizu su" << endl;
	max(niz);

	cout << "Elementi iznad glavne i iznad sporedne dijagonale su" << endl;
	iznad_glavne_sporedne(niz);


	system("Pause>0");
}

void unos(int n[][vel]) {

	for (int i = 0; i < vel; i += 2)
	{
		for (int j = 0; j < vel; j++) {

			cin >> n[i][j];
			n[i + 1][j] = obrnutiBr(n[i][j]);

			if (n[i][j] < 100)
				j--;

		}
	}
}

void ispis(int n[][vel]) {

	for (int i = 0; i < vel; i++)
	{
		for (int j = 0; j < vel; j++) {
			cout << setw(10) << n[i][j];


		}
		cout << endl;
	}
}

int obrnutiBr(int broj) {

	int obrnuti = 0;
	while (broj > 0) {

		obrnuti *= 10;
		obrnuti += broj % 10;
		broj /= 10;


	}

	return obrnuti;


}

void unosMax(int n[], int redUMatrici[], int lokacija) {
	int najveci = redUMatrici[0];
	for (int i = 0; i < vel; i++)
	{
		if (redUMatrici[i] > najveci)
			najveci = redUMatrici[i];
	}
	n[lokacija] = najveci;



}

void max(int n[][vel]) {

	int niz[vel];
	for (int i = 0; i < vel; i++)
	{
		unosMax(niz, n[i], i);

	}
	ispis1(niz, vel);
	cout << endl;
}

void ispis1(int n[], int velicina) {

	for (int i = 0; i < velicina; i++)
	{

		cout << "  " << n[i];
	}
}

void iznad_glavne_sporedne(int n[][vel]) {

	for (int i = 0; i < vel; i++)
	{
		for (int j = 0; j < vel; j++)
		{

			if (i < j && i + j < vel - 1)
				cout << " " << n[i][j];
		}
	}
}
*/


//-------------------------------------------------------------------------------------------------------------------- -

