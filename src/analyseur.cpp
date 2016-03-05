#include "analyseur.hpp"

using namespace std;

bool analyse(Scanner * s, Node** G0, Node* p) {
	bool analyseur = false;

	switch(p->classe) {
		case CONC: {
			Conc* pconc = (Conc*)p;
			if(analyse(s, G0, pconc->left)) {
				analyseur = analyse(s, G0, pconc->right);
			} else {
				analyseur = false;
			}
		}
			break;
		case UNION: {
			Union* punion = (Union*)p;
			if(analyse(s, G0, punion->left)) {
				analyseur = true;
			} else {
				analyseur = analyse(s, G0, punion->right);
			}
		}
			break;
		case STAR: {
			Star* pstar = (Star*)p;
			analyseur = true;
			while (analyse(s, G0, pstar->stare)) {}
		}
			break;
		case UN: {
			Un* pun = (Un*)p;
			analyseur = true;
			analyse(s, G0, pun->une);
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
						//lireMot(s);
					} else {
						analyseur = false;
					}
				}
					break;
				case NONTERMINAL: {
					if(analyse(s, G0, G0[pa->code])) { //on choppe la case de G0 contenant l'action a effectuer //if(p->action !=0) {
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