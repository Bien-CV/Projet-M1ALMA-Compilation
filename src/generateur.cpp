#include "generateur.hpp"

Conc* GenConc(Node* left, Node* right) {
	Conc* p_conc = new Conc();

	p_conc->left = left;
	p_conc->right = right;
	p_conc->classe = CONC;
	return p_conc;
}
/*
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
*/
Atom* GenAtom(int code, int action, AtomType type) {
	Atom* p_atom = new Atom();

	p_atom->code = code;
	p_atom->action = action;
	p_atom->type = type;
	p_atom->classe = ATOM;
	return p_atom;
}