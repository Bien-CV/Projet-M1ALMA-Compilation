#ifndef TABSYMBOLE_HPP
#define TABSYMBOLE_HPP

#include <iostream>
#include <string>
#include <map>

typedef std::map <int, std::string> type_tableSymbole;

void initTableSymbole(type_tableSymbole & tabSym);

void affTableSymbole(type_tableSymbole & tabSymb);

int rechercheSymboleDansG0(std::string s, type_tableSymbole & tabSymb);

int rechercheSymbole(std::string s, type_tableSymbole & tabSym);

int recherche_symb_ac_add(std::string s, type_tableSymbole & tabSym);

#endif //TABSYMBOLE_HPP