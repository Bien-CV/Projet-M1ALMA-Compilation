#include "analyseur.hpp"

// using namespace std;

bool analyse(Scanner * s, std::map<int, Node*>& G0, Node* p, type_tableSymbole & tabSymb, type_pile & pile) {
	bool analyseur = false;

	switch(p->classe) {
		case CONC: {
			Conc* pconc = (Conc*)p;
			//std::cout<< " conc "  <<  std::endl;
			if(analyse(s, G0, pconc->left, tabSymb, pile)) {
				//std::cout<< " conc gauche ok donc go droite" << std::endl;
				analyseur = analyse(s, G0, pconc->right, tabSymb, pile);
				//std::cout<< " conc droite a été fait " << std::endl;

			} else {
				analyseur = false;
			}

			//std::cout<< ", analyseur conc: " << analyseur <<  std::endl;
		}
			break;
		case UNION: {
			//std::cout<< " union" << std::endl;
			Union* punion = (Union*)p;
			if(analyse(s, G0, punion->left, tabSymb, pile)) {
				//std::cout<< " union gauche ok pas de droite" << std::endl;
				analyseur = true;
			} else {
				//std::cout<< " union gauche pas ok go droite" << std::endl;
				analyseur = analyse(s, G0, punion->right, tabSymb, pile);
			}

			//std::cout<< ", analyseur union : " << analyseur <<  std::endl;
		}
			break;
		case STAR: {
			//std::cout<< " star" << std::endl;
			Star* pstar = (Star*)p;
			analyseur = true;
			while (analyse(s, G0, pstar->stare, tabSymb, pile)) {
				//std::cout<< "1 star effectué" << std::endl;
			}
		}
			break;
		case UN: {
			//std::cout<< " un" << std::endl;
			Un* pun = (Un*)p;
			analyseur = true;
			analyse(s, G0, pun->une, tabSymb, pile);
			//std::cout<< ", analyseur un : " << analyseur <<  std::endl;
		}
			break;
		case ATOM: {
			Atom* pa = (Atom*)p;
			//std::cout<< " ATom" << std::endl;

			switch(pa->type) {
				case TERMINAL: {
					std::cout<< "-------------------" << std::endl;
					if(pa->code == s->instance->code) {

						// std::cout<< "je suis term, symb = " << s->instance->chaine << ", code mère:" << pa->code  << ", code action pa-> :" << pa->action << " , action instance:" << s->instance->action << std::endl;
						analyseur = true;
						if(pa->action !=0) {
							g0_action(pa, s->instance->type, s->instance->action, G0, tabSymb, pile, s->instance->chaine);
						}
						lireMot(s, tabSymb);
					} else {
						//std::cout<< "je suis term, symb = " << s->instance->chaine << ", code mère:" << pa->code  << ", code gpl :" << s->instance->code << " differents" << std::endl;
						
						analyseur = false;
					}
				}
					break;
				case NONTERMINAL: {
					std::cout<< " ----------------" << std::endl;
					//on choppe la case de G0 contenant l'action a effectuer
					//std::cout<< "je suis passé par non term" << std::endl;
					if(analyse(s, G0, G0[pa->code], tabSymb, pile)) {
						if(pa->action !=0) {
							g0_action(pa, s->instance->type, s->instance->action, G0, tabSymb, pile, s->instance->chaine);
						}
						analyseur = true;
					} else {
						analyseur = false;
					}

					// std::cout<< ", analyseur atom non term: " << analyseur <<  std::endl;
				}
					break;
			}
		}
			break;
	}
	return analyseur;
}


// bool analyse_GPL(Scanner_GPL * s, std::map<int, Node*>& G0, Node* p, type_tableSymbole & tabSymb, std::stack<int>& pileOP, std::map<std::string, int>& IATAB, std::vector<int>& p_code) {
// 	bool analyseur_GLP = false;

// 	switch(p->classe) {
// 		case CONC: {
// 			Conc* pconc = (Conc*)p;
// 			std::cout<< " conc "  <<  std::endl;
// 			if(analyse_GPL(s, G0, pconc->right, tabSymb, pileOP, IATAB, p_code)) {
// 				//std::cout<< " conc gauche ok donc go droite" << std::endl;
// 				analyseur_GLP = analyse_GPL(s, G0, pconc->left, tabSymb, pileOP, IATAB, p_code);
// 				//std::cout<< " conc droite a été fait " << std::endl;

// 			} else {
// 				analyseur_GLP = false;
// 			}

// 			//std::cout<< ", analyseur_GLP = conc: " << analyseur_GLP = <<  std::endl;
// 		}
// 			break;
// 		case UNION: {
// 			std::cout<< " union" << std::endl;
// 			Union* punion = (Union*)p;
// 			if(analyse_GPL(s, G0, punion->right, tabSymb, pileOP, IATAB, p_code)) {
// 				//std::cout<< " union gauche ok pas de droite" << std::endl;
// 				analyseur_GLP = true;
// 			} else {
// 				//std::cout<< " union gauche pas ok go droite" << std::endl;
// 				analyseur_GLP = analyse_GPL(s, G0, punion->left, tabSymb, pileOP, IATAB, p_code);
// 			}

// 			//std::cout<< ", analyseur_GLP = union : " << analyseur_GLP = <<  std::endl;
// 		}
// 			break;
// 		case STAR: {
// 			std::cout<< " star" << std::endl;
// 			Star* pstar = (Star*)p;
// 			analyseur_GLP = true;
// 			while (analyse_GPL(s, G0, pstar->stare, tabSymb, pileOP, IATAB, p_code)) {
// 				//std::cout<< "1 star effectué" << std::endl;
// 			}
// 		}
// 			break;
// 		case UN: {
// 			std::cout<< " un" << std::endl;
// 			Un* pun = (Un*)p;
// 			analyseur_GLP = true;
// 			analyse_GPL(s, G0, pun->une, tabSymb, pileOP, IATAB, p_code);
// 			//std::cout<< ", analyseur_GLP = un : " << analyseur_GLP = <<  std::endl;
// 		}
// 			break;
// 		case ATOM: {
// 			Atom* pa = (Atom*)p;
// 			std::cout<< " ATom" << pa->code << std::endl;

// 			switch(pa->type) {
// 				case TERMINAL: {
// 					std::cout<< "-------------------" << std::endl;
// 					if(pa->code == s->instance->code) {

// 						//std::cout<< "je suis term, symb = " << s->instance->chaine << ", code mère:" << pa->code  << ", code gpl :" << s->instance->code << std::endl;
// 						analyseur_GLP = true;
// 						if(pa->action !=0) {
// 							//gpl_action(pa, s->instance->action, G0, tabSymb, pile, s->instance->chaine);
// 						}

// 						lireMotGPL(s, tabSymb);

// 					} else {
// 						std::cout<< "je suis term, symb = " << s->instance->chaine << ", code mère:" << pa->code  << ", code gpl :" << s->instance->code << " differents" << std::endl;
						
// 						analyseur_GLP = false;
// 					}

// 					//std::cout<< ", analyseur_GLP = atom term: " << analyseur_GLP = <<  std::endl;
// 				}
// 					break;
// 				case NONTERMINAL: {
// 					std::cout<< " ----------------" << std::endl;
// 					//on choppe la case de G0 contenant l'action a effectuer
// 					//std::cout<< "je suis passé par non term" << std::endl;
// 					if(analyse_GPL(s, G0, G0[pa->code], tabSymb, pileOP, IATAB, p_code)) {
// 						if(pa->action !=0) {
// 							//gpl_action(pa, s->instance->action, G0, tabSymb, pile, s->instance->chaine);
// 						}
// 						analyseur_GLP = true;
// 					} else {
// 						analyseur_GLP = false;
// 					}

// 					//std::cout<< ", analyseur_GLP = atom non term: " << analyseur_GLP = <<  std::endl;
// 				}
// 					break;
// 			}
// 		}
// 			break;
// 	}
// 	return analyseur_GLP;
// }

bool analyse_GPL(Scanner_GPL * s, std::map<int, Node*>& G0, Node* p, type_tableSymbole & tabSymb, std::stack<int>& pileOP, std::map<std::string, int>& IATAB, std::vector<int>& p_code) {
	bool analyseur_GLP = false;

	switch(p->classe) {
		case CONC: {
			Conc* pconc = (Conc*)p;
			// std::cout<< " conc "  <<  std::endl;
			if(analyse_GPL(s, G0, pconc->left, tabSymb, pileOP, IATAB, p_code)) {
				//std::cout<< " conc gauche ok donc go droite" << std::endl;
				analyseur_GLP = analyse_GPL(s, G0, pconc->right, tabSymb, pileOP, IATAB, p_code);
				//std::cout<< " conc droite a été fait " << std::endl;

			} else {
				analyseur_GLP = false;
			}

			//std::cout<< ", analyseur_GLP = conc: " << analyseur_GLP = <<  std::endl;
		}
			break;
		case UNION: {
			// std::cout<< " union" << std::endl;
			Union* punion = (Union*)p;
			if(analyse_GPL(s, G0, punion->left, tabSymb, pileOP, IATAB, p_code)) {
				//std::cout<< " union gauche ok pas de droite" << std::endl;
				analyseur_GLP = true;
			} else {
				//std::cout<< " union gauche pas ok go droite" << std::endl;
				analyseur_GLP = analyse_GPL(s, G0, punion->right, tabSymb, pileOP, IATAB, p_code);
			}

			//std::cout<< ", analyseur_GLP = union : " << analyseur_GLP = <<  std::endl;
		}
			break;
		case STAR: {
			// std::cout<< " star" << std::endl;
			Star* pstar = (Star*)p;
			analyseur_GLP = true;
			while (analyse_GPL(s, G0, pstar->stare, tabSymb, pileOP, IATAB, p_code)) {
				//std::cout<< "1 star effectué" << std::endl;
			}
		}
			break;
		case UN: {
			// std::cout<< " un" << std::endl;
			Un* pun = (Un*)p;
			analyseur_GLP = true;
			analyse_GPL(s, G0, pun->une, tabSymb, pileOP, IATAB, p_code);
			//std::cout<< ", analyseur_GLP = un : " << analyseur_GLP = <<  std::endl;
		}
			break;
		case ATOM: {
			Atom* pa = (Atom*)p;
			// std::cout<< " ATom " << pa->code << std::endl;

			switch(pa->type) {
				case TERMINAL: {
					std::cout<< "-------------------" << std::endl;
					if(pa->code == s->instance->code) {

						//std::cout<< "je suis term, symb = " << s->instance->chaine << ", code mère:" << pa->code  << ", code gpl :" << s->instance->code << std::endl;
						analyseur_GLP = true;
						if(pa->action !=0) {
							gpl_action(IATAB, pileOP, p_code, s->instance->chaine, pa->action);
						}

						lireMotGPL(s, tabSymb);

					} else {
						
						analyseur_GLP = false;
					}

					//std::cout<< ", analyseur_GLP = atom term: " << analyseur_GLP = <<  std::endl;
				}
					break;
				case NONTERMINAL: {
					std::cout<< " ----------------" << std::endl;
					//on choppe la case de G0 contenant l'action a effectuer
					//std::cout<< "je suis passé par non term" << std::endl;
					if(analyse_GPL(s, G0, G0[pa->code], tabSymb, pileOP, IATAB, p_code)) {
						if(pa->action !=0) {
							gpl_action(IATAB, pileOP, p_code, s->instance->chaine, pa->action);
						}
						analyseur_GLP = true;
					} else {
						analyseur_GLP = false;
					}

					//std::cout<< ", analyseur_GLP = atom non term: " << analyseur_GLP = <<  std::endl;
				}
					break;
			}
		}
			break;
	}
	return analyseur_GLP;
}