#include "action.hpp"

using namespace std;

type_pile pile;
type_dico dicoT, dicoNT;

int recherche(type_dico & dico, int code) {
	unsigned int i;
	for (i = 0; i < dico.size(); ++i) {
		if(dico[i] == code) {

		}
	}
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

void g0_action(Atom *pa, int scanAction, Node** G0, type_tableSymbole & tabSymb, type_pile & pile) {
	Node * t1 = NULL;
	Node * t2 = NULL;

	switch (pa->action) {
		case 1: {
			depiler(pile, t1);
			depiler(pile, t2);
			Atom* p = (Atom*)t2;
			G0[(p->code)+5] = t1;
		}
			break;
		case 2: {
			//recherche renvoie le code du terminal si elle le trouve
			// sinon le stocke dans dicot ou dicont et le renvoie
			empiler(pile, GenAtom(recherche(dicoNT, pa->code), scanAction, pa->type));
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
			if (pa->type == TERMINAL) {
				empiler(pile, GenAtom(recherche(dicoT, pa->code), pa->action, TERMINAL));
			} else {
				empiler(pile, GenAtom(recherche(dicoNT, pa->code), scanAction, NONTERMINAL));
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