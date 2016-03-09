#include "action.hpp"

using namespace std;

type_pile pile;
type_dico dicoT, dicoNT;

int recherche(type_dico dico) {
	for (int i = 0; i < dico.size(); ++i)
	{
		
	}
	return -1;
}

void empiler(Node * p) {

}

void depiler(Node * p) {

}

void G0_action(int action, Node** G0) {
	Node * t1, t2;

	switch (action) {
		case 1: {
			depiler(t1);
			depiler(t2);
			G0[t2->code] = t1;
		}
			break;
		case 2: {
			//recherche renvoie le code du terminal si elle le trouve
			// sinon le stocke dans dicot ou dicont et le renvoie
			empiler(GenAtom(recherche(dicoNT), action, NONTERMINAL)); /*atomtype?*/
		}
			break;
		case 3: {
			depiler(t1);
			depiler(t2);
			empiler(GenUnion(t2, t1));
		}
			break;
		case 4: {
			depiler(t1);
			depiler(t2);
			empiler(GenConc(t2, t1));
		}
			break;
		case 5: {
			if Atype == TERMINAL {
				empiler(GenAtom(recherche(dicoT), action, TERMINAL));
			} else {
				empiler(GenAtom(recherche(dicoNT), action, NONTERMINAL));
			}
		}
			break;
		case 6: {
			depiler(t1);
			empiler(GenStar(t1));
		}
			break;
		case 7: {
			depiler(t1);
			empiler(GenUn(t1));
		}
			break;
	}
}