#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "typage.hpp"

typedef struct {
	std::fstream * fs;
	std::map <std::string, int> tabSymbole;
} Scanner;

//scan permet d'avancer dans phrase (S -> 'a' + 'b') et avec analyse
// -> a chaque fin d'analyse (ATOM) on check si se qu'on a trouve == 
//ce sur quoi le scan est. si ok on avance scan et on continue 
// ex ici conc -> star -> conc -> conc -> N ->idnter : scan = S donc ok, on continue;
// conc droit = ->, scan est sur fleche: ok...

void initScan(Scanner * s, std::string file);
int recherche(string s);
Node * lireMot(Scanner * s);




#endif //SCANNER_HPP
