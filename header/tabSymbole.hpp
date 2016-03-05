#ifndef TABSYMBOLE_HPP
#define TABSYMBOLE_HPP

#include <iostream>
#include <string>
#include <map>

typedef std::map <std::string, int> type_tableSymbole;

void initTableSymbole(type_tableSymbole & tabSym);

int rechercheSymbole(std::string s, type_tableSymbole & tabSym);

#endif //TABSYMBOLE_HPP