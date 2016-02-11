#include <iostream>
#include <fstream>
#include <string>

#include "/comptes/E10A324K/M1info/S2/compil/Projet-M1ALMA-Compilation/header/generateur.hpp"
#include "/comptes/E10A324K/M1info/S2/compil/Projet-M1ALMA-Compilation/header/Scanner.hpp"

using namespace std;

// bool analyse(Node** G0, Node* p) {
// 	switch(p->classe) {
// 		case CONC: {
// 			if(analyse(p->left)) {
// 				return analyse(p->right);
// 			} else {
// 				return false;
// 			}
// 		}
// 			break;
// 		case UNION: {
// 			if(analyse(p->left)) {
// 				return true;
// 			} else {
// 				return analyse(p->right);
// 			}
// 		}
// 			break;
// 		case STAR: {
// 			return analyse(p->stare);
// 		}
// 			break;
// 		case UN: {
// 			return analyse(p->une);
// 		}
// 			break;
// 		case ATOM: {
// 			switch(p->classe) {
// 				case TERMINAL: {
// 					if(p->code == "? a confirmer") { //tabsymb.contains(p->code)
// 						if(p->action !=0) {
// 							//G0.action(p->act)
// 							// scan(string) //?
// 							return true;
// 						} else {
// 							return false;
// 						}
// 					}
// 				}
// 					break;
// 				case NONTERMINAL: {
// 					if( analyse(G0[p->code]) ) { //on choppe la case de G0 contenant l'action a effectuer //if(p->action !=0) {
// 							//G0.action(p->act)
// 							return true;
// 						} 
// 					} else {
// 						return false;
// 					}
// 				}
// 					break;
// 			}
// 		}
// 			break;
// 	}
// }


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
    lireMot(scan);
    lireMot(scan);
	
	//cout << scan(0) << " " << scan(3) << endl; 

	return 0;
}
