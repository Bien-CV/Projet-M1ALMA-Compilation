#ifndef ACTION_HPP
#define ACTION_HPP

#include <iostream>
#include <vector>
#include <stack>
#include "generateur.hpp"
#include "tabSymbole.hpp"
#include "typage.hpp"

typedef std::stack<Node*> type_pile;
typedef std::vector<int> type_dico;

int recherche(type_dico & dico, int code);
void empiler(type_pile & pile, Node * p);
Node * depiler(type_pile & pile);
void g0_action(Atom *pa, int scanAction, std::map<int, Node*>& G0, type_tableSymbole & tabSymb, type_pile & pile);

#endif //ACTION_HPP