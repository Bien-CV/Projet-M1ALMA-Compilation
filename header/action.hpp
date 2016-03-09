#ifndef ACTION_HPP
#define ACTION_HPP

#include <iostream>
#include <vector>
#include "generateur.hpp"
#include "typage.hpp"

typedef std::vector<Node> type_pile;
typedef std::vector<std::string> type_dico;

int recherche(type_dico dico);
void empiler(Node * p);
void depiler(Node * p);
void G0_action(int action, Node ** G0);

#endif //ACTION_HPP