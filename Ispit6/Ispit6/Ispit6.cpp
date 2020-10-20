///////////////////////////////////////////// INTEGRALNI ISPIT (18.2.2017) GRUPA A /////////////////////////////////////////

//Poštujući sve faze procesa programiranje, napisati program koji izračunava sumu svih brojeva u interval od 2 do n  koji su
//stepeni broja 2. Granična vrijednost n se unosi na početku glavnog programa, pri čemu je potrebno voditi računa da se podrži
//što veća granična vrijednost.Kreirati pomoćnu funkciju DaLiJeStepen2 za provjeru da li je proslijeđeni broj stepen broja 2
//(stepeni broja 2 su: 2, 4, 8, 16, 32…).Izračun i ispis sume uraditi u glavnom programu.
//Unesite gornju granicu intervala : 64
//Suma brojeva koji se mogu napisati kao stepen broja 2 u intervalu[2, 64] je : 126

/*
#include <iostream>
using namespace std;

int jeLiStepen2(int);

void main(){
	int n;
	int donja = 2;

	cout << "Unesite gornju granicu intervala: ";
	cin >> n;
	cout << endl;

	float s = 0;
	for (int i=donja; i <=n ; i++)
	{
		if (jeLiStepen2(i))
			s += i;

	}

	cout << "Suma brojeva koji se mogu napisati kao stepen broja 2 u intervalu [" << donja << ", " << n << "] je: " << s << endl;


	system("pause>0");
}

int jeLiStepen2(int broj){

		for (int j = 0; j <= broj; j++)
		{
			if (pow(2, j) == broj)
				return broj;
		}

	return 0;
}
*/


//------------------------------------------------------------------------------------------------------------------ -

//Napisati program koji učitava dva pozitivna cijela broja i ispisuje uniju cifara učitanih brojeva.
//Cifre treba ispisati sortirane po veličini od najmanje ka najvećoj.Svaku cifru ispisati samo jedanput.
//Pomoć: Za pohranu zajedničkih cifara koristiti niz od 10 cijelih brojeva.
//Unesite dva cijela broja : 2017 68105
//Zajednicke cifre : 0 1 2 5 6 7 8


/*
#include <iostream>
using namespace std;

void ispisNiza(int[], int);
bool seNalaziUNizu(int, int[], int);
void staviUNiz(int, int[], int &);
void sortiranje(int[], int);
void ispisUnije(int, int);

void main(){
	int prvi = 0, drugi = 0;

	cout << "Unesite dva pozitivna cijela broja " << endl;
	do {
		cin >> prvi >> drugi;

	} while (prvi < 0 && drugi < 0);

	ispisUnije(prvi, drugi);


	system("pause>0");
}

void ispisNiza(int n[], int vel){
	for (int i = 0; i <vel ; i++)
	{
		cout << "niz[" << i << "]" << n[i] << endl;
	}

}

bool seNalaziUNizu(int znamenka, int n[], int vel){
	for (int  i = 0; i <vel ; i++)
	{
		if (n[i] == znamenka)
			return true;
	}
	return false;
}

void staviUNiz(int broj, int n[], int &brojac){

	int znamenka = 0;
	while (broj > 0){
		znamenka = broj % 10;
		if (!(seNalaziUNizu(znamenka, n, brojac)))
		{
			n[brojac] = znamenka;;
			brojac++;
		}
		broj /= 10;
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

			if (niz[i]>niz[i + 1])
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

void ispisUnije(int br1, int br2){

	int niz[10];
	int brojac = 0;
	staviUNiz(br1, niz, brojac);
	staviUNiz(br2, niz, brojac);
	sortiranje(niz, brojac);
	ispisNiza(niz, brojac);

}
*/


//-----------------------------------------------------------------------------------------------------------------------------

//PRESJEK DVA SKUPA npr. 2017 i 65801 ---> 0 i 1 ///

/*
#include <iostream>
using namespace std;


void presjek(int a, int b, int niz[], int &vel)
{
	int temp = b;
	do {
		int provjera = a % 10;

		b = temp;
		do {
			int provjera1 = b % 10;

			if (provjera == provjera1)
			{
				bool dodaj_a = true;
				for (int i = 0; i < vel; i++)
				{
					if (niz[i] == provjera)
						dodaj_a = false;
				}
				if (dodaj_a == true)
					niz[vel++] = provjera;
			}
			b /= 10;
		} while (b != 0);
		a /= 10;
	} while (a != 0);

}

void sortiraj(int niz[], int &vel)
{
	bool promjena = true;
	while (promjena)
	{
		promjena = false;
		for (int i = 0; i < vel - 1; i++)
		{
			if (niz[i] > niz[i + 1])
			{
				int temp = niz[i];
				niz[i] = niz[i + 1];
				niz[i + 1] = temp;
				promjena = true;
			}

		}
	}
}

void main()
{
	int a, b;
	cin >> a >> b;
	int vel = 0;
	int niz[10];
	cout << "Zajednicke cifre" << endl;

	presjek(a, b, niz, vel);
	sortiraj(niz, vel);
	for (int i = 0; i < vel; i++)
	{
		cout << niz[i] << " ";
	}

	system("pause>0");

}*/

//-------------------------------------------------------------------------------------------------------------- -

//Napisati program koji od korisnika zahtijeva unos niza od najviše 20 realnih brojeva u rasponu od - 100 do 100.
//U slučaju da korisnik unese bilo koji broj izvan datog raspona korisnik ponavlja unos tog elementa niza.
//Također, unos je moguće prekinuti prije nego što se dostigne kapacitet niza unosom broja 0 koji ne treba da bude element niza i služi
//samo za prekid.Nakon toga, program računa aritmetičku sredinu unesenih brojeva, te iz niza izbacuje sve one elemente čija je udaljenost
//od aritmetičke sredine veća od 10, na način da se sačuva redoslijed dodavanja elemenata.Implementaciju uraditi upotrebom sljedećih funkcija :
//•	void unos(double[], int, int&); gdje je treći parametar stvarna veličina niza nakon unosa;
//•	double aritmeticka_sredina(double[], int);
//•	void ukloni(double[], double, int&); gdje je drugi parametar aritmetička sredina, a posljednji veličina niza nakon uklanjanja elemenata.
//U glavnom programu testirati dostupne funkcije, te obaviti ispis elemenata niza nakon uklanjanja vodeći se datim primjerom izlaza.
//Unesite elemente niza : 2.5 - 8.9 15.89 16.78 34 25 11 0
//Aritmeticka sredina elemenata niza iznosi : 13.75
//Sadrzaj niza nakon uklanjanja : 15.89 16.78 11.00



/*
#include <iostream>
using namespace std;

const int vel = 20;

void unos(double[], int, int&);
double aritmeticka_sredina(double[], int);
void ukloni(double[], double, int&);

void main() {

	int brojac = 0, brojacNakon = 0;
	double niz[20];
	unos(niz, vel, brojac);
	cout << "Velicina niza je: " << brojac << endl;


	cout << endl << "Aritmeticka: " << aritmeticka_sredina(niz, brojac) << endl;
	brojacNakon = brojac;
	ukloni(niz, aritmeticka_sredina(niz, brojac), brojacNakon);





	system("pause>0");
}

void unos(double n[], int vel, int& brojac) {

	for (int i = 0; i < vel; i++)
	{
		cout << "Unesite element" << endl;
		cin >> n[i];
		if (n[i] < -100 || n[i]>100) {
			i--;
		}
		if (n[i] == 0) {
			break;

		}
		brojac++;
	}
}


double aritmeticka_sredina(double niz[], int n) {
	double suma = 0;
	for (size_t i = 0; i < n; i++)
	{
		suma += niz[i];

	}

	return (float)suma / n;
}
void ukloni(double niz[], double ar, int& n) {
	for (size_t i = 0; i < n; i++)
	{
		if (niz[i]<ar - 10 || niz[i]>ar + 10) {
			cout << endl << "Oklonjen je broj: " << niz[i] << endl;
			for (size_t j = i; j < n; j++)
			{
				cout << endl << "Broj " << niz[j] << "je zamjenjen sa brojem " << niz[j + 1] << endl;
				niz[j] = niz[j + 1];
			}
			n--;
			i--;
			cout << endl << endl;
			for (size_t k = 0; k < n; k++)
			{
				cout << " " << niz[k];
			}

		}
	}
	cout << "Sadrzaj niza nakon uklanjanja : ";
	cout << endl << endl;
	for (size_t i = 0; i < n; i++)
	{
		cout << " " << niz[i];
	}
}
*/



//------------------------------------------------------------------------------------------------------------------------------ -


//Neka je data matrica kompetencija studenata dimenzija 10x5, gdje svaki red matrice predstavlja studenta,
//a svaka kolona matrice kompetenciju koju je potrebno evaluirati.Matrica sadrži podatke o studentima sa dva studijska programa, prvih 5
//redova za jedan i drugih 5 redova za drugi program.Kompetencije se definišu putem sljedeće skale : A(ekspert), B(stručnjak), C(zadovoljava),
//D(djelimično zadovoljava) i E(ne zadovoljava).Napisati program koji će implementirati i testirati sljedeće funkcije :
//• evaluiraj – funkcija omogućava unos evaluacije za određenog(odabranog u glavnom programu) studenta(unosi se samo jedan red matrice),
//na način da su dozvoljene samo vrijednosti usvojene prethodnom skalom(A, B, C, D i E).U slučaju unosa bilo kojeg karaktera izvan ovog opsega,
//potrebno je ponoviti unos.Prilikom unosa ispisati poruku za svaku kompetenciju na sljedeći način : „Unesite evaluaciju za kompetenciju C1“,
//i tako redom za svaku kolonu.
//
//• najuspjesnija_kompetencija – funkcija pronalazi kompetenciju(u oba studijska programa) koja je najuspješnija,
//odnosno na kojoj su studenti ostvarili najbolji rezultat, te vraća i prosječnu ocjenu za tu kompetenciju.
//Napomena : Pridružiti svakoj oznaci numeričku vrijednost, radi jednostavnosti kalkulacije i poređenja uspjeha pojedinih kompetencija.
//Koristiti prosljeđivanje najmanje jednog parametra po referenci, te ispis rezultata ne vršiti u funkciji.
//
//• najuspjesniji_student – funkcija pronalazi najuspješnijeg studenta u odabranom studijskom programu(studijski program se bira u
//glavnom programu putem vrijednost 1 (prvih 5 redova) ili 2 (drugih 5 redova), te vraća i prosječnu ocjenu tog studenta.
//Vrijede iste napomene kao i za prethodnu funkciju.
//
//U glavnom programu testirati implementirane funkcije na način da se uz uspjeh kompetencije ili studenta definiše opisna evaluacija
//(ekspert, stručnjak, ...).Dodatno ispisati podatke o najuspješnijem studentu, posmatrajući oba studijska programa.
//Ispis najsupješnije kompetencije ili studenta izvršiti sa oznakama C ili S, uz redni broj kolone ili reda gdje se nalaze u matrici.
//Npr.Najuspješniji student je S2 sa prosječnom ocjenom „stručnjak“.


/*
#include <iostream>
using namespace std;

const int r = 10, k = 5;

void evaluiraj(char[], int);
void ispis(char[][k]);
double najkomp(int[][k], int&);
void konverzija(char[][k], int[][k]);
void funkcijaZaProsjek(int[][k]);
int konverzijaUBroj(char, int);
int main() {

	char niz[r][k] = {};
	int niz2[r][k] = {};
	int izbor, iz2;
	cout << "Izaberite neke od sljedecih vrijednosti: " << endl;
	cout << "A = " << int('A') << endl;
	cout << "B = " << int('B') << endl;
	cout << "C = " << int('C') << endl;
	cout << "D = " << int('D') << endl;
	cout << "E = " << int('E') << endl;
	cout << "-----------------------" << endl;
	do {
		cout << "Kojeg studenta zelite evaluirati ? " << endl;
		do {
			cin >> izbor;
		} while ((izbor > 10 || izbor < 1) || niz[izbor - 1][0] != 0);
		evaluiraj(niz[izbor - 1], k);
		cout << "Da li zelite jos evaluacija ? (0 za ne)" << endl;
		cin >> iz2;
	} while (iz2 != 0);
	konverzija(niz, niz2);
	ispis(niz);
	cout << endl;
	funkcijaZaProsjek(niz2);


	system("pause>0");
	return 0;
}



void funkcijaZaProsjek(int niz[][k])
{
	float suma = 0;

	int indeks;

	float najveci = 0;
	for (int i = 0; i < k; i++)
	{
		int brojac = 0;
		float prosjek = 0;
		for (int j = 0; j < k; j++)
		{
			suma += niz[i][j];
			brojac++;

		}

		prosjek = suma / brojac;
		cout << "prosjek za " << i + 1 << ". studenta je" << prosjek << endl;
		if (prosjek > najveci)
		{
			najveci = prosjek;
			indeks = i;
		}
		suma = 0;
		prosjek = 0;
	}
	cout << "Najbolji prosjek ima kompetencija sa iznosom : " << najveci << " i njegov indeks je  " << indeks + 1 << endl;
}

double najkomp(int niz[][k], int& najK) {
	int naj = 0, suma = 0, brojac = 0;
	for (int i = 0; i < k; i++)
	{
		brojac = 0;
		for (int j = 0; j < r; j++)
		{
			suma += niz[j][i];
			if (niz[j][i] != 0)
				brojac++;
		}
		if (suma > naj) {
			naj = suma;
			najK = i;
		}
		suma = 0;

	}
	return (naj / brojac);

}

void evaluiraj(char niz[], int k) {

	for (int i = 0; i < k; i++) {
		cout << "Unesite evaluaciju za " << i + 1 << " : " << endl;
		do {
			cin >> niz[i];
		} while (!(niz[i] == 'A' || niz[i] == 'B' || niz[i] == 'C' || niz[i] == 'D' || niz[i] == 'E'));
	}
}


void ispis(char niz[][k]) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < k; j++) {
			cout << niz[i][j] << "  ";
		}
		cout << endl;
		if (i == 4)
			cout << endl;
	}
}

void konverzija(char niz[][k], int niz2[][k]) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < k; j++)
			switch (niz[i][j]) {
				{
			case 'A':
				niz2[i][j] = (int)niz[i][j];// konverzijaUBroj(niz[i][j], niz2[i][j]);
				break;
			case 'B':
				niz2[i][j] = (int)niz[i][j];
				break;
			case 'C':
				niz2[i][j] = (int)niz[i][j];
				break;
			case 'D':
				niz2[i][j] = (int)niz[i][j];
				break;
			case 'E':
				niz2[i][j] = (int)niz[i][j];
				break;
				}
			}
	}

}


int konverzijaUBroj(char zn, int broj) {

	return (int)zn;

}
*/

//------------------------------------------------------------------------------------------------------------------------------------