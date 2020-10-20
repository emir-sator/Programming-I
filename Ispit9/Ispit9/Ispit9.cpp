//////////////////////////////////////////////// INTEGRALNI ISPIT (8.9.2017) GRUPA : A ///////////////////////////////////////////////////

//Poštujući sve faze procesa programiranja, napisati program koji izračunava aritmetičku sredinu svih savršenih brojeva iz zadatog intervala.
//Za neki broj se kaže da je savršen ukoliko je jednak sumi svih svojih djelilaca(ne uključujući njega samog).Na primjer, 28 je savršen broj:
//njegovi djelioci su 1, 2, 4, 7 i 14, a 1 + 2 + 4 + 7 + 14 = 28. Jedini savršeni brojevi u opsegu od 1 do 100 su brojevi 6 i 28.
//U rješenju koristiti funkciju sljedećeg prototipa : bool IsSavrsen(int).
//
//Unesite granice intervala : 1 500
//Aritmeticka sredina savrsenih brojeva iz zadatog intervala je : 176.667

/*
#include <iostream>
using namespace std;

bool djeljiv(int n, int n1) {
	if (n % n1 == 0)
		return true;
	else
		return false;
}
bool savrsen(int a) {
	int suma = 0;

	for (int i = 1; i < a; i++)
	{
		if (djeljiv(a, i)) {
			suma += i;
		}
	}
	if (suma == a) {
		return true;
	}
	return false;
}
void main()
{
	int brojac = 0;
	float s = 0;
	int x, y;
	cout << "upisite dva broj" << endl;
	cin >> x >> y;
	for (x; x < y; x++)
	{
		if (savrsen(x)) {
			cout << x << endl;
			brojac++;
			s += x;
		}

	}
	cout << "Aritmeticka sredina je: ";
	cout << s / brojac << endl;

	system("pause");
}
*/


//------------------------------------------------------------------------------------------------------------------------------

//Napisati program koji na osnovu unesenog cijelog broja N formira i ispisuje broj sastavljen od istih cifara u rastućem poretku uzimajući
//samo neparne cifre.Za sortiranje cifara koristiti pomoćni niz od najviše 10 elemenata.

//Unesite cijeli broj N : 4513982
//Broj sa sortiranim ciframa : 1359

//Unesite cijeli broj N : 109225
//Broj sa sortiranim ciframa : 159

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
		if (ostatak % 2 != 0){// ostatak%2==0 za parne cifre

			n[pozicija] = ostatak;
			pozicija++;
			neparni++;
		}
	}
	bool sorted = true;
	while (sorted) {
		sorted = false;
		for (int i = 0; i < neparni - 1; i++) {

			if (n[i] >n[i + 1]) {// < znaci od najveceg ka najmanjem
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
funckija(n, niz,velicina);


system("pause>0");
}
*/

//------------------------------------------------------------------------------------------------------

//Napisati funkciju koja kao parametar prima rečenicu(niz od najviše 200 karaktera) i iz nje uklanja svaku riječ koja počinje velikim slovom.
//Pored toga, funkcija treba da prebroji ukupan broj riječi u rečenici prije izmjene.Koristiti sljedeći prototip funkcije : int ukloniRijeci(char[]).
//Npr.ako je data rečenica :
//"Stari most u Mostaru spaja obale rijeke Neretve."
//funkcija je treba pretvoriti u :
//"most u spaja obale rijeke"
//Funkcija vraća broj riječi u polaznoj rečenici(prije odsijecanja ostalih riječi).Radi jednostavnosti rješenja, pretpostavite da je
//riječ bilo koji niz znakova razdvojen znakom razmak.

/*
#include<iostream>
using namespace std;

int funkcija(char[], int, int &);
void main(){
	int brojac = 0;
	char niz[200];
	cout << "Unesite recenicu: " << endl;
	cin.getline(niz, 200);
	int duzina = strlen(niz);

	for (int i = 0; i < duzina; i++){
		if (niz[i] == 32)
			brojac++;
	}
	cout << "Broj rijeci u recenici je: " << funkcija(niz, duzina, brojac);
	system("pause>0");
}

int funkcija(char niz[], int duzina, int & brojac){
	 IZBACUJE SVA VELIKA SLOVA

	for (int i = 0; i < duzina; i++){
		if (niz[i] >= 65 && niz[i] <= 90){
			for (int j = i; j < duzina; j++){
				if (niz[j] != 32){
					niz[j] = ' ';
				}
				else
					break;

			}
		}
	}
	if (brojac >= 1)
		brojac++;

	cout << niz << endl;
	return brojac;
}
*/


//----------------------------------------------------------------------------------------------------------------------

//Neka je data matrica dimenzija 10x12 u kojoj svaki red predstavlja uposlenika određene kompanije, a svaka kolona mjesec u godini.
//Elementi matrice predstavljaju radne sate uposlenika po mjesecima jedne kalendarske godine.Kreirati, a potom u glavnom programu testirati, sljedeće funkcije :
//•	Funkciju koja za odabranog uposlenika vrši ispis platne liste po mjesecima, ako je poznato da je satnica svih uposlenika 12 KM.Pored toga,
//funkcija kao rezultat vraća prosječnu mjesečnu platu tog uposlenika.
//•	Funkciju koja pronalazi uposlenika sa najviše prekovremenih radnih sati, ako je usvojeno da jedna radna sedmica ima 40 obaveznih radnih sati,
//a svaki mjesec 4 sedmice.
//•	Funkciju koja za svaki mjesec u godini ispisuje prosječan iznos isplaćenih plata(za ukupne radne sate) uz posebno naznačen iznos koji je
//izdvojen isključivo za prekovremeni rad.Ispis za mjesec januar bi izgledao kako slijedi :
//---------------- - Januar---------------- -
//Ukupno isplaceno : 25700 KM
//Isplaceno za prekovremeni rad : 6500 KM

//Napomena : Pretpostaviti da je u programu implementirana funkcija za unos radnih sati jedne kalendarske godine i koristiti je u glavnom programu
//(dakle, funkciju unos nije potrebno implementirati).

/*
#include<iostream>
using namespace std;
float prosjecnaPlata(int radnici[][12], int uposlenik)
{
	float plate = 0;
	for (int i = 0; i < 12; i++) {
		cout <<"Prosjecna plata za "<< i +1 << ". mjesec " << (radnici[uposlenik][i] * 12)/12 << endl;
		plate += radnici[uposlenik][i] * 12;

	}
	return plate / 6;
}
•	Funkciju koja pronalazi uposlenika sa najviše prekovremenih radnih sati,
ako je usvojeno da jedna radna sedmica ima 40 obaveznih radnih sati, a svaki mjesec 4 sedmice.
int najvrjednijiRadnik(int radnici[][12]) {
	int najviseDana = 0, indexRadnika = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 12; j++) {
			if (radnici[i][j] > 160) {
				najviseDana = radnici[i][j];
				indexRadnika = i;
			}
		}
	}
	return indexRadnika+1;
}

void isplata(int radnici[][12]) {
	for (int i = 0; i < 12; i++) {
		int prekovremeniSati = 0, plate = 0;
		for (int j = 0; j < 10; j++) {
			if (radnici[j][i] > 160)
				prekovremeniSati += radnici[j][i];
			else
				plate += radnici[j][i];
		}
		cout << "ukupno isplaceno za " << i + 1 << ". Mjesec " << plate << endl;
		cout << "Isplaceno za prekovremeni rad " << prekovremeniSati << endl;
		cout << "-----------";
	}
}

void main()
{

	int matrica[10][12];
	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < 12; j++)

			cin >> matrica[i][j];
		cout << "-----" << endl;
	}
	int izb;
	cout << "Unesite radnika za kojeg zelite provjeriti plate po mjesecima (0-11)" << endl;
	cin >> izb;
	cout << prosjecnaPlata(matrica, izb) << endl;
	cout << " Najjvrijedniji radnik je " << najvrjednijiRadnik(matrica) << endl;
	isplata(matrica);

	system("pause>0");

}
*/


//------------------------------------------------------------------------------------------------------------------------