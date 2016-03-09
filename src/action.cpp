#include "action.hpp"

using namespace std;

type_pile pile;
type_dico dicoT, dicoNT;

int recherche(type_dico & dico, type_tableSymbole & tabSymb) {
	// for (int i = 0; i < dico.size(); ++i)
	// {
		
	// }
	return 0;
}

void empiler(type_pile & pile, Node * p) {
	p = pile.top();
	pile.push(p);
}

void depiler(type_pile & pile, Node * p) {
	p = pile.top();
	pile.pop();
}

void g0_action(int pAction, int scanAction, AtomType atype, Node** G0, type_tableSymbole & tabSymb, type_pile & pile) {
	Node * t1 = NULL;
	Node * t2 = NULL;

	switch (pAction) {
		case 1: {
			depiler(pile, t1);
			depiler(pile, t2);
			Atom* pa = (Atom*)t2;
			G0[(pa->code)+5] = t1;
		}
			break;
		case 2: {
			//recherche renvoie le code du terminal si elle le trouve
			// sinon le stocke dans dicot ou dicont et le renvoie
			empiler(pile, GenAtom(recherche(dicoNT,tabSymb), scanAction, atype));
		}
			break;
		case 3: {
			depiler(pile, t1);
			depiler(pile, t2);
			empiler(pile, GenUnion(t2, t1));
		}
			break;
		case 4: {
			depiler(pile, t1);
			depiler(pile, t2);
			empiler(pile, GenConc(t2, t1));
		}
			break;
		case 5: {
			if (atype == TERMINAL) {
				empiler(pile, GenAtom(recherche(dicoT,tabSymb), pAction, TERMINAL));
			} else {
				empiler(pile, GenAtom(recherche(dicoNT,tabSymb), scanAction, NONTERMINAL));
			}
		}
			break;
		case 6: {
			depiler(pile, t1);
			empiler(pile, GenStar(t1));
		}
			break;
		case 7: {
			depiler(pile, t1);
			empiler(pile, GenUn(t1));
		}
			break;
	}
}