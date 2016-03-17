#include "action.hpp"

using namespace std;

type_pile pile;
type_dico dicoT, dicoNT;

int recherche(type_dico & dico, int code) {
	unsigned int i;
	for (i = 0; i < dico.size(); ++i) {
		if(dico[i] == code) {
			return code;
		}
	}
	dico.push_back(code);
	return code;
}

void empiler(type_pile & pile, Node * p) {
	pile.push(p);
}


void depiler(type_pile & pile, Node * p) {
	p = pile.top();
	pile.pop();
}

void g0_action(Atom *pa, int scanAction, Node** G0, type_tableSymbole & tabSymb, type_pile & pile) {
	Node * t1 = new Node();
	Node * t2 = new Node();

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

			cout << "##############################################" << endl;
			ImprimeArbre(pile.top(), 0);
			cout << "#####################f########################" << endl;
		}
			break;
		case 4: {
			depiler(pile, t1);
			depiler(pile, t2);
			empiler(pile, GenConc(t2, t1));
			cout << "##############################################" << endl;
			ImprimeArbre(pile.top(), 0);
			cout << "#####################f########################" << endl;
		}
			break;
		case 5: {
			if (pa->type == TERMINAL) {
				empiler(pile, GenAtom(recherche(dicoT, pa->code), pa->action, TERMINAL));
				cout << "##############################################" << endl;
			ImprimeArbre(pile.top(), 0);
			cout << "#####################f########################" << endl;
			} else {
				empiler(pile, GenAtom(recherche(dicoNT, pa->code), scanAction, NONTERMINAL));
				cout << "##############################################" << endl;
			ImprimeArbre(pile.top(), 0);
			cout << "#####################f########################" << endl;
			}
		}
			break;
		case 6: {
			depiler(pile, t1);
			empiler(pile, GenStar(t1));
			cout << "##############################################" << endl;
			ImprimeArbre(pile.top(), 0);
			cout << "#####################f########################" << endl;
		}
			break;
		case 7: {
			depiler(pile, t1);
			empiler(pile, GenUn(t1));
			cout << "##############################################" << endl;
			ImprimeArbre(pile.top(), 0);
			cout << "#####################f########################" << endl;
		}
			break;
	}
}