#include "analyseur.hpp"

using namespace std;

bool analyse(Scanner * s, Node** G0, Node* p, type_tableSymbole & tabSymb) {
	bool analyseur = false;

	switch(p->classe) {
		case CONC: {
			Conc* pconc = (Conc*)p;
			cout << " conc " << endl;
			if(analyse(s, G0, pconc->left, tabSymb)) {
				cout << " conc gauche ok donc go droite" << endl;
				analyseur = analyse(s, G0, pconc->right, tabSymb);
				cout << " conc droite a été fait " << endl;

			} else {
				analyseur = false;
			}
		}
			break;
		case UNION: {
			cout << " union" << endl;
			Union* punion = (Union*)p;
			if(analyse(s, G0, punion->left, tabSymb)) {
				cout << " union gauche ok pas de droite" << endl;
				analyseur = true;
			} else {
				cout << " union gauche pas ok go droite" << endl;
				analyseur = analyse(s, G0, punion->right, tabSymb);
			}
		}
			break;
		case STAR: {
			cout << " star" << endl;
			Star* pstar = (Star*)p;
			analyseur = true;
			while (analyse(s, G0, pstar->stare, tabSymb)) {}
		}
			break;
		case UN: {
			cout << " un" << endl;
			Un* pun = (Un*)p;
			analyseur = true;
			analyse(s, G0, pun->une, tabSymb);
		}
			break;
		case ATOM: {
			Atom* pa = (Atom*)p;
			cout << " ATom" << endl;

			switch(pa->type) {
				case TERMINAL: {
					cout << "-------------------" << endl;
					if(pa->code == s->instance->code) {
						cout << "je suis term" << endl;
						analyseur = true;
						if(pa->action !=0) {
							G0_action(p->act, G0);
						}
						lireMot(s, tabSymb);
					} else {
						analyseur = false;
					}
				}
					break;
				case NONTERMINAL: {
					cout << " ----------------" << endl;
					//on choppe la case de G0 contenant l'action a effectuer
					cout << "je suis passé par non term" << endl;
					if(analyse(s, G0, G0[pa->code], tabSymb)) {
						if(pa->action !=0) {
							G0_action(p->act, G0);
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