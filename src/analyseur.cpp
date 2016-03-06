#include "analyseur.hpp"

using namespace std;

bool analyse(Scanner * s, Node** G0, Node* p, type_tableSymbole & tabSymb) {
	bool analyseur = false;

	switch(p->classe) {
		case CONC: {
			Conc* pconc = (Conc*)p;
			if(analyse(s, G0, pconc->left, tabSymb)) {
				analyseur = analyse(s, G0, pconc->right, tabSymb);
			} else {
				analyseur = false;
			}
		}
			break;
		case UNION: {
			Union* punion = (Union*)p;
			if(analyse(s, G0, punion->left, tabSymb)) {
				analyseur = true;
			} else {
				analyseur = analyse(s, G0, punion->right, tabSymb);
			}
		}
			break;
		case STAR: {
			Star* pstar = (Star*)p;
			analyseur = true;
			while (analyse(s, G0, pstar->stare, tabSymb)) {}
		}
			break;
		case UN: {
			Un* pun = (Un*)p;
			analyseur = true;
			analyse(s, G0, pun->une, tabSymb);
		}
			break;
		case ATOM: {
			Atom* pa = (Atom*)p;

			switch(pa->type) {
				case TERMINAL: {
					if(pa->code == s->instance->code) {
						analyseur = true;
						if(pa->action !=0) {
							//G0.action(p->act);
						}
						lireMot(s, tabSymb);
					} else {
						analyseur = false;
					}
				}
					break;
				case NONTERMINAL: {
					//on choppe la case de G0 contenant l'action a effectuer
					if(analyse(s, G0, G0[pa->code], tabSymb)) {
						if(pa->action !=0) {
							//G0.action(p->act);
						}
						analyseur = true;
					} else {
						analyseur = false;
					}
				}
					break;
			}
		}
			break;
	}
	return analyseur;
}