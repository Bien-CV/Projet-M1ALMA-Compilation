#include "action.hpp"

// using namespace std;

type_pile pile;
// type_dico dicoT, dicoNT;

// int recherche(type_dico & dico, std::string symb) {
// 	unsigned int i;
// 	for (i = 0; i < dico.size(); ++i) {
// 		if(dico[i] == code) {
// 			return code;
// 		}
// 	}
// 	dico.push_back(code);
// 	return code;
// }

void empiler(type_pile & pile, Node * p) {
	pile.push(p);
}


Node * depiler(type_pile & pile) {
	Node * p = new Node();
	p = pile.top();
	pile.pop();
	return p;
}

void g0_action(Atom *pa, AtomType type, int scanAction, std::map<int, Node*>& G0, type_tableSymbole & tabSymb, type_pile & pile, std::string symbole) {
	Node * t1 = new Node();
	Node * t2 = new Node();

	switch (pa->action) {
		case 1: {
			t1 = depiler(pile);
			t2 = depiler(pile);
			Atom* p = (Atom*)t2;
			G0[(p->code)] = t1;
			ImprimeArbre(G0[(p->code)],0);
		}
			break;
		case 2: {
			//recherche renvoie le code du terminal si elle le trouve
			// sinon le stocke dans dicot ou dicont et le renvoie
			empiler(pile, GenAtom(/*recherche(dicoNT, pa->code)*/ recherche_symb_ac_add(symbole,tabSymb), scanAction, pa->type));
		}
			break;
		case 3: {
			t1 = depiler(pile);
			t2 = depiler(pile);
			// cout << t1->action << " t1 union t2 : " << t2->action << endl;
			empiler(pile, GenUnion(t2, t1));
		}
			break;
		case 4: {
			t1 = depiler(pile);
			t2 = depiler(pile);
			// cout << t1->action << " t1 conc t2 : " << t2->action << endl;
			empiler(pile, GenConc(t2, t1));
		}
			break;
		case 5: {
			if (type == TERMINAL) {
				empiler(pile, GenAtom(recherche_symb_ac_add(symbole,tabSymb), scanAction /*pa->action*/, TERMINAL));
			} else {
				empiler(pile, GenAtom(recherche_symb_ac_add(symbole,tabSymb), scanAction, NONTERMINAL));
			}
		}
			break;
		case 6: {
			t1 = depiler(pile);
			empiler(pile, GenStar(t1));
		}
			break;
		case 7: {
			t1 = depiler(pile);
			empiler(pile, GenUn(t1));
		}
			break;
	}
}

void gpl_action( std::map<std::string, int>& IATAB, std::stack<int>& pileOP, std::vector<int>& p_code, std::string chaine, int action) {
	switch (action) {
    
	    case 1: {//prep memoire
        	IATAB[chaine] = IATAB.size();
	    } 
		break;
	    
	    case 2: {//lda
        	p_code.push_back(1);
        	p_code.push_back(IATAB[chaine]);
	    } 
		break;
	    
	    case 3: {//ldv
        	p_code.push_back(2);
        	p_code.push_back(IATAB[chaine]);
	    } 
		break;
	    
	    case 4: {//ldc
        	p_code.push_back(3);
        	p_code.push_back(atoi(chaine.c_str()));
	    } 	
		break;
	    
	    case 5: {//aff
        	p_code.push_back(28);
	    } 
		break;
	    
	    case 6: {//add
        	pileOP.push(18);
	    } 
		break;

	    case 7: {//moins
        	pileOP.push(19);
	    } 
		break;
	    
	    case 8: {//mult
        	pileOP.push(20);
	    } 
		break;
	    
	    case 9: {//div
        	pileOP.push(21);
	    } 
		break;
	    
	    case 10: {//ldv + depilement d'action
        	p_code.push_back(2);
        	p_code.push_back(IATAB[chaine]);
        	p_code.push_back(pileOP.top());
        	pileOP.pop();
	    } 
		break;
	    
	    case 11: {//ldc + depilement d'action
        	p_code.push_back(3);
        	p_code.push_back(atoi(chaine.c_str()));
        	p_code.push_back(pileOP.top());
        	pileOP.pop();
	    } 
		break;
	    
	    case 12: {//wrt
        	pileOP.push(16);
	    } 
		break;
	    
	    case 13: {//wrtln
        	pileOP.push(17);
	    } 
		break;
	    
	    case 14: {//stop
        	p_code.push_back(29);
	    } 
		break;
	    
	    case 15: {//or
        	pileOP.push(26);
	    } 
		break;
	    
	    case 16: {//depile action
        	p_code.push_back(pileOP.top());
        	pileOP.pop();
	    } 
		break;
	    
	    case 17: {//and
        	pileOP.push(25);
	    } 
		break;
	    
	    case 18: {//not
        	pileOP.push(27);
	    } 
		break;
	    
	    case 19: {//empile ==
        	pileOP.push(12);
	    } 
		break;
	    
	    case 20: {//empile >=
        	pileOP.push(9);
	    } 
		break;
	    
	    case 21: {//empile <=
        	pileOP.push(11);
	    } 
		break;
	    
	    case 22: {//empile !=
        	pileOP.push(13);
	    } 
		break;
	    
	    case 23: {//empile >
        	pileOP.push(8);
	    } 
		break;
	    
	    case 24: {//stop
        	pileOP.push(10);
	    } 
		break;

		case 25: {//jump if false
        	int c0 = p_code.size()-1;
        	p_code.push_back(5);
        	pileOP.push(c0 +2);
        	p_code.push_back(-1);

	    } 
		break;

		case 26: {//fin if
			p_code[pileOP.top()] = p_code.size();
        	pileOP.pop();
	    } 
		break;

		case 27: {//saut du else
        	int c0 = p_code.size()-1;
        	p_code.push_back(4);
        	p_code[pileOP.top()] = c0+3;
        	pileOP.pop();
        	pileOP.push(c0 +2);
        	p_code.push_back(-1);
	    } 
		break;

		case 28: {//prep while
			int c0 = p_code.size()-1;
        	pileOP.push(c0 +1);

	    } 
		break;

		case 29: {//saut du do
			int c0 = p_code.size()-1;
        	p_code.push_back(5);
        	pileOP.push(c0 +2);
        	p_code.push_back(-1);
	    } 
		break;

		case 30: {//end while
        	int c0 = p_code.size()-1;
        	p_code[pileOP.top()] = c0+3;
        	pileOP.pop();
        	p_code.push_back(4);
        	p_code.push_back(pileOP.top());
        	pileOP.pop();
	    } 
		break;

	}

}