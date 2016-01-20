#include <iostream>
#include <string>

#include "generateur.hpp"

using namespace std;

void ImprimeArbre(Node * p, int prof) {
	//int prof = 0;
	//prof += 1;
	for (int k = 0; k <= prof; ++k)
	{
		cout << "---" ;
	}
		switch (p->classe) {
			case CONC: {
				Conc* pconc = (Conc*)p;
				cout << "> conc" << endl;
				ImprimeArbre(pconc->left, prof+1);
				ImprimeArbre(pconc->right, prof+1);
			}
				break;
			case UNION: {
				Union* punion = (Union*)p;
				cout << "> union" << endl;
				ImprimeArbre(punion->left, prof+1);
				ImprimeArbre(punion->right, prof+1);
			}
				break;
			case STAR: {
				Star* pstar = (Star*)p;
				cout << "> star" << endl;
				ImprimeArbre(pstar->stare, prof+1);
			}
				break;
			case UN: {
				Un* pun = (Un*)p;
				cout << "> un" << endl;
				ImprimeArbre(pun->une, prof+1);
			}
				break;
			case ATOM: {
				Atom* pa = (Atom*)p;
				cout << "> " << pa->code << endl;
			}
				break;
		}
}

int main() {
	
	Atom* a = GenAtom(1,0, TERMINAL);
	Atom* b = GenAtom(2,0, TERMINAL);
	Conc* c = GenConc(a, b);
	//ImprimeArbre(a);
	//ImprimeArbre(b);
	ImprimeArbre(c, 0); //profondeur de 0

	//cout << c->left->code << endl;
	//cout << c->right->code << endl;

	delete(a);
	delete(b);
	delete(c);
	return 0;
}