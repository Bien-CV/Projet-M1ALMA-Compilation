#include <iostream>
#include <string>

#include "generateur.hpp"

using namespace std;

void ImprimeArbre(Node * p, int prof) {
	//int prof = 0;
	//prof += 1;
	for (int k = 0; k <= prof; ++k)
	{
		cout << "--- " ;
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
	
	//Atom* a = GenAtom(1,0, TERMINAL);
	//Atom* b = GenAtom(2,0, TERMINAL);
	//Conc* c = GenConc(GenAtom(1,0, TERMINAL), GenAtom(2,0,TERMINAL));
	//ImprimeArbre(a);
	//ImprimeArbre(b);
	Node* node;
	node = GenForet();
	//ImprimeArbre(S, 0);
	//ImprimeArbre(c, 0); //profondeur de 0
	//Node* E = GenConc(GenAtom(1,0,NONTERMINAL),GenStar(GenConc(GenAtom(2,1,TERMINAL), GenAtom(3,0,NONTERMINAL))));
	//ImprimeArbre(E, 0);
for(int i = 0; i < 5; ++i) {
	ImprimeArbre(node, 0);
}
	//delete(a);
	//delete(b);
	//delete(c);
	//delete(S);
	//delete(E);
	return 0;
}
