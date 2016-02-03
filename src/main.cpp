#include <iostream>
#include <string>

#include "generateur.hpp"

using namespace std;

bool analyse(Node** snetf, Node* p) {
	switch(p->classe) {
		case CONC: {
			if(analyse(p->left)) {
				return analyse(p->right);
			} else {
				return false;
			}
		}
			break;
		case UNION: {
			if(analyse(p->left)) {
				return true;
			} else {
				return analyse(p->right);
			}
		}
			break;
		case STAR: {
			return analyse(p->stare);
		}
			break;
		case UN: {
			return analyse(p->une);
		}
			break;
		case ATOM: {
			switch(p->classe) {
				case TERMINAL: {
					if(p->code == "? a confirmer") {
						if(p->action !=0) {
							//snetf.action(p->act)
							// scan(string) //?
							return true;
						} else {
							return false;
						}
					}
				}
					break;
				case NONTERMINAL: {
					if( analyse(snetf[p->code]) ) { //on choppe la case de G0 contenant l'action a effectuer 						if(p->action !=0) {
							//snetf.action(p->act)
							return true;
						} 
					} else {
						return false;
					}
				}
					break;
			}
		}
			break;
	}
}


char scan(int nb) {
	ifstream file(filename);
	int k = nb;
	string line;
	getline(file, line);
	while((line.length() < nb) && (!file.eof()))  {
		nb = nb - line.length();
		getline(file, line);
	}
	if(!file.eof()) {
		return line[nb];
	} else {
		return '';
	}
}

int main() {
	
	Node** node;
	node = GenForet();

	for(int i = 0; i < 5; ++i) {
		ImprimeArbre(node[i], 0);
		cout << "\n";
	}
	
	return 0;
}
