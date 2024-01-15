#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
using namespace std;


//domeniul ales este piata de capital, intialele mele fiind "i" si "p"

class actiune {
private:

	static string clasa_risc;
	static int contor;
	static void afisare_risc();
	const int nr_actiuni_emise;
	char* nume_actiune;
	int volum_mediu;
	float pret, randament_anual;
public:
	actiune() :nr_actiuni_emise(contor * 1000) {
		contor++;
		this->nume_actiune = new char[7];
		strcpy(this->nume_actiune, "Nvidia");
		this->volum_mediu = 45;
		this->pret = 403.26f;
		this->randament_anual = 207.6f;
	}
	actiune(int volum, float pret) :nr_actiuni_emise(contor * 1000) {
		contor++;
		this->nume_actiune = new char[6];
		strcpy(this->nume_actiune, "Apple");
		this->volum_mediu = volum;
		this->pret = pret;
		this->randament_anual = ((this->pret) / 125 - 1) * 100;
	}
	actiune(char* nume, int volum, float pret, float randament_anual) :nr_actiuni_emise(contor * 1000) {
		contor++;
		this->nume_actiune = new char[strlen(nume) + 1];
		strcpy(this->nume_actiune, nume);
		this->volum_mediu = volum;
		this->pret = pret;
		this->randament_anual = randament_anual;
	}

	//constructor de copiere
	actiune(const actiune& actiune) : nr_actiuni_emise(actiune.nr_actiuni_emise) {
		contor++;
		this->nume_actiune = new char[strlen(actiune.nume_actiune) + 1];
		strcpy(this->nume_actiune, actiune.nume_actiune);
		this->volum_mediu = actiune.volum_mediu;
		this->pret = actiune.pret;
		this->randament_anual = actiune.randament_anual;
	}
	~actiune() {
		delete[] nume_actiune;
	}
	int get_volum() {
		return volum_mediu;
	}
	void set_volum(int volum) {
		this->volum_mediu = volum;
	}
	float get_pret() {
		return pret;
	}
	void set_pret(float pret) {
		if (pret > 0)
			this->pret = pret;
	}
	float get_randament() {
		return randament_anual;
	}
	void set_randament(float randament) {
		this->randament_anual = randament;
	}
	char* get_nume() {
		return nume_actiune;
	}
	void set_nume(char* nume) {
		if (this->nume_actiune != NULL)
			delete[]nume_actiune;
		this->nume_actiune = new char[strlen(nume) + 1];
		strcpy(this->nume_actiune, nume);
	}

	void afisare_info_actiune() {
		cout << "Exista un nr de " << this->nr_actiuni_emise
			<< " actiuni emise de " << this->nume_actiune
			<< "; ultimul pret a fost de " << this->pret << "$;"
			<< " volumul de tranzactionare mediu recent este " << this->volum_mediu
			<< "; performanta actiunii de la inceputul anului este de " << this->randament_anual << "%"
			<< endl;
	}
	

	actiune& operator=(const actiune& a) {
		if (this != &a) {
			if(nume_actiune != NULL)
				delete[] nume_actiune;
			nume_actiune = new char[strlen(a.nume_actiune) + 1];
			strcpy(nume_actiune, a.nume_actiune);
			volum_mediu = a.volum_mediu;
			pret = a.pret;
			randament_anual = a.randament_anual;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& os, const actiune& a) {
		os 
		<< "Nume Actiune: " << a.nume_actiune << endl
		<< "Nr Actiuni Emise: " << a.nr_actiuni_emise << endl
		<< "Volum Mediu: " << a.volum_mediu << endl
		<< "Pret: " << a.pret << endl
			<< "Randament Anual: " << a.randament_anual << "%" << endl;
		return os;
	}
	friend istream& operator>>(istream& is, actiune& a) {
		cout << " Nume Actiune: ";
		is >> a.nume_actiune;
		cout << " Volum Mediu: ";
		is >> a.volum_mediu;
		cout << " Pret: ";
		is >> a.pret;
		cout << " Randament Anual: ";
		is >> a.randament_anual;
		return is;
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
	char* emitent;
	int maturitate;
	float  dobanda;

	obligatiune() :nr_obligatiuni_emise(1000 * (i++)) {
		this->emitent = new char[4];
		strcpy(this->emitent , "SUA");
		this->maturitate = 10;
		this->dobanda = 4.88f;
	}
	obligatiune(char *emitent, float dobanda) :nr_obligatiuni_emise(1000*(i++)) {
		this->emitent = new char[strlen(emitent) + 1];
		strcpy(this->emitent, emitent);
		this->maturitate = 10;		
		this->dobanda = dobanda;
	}
	obligatiune(char *emitent, int maturitate,  float dobanda) :nr_obligatiuni_emise(1000 * (i++)) {
		this->emitent = new char[strlen(emitent) + 1];
		strcpy(this->emitent, emitent);
		this->maturitate = maturitate;
		this->dobanda = dobanda;
	}
	obligatiune(const obligatiune& obligatiune) : nr_obligatiuni_emise(obligatiune.nr_obligatiuni_emise) {
		this->emitent = new char[strlen(obligatiune.emitent) + 1];
		strcpy(this->emitent, obligatiune.emitent);
		this->maturitate = obligatiune.maturitate;
		this->dobanda = obligatiune.dobanda;
	}
	~obligatiune() {
		delete[] emitent;
	}
	void afisare_info_obligatiune() {
		cout << "Obligatiunile emise de " << emitent
			<< " in numar de " << nr_obligatiuni_emise
			<< " cu o maturitate de " << maturitate 
			<< " ani ofera in prezent o dobanda de " << dobanda << "%" <<" anual"
			<< endl;
	}
	
	obligatiune& operator=(const obligatiune& o) {
		if (this != &o) {
			if(emitent != NULL)
				delete[] emitent;
			emitent = new char[strlen(o.emitent) + 1];
			strcpy(emitent, o.emitent);
			maturitate = o.maturitate;
			dobanda = o.dobanda;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& os, const obligatiune o) {
		os << "Emitent: " << o.emitent << endl
			<< "Nr Obligatiuni Emise: " << o.nr_obligatiuni_emise << endl			
			<< "Maturitate: " << o.maturitate << " ani" << endl
			<< "Dobanda: " << o.dobanda << "%" << endl;
		return os;
	}
	friend istream& operator>>(istream& is, obligatiune& o) {
		cout << " Emitent: ";
		is >> o.emitent;
		cout << " Maturitate (ani): ";
		is >> o.maturitate;
		cout << " Dobanda: ";
		is >> o.dobanda;
		return is;
	}
};
int obligatiune::i = 1;
string obligatiune::clasa_risc = "minim";
void obligatiune::afisare_risc() {
	cout << clasa_risc;
}

class indice_de_actiuni {
public:
	static string clasa_risc;
	static void afisare_risc();
	char* nume_indice;
	const int nr_actiuni_componente;
	int pret;
	float randament_anual, randament_istoric_anualizat;

	indice_de_actiuni() :nr_actiuni_componente(500) {
		this->nume_indice = new char[8];
		strcpy(this->nume_indice, "S&P 500");
		this->pret = 4193;
		this->randament_anual = 9.67f;
		this->randament_istoric_anualizat = 11.82f;
	}
	indice_de_actiuni(int pret, float randament_anual, float randament_istoric_anualizat) :nr_actiuni_componente(100) {
		this->nume_indice = new char[11];
		strcpy(this->nume_indice, "Nasdaq 100");
		this->pret = pret;
		this->randament_anual = randament_anual;
		this->randament_istoric_anualizat = randament_istoric_anualizat;
	}
	indice_de_actiuni(char* nume, int pret, float randament_anual, float randament_istoric_anualizat) :nr_actiuni_componente(50) {
		this->nume_indice = new char[strlen(nume) + 1];
		strcpy(this->nume_indice, nume);
		this->pret = pret;
		this->randament_anual = randament_anual;
		this->randament_istoric_anualizat = randament_istoric_anualizat;

	}
	//constructor de copiere
	indice_de_actiuni(const indice_de_actiuni& i) : nr_actiuni_componente(i.nr_actiuni_componente) {
		this->nume_indice = new char[strlen(i.nume_indice) + 1];
		strcpy(this->nume_indice, i.nume_indice);
		this->pret = i.pret;
		this->randament_anual = i.randament_anual;
		this->randament_istoric_anualizat = i.randament_istoric_anualizat;
	}
	~indice_de_actiuni() {
		delete[] nume_indice;
	}
	void afisare_indice() {
		cout << "Indicele " << nume_indice
			<< " compus din " << nr_actiuni_componente
			<< "  de actiuni a inregistrat in ultimul an o performanta de " << randament_anual << "%. "
			<< " Acest indice bursier a oferit in trecut un randament mediu (anualizat) de " << randament_istoric_anualizat << "%."
			<< "In prezent se tranzactioneaza la pretul de " << pret
			<< endl;

	}



	indice_de_actiuni& operator=(const indice_de_actiuni& i) {
		if (this != &i) {
			if(nume_indice != NULL)
				delete[] nume_indice;
			nume_indice = new char[strlen(i.nume_indice) + 1];
			strcpy(nume_indice, i.nume_indice);
			pret = i.pret;
			randament_anual = i.randament_anual;
			randament_istoric_anualizat = i.randament_istoric_anualizat;
		}
		return *this;
	}
};
string indice_de_actiuni::clasa_risc = "scazut";
void indice_de_actiuni::afisare_risc() {
	cout << clasa_risc;
}

class portofoliu_de_investitii {
private:
	int istoric, expunere_actiuni, expunere_obligatiuni;
	float performanta_oferita;
	char* manager;
	actiune a[3];
	obligatiune o;

public:
	portofoliu_de_investitii(int istoric, char* manager, float performanta, actiune actiuni[3], obligatiune o, int expunere_actiuni, int expunere_obligatiuni) {
		this->istoric = istoric;
		this->manager = new char[strlen(manager)];
		strcpy(this->manager, manager);
		this->performanta_oferita = performanta;
		for (int i = 0; i < 3; i++)
			a[i] = actiuni[i];
		this->o = o;
		this->expunere_actiuni = expunere_actiuni;
		this->expunere_obligatiuni = expunere_obligatiuni;
	}
	
	int get_istoric() {
		return this->istoric;
	}
	void set_istoric(int istoric) {
		this->istoric = istoric;
	}
	int get_expunere_actiuni() {
		return this->expunere_actiuni;
	}
	void set_expunere_actiuni(int expunere_actiuni) {
		this->expunere_actiuni = expunere_actiuni;
	}
	int get_expunere_obligatiuni() {
		return this->expunere_obligatiuni;
	}
	void set_expunere_obligatiuni(int expunere_obligatiuni) {
		this->expunere_obligatiuni = expunere_obligatiuni;
	}
	float get_performanta() {
		return this->performanta_oferita;
	}
	void set_performanta(float performanta_actualizata) {
		this->performanta_oferita = performanta_actualizata;
	}
	char* get_manager() {
		return this->manager;
	}
	void set_manager(char* new_manager) {
		if (this->manager != new_manager)
		{
			if (this->manager != NULL)
				delete[]this->manager;
			this->manager = new char[strlen(new_manager)];
			strcpy(this->manager, new_manager);
		}
	}
	actiune get_actiuni() {
		for (int i = 0; i < 3; i++)
			return a[i];
	}
	void set_actiuni(actiune actiune, int i) {
		a[i] = actiune;
	}
	obligatiune get_obligatiune() {
		return o;
	}
	void set_obligatiune(obligatiune o) {
		this->o = o;
	}

	portofoliu_de_investitii& operator=(const portofoliu_de_investitii& p) {
		if (this != &p && &p!=NULL)
		{
			istoric = p.istoric;
			if (manager != NULL)
				delete[]manager;
			manager = new char[strlen(p.manager)];
			strcpy(manager, p.manager);
			performanta_oferita = p.performanta_oferita;
			for (int i = 0; i < 3; i++)
				a[i] = p.a[i];
			o = p.o;
			expunere_actiuni = p.expunere_actiuni;
			expunere_obligatiuni = p.expunere_obligatiuni;
		}
		return *this;
		
	}

	friend ostream& operator<<(ostream &o, portofoliu_de_investitii p) {
		o << endl << " Portofoliul administrat de catre " << p.manager
			<< " are un istoric de " << p.istoric
			<< " ani pe piata, oferind investitorilor sai o performanta medie anuala de " << p.performanta_oferita << " %. "
			<< " In prezent, structura portofoliului este urmatoarea: " << endl
			<< p.expunere_actiuni << " % actiuni "
			<< p.expunere_obligatiuni << " % obligatiuni" << endl
			<< " Detalii instrumente aflate in portofoliu: " << endl;
		for (int i = 0; i < 3; i++)
			o << p.a[i] << endl;
		o << p.o << endl;
		return o;
	}
	friend istream& operator>>(istream& i, portofoliu_de_investitii& p) {
		i >> de
	}


	void afisare_info_portofoliu() {
		cout << endl <<" Portofoliul administrat de catre " << manager
			<< " are un istoric de " << istoric
			<< " ani pe piata, oferind investitorilor sai o performanta medie anuala de " << performanta_oferita << " %. "
			<< " In prezent, structura portofoliului este urmatoarea: " << endl
			<< expunere_actiuni << " % actiuni "
			<< expunere_obligatiuni << " % obligatiuni" << endl
			<< " Detalii instrumente aflate in portofoliu: " << endl;
		for (int i = 0; i < 3; i++)
			a[i].afisare_info_actiune();
		o.afisare_info_obligatiune();
	}
};

void main()
{
	//liniile comentate mai jos sunt aferente fazei 1 a proiectului

	
	/* actiune actiune1;
	 actiune1.afisare_info_actiune();
	 
	 actiune actiune2(2345, 170.5f);
	 actiune2.afisare_info_actiune();

	 actiune actiune3("tesla", 3500, 219.96f, 30.5f);
	 actiune3.afisare_info_actiune();

	 obligatiune obligatiune1;
	 obligatiune1.afisare_info_obligatiune();

	 obligatiune obligatiune2("ue", 3.58f);
	 obligatiune2.afisare_info_obligatiune();

	 obligatiune obligatiune3("guvernul sua ", 30, 4.59f);
	 obligatiune3.afisare_info_obligatiune();

	 indice_de_actiuni indice1;
	 indice1.afisare_indice();

	 indice_de_actiuni indice2(15154, 39.5f, 10.8f);
	 indice2.afisare_indice();

	 indice_de_actiuni indice3("stoxx 50", 4158, 7.8f, 6.6f);
	 indice3.afisare_indice();*/


	 //liniile comentate mai jos sunt aferente fazei 2 a proiectului

	/*actiune a1;
	
	cout << "Volum Mediu: " << a1.get_volum() << endl;
	cout << "Pret: " << a1.get_pret() << endl;
	cout << "Randament Anual: " << a1.get_randament() << "%" << endl;
	cout << "Nume Actiune: " << a1.get_nume() << endl;

	char* nume_nou = new char[10];
	strcpy(nume_nou, "Microsoft");
	a1.set_nume(nume_nou);
	cout << "Numele nou: " << a1.get_nume() << endl;

	actiune a2 = a1;
	cout << "Info copiat din a1 in a2:" << endl;
	a2.afisare_info_actiune();
	process_actiune(a1);
	
	obligatiune o1;
	cout << "Maturitate: " << o1.maturitate << " years" << endl;
	cout << "Dobanda: " << o1.dobanda << "%" << endl;
	cout << "Emitent: " << *o1.emitent << endl;

	obligatiune o2 = o1;
	cout << "Info copiat din o1 in o2:" << endl;
	o2.afisare_info_obligatiune();
	process_obligatiune(o1);

	indice_de_actiuni i1;
	cout << "Pret Indice: " << i1.pret << endl;
	cout << "Randament Anual Indice: " << i1.randament_anual << "%" << endl;
	cout << "Randament Istoric Anualizat: " << i1.randament_istoric_anualizat << "%" << endl;
	cout << "Nume Indice: " << *i1.nume_indice << endl;

	indice_de_actiuni i2 = i1;
	cout << "Info copiat din i1 in i2:" << endl;
	i2.afisare_indice();

	process_indice_de_actiuni(i1);*/


	actiune actiuni[3];
	actiuni[0] = actiune(strdup("Tesla"), 3500, 219.96f, 30.5f);
	actiuni[1] = actiune(strdup("Apple"), 5000, 150.75f, 20.0f);
	actiuni[2] = actiune(strdup("Microsoft"), 3000, 180.0f, 15.5f);
	cout << "vectorul declarat de obiecte de tip actiune este: " << endl;
	for (int i = 0; i < 3; i++)
		actiuni[i].afisare_info_actiune();

	obligatiune obligatiuni[3];
	obligatiuni[0] = obligatiune(strdup("US Treasury"), 4.5f);
	obligatiuni[1] = obligatiune(strdup("UE"), 10, 5.8f);
	obligatiuni[2] = obligatiune(strdup("Guv. Romaniei"), 3, 7.2f);
	cout << endl << "vectorul declarat de obiecte de tip obligatiune este: " << endl;
	for (int i = 0; i < 3; i++)
		obligatiuni[i].afisare_info_obligatiune();

	indice_de_actiuni indici[3];
	indici[0] = indice_de_actiuni(strdup("S&P 500 "), 4780, 19.8f, 11.0f);
	indici[1] = indice_de_actiuni(14972, 34, 10.5f);
	indici[2] = indice_de_actiuni(strdup("Stoxx50 "), 4480, 8.7f, 9.8f);
	cout << endl << "vectorul declarat de obiecte de indice de actiuni actiune este: " << endl;
	for (int i = 0; i < 3; i++)
		indici[i].afisare_indice();

	actiune matrice_actiuni[3][3] = 
	{
	   
	   {actiune(strdup("Bank of America"), 5000, 45.0f, 2.5f),
	   actiune(strdup("JP Morgan"), 3000, 150.0f, 3.8f), 
	   actiune(strdup("Goldman Sachs"), 2000, 220.0f, 4.2f)},

	   {actiune(strdup("Qualcomm"), 1200, 150.0f, 2.7f), 
	   actiune(strdup("AMD"), 1800, 85.0f, 2.0f), 
	   actiune(strdup("Alphabet"), 2500, 1800.0f, 1.5f)},

	   {actiune(strdup("Amazon"), 800, 3400.0f, 1.8f),
	   actiune(strdup("Intel"), 1600, 55.0f, 3.5f), 
	   actiune(strdup("Netflix"), 1200, 520.0f, 2.0f)}

	};
	cout << endl << "Matricea declarata de obiecte de tip actiune este: " << endl;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			matrice_actiuni[i][j].afisare_info_actiune();

	obligatiune obligatiune(strdup("Guv. Romaniei"), 3, 7.2f);
	portofoliu_de_investitii p(20, strdup("Focus Invest"), 13.8f, actiuni, obligatiune, 70, 30);

	cout << p;
}
