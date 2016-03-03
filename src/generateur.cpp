#include "header/generateur.hpp"

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

Node** GenForet() {
	Node** node = new Node*[5];

	node[0] = GenConc(
		GenStar(
			GenConc(
				GenConc(
					GenConc(
						GenAtom((int)'N',0,NONTERMINAL),
						GenAtom((int)'>',0,TERMINAL)),
					GenAtom((int)'E',0,NONTERMINAL)),
				GenAtom((int)',',0,TERMINAL))
			),
		GenAtom((int)';',0,TERMINAL));
	
	node[1] = //GenConc(
						GenAtom((int)'N',0,NONTERMINAL);//,
						//GenAtom((int)'>',0,TERMINAL));
	
	node[2] = GenConc(
						GenAtom((int)'T',0,NONTERMINAL),
						GenStar(
							GenConc(
								GenAtom((int)'+',0,TERMINAL),
								GenAtom((int)'T',0,NONTERMINAL))
							)
						);
							
	node[3] = GenConc(
						GenAtom((int)'F',0,NONTERMINAL),
						GenStar(
							GenConc(
								GenAtom((int)'.',0,TERMINAL),
								GenAtom((int)'F',0,NONTERMINAL))
							)
						);
						
	node[4] = GenUnion(
				GenUnion(
					GenUnion(
						GenUnion(
							GenAtom((int)'N',0,NONTERMINAL),
							GenAtom((int)'e',0,TERMINAL)
						),
						GenConc(
							GenAtom((int)'(',0,TERMINAL),
							GenConc(
								GenAtom((int)'E',0,NONTERMINAL),
								GenAtom((int)')',0,TERMINAL)
							)
						)
					),
					GenConc(
						GenAtom((int)'[',0,TERMINAL),
						GenConc(
							GenAtom((int)'E',0,NONTERMINAL),
							GenAtom((int)']',0,TERMINAL)
						)
					)
				),
				GenConc(
					GenConc(
						GenAtom((int)'(',0,TERMINAL),
						GenAtom((int)'|',0,TERMINAL)
					),
					GenConc(
						GenAtom((int)'E',0,NONTERMINAL),
						GenConc(
							GenAtom((int)'|',0,TERMINAL),
							GenAtom((int)')',0,TERMINAL)
						)
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
				cout << "> " << pa->code << endl;
			}
				break;
		}
}