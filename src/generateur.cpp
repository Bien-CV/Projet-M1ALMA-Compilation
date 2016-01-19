#include "generateur.hpp"

Atom* GenAtom(int code, int action, AtomType type) {
	Atom* p_atom = new Atom();

	p_atom->code = code;
	p_atom->action = action;
	p_atom->type = type;
	p_atom->classe = CONC;
	return p_atom;
}