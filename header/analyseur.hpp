#ifndef ANALYSEUR_HPP
#define ANALYSEUR_HPP

#include <iostream>
#include "typage.hpp"
#include "scanner.hpp"

bool analyse(Scanner * s, Node** G0, Node* p);

#endif //ANALYSEUR_HPP