///////////////////////////////////////////// INTEGRALNI ISPIT (28.1.2017) GRUPA : B /////////////////////////////////////////////////

//Poštujući sve faze programiranja napisati program kojim će se izračunati 20 uzastopnih vrijednosti brzine i prijeđenog puta objekta u slobodnom padu u
//razmaku od po 3 sec.Izračunate vrijednosti brzine i prijeđenog puta smjestiti u odvojene nizove od po 20 elemenata,
//te ispisati na ekranu uzastopno brzinu i prijeđeni put zajedno za svaki period od 3 sec.Obratiti pažnju da se koriste
//ispravni tipovi podataka.Za izračun brzine slobodnog pada te prijeđenog puta pri slobodnom padu koristiti zasebne funkcije.
//Formula za brzinu slobodnog pada je : v = g * t  //g=9.81
//Formula za prijeđeni put pri slobodnom padu je : s = (g / 2) * pow(t, 2)  //g=9.81
//Primjer izlaza :
//Situacija u 3 - oj sekundi je :
//Brzina: 29.43 Prijeđeni put : 44.145
//Situacija u 6 - oj sekundi je :
//Brzina: 58.86 Prijeđeni put : 176.57
//Situacija u 9 - oj sekundi je :
//Brzina: 88.29 Prijeđeni put : 397.305
//Prijedlog rješenja :


/*
#include <iostream>
#include <math.h>

using namespace std;

const float g = 9.81;
void brzSlobPad(float[]);
void putSlobPad(float[]);

void main()
{
	float	brzine[20], duzine[20];
	brzSlobPad(brzine);
	putSlobPad(duzine);
	for (int i = 1; i <= 20; i++)
	{
		cout << "Situacija u " << i * 3 << "-oj sekundi je:" << endl;
		cout << "Brzina: " << brzine[i - 1] << endl;
		cout << "Predjeni put: " << duzine[i - 1] << endl;
	}


	system("pause");

}

void brzSlobPad(float brzine[])
{
	for (int i = 1; i <= 20; i++)
	{
		brzine[i - 1] = g * i * 3;
	}
}
void putSlobPad(float duzine[])
{
	for (int i = 1; i <= 20; i++)
	{
		duzine[i - 1] = (g / 2) * pow(float(i * 3), 2);
	}
}
*/



//------------------------------------------------------------------------------------------------------------------------------

//Svaki paran broj može se prikazati kao suma dvaju  prostih  brojeva(tkzv.Goldbachovo  pravilo).Razraditi logiku programa koji će najprije
//učitati dva prirodna broja n1 i n2.Ako je n1 > n2 zamijeniti n1 sa n2.Prikazati sve parne brojeve u intervalu n1 do n2 kao sumu dvaju
//prostih brojeva.U glavnom programu samo unijeti navedena dva prirodna broja i pozvati funkciju koja obavlja zadani posao.




/*
#include<iostream>
#include<iomanip>

using namespace std;

void goldbach(int, int);
bool prost(int);
void main()
{
	int n1, n2;
	cout << "Unesite brojeve n1 i n2 (n1<n2) " << endl;
	do
	{
		cin >> n1 >> n2;

	} while ( n1<0);
	if (n1>n2){
		cout << "Unijeli ste prvo veci pa manji, uradit cemo zamjenu vrijednosti za n1 i n2" << endl;
	}
	if (n1>n2){
		int temp = 0;
		temp = n1;
		n1 = n2;
		n2=temp;

	}
	cout << "n1  = " << n1 << endl << "n2 = " << n2 << endl;

	goldbach(n1, n2);

	system("pause>0");
}

void goldbach(int n1, int n2)
{
	for (int i = ((n1 % 2 != 0) ? ++n1 : n1); i <= n2; i += 2)
	{
		cout << i << " je zbir prostih brojeva ";
		for (int j = i / 2, k = i / 2; j>0; j--, k++)
		{
			if (prost(j) && prost(k))
			{
				cout << j << " i " << k << endl;
				break;
			}
		}
	}
}

bool prost(int broj)
{
	for (int i = 2; i <= broj / 2; i++)
	{
		if (broj%i == 0)
			return 0;
	}
	return 1;
}
*/



//----------------------------------------------------------------------------------------------------------------------------------



//Napisati program koji računa koliko je dana proteklo između dva datuma u istoj godini.Pretpostavka je da će korisnik
//unijeti prvo manji(dan, mjesec i godinu), a zatim veći datum(dan, mjesec i godinu).Potrebno je da uneseni dani budu u
//rasponu od 1 - 31, mjeseci u rasponu od 1 - 12 i da su godine jednake.Ukoliko je bilo šta od navedenog narušeno za jedan od datuma,
//unos se ponavlja.Voditi računa i da unesena godina može biti prestupna(svaka godina koja je djeljiva sa 4, nije djeljiva sa 100 ili je djeljiva sa 400;
//npr. 1600. jeste prestupna, jer je djeljiva sa 400, 2017. nije prestupna jer ne ispunjava niti jedan od uslova).
//Pomoć: Za potrebe pronalaska broja dana u mjesecu koristiti sljedeći niz(sa eventualnom izmjenom za prestupnu godinu)
//	: int broj_dana[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


/*
#include<iostream>
#include<iomanip>

using namespace std;


int main()
{
	int d1, m1, g1, d2, m2, g2, proteklo_dana = 0;

	do
	{
		cout << "Unesite dan, mjesec i godinu prvog datuma: ";
		cin >> d1 >> m1 >> g1;

	} while (d1 < 1 || d1>31 || m1 < 1 || m1>12);

	Unos drugog datuma se ponavlja i ukoliko godina nije ista kao i za prvi datum
	do
	{
		cout << "Unesite dan, mjesec i godinu drugog datuma: ";
		cin >> d2 >> m2 >> g2;

	} while (d2 < 1 || d2 > 31 || m2 < 1 || m2 > 12 || g2 != g1);

	int broj_dana[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	Ako je godina prestupna mijenjamo broj dana za mjesec februar
	if (g1 % 100 != 0 && g1 % 4 == 0 || g1 % 400 == 0)
		broj_dana[1] = 29;

	Rjesenje je predlozeno pod pretpostavkom da korisnik prvo unosi manji datum,
	što je i naglašeno u postavci zadatka.

	if (m1 == m2)
		proteklo_dana = d2 - d1;
	else
	{
		int temp = m1;
		proteklo_dana = broj_dana[temp - 1] - d1;
		while (++temp < m2)
		{
			proteklo_dana += broj_dana[temp - 1];
		}

		proteklo_dana += d2;
	}

	cout << "Izmedju datuma " << d1 << "." << m1 << "." << g1 << ". godine i datuma " << d2 << "." << m2 << "." << g2 << ". godine proteklo je "
	<< proteklo_dana << " dana"<<endl;
	system("pause");
	return 0;
}
*/

//----------------------------------------------------------------------------------------------------------------------------------------------


//Deklarisati kvadratnu matricu cijelih brojeva proizvoljnih dimenzija sa parnim brojem redova, te implementirati sljedeće funkcije :
//•	Funkciju za unos i formiranje elemenata matrice prema sljedećem obrascu : elemente neparnih redova matrice(1., 3., 5. itd.) čine brojevi
//koje unosi korisnik programa; elementi parnih redova matrice se formiraju na osnovu elemenata iz prethodnog reda u istoj koloni
//matrice i to na način da je svaki novokreirani element matrice zapravo srednja cifra broja koji se u matrici nalazi iznad njega.
//a pronalazak srednje cifre broja kreirati zasebnu funkciju srednja_cifra, te je pozvati u funkciji unos.
//Srednju cifru brojeva sa parnim brojem cifara formirati kao srednju vrijednost dvaju cifara u sredini, npr.broj 4213 ima dvije srednje cifre,
//te funkcija treba da kao srednju cifru vrati vrijednost aritmetičke sredine cifre 2 i 1 zaokružene na veću decimalnu, u konkretnom slučaju broj 2.
//•	Funkciju max_element koja pronalazi element sa najvećim brojem cifara.Kreirati pomoćnu funkciju broj_cifara koja vraća broj
//cifara broja proslijeđenog kao parametar.
//•	Funkciju za ispis elemenata matrice sa parametrom tipa bool koji određuje da li se ispisuje kompletna matrica ili samo
//elementi matrice koje je unio korisnik(elementi neparnih redova).
//Napisati i kratak testni program koji demonstrira funcionalnost kreiranih funkcija.
//Primjer matrice dimenzija 4x4 i očekivanih rezultata je dat ispod.
//
//2163	123	30452	671
//4	     2    4	     7
//7331	6113	741232	798
//3	     1	       2	9
//Element matrice sa najvećim broje cifara : 741232.

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

void main(){
	char izbor;
	int niz[red][kol];



	cout << "Unesite elemente 2D niza" << endl;
	unos(niz);

	cout << "Unesite izbor y za ispis elemennata koje je korisnik unio ili n za ispis citavog 2d niza " << endl;
	do
	{
		cin >> izbor;
	} while (!(izbor == 'y' || izbor == 'n'));
	izbor== 'y' ? izbor = true : izbor = false;

	ispis(niz, izbor);

	cout << "Element koji ima najvise cifara je " << max_element(niz) << endl;


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
		return ((prvi % 10 + drugi % 10) / 2);
	}
	else{
		int pom = broj / pow(10, brojacCif / 2);
		return pom% 10;
	}
}

void unos(int n[][kol]){

	for (int i = 0; i <red ; i+=2)
	{
		for (int j = 0; j < kol; j++){


				cin >> n[i][j];
				if (n[i][j] < 100)
					j--;
				n[i + 1][j] = srednjaCif(n[i][j]);

			}
		}
	}
void ispis(int n[][kol], bool izbor){

	for (int i = 0; i < red; izbor ? i += 2 : i++)
	{
		for (int j = 0; j < kol; j++)
		{
			cout << setw(7) << n[i][j];

		}
		cout << endl;
	}
}

int max_element(int n[][kol]){
	int najveci = n[0][0];
	for (int  i = 0; i <red ; i+=2)
	{
		for (int j = 0; j < kol; j++){
			if (broj_cifara(najveci) < broj_cifara(n[i][j])){
				najveci = n[i][j];
			}
		}
	}

	return najveci;
}

*/