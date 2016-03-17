#ifndef ANALYSEUR_HPP
#define ANALYSEUR_HPP

#include <iostream>
#include "typage.hpp"
#include "scanner.hpp"
#include "tabSymbole.hpp"
#include "action.hpp"

bool analyse(Scanner * s, Node** G0, Node* p, type_tableSymbole & tabSymb, type_pile & pile);

#endif //ANALYSEUR_HPP