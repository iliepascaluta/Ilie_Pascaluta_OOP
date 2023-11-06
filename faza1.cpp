#include <iostream>
using namespace std;

//domeniul ales este piata de capital, intialele mele fiind "i" si "p"

class actiune {
public:

	static string clasa_risc;
	static int contor;
	static void afisare_risc();
	const int nr_actiuni_emise;
	string *nume_actiune;
	int volum_mediu;
	float pret, randament_anual;

	actiune() :nr_actiuni_emise(contor*1000) {
		contor++;
		this->nume_actiune = new string[1];
		this->nume_actiune[0] = "Nvidia";
		this->volum_mediu = 45;
		this->pret = 403.26f;
		this->randament_anual = 207.6f;
	}
	actiune(int volum, float pret) :nr_actiuni_emise(contor * 1000) {
		contor++;
		this->nume_actiune = new string[1];
		this->nume_actiune[0] = "Apple";
		this->volum_mediu = volum;
		this->pret = pret;
		this->randament_anual = ((this->pret)/125-1) * 100;
	}
	actiune(string nume_actiune, int volum, float pret, float randament_anual) :nr_actiuni_emise(contor * 1000) {
		contor++;
		this->nume_actiune = new string[1];
		this->nume_actiune[0] = nume_actiune;
		this->volum_mediu = volum;
		this->pret = pret;
		this->randament_anual = randament_anual;
	}
	
	void afisare_info_actiune() {
		cout << "Exista un nr de " << this->nr_actiuni_emise 
			 << " actiuni emise de " << *this->nume_actiune 
			 << "; ultimul pret a fost de " << this->pret << "$;"
		     << " volumul de tranzactionare mediu recent este " << this->volum_mediu 
			 << "; performanta actiunii de la inceputul anului este de " << this->randament_anual << "%"
			 << endl;
	}
};
int actiune::contor = 1;
string actiune::clasa_risc = "moderat";
void actiune::afisare_risc() {
	cout << clasa_risc;
}

class obligatiune {
public:
	static int i;
	static string clasa_risc;
	static void afisare_risc();
	const int nr_obligatiuni_emise;
	string* emitent;
	int maturitate;
	float  dobanda;

	obligatiune() :nr_obligatiuni_emise(1000 * (i++)) {
		this->emitent = new string[1];
		this->emitent[0] = "SUA";
		this->maturitate = 10;
		this->dobanda = 4.88f;
	}
	obligatiune(string emitent, float dobanda) :nr_obligatiuni_emise(1000*(i++)) {
		this->emitent = new string[1];
		this->emitent[0] = emitent;
		this->maturitate = 10;		
		this->dobanda = dobanda;
	}
	obligatiune(string emitent, int maturitate,  float dobanda) :nr_obligatiuni_emise(1000 * (i++)) {
		this->emitent = new string[1];
		this->emitent[0] = emitent;
		this->maturitate = maturitate;
		this->dobanda = dobanda;
	}
	void afisare_info_obligatiune() {
		cout << "Obligatiunile emise de " << *emitent
			<< " in numar de " << nr_obligatiuni_emise
			<< " cu o maturitate de " << maturitate 
			<< " ani ofera in prezent o dobanda de " << dobanda << "%" <<" anual"
			<< endl;
	}
};
int obligatiune::i = 1;
string obligatiune::clasa_risc = "inexistent";
void obligatiune::afisare_risc() {
	cout << clasa_risc;
}

class indice_de_actiuni {
public:
	static string clasa_risc;
	static void afisare_risc();
	string* nume_indice;
	const int nr_actiuni_componente;
	int pret;
	float randament_anual, randament_istoric_anualizat;

	indice_de_actiuni():nr_actiuni_componente(500) {
		this->nume_indice = new string[1];
		this->nume_indice[0] = "S&P 500";
		this->pret = 4193;
		this->randament_anual = 9.67f;
		this->randament_istoric_anualizat = 11.82f;
	}
	indice_de_actiuni(int pret, float randament_anual, float randament_istoric_anualizat) :nr_actiuni_componente(100){
		this->nume_indice = new string[1];
		this->nume_indice[0] = "Nasdaq";
		this->pret = pret;
		this->randament_anual = randament_anual;
		this->randament_istoric_anualizat = randament_istoric_anualizat;
	}
	indice_de_actiuni(string nume, int pret, float randament_anual, float randament_istoric_anualizat):nr_actiuni_componente(50) {
		this->nume_indice = new string[1];
		this->nume_indice[0] = nume;
		this->pret = pret;
		this->randament_anual = randament_anual;
		this->randament_istoric_anualizat = randament_istoric_anualizat;

	}
	void afisare_indice() {
		cout << "Indicele " << *nume_indice
			<< " compus din" << nr_actiuni_componente
			<< "  de actiuni inregistreaza anul acesta o performanta de " << randament_anual << "%. "
			<< " Acest indice de actiuni a oferit in trecut un randament mediu anualizat de " << randament_istoric_anualizat << "%."
			<< "In prezent se tranzactioneaza la pretul de " << pret
			<< endl;
			 
	}
};
string indice_de_actiuni::clasa_risc = "scazut";
void indice_de_actiuni::afisare_risc() {
	cout << clasa_risc;
}

void main()
{

	 actiune actiune1;
	 actiune1.afisare_info_actiune();

	 actiune actiune2(2345, 170.5f);
	 actiune2.afisare_info_actiune();

	 actiune actiune3("Tesla", 3500, 219.96f, 30.5f);
	 actiune3.afisare_info_actiune();

	 obligatiune obligatiune1;
	 obligatiune1.afisare_info_obligatiune();

	 obligatiune obligatiune2("UE", 3.58f);
	 obligatiune2.afisare_info_obligatiune();

	 obligatiune obligatiune3("Guvernul SUA ", 30, 4.59f);
	 obligatiune3.afisare_info_obligatiune();

	 indice_de_actiuni indice1;
	 indice1.afisare_indice();

	 indice_de_actiuni indice2(15154, 39.5f, 10.8f);
	 indice2.afisare_indice();

	 indice_de_actiuni indice3("Stoxx 50", 4158, 7.8f, 6.6f);
	 indice3.afisare_indice();
}
