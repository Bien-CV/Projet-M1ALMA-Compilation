#ifndef ANALYSEUR_HPP
#define ANALYSEUR_HPP

#include <iostream>
#include <map>
#include "typage.hpp"
#include "scanner.hpp"
#include "tabSymbole.hpp"
#include "action.hpp"

bool analyse(Scanner * s, std::map<int, Node*>& G0, Node* p, type_tableSymbole & tabSymb, type_pile & pile);
bool analyse_GLP(Scanner * s, std::map<int, Node*>& G0, Node* p, type_tableSymbole & tabSymb, type_pile & pile);

#endif //ANALYSEUR_HPP