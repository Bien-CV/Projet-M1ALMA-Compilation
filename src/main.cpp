#include <iostream>
#include <string>

#include "generateur.hpp"
#include "scanner.hpp"
#include "analyseur.hpp"
#include "tabSymbole.hpp"
#include "action.hpp"

using namespace std;

int main() {
	
	//initialisation de la table des symboles
	type_tableSymbole symboles;
	initTableSymbole(symboles);
	cout << "*** Initialisation de la table des symboles ***" << endl;
	
	type_pile pile;

	// création de la grammaire mere
/////////////////////////////////////////////////////
	std::map<int, Node*> node = GenForet();
	//Node** node;//HASHMAP!!!!!
/////////////////////////////////////////////////////

	// node = GenForet();

	//affichage de la création des arbres
	cout << "*** Affichage des arbres de la grammaire mère ***" << endl;
	for(int i = 0; i < 5; ++i) {
		ImprimeArbre(node[i], 0);
		cout << "\n";
	}

	// Initialisation du scanner
   Scanner * scan = new Scanner;
   initScan(scan,"src/gpl.txt");

   // Lecture de la gpl
   cout << "*** Scanner de la GPL ***" << endl;
 //   while (!scan->fs->eof()) {
 //   	lireMot(scan, symboles);
	// }

	// Analyse de la gpl
	cout << "*** Analyse de la GPL***" << endl;
	lireMot(scan, symboles);
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



	// for( unsigned int a = 0; a < sizeof(node)/sizeof(node[0]); a = a + 1 ) {
	// 	if(node[a] != NULL) {
	// 		ImprimeArbre(node[a], 0);
	// 		cout << "\n";
	// 	}
	// }
	// for(int i = 0; i < 5; ++i) {
	// 	ImprimeArbre(node[i], 0);
	// 	cout << "\n";
	// }


	//libération de la mémoire allouer
   closeScan(scan);
   //delete scan;
   //desallouer chaque node proprement et ensuite l'arbre
   //delete node;

	return 0;
}
