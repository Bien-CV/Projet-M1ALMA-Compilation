#include "analyseur.hpp"

// using namespace std;

bool analyse(Scanner * s, std::map<int, Node*>& G0, Node* p, type_tableSymbole & tabSymb, type_pile & pile) {
	bool analyseur = false;

	switch(p->classe) {
		case CONC: {
			Conc* pconc = (Conc*)p;
			if(analyse(s, G0, pconc->left, tabSymb, pile)) {
				analyseur = analyse(s, G0, pconc->right, tabSymb, pile);

			} else {
				analyseur = false;
			}

		}
			break;
		case UNION: {
			Union* punion = (Union*)p;
			if(analyse(s, G0, punion->left, tabSymb, pile)) {
				analyseur = true;
			} else {
				analyseur = analyse(s, G0, punion->right, tabSymb, pile);
			}
		}
			break;
		case STAR: {
			Star* pstar = (Star*)p;
			analyseur = true;
			while (analyse(s, G0, pstar->stare, tabSymb, pile)) {
			}
		}
			break;
		case UN: {
			Un* pun = (Un*)p;
			analyseur = true;
			analyse(s, G0, pun->une, tabSymb, pile);
		}
			break;
		case ATOM: {
			Atom* pa = (Atom*)p;

			switch(pa->type) {
				case TERMINAL: {
					if(pa->code == s->instance->code) {

						analyseur = true;
						if(pa->action !=0) {
							g0_action(pa, s->instance->type, s->instance->action, G0, tabSymb, pile, s->instance->chaine);
						}
						lireMot(s, tabSymb);
					} else {
						analyseur = false;
					}
				}
					break;
				case NONTERMINAL: {
					//on choppe la case de G0 contenant l'action a effectuer
					if(analyse(s, G0, G0[pa->code], tabSymb, pile)) {
						if(pa->action !=0) {
							g0_action(pa, s->instance->type, s->instance->action, G0, tabSymb, pile, s->instance->chaine);
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

bool analyse_GPL(Scanner_GPL * s, std::map<int, Node*>& G0, Node* p, type_tableSymbole & tabSymb, std::stack<int>& pileOP, std::map<std::string, int>& IATAB, std::vector<int>& p_code) {
	bool analyseur_GLP = false;

	switch(p->classe) {
		case CONC: {
			Conc* pconc = (Conc*)p;
			if(analyse_GPL(s, G0, pconc->left, tabSymb, pileOP, IATAB, p_code)) {
				analyseur_GLP = analyse_GPL(s, G0, pconc->right, tabSymb, pileOP, IATAB, p_code);

			} else {
				analyseur_GLP = false;
			}
		}
			break;
		case UNION: {
			Union* punion = (Union*)p;
			if(analyse_GPL(s, G0, punion->left, tabSymb, pileOP, IATAB, p_code)) {
				analyseur_GLP = true;
			} else {
				analyseur_GLP = analyse_GPL(s, G0, punion->right, tabSymb, pileOP, IATAB, p_code);
			}
		}
			break;
		case STAR: {
			Star* pstar = (Star*)p;
			analyseur_GLP = true;
			while (analyse_GPL(s, G0, pstar->stare, tabSymb, pileOP, IATAB, p_code)) {
			}
		}
			break;
		case UN: {
			Un* pun = (Un*)p;
			analyseur_GLP = true;
			analyse_GPL(s, G0, pun->une, tabSymb, pileOP, IATAB, p_code);
		}
			break;
		case ATOM: {
			Atom* pa = (Atom*)p;

			switch(pa->type) {
				case TERMINAL: {
					if(pa->code == s->instance->code) {
						analyseur_GLP = true;
						if(pa->action !=0) {
							gpl_action(IATAB, pileOP, p_code, s->instance->chaine, pa->action);
						}

						lireMotGPL(s, tabSymb);

					} else {
						
						analyseur_GLP = false;
					}
				}
					break;
				case NONTERMINAL: {
					//on choppe la case de GPL contenant l'action a effectuer
					if(analyse_GPL(s, G0, G0[pa->code], tabSymb, pileOP, IATAB, p_code)) {
						if(pa->action !=0) {
							gpl_action(IATAB, pileOP, p_code, s->instance->chaine, pa->action);
						}
						analyseur_GLP = true;
					} else {
						analyseur_GLP = false;
					}
				}
					break;
			}
		}
			break;
	}
	return analyseur_GLP;
}