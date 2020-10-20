//////////////////////////////////////// INTEGRALNI ISPIT (16.9.2017) GRUPA : A ////////////////////////////////////////////

//Poštujući sve faze procesa programiranja, napisati program koji rjesava slijedeći problem.
//Date su firme A, B i C sa godišnjim prihodima :
//A – prihod 10M Eur
//B – prihod 7M Eur
//C – prihod 5M Eur
//sa slijedećim stabilnim fiksnim godišnjim rastom prihoda za koji pretpostavljamo da se neće mijenjati
//A – 2.05 %
//B – 2.80 %
//C – 4.30 %
//Potrebno je pronaći koja firma će prva prestići firmu A u godišnjem prihodu i za koliko godina će se to desiti.
//Također potrebno je ispisati koliko će sve tri firme imati godišnji prihod u toj godini.Obavezno koristiti funkciju
//za izračun potrebnog broja godina i godisnjih prihoda za sve firme.

/*
#include <iostream>
using namespace std;

void izracun(double, double, double, double, double, double);

void main()
{
	const double godRastPrihodaA = 2.05,
		godRastPrihodaB = 2.80,
		godRastPrihodaC = 4.30;

	double prihodA = 10,
		prihodB = 7,
		prihodC = 5;

	izracun(prihodA, prihodB, prihodC, godRastPrihodaA, godRastPrihodaB, godRastPrihodaC);
	system("pause>0");
}
void izracun(double prihodA, double prihodB, double prihodC, double  godRastPrihodaA, double  godRastPrihodaB, double godRastPrihodaC){
	int i = 0;


	do
	{
		prihodA = prihodA + prihodA * godRastPrihodaA / 100;
		prihodB = prihodB + prihodB * godRastPrihodaB / 100;
		prihodC = prihodC + prihodC * godRastPrihodaC / 100;
		i++;

	} while (prihodB < prihodA || prihodC < prihodA);

	if (prihodB > prihodC)
		cout << "Firma B ce prva prestici firmu A za " << i << " godina" << endl;
	else
		cout << "Firma C ce prva prestici firmu A za " << i << " godina" << endl;

	cout << "Firma A nakon " << i << " godina: " << prihodA << " miliona" << endl;
	cout << "Firma B nakon " << i << " godina: " << prihodB << " miliona" << endl;
	cout << "Firma C nakon " << i << " godina: " << prihodC << " miliona" << endl;


}

*/

//-----------------------------------------------------------------------------------------------------------------------------------

//Napisati program koji na osnovu unesenog cijelog broja N pronalazi i ispisuje srednju cifru ako broj N ima neparan broj cifara,
//odnosno aritmeticku sredinu(tip float) srednje dvije cifre ako broj N ima parni broj cifara, a zatim pronaci najmanji broj tipa
//int sa kojim se srednja cifra ili aritmeticka sredina srednjih cifri treba pomnoziti da bi se dobio broj koji je veci od inicijalnog zadanog broja.
//Npr.
//za broj 75631 srednja cifra je 6, najmanja integer vrijednost sa kojom treba pomnoziti broj 6 da bi se dobio broj veci od 75631
//je 12606 jer je 12606 * 6 = 75636, 75636 > 75631
//ili
//za broj 984354 aritmeticka sredina srednje dvije cifre je 3.5, najmanja integer vrijednost sa kojom treba pomnoziti broj 3.5
//da bi se dobio broj veci od 984354 je 281245 jer je 281245 * 3.5 = 984357.5, 984357.5 > 984354
//(Napomena: Potrebno je voditi racuna o tipovima podataka.)

/*
#include <iostream>
using namespace std;

float  srednjaCif(int);

int pronalazak(int);

void main(){
	int broj;

	cout << "Unesite jedan cijeli broj" << endl;
	cin >> broj;

	cout << "Srednja cifra broja " << broj << " je " << srednjaCif(broj) << endl;
	cout << "Trazeni broj je " << pronalazak(broj) << endl;



	system("pause>0");
}

float  srednjaCif(int broj){
	int broj_cifara = 0;
	int pomocna = broj;
	while (pomocna > 0){
		pomocna /= 10;
		broj_cifara++;

	}
		if (broj_cifara % 2 == 0){
			int  prvi = broj / pow(10, (broj_cifara / 2));
			int  drugi = broj / pow(10, ((broj_cifara / 2) - 1));
			return (float)((prvi % 10 + drugi % 10) / 2)+0.5;
		}
		else{
			int pom = broj / pow(10, broj_cifara / 2);
			return pom % 10;
		}

}

int pronalazak(int broj){
	int srednja = srednjaCif(broj);
	int najmanji=0;
	for (int  i = 0; i <broj ; i++)
	{
		if (i*srednja>broj){
			najmanji=i ;
			break;
		}
	}
	return najmanji;


}
*/

//------------------------------------------------------------------------------------------------------------------ -

//Napisati funkciju koja kao parametare prima dva niza char recenica[200] i char rijec[10] odnosno rečenicu(niz od najviše 200 karaktera)
//i riječ(niz od najviše 10 karaktera) te u nizu recenica[200] pretrazuje i pronalazi sekvencu karaktera unesenih u niz rijec[10].
//Radi jednostavnosti rjesenja podrazumjeva se da i recenica i rijec koja se pretrazuje zavrsavaju tackom.
//Poslije pronalaska trazene rijeci, pomenutu rijec treba zamijeniti karakterima „FIT“(Pomoc: Treba voditi racuna koliko karaktera ima
//	rijec koja je pronadjena i zamjenjena)
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

//Neka je dat 2D niz tipa int dimenzija 10x10.Kreirati, a potom u glavnom programu testirati, sljedeće funkcije :
//a)	Funkciju koja za vrsi generisanje podataka u 2D nizu na nacin da se u elementu sa indexom[0][0] upise vrijednost
//1 a svaki slijedeci element da ima vrijednost prethodnog elementa pomnozenog sa 2 kao na slici.Generisanje se prekida ako se desi overflow na varijabli int.
//b)	Funkciju koja popunjenu matricu iz pod - zadatka a) transponuje tako sto joj zamjeni redove i kolone.
//c)	Funkciju koja kao parametar prima pomenuti niz i index kolone te silazno sortira kompletan 2D niz po izabranoj
//koloni na nacin da se kompletni redovi zamjene prema vrijednosti u izabranoj koloni(princip sortiranja po koloni kao u MS Excel tabeli)
//1	2	4	8	16	32	64	128	256	512
//1024	2048	itd.itd.itd.itd.itd.itd.

/*
#include <iostream>
#include <iomanip>
using namespace std;

void ispis(int niz2[][10]){
	for (size_t i = 0; i < 10; i++)
	{
		cout << endl;
		for (size_t j = 0; j < 10; j++)
		{
			if(niz2[i][j]>=0)
			cout << setw(12) << niz2[i][j];

		}

	}
}

void zamjena(int niz[][10], int a, int b){

	int temp = 0;
	for (int i = 0; i <10; i++)
	{
		temp = niz[a][i];// [i][a]
		niz[a][i] = niz[b][i];//[i][a]=[i][b]   ZA KOLONE
		niz[b][i] = temp;//[i][b]=temp
	}

}
void sortiranje(int niz[][10], int izbor){//,int sort){

	bool prolaz = true;
	int temp = 0;
	int brojacProlaza = 10;
	while (prolaz){
		prolaz = false;
		for (int i = 0; i < brojacProlaza - 1; i++)
		{
			if (niz[i][izbor] < niz[i + 1][izbor]){
				zamjena(niz, i, i + 1);
				prolaz = true;
			}

		}
		brojacProlaza--;
	}
}


void transpose(int niz[][10]){
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			if (j > i){
				int temp = niz[i][j];
				niz[i][j] = niz[j][i];
				 niz[j][i]=temp;
			}
		}
	}
}

bool Generisi(int niz2[][10]) {

	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			if (i == 0 && j == 0) {
				j = 1;
			}

			niz2[i][j] = niz2[i][j - 1] * 2;
			if (niz2[i][j] >= INT_MAX)
				return false;


		}

	}
	return true;
}

void main(){


	int niz2[10][10];
	niz2[0][0] = 1;
	Generisi(niz2);
	ispis(niz2);
	transpose(niz2);
	cout << endl;
	ispis(niz2);
	cout << endl;
	int izbor;
	cout << "Unesite index kolone za sortiranje" << endl;
	do{
		cin >> izbor;
	} while (izbor < 1 || izbor>6);

	cout << "Nakon sortiranja" << endl;
	sortiranje(niz2,izbor);
	ispis(niz2);
	cout << endl;
	system("pause");
}

*/


//----------------------------------------------------------------------------------------------------------------------------