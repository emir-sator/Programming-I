///////////////////////////////////////////// INTEGRALNI ISPIT (16.9.2017) GRUPA : B /////////////////////////////////////

//Poštujući sve faze procesa programiranja napraviti program koji pronalazi i ispisuje sve složene brojeve brojeve iz intervala m - n(10 < m < 100, 500 < n < 2000, m < n;
//ukoliko unesene vrijednosti nisu ispravne, učitavanje treba ponavljati), te pronalazi i ispisuje njihovu aritmetičku sredinu.Napraviti sljedeće funkcije :
//-bool slozeni – koja će ispitivati da li je broj složeni i
//- ispis – koja koja će ispisivati sve složene brojeve i vratiti main funkciji njihovu aritmetičku sredinu.
//U glavnom programu je potrebno ispisati aritmetičku sredinu.Složeni broj je svaki broj koji nije prosti, odnosno koji ima bar jednog
//djelioca osim broja 1 i samog sebe.

/*
#include <iostream>
using namespace std;

bool slozeni(int);
float ispis(int, int);

void main(){

	int m, n;

	cout << "Unesite intervale" << endl;

	do{
		cin >> m >> n;
		if (m < 10 || m>100 || n < 500 || m>2000 && n < m)
			cout << "Pogresan unos. Ponovite" << endl;
	} while (m < 10 || m>100 || n < 500 || m>2000 && n > m);

	cout << "Aritmeticka sredina slozenih brojeva u intervalu od m do n je: " << ispis(m, n) << endl;


	system("pause>0");
}

bool slozeni(int broj){

	for (int i = 2; i <= broj/2; i++)
	{
		if (broj%i==0)
			return true;
	}
	return false;
}


float ispis(int donja, int gornja){
	float s = 0;
	int brojac = 0;
	for (size_t i = donja; i <= gornja; i++)
	{
		if (slozeni(i)){
			cout << i<<endl;
			brojac++;
			s += i;

		}
	}


	return s / brojac;

}

*/

//---------------------------------------------------------------------------------------------------------------- -

//Napisati program koji će uzastopno učitatvati cijele brojeve m i n(1≤m≤50, 1≤n≤500) i pronalaziti srednju cifru njihovog proizvoda / umnoška
//(srednju cifru ako proizvod / umnožak ima neparan broj cifara, odnosno aritmeticku sredinu(tip float) dvije srednje cifre ako proizvod / umnožak
//ima parni broj cifara).Program treba ispisivati srednju cifru samo ako je veća od prethodno izračunate srednje cifre.Prva pronađena srednja cifra
//se svakako ispisuje.Program se forsirano prekida ako korisnik unese n = 0. Program se prirodno završava ako je pronađena srednja cifra 9.
//Primjer izvršenja :
//unesi m i n : 10, 15
//srednja cifra / sredina proizvoda brojeva 10 i 15 (10 * 15 = 150) je : 5
//unesi m i n : 10, 42
//srednja cifra / sredina proizvoda brojeva 10 i 42 (10 * 42 = 420) je : ne ispisuje se
//unesi m i n : 12, 31
//srednja cifra / sredina proizvoda brojeva 12 i 31 (12 * 31 = 372) je : 7
//unesi m i n : 149, 20
//srednja cifra / sredina proizvoda brojeva 149 i 20 (149 * 20 = 2980) je : 8.5
//unesi m i n : 150, 0
//forsirani prekid...

/*
#include <iostream>
using namespace std;

float srednjaCif(int, int );


void main(){
	int m, n;
	float trenutna=0;
	do{
		cout << "Unesi m i n" << endl;

		cin >> m >> n;
		if (n == 0){
			cout << "Forsirani prekid" << endl;
			break;
		}


		if (srednjaCif(n, m) > trenutna) {
			trenutna = srednjaCif(n, m);
			cout << "Srednja cifra / sredina proizvoda brojeva " << m << " i " << n << "  (" << m << " * " << n << " = " << m*n << ")" << " je :" << trenutna << endl;
		}

		else
			continue;

	} while (n != 0);




	system("pause>0");
}

float  srednjaCif(int br1, int br2){
	int broj_cifara = 0;
	int pomocna = br1*br2;
	int pomocna1 = br1*br2;
	while (pomocna > 0){
		pomocna /= 10;
		broj_cifara++;

	}
	if (broj_cifara % 2 == 0){
		int  prvi = pomocna1 / pow(10, (broj_cifara / 2));
		int  drugi = pomocna1 / pow(10, ((broj_cifara / 2) - 1));
		return (float)((prvi % 10 + drugi % 10) / 2) + 0.5;
	}
	else{
		int pom = pomocna1 / pow(10, broj_cifara / 2);
		return pom % 10;
	}

}
*/

//--------------------------------------------------------------------------------------------------------------------------

//Napisati funkciju koja kao parametare prima dva niza char recenica[200] i char rijec[10] odnosno rečenicu(niz od najviše 200 karaktera)
//i riječ(niz od najviše 10 karaktera) te u nizu recenica[200] pretrazuje i pronalazi sekvencu karaktera unesenih u niz rijec[10].Radi jednostavnosti
//rjesenja podrazumjeva se da i recenica i rijec koja se pretrazuje zavrsavaju tackom.
//Poslije pronalaska trazene rijeci, pomenutu rijec treba zamijeniti karakterima „FIT“(Pomoc: Treba voditi racuna koliko karaktera ima rijec koja je
//	pronadjena i zamjenjena)
//	Npr.ako je data rečenica u nizu recenica[200]:
//"Ja studiram na fakultetu jer zelim biti expert."
//i rijec[10] :
//	„fakultet“,
//	funkcija je treba pronaci rijec „fakultet“ u recenici i pretvoriti je u „FIT“ :
//" Ja studiram na FITu jer zelim biti expert." (ima ukupno manje slova a zadrzan je samo po jedan space izmedju rijeci)
//Obavezno u main funkciji omoguciti unos recenice, zatim trazene rijeci i ispisati novu recenicu poslije zamjene.

/*
#include <iostream>
using namespace std;

void zamjena(char[], char[]);

void main(){
	char recenica[200]; //= { "Ja studiram na fakultetu jer zelim biti expert." };
	char rijec[10];// = { "fakultet." };

	zamjena(recenica, rijec);
	system("pause>0");
}

void zamjena(char recenica[], char rijec[]){
	bool pronadjena = false;
	int lokacijaRijeci = 0;
	int brojac = 0;
	cout << "Unesite recenicu" << endl;
	cin.getline(recenica, 200);

	cout << "Unesite rijeci 'fakultet'" << endl;
	cin.getline(rijec, 10);

	cin >> recenica;
	cin >> rijec;
	for (int i = 0; i < strlen(recenica); i++){
		if (recenica[i] == rijec[0]){
			for (int j = 0, k = i; j < strlen(rijec) - 1; j++){
				if (recenica[k] == rijec[j]){
					brojac++;
					k++;
					if (brojac == strlen(rijec) - 1){
						pronadjena = true;
						lokacijaRijeci = i;
					}
				}
			}
		}
	}

	if (pronadjena == true){
		recenica[lokacijaRijeci] = 'F';
		recenica[lokacijaRijeci + 1] = 'I';
		recenica[lokacijaRijeci + 2] = 'T';
		recenica[lokacijaRijeci + 3] = 'u';
		for (int i = lokacijaRijeci + 4; i<lokacijaRijeci + strlen(rijec); i++){
			recenica[i] = ' ';
		}
	}
	for (int i = 0; i < strlen(recenica); i++){
		if (recenica[i] == ' ' && recenica[i + 1] == ' ')
			continue;
		else
			cout << recenica[i];
	}
}
*/

//------------------------------------------------------------------------------------------------------------------ -

//Neka je dat 2D niz tipa int dimenzija 5x5.Kreirati, a potom u glavnom programu testirati, sljedeće funkcije :
//a)	Funkciju koja vrši generisanje Fibonaccijevih brojeva u 2D nizu dok se niz ne popuni
//b)	Funkcija koja ispisuje najveće zajedničke djelitelje brojeva na suprotnim indeksima matrice koristeći Euklidov algoritam,
//kad se indeksi izjednače petlja se treba prekinuti :
//Euklidov algoritam(a, b) :
//	Dok(b > 0)
//	p = a;
//a = b;
//b = p mod b;
//NZD = a;
//Gdje je 'p' pomoćna varijabla.Suprotni indeksi matrice su matrica[0, 0] i matrica[5, 5], zatim matrica[0, 1] i matrica[5, 4] itd .
//Primjer:
//Najveći zajednički djelitelj za brojeve 610 i 34 je 2. Najveći zajednički djelitelj za brojeve 8 i 2584 je 8 itd.


/*
#include <iostream>
#include <iomanip>
using namespace std;

int fib(int);
void Generisi(int[][5]);
void ispis(int[][5]);
int NZD(int, int);
void ispisNZDBr(int[][5]);

void main() {
	int a, b;
	int niz[5][5];
	Generisi(niz);
	ispis(niz);

	ispisNZDBr(niz);


	system("pause>0");
}

int fib(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fib(n - 1) + fib(n - 2);
}

void Generisi(int niz[][5]) {
	int pocetak = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			niz[i][j] = fib(pocetak);
			pocetak++;
		}
	}
}

void ispis(int niz[][5]) {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (j > i) {
				int temp = niz[i][j];
				niz[i][j] = niz[j][i];
				niz[j][i] = temp;


			}
			cout << setw(7) << niz[i][j];
		}
		cout << endl;
	}
}

int NZD(int a, int b) {

	int n, djelj = 0;
	if (a > b)
		n = a;
	else
		n = b;
	for (int i = 1; i < n; i++)
	{
		if ((a % i == 0) && (b % i == 0))
			djelj = i;
	}
	return djelj;
}



void ispisNZDBr(int niz[][5]) {

	for (int i = 0; i < 5; i++) {

		for (int j = 0; j < 5; j++) {

			if (i == 2 && j == 2)
				return;

			cout << "Za " << niz[i][j] << " i " << niz[4 - i][4 - j] << " najmanji zajednici djelilac je " << NZD(niz[i][j], niz[4 - i][4 - j]) << endl;


		}
	}
}
*/
