#include <iostream>
#include <string>

using namespace std;

void interschimbare(int a, int b)
{
	int aux = a;
	a = b;
	b = aux;
}
void interschimbare(int* a, int* b) // avem doua functii cu acelasi nume, dar cu tipuri diferite de parametri = POLIMORFISM
{
	int aux = *a; // * face dereferentiere, valoarea memorata la adresa aux se inlocuieste cu valoarea memorata in a
	*a = *b; 
	*b = aux;
}
void interschimbare_referinta(int& a, int& b)
{
	int aux = a;
	a = b;
	b = aux;
}

struct produs_Machiaj {
	float pret;
	int cantitate;
	string producator;
};

produs_Machiaj citesteProdusMachiaj()
{
	produs_Machiaj produs;
	cout << "Pret produs ";
	cin >> produs.pret;
	cout << "Cant. produs ";
	cin >> produs.cantitate;
	cout << "Producator ";
	cin >> produs.producator;
	return produs;
}
void schimbarePret(produs_Machiaj &produs, int pretNou)
{
	produs.pret = pretNou;
}
void afisareProdusMachiaj(produs_Machiaj produs)
{
	cout << produs.producator << " ";
	cout << produs.cantitate << " ";
	cout << produs.pret << " ";
}
void main()
{
	int x = 20, y = 70;
	std::cout << "x= " << x << " y= " << y << std::endl;
	interschimbare(x, y);
	std::cout << "x= " << x << " y= " << y << std::endl;  //interschimbarea nu functioneaza
	interschimbare(&x, &y);
	std::cout << "x= " << x << " y= " << y << std::endl;
	interschimbare_referinta(x, y);
	std::cout << "x= " << x << " y= " << y << std::endl;   
	produs_Machiaj produs = citesteProdusMachiaj();
	afisareProdusMachiaj(produs);
	schimbarePret(produs, 1250);
	afisareProdusMachiaj(produs);
}