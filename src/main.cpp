#include <iostream>
#include <fstream>
#include <string>

#include "/comptes/E10A324K/M1info/S2/compil/Projet-M1ALMA-Compilation/header/generateur.hpp"
#include "/comptes/E10A324K/M1info/S2/compil/Projet-M1ALMA-Compilation/header/Scanner.hpp"

using namespace std;

bool analyse(Scanner * s, Node** G0, Node* p) {
	Node * nextSymbol;
	switch(p->classe) {
		case CONC: {
			Conc* pconc = (Conc*)p;
			if(analyse(s, G0, pconc->left)) {
				return analyse(s, G0, pconc->right);
			} else {
				return false;
			}
		}
			break;
		case UNION: {
			Union* punion = (Union*)p;
			if(analyse(s, G0, punion->left)) {
				return true;
			} else {
				return analyse(s, G0, punion->right);
			}
		}
			break;
		case STAR: {
			Star* pstar = (Star*)p;
			return analyse(s, G0, pstar->stare);
		}
			break;
		case UN: {
			Un* pun = (Un*)p;
			return analyse(s, G0, pun->une);
		}
			break;
		case ATOM: {
			Atom* pa = (Atom*)p;
			switch(pa->type) {
				case TERMINAL: {
					if(pa->code == 1/* code! */) { //tabsymb.contains(p->code)
						if(pa->action !=0) {
							//G0.action(p->act)
							nextSymbol = lireMot(s);

							return analyse(s, G0,nextSymbol);
							//return true;
						} else {
							return false;
						}
					}
				}
					break;
				case NONTERMINAL: {
					if(analyse(s, G0, G0[pa->code])) { //on choppe la case de G0 contenant l'action a effectuer //if(p->action !=0) {
							//G0.action(p->act)
							return true;
					} else {
						return false;
					}
				}
					break;
			}
		}
			break;
	}
	return false;
}


// string scan(int nb) {

// 	ifstream file;
//     file.open ("src/gpl.txt");
//     string word = "";
//     char x ;
//     word.clear();

//     while ((!file.eof()) && (nb > 0)) {
//         x = file.get();
//         while ( x != ' ' ) {
//             word = word + x;
//             x = file.get();
//         }
//         nb--;
//         word.clear();
//     }
//     if(!file.eof()) {

//     	x = file.get();
//     	while ( x != ' ' ) {
//             word = word + x;
//             x = file.get();
//             cout << x;
//         }
//     }
//     return word;
// }

int main() {
	
	Node** node;
	node = GenForet();

	for(int i = 0; i < 5; ++i) {
		ImprimeArbre(node[i], 0);
		cout << "\n";
	}

    Scanner * scan = new Scanner;
    initScan(scan,"src/gpl.txt");
    // lireMot(scan);
    // lireMot(scan);
	
	//cout << scan(0) << " " << scan(3) << endl; 

	return 0;
}
