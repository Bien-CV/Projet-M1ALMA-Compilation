#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include "typage.hpp"
#include "tabSymbole.hpp"

typedef struct {
	int code;
	int action;
	AtomType type;
	std::string chaine;
} Instance;

typedef struct {
	std::fstream * fs;
	Instance * instance;
} Scanner;

///////////////////////////////////////////////////
enum Symbole_GPL {ENT, IDENT, SYMBOLE, NOTHING};

typedef struct {
	int code;
	Symbole_GPL symb;
	std::string chaine;
} Instance_GPL;//?????

typedef struct {
	std::fstream * fs;
	Instance_GPL * instance;
	std::vector<std::string> *listeidents;
	bool isident;
} Scanner_GPL;
///////////////////////////////////////////////////

//scan permet d'avancer dans phrase (S -> 'a' + 'b') et avec analyse
// -> a chaque fin d'analyse (ATOM) on check si se qu'on a trouve == 
//ce sur quoi le scan est. si ok on avance scan et on continue 
// ex ici conc -> star -> conc -> conc -> N ->idnter : scan = S donc ok, on continue;
// conc droit = ->, scan est sur fleche: ok...

void initScan(Scanner * s, std::string file);
void closeScan(Scanner * s);
//int recherche(string s);
void lireMot(Scanner * s, type_tableSymbole & tabSymb);
// void lireBlanc(Scanner * s);
void afficheInstance(Instance * inst);

void initScanGPL(Scanner_GPL * scan, std::string file);
void closeScanGPL(Scanner_GPL * scan);
bool itisanumber(std::string word);
void lireMotGPL(Scanner_GPL * s, type_tableSymbole & tabSymb);
void afficheInstance_GPL(Instance_GPL * inst);

#endif //SCANNER_HPP