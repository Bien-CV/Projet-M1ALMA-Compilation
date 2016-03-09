#ifndef ACTION_HPP
#define ACTION_HPP

#include <iostream>
#include <vector>
#include <stack>
#include "generateur.hpp"
#include "tabSymbole.hpp"
#include "typage.hpp"

typedef std::stack<Node*> type_pile;
typedef std::vector<std::string> type_dico;

int recherche(type_dico & dico, type_tableSymbole & tabSymb);
void empiler(type_pile & pile, Node * p);
void depiler(type_pile & pile, Node * p);
void g0_action(int action, int scanAction, AtomType atype, Node ** G0, type_tableSymbole & tabSymb, type_pile & pile);

#endif //ACTION_HPP