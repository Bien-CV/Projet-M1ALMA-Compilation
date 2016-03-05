#include <iostream>
#include <string>

#include "generateur.hpp"
#include "scanner.hpp"
#include "analyseur.hpp"
#include "tabSymbole.hpp"

using namespace std;

// string scan(int nb) {

// 	ifstream file;
//     file.open ("src/gpl.txt");
//     string word = "";
//     char x ;
//     word.clear();

//     while ((!file.eof()) && (nb > 0)) {
//         x = file.get();
//         while ( x != ' ' ) {
//             word = word + x;
//             x = file.get();
//         }
//         nb--;
//         word.clear();
//     }
//     if(!file.eof()) {

//     	x = file.get();
//     	while ( x != ' ' ) {
//             word = word + x;
//             x = file.get();
//             cout << x;
//         }
//     }
//     return word;
// }

int main() {
	
	//initialisation de la table des symboles
	type_tableSymbole symboles;
	initTableSymbole(symboles);
	cout << "*** Initialisation de la table des symboles ***" << endl;
	
	// création de la grammaire mere
	Node** node;
	node = GenForet();

	//affichage de la création des arbres
	cout << "*** Affichage des arbres de la grammaire mère ***" << endl;
	for(int i = 0; i < 5; ++i) {
		ImprimeArbre(node[i], 0);
		cout << "\n";
	}

	// Initialisation du scanner
   Scanner * scan = new Scanner;
   initScan(scan,"src/gpl.txt");

   // Lecture de la grammaire
   cout << "*** Scanner de la GPL ***" << endl;
   while (!scan->fs->eof()) {
   lireMot(scan, symboles);
	}

	//libération de la mémoire allouer
   closeScan(scan);
   delete scan;
   delete node;

	return 0;
}
