#include <iostream>
#include <string>

#include "generateur.hpp"

using namespace std;

void ImprimeArbre(Node * p) {
	int k = 1, prof = 0;
	prof += 1;
	for (k = 1; k <= prof; ++k)
	{
		cout << "---" ;
		switch (p->classe) {

			case CONC:
				cout << "lala" <<endl;
				break;
			case UNION:
				cout << "lala" <<endl;
				break;
			case STAR:
				cout << "lala" <<endl;
				break;
			case UN:
				cout << "lala" <<endl;
				break;
			case ATOM: 
				Atom* pa = (Atom*)p;
				cout << "> " << pa->code << endl;
				break;
		}
	}

}

int main() {
	
	Atom* a = GenAtom(1,0, TERMINAL);
	ImprimeArbre(a);

	delete(a);
	return 0;
}