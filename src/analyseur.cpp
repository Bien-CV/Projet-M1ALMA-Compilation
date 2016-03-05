#include "analyseur.hpp"

using namespace std;

bool analyse(Scanner * s, Node** G0, Node* p) {
	bool analyseur = false;

	switch(p->classe) {
		case CONC: {
			Conc* pconc = (Conc*)p;
			cout << "par conc" << endl;
			if(analyse(s, G0, pconc->left)) {
				analyseur = analyse(s, G0, pconc->right);
			} else {
				analyseur = false;
			}
		}
			break;
		case UNION: {
			Union* punion = (Union*)p;
			cout << "par union" << endl;
			if(analyse(s, G0, punion->left)) {
				analyseur = true;
			} else {
				analyseur = analyse(s, G0, punion->right);
			}
		}
			break;
		case STAR: {
			cout << "par star" << endl;
			Star* pstar = (Star*)p;
			analyseur = true;
			while (analyse(s, G0, pstar->stare)) {}
		}
			break;
		case UN: {
			Un* pun = (Un*)p;
			cout << "par un" << endl;
			analyseur = true;
			analyse(s, G0, pun->une);
		}
			break;
		case ATOM: {
			Atom* pa = (Atom*)p;

			switch(pa->type) {
				case TERMINAL: {
					cout << "par atom term" << endl;
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
					cout << "par atom non term" << endl;
					// erreur de segm a cause de G0[pa->code] car code = 18 -> IDNTER
					if(analyse(s, G0, G0[pa->code])) { //on choppe la case de G0 contenant l'action a effectuer //if(p->action !=0) {
						cout << pa->code << endl;
						if(pa->action !=0) {
							//G0.action(p->act);
							cout << "true non term" <<endl;
						}
						analyseur = true;
					} else {
						analyseur = false;
						cout << "false non term" << endl;
					}
				}
					break;
			}
		}
			break;
	}
	return analyseur;
}