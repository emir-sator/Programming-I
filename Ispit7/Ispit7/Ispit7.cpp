/////////////////////////////////////////// INTEGRALNI ISPIT (24.6.2017) GRUPA : A //////////////////////////////////////////////////////////

//Data su dva prirodna broja X i Y iz intervala od 10 do 5000. Poštujući sve faze procesa programiranja, kreirati program
//koji će pronaći i ispisati sve brojeve od X do Y(uključujući granične vrijednosti) čija je suma cifara djeljiva sa brojem
//koji se dobije u obrnutom poretku tih cifara.U rješenju koristiti najmanje jednu funkciju.
//Npr.Za broj 144 vrijedi da mu je suma cifara 9 i da je broj koji se dobije nakon što se njegove cifre obrnu, 441, djeljiv sa 9.
//Definisite vrijednosti intervala[X, Y]: 11 150
//Brojevi koji ispunjavaju dati uslov : 18 20 21 24 27

/*
#include <iostream>
using namespace std;

int sumaCifara(int);
int obrnutiBroj(int);
void ispisBrojeva(int, int);


void main(){

	int x, y;

	cout << "Unesite dva prirodna broja" << endl;

	do{
		cin >> x >> y;
	}while(x < 0 || y<0 || x>y);

	ispisBrojeva(x, y);


	system("pause>0");
}

int sumaCifara(int broj){
	int s = 0;
	while (broj>0){
		s += broj % 10;
		broj /= 10;

	}
	return s;


}

int obrnutiBroj(int broj){
	int obrnuti = 0;
	while (broj > 0){

		obrnuti *= 10;
		obrnuti += broj % 10;
		broj /= 10;
	}
	return obrnuti;
}

void ispisBrojeva(int donja, int gornja){
	int obrnutiBr = 0;
	int sumaCif = 0;
	for (int  i = donja; i <=gornja ; i++)
	{
		obrnutiBr = obrnutiBroj(i);
		sumaCif = sumaCifara(i);
		if (obrnutiBr%sumaCif == 0)
			cout << "  " << i;
	}




}
*/

//-------------------------------------------------------------------------------------------- -

//Napisati program koji omogućava unos karaktera sve dok se ne popuni niz od 30 elemenata prema sljedećim pravilima :
//•	Elementi niza mogu biti samo velika slova i brojevi.
//•	Svaki naredni element u nizu treba da bude abecedno poslije prethodnog, odnosno u slučaju broja, dalje od nule na
//    brojnoj osi(voditi računa da se međusobno porede samo slova i samo brojevi).
//•	Ukupna suma ASCII kodova unesenih elemenata ne smije biti veća od 1000.
//Izlaz iz programa treba da budu dobiveni elementi niza.Testni primjer je urađen za niz od 5 elemenata.
//
//Unesite veliko slovo ili broj : D
//Unesite veliko slovo ili broj : 3
//Unesite veliko slovo ili broj : A
//Unesite veliko slovo ili broj : F
//Unesite veliko slovo ili broj : 0
//Unesite veliko slovo ili broj : 4
//Unesite veliko slovo ili broj : R
//
//Elementi niza : D 3 F 4 R

/*
#include <iostream>
using namespace std;

const int vel = 30;
int brojac = 0;
bool JeLiVelikoSlovo(char);
bool JeLiBroj(char);
bool IspisPoslijePredhodnog(char[], char, int);
void unosNiza(char[]);
void ispis(char[]);


void main(){

	char niz[vel];
	unosNiza(niz);
	ispis(niz);


	system("pause>0");
}

void ispis(char niz[]){
	for (int i = 0; i < brojac; i++)
	{
		cout << niz[i] << endl;
	}
}
bool JeLiVelikoSlovo(char zn){
	bool veliko = zn >= 'A'&& zn <= 'Z';
	return veliko;


}

bool JeLiBroj(char zn){
	bool broj = zn >= '0' && zn <= '9';
	return broj;
}

bool IspisPoslijePredhodnog(char niz[], char noviKarakter, int velicinaNiza){
	bool JeLiNoviSlovo = JeLiVelikoSlovo(noviKarakter);

	bool JeliElementNizaSlovo;
	for (int i = 0; i < velicinaNiza; i++)
	{
		JeliElementNizaSlovo = JeLiVelikoSlovo(niz[i]);
		if (JeliElementNizaSlovo != JeLiNoviSlovo)
			continue;
		if (noviKarakter < niz[i])
			return false;
	}
	return true;

	}

void unosNiza(char niz[]){
	int suma = 0;

	for (int i = 0; i < vel; i++){

		cout << "Unesite karakter ili broj" << endl;
		cin >> niz[i];
		if (!JeLiVelikoSlovo(niz[i]) && !JeLiBroj(niz[i])){
			cout << "Pogresan unos" << endl;
			i--;
		}
		else if (!IspisPoslijePredhodnog(niz, niz[i], i + 1))
		{
			cout << "Manji je od predhodnika" << endl;
			i--;
		}

		else
		{

			if (suma + niz[i] > 500){

				cout << "Suma je veca od 500" << endl;

				i--;
				break;

			}

			else
			{
				suma += niz[i];
				brojac++;
			}

		}

		}

	}
*/

//---------------------------------------------------------------------------------------------------------------------- -
//
//Napisati funkciju koja niz od 10 cijelih brojeva sortira u opadajućem ili rastućem poretku.Unos elemenata niza se obavlja u glavnom programu,
//kao i odabir opcije koja određuje da li rezultirajući niz treba biti opadajući ili rastući.Obavezno testirati implementiranu funkciju vodeći
//se datim primjerom ispisa.
//
//Unesite elemente niza : 12 2 3 0 45 6 98 - 9 3 - 10
//Kako zelite sortirati niz(unesite 1 ili 2) :
//	1.	U opadajucem poretku
//	2.	U rastucem poretku
//	1
//	Rezultirajuci niz : 98 45 12 6 3 3 2 0 - 9 - 10

/*
#include <iostream>
using namespace std;

void unos(int[], int);
void sortiranje(int[], int, int);
void ispis(int[], int);

void main() {

	const int vel = 10;
	int niz[vel];
	int izbor;
	cout << "Unesite elemente niza: ";
	unos(niz, vel);
	cout << endl;
	cout << "Kako zelite sortirati niz(unesite 1 ili 2): " << endl;
	cout << "1.      " << " U opadajucem poretku" << endl;
	cout << "2.      " << " U rastucem poretku" << endl;

	do {
		cin >> izbor;
	} while (izbor < 1 || izbor >2);
	sortiranje(niz, vel, izbor);
	cout << "Rezultujuci niz: ";
	ispis(niz, vel);


	system("pause>0");
}

void unos(int n[], int v) {
	for (int i = 0; i < v; i++)
	{
		cin >> n[i];
	}
}

void ispis(int n[], int v) {
	for (int i = 0; i < v; i++)
	{
		cout << "   " << n[i];
	}
}

void sortiranje(int n[], int v, int izb) {

	bool prolaz = true;
	while (prolaz) {
		prolaz = false;
		for (int i = 0; i < v - 1; i++)
		{
			int temp = 0;
			if ((n[i] < n[i + 1] && izb == 1) || (n[i] > n[i + 1] && izb == 2)) {
				temp = n[i];
				n[i] = n[i + 1];
				n[i + 1] = temp;
				prolaz = true;
			}
		}
		v--;
	}
}
*/



//---------------------------------------------------------------------------------------------------------------------- -

//Uz pomoć matrice realnih brojeva dimenzija 5x7 izraditi program za evidenciju i kalkulaciju uspješnosti vremenskih prognoza
//(prosječnih dnevnih temperatura) određenog grada.Redovi matrice predstavljaju meteorologe čije se prognoze unose, dok se kolone odnose
//na vremenski period od 7 dana.Uz matricu je neophodno krerati globalni jednodimenzionalni niz od 7 elemenata koji će čuvati stvarna mjerenja
//temperatura za isti vremenski period, a na osnovu kojeg će se procijeniti uspješnost prognoza pojedinih meteorologa.Vrijednosti elemenata ovog
//niza prilikom deklaracije postaviti na : 25.5, 26.8, 21, 32, 35.6, 36, 33.5.
//Implementaciju programa uraditi pomoću sljedećih funkcija :
//•	UnesiPrognoze – funkcija za unos prognoza određenog meteorologa za kompletan period od 7 dana.Vrijednosti prosječnih temperatura moraju biti
//unutar intervala[-20, 50] °C. (Pojasnjenje : unose se podaci za samo jedan izabrani red.)
//
//•	IzracunajUspjesnost – funkciju koja vraća procentualnu vrijednost uspješnosti prognoza za željenog meteorologa.Prognoza, odnosno prosječna
//temperatura na određeni dan, smatra se uspješnom ako od stvarnog mjerenja ne odstupa više od 5 °C. (Pojasnjenje : poredi se podaci iz jednog reda
//odnosno za jednog meteorologa sa podacima iz posebnog niza koji sadrži stvarne vrijednosti mjerenja, te ako je razlika manja od + / -5 taj podatak
//se smatra uspjesnom prognozom.)
//
//•	PronadjiNajuspjesnijegMeteorologa – funkciju koja pronalazi meteorologa sa najtačnijim vremenskim prognozama, odnosno najvećim procentom uspjeha.
//(Pojasnjenje : Red koji ima najveci procenat koji se dobije iz prethodno opisane funkcije IzracunajUspjesnost je u stvari red sa najuspjesnijim meteorologom.)
//
//•	PronadjiDanSaNajnizimPrognozama – funkciju koja pronalazi dan koji je imao u prosjeku najnize prognoze.
//Napisati i kratak testni program za provjeru ispravnosti implementiranih funkcija.


/*
#include <iostream>
#include <iomanip>
using namespace std;

const int red = 5;
const int kolona = 7;
float nizTacnih[kolona] = { 25.5, 26.8, 21, 32, 35.6, 36, 33.5 };

void UnesiPrognoze(float matrica[red][kolona]) {
	for (int i = 0; i < red; i++)
	{
		cout << "Meterolog " << i + 1 << ": ";
		cout << endl;
		for (int j = 0; j < kolona; j++)
		{
			cout << "Dan: " << j + 1 << ":";
			do {
				cin >> matrica[i][j];
			} while (matrica[i][j] < -20 && matrica[i][j]>50);
		}
	}

}
void Ispis(float matrica[][kolona]) {
	for (int i = 0; i < red; i++)
	{
		cout << "Meterolog " << i + 1 << ": ";
		cout << endl;
		for (int j = 0; j < kolona; j++)
		{
			cout << matrica[i][j] << endl;
		}
	}

}
float IzracunajUspjesnost(float matrica[], float nizTacnih[kolona]) {
	int uspjesni = 0;
	for (int i = 0; i < kolona; i++)
	{
		if (abs(matrica[i] - nizTacnih[i]) <= 5) {
			uspjesni++;
		}
	}

	return(float(uspjesni) / kolona) * 100;
}
int PronadjiNajuspjesnijeg(float niz[][kolona], float nizTacnih[]) {
	float najveci = IzracunajUspjesnost(niz[0], nizTacnih);
	int pozicija = 0;
	int temp = 0;
	for (int i = 0; i < red; i++)
	{
		temp = IzracunajUspjesnost(niz[i], nizTacnih);
		if (temp > najveci) {
			pozicija = i;
			najveci = temp;
		}
	}
	return pozicija;

}

int PronadjiDanSaNajvisimPrognozama(float matrica[][kolona]) {
	int suma = 0;
	int najvise = matrica[0][0];
	int dan = 0;

	float prosjek = 0;
	for (int i = 0; i < red; i++)
	{
		int j = 0;
		while (j < 5) {
			suma += matrica[j][i];

			j++;

		}
		prosjek += suma / 5;
		cout << "Prosjeci po danu iznose " << prosjek << endl;
		if (prosjek < najvise) {
			najvise = prosjek;
			dan = i;

		}
		suma = 0;
		prosjek = 0;

	}
	return dan;
}



int main()
{
	float matricaPrognoza[red][kolona];

	UnesiPrognoze(matricaPrognoza);
	Ispis(matricaPrognoza);



	cout << "Najuspjeniji meteorolog je" << PronadjiNajuspjesnijeg(matricaPrognoza, nizTacnih) + 1 << endl;

	cout << "Dan sa najnizim prognozama je dan " << PronadjiDanSaNajvisimPrognozama(matricaPrognoza) + 1 << endl;


	system("pause>0");
}
*/