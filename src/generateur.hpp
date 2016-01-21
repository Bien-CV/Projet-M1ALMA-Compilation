#ifndef GENERATEUR_HPP
#define GENERATEUR_HPP

#include "typage.hpp"

Conc* GenConc(Node* left, Node* right);
Union* GenUnion(Node* left, Node* right);
Star* GenStar(Node* stare);
Un* GenUn(Node* une);
Atom* GenAtom(int code, int action, AtomType type);
Node** GenForet();

#endif //GENERATEUR_HPP
