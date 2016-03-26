#include "generateur.hpp"

using namespace std;

Conc* GenConc(Node* left, Node* right) {
	Conc* p_conc = new Conc();

	p_conc->left = left;
	p_conc->right = right;
	p_conc->classe = CONC;
	return p_conc;
}

Union* GenUnion(Node* left, Node* right) {
	Union* p_union = new Union();

	p_union->left = left;
	p_union->right = right;
	p_union->classe = UNION;
	return p_union;
}

Star* GenStar(Node* stare) {
	Star* p_stare = new Star();

	p_stare->stare = stare;
	p_stare->classe = STAR;
	return p_stare;
}
Un* GenUn(Node* une) {
	Un* p_un = new Un();

	p_un ->une = une;
	p_un ->classe = UN;
	return p_un ;
}

Atom* GenAtom(int code, int action, AtomType type) {
	Atom* p_atom = new Atom();

	p_atom->code = code;
	p_atom->action = action;
	p_atom->type = type;
	p_atom->classe = ATOM;
	return p_atom;
}

// Node** GenForet() {
std::map<int, Node*> GenForet() {
	// Node** node = new Node*[5];

	std::map<int, Node*> node;

	node[0] = GenConc(
					GenStar(
						GenConc(
							GenConc(
								GenConc(
									GenAtom(1,0,NONTERMINAL),
									GenAtom(5,0,TERMINAL)),
								GenAtom(2,0,NONTERMINAL)),
							GenAtom(10,1,TERMINAL))
						),
					GenAtom(9,0,TERMINAL));
	
	node[1] = GenAtom(18,2,TERMINAL);
	
	node[2] = GenConc(
						GenAtom(3,0,NONTERMINAL),
						GenStar(
							GenConc(
								GenAtom(7,0,TERMINAL),
								GenAtom(3,3,NONTERMINAL))
							)
						);
							
	node[3] = GenConc(
						GenAtom(4,0,NONTERMINAL),
						GenStar(
							GenConc(
								GenAtom(6,0,TERMINAL),
								GenAtom(4,4,NONTERMINAL))
							)
						);
						
	node[4] = GenUnion(
					GenUnion(
						GenUnion(
							GenUnion(
								GenAtom(18,5,TERMINAL),
								GenAtom(17,5,TERMINAL)
							),
							GenConc(
								GenAtom(11,0,TERMINAL),
								GenConc(
									GenAtom(2,0,NONTERMINAL),
									GenAtom(12,0,TERMINAL)
								)
							)
						),
						GenConc(
							GenAtom(13,0,TERMINAL),
							GenConc(
								GenAtom(2,0,NONTERMINAL),
								GenAtom(14,6,TERMINAL)
							)
						)
					),
					GenConc(
						GenAtom(15,0,TERMINAL),
							GenConc(
								GenAtom(2,0,NONTERMINAL),
								GenAtom(16,7,TERMINAL)
							)
						)
				);
	
	return node;
}

void ImprimeArbre(Node * p, int prof) {
	for (int k = 0; k <= prof; ++k)
	{
		cout << "---" ;
	}
	if(p != NULL)
	{
		switch (p->classe) {
			case CONC: {
				Conc* pconc = (Conc*)p;
				cout << "> conc" << endl;
				ImprimeArbre(pconc->left, prof+1);
				ImprimeArbre(pconc->right, prof+1);
			}
				break;
			case UNION: {
				Union* punion = (Union*)p;
				cout << "> union" << endl;
				ImprimeArbre(punion->left, prof+1);
				ImprimeArbre(punion->right, prof+1);
			}
				break;
			case STAR: {
				Star* pstar = (Star*)p;
				cout << "> star" << endl;
				ImprimeArbre(pstar->stare, prof+1);
			}
				break;
			case UN: {
				Un* pun = (Un*)p;
				cout << "> un" << endl;
				ImprimeArbre(pun->une, prof+1);
			}
				break;
			case ATOM: {
				Atom* pa = (Atom*)p;
				cout << "> " << pa->code;
				if(pa->action != -1){
					cout << ", act " << pa->action;
				}
				cout << endl;
			}
				break;
		}
	} else {
		cout << "vide" << endl;
	}
}