#include <iostream>
#include <string>

#include <vector>

#include "generateur.hpp"
#include "scanner.hpp"
#include "analyseur.hpp"
#include "tabSymbole.hpp"
#include "action.hpp"
#include "interpreteur.hpp"

using namespace std;

int main() {
	
	//initialisation de la table des symboles
	type_tableSymbole symboles;
	initTableSymbole(symboles);
	cout << "*** Initialisation de la table des symboles ***" << endl;
	
	type_pile pile;

	// création de la grammaire mere
	std::map<int, Node*> node = GenForet();

	//affichage de la création des arbres
	cout << "*** Affichage des arbres de la grammaire mère ***" << endl;
	for(int i = 0; i < 5; ++i) {
		ImprimeArbre(node[i], 0);
		cout << "\n";
	}

	// Initialisation du scanner
   Scanner * scan = new Scanner;
   initScan(scan,"src/gplfinal.txt");

   // Lecture de la gpl
   cout << "*** Scan de la GPL ***" << endl;

	lireMot(scan, symboles);
	// Analyse de la gpl
	cout << "*** Analyse de la GPL***" << endl;
	if(analyse(scan, node, node[0], symboles, pile)) {
		cout << "OK" << endl;
	} else {
		cout << "Pas OK" << endl;
	}
	
	cout << "*** Affichage des arbres ***" << endl;


	for(auto &iterator : node) {
		cout << "***** arbre a la case " << iterator.first << "***** " << endl;
		ImprimeArbre(iterator.second, 0);
		cout << "\n";
	}

	cout << "*** Affichage de la pile de symboles ***" << endl;
	affTableSymbole(symboles);

	// Initialisation du scanner gpl
	Scanner_GPL * scangpl = new Scanner_GPL;
	initScanGPL(scangpl,"src/programme.txt");

	// Lecture de la gpl
	cout << "*** Scan du prog ***" << endl;
	
	lireMotGPL(scangpl,symboles);
   	
	// Analyse de la gpl
	cout << "*** Analyse du prog***" << endl;
	stack<int> pileOP;
	map<std::string, int> IATAB;
	vector<int> p_code;

	if(analyse_GPL(scangpl, node, node[19], symboles, pileOP, IATAB, p_code)) {
		cout << "OK" << endl;
	} else {
		cout << "Pas OK" << endl;
	}

	cout << "*** Affichage du Pcode***" << endl;
	for(size_t i = 0; i < p_code.size(); i++) {
		cout << p_code[i] << endl;
	}

	cout << "*** Execution du Pcode" << endl;
	exec(p_code, IATAB.size());

	//libération de la mémoire allouée
   	closeScan(scan);
   	closeScanGPL(scangpl);

   	// doIt();

	return 0;
}
