#include "scanner.hpp"

using namespace std;

void initScan(Scanner * scan, string file) {
	scan->fs = new fstream;
	scan->fs->open(file, fstream::in);
	scan->instance = new Instance();
}

void closeScan(Scanner * scan) {
	if(scan->fs->is_open()) {
		scan->fs->close();
	}
	delete scan->instance;
	delete scan->fs;
}

// int recherche(string s) {
// 	if (s->tabSymbole.find(s) != s->tabSymbole.end()) {
// 		return s->tabSymbole.find(s)->second;
// 	} else {
// 		return -1;
// 	}
// }

// int rechercheEtAjout(String s) {
// 	if (s->tabSymbole.find(s) != s->tabSymbole.end()) {
// 		return s->tabSymbole.find(s)->second;
// 	} else {
// 		s->tabSymbole.insert()//?
// 		return -1;
// 	}
// }

void lireMot(Scanner * scan, type_tableSymbole & tabSymb) {
	string word = "";
	string temp = "";
	char carac;
	int numSymb;

	carac = scan->fs->get();

	//capture d'un mot
	while ((!scan->fs->eof()) && (carac != ' ') && (carac != '\n')) {
		word += carac;
		carac = scan->fs->get();
   }

   if(word[0] == '\''){ // c'est un terminal
    	scan->instance->code = 17;
    	scan->instance->type = TERMINAL;
   } else { // c'est un non terminal
    	if ( (numSymb = rechercheSymbole(word, tabSymb)) != -1 ) { //on l'a trouvé dans la table des symboles
    		scan->instance->code = numSymb;
    		//scan->instance->action = 0;
    		scan->instance->type = NONTERMINAL;
    		//scan->instance->chaine = word;
    	} else {
    		scan->instance->code = 18;
    		//scan->instance->action = 0;
    		scan->instance->type = NONTERMINAL;
    		//scan->instance->chaine = word;
    	}
   }
   //déterminer si symbole a une action
   if (word.find("#") != std::string::npos) {
   	if(scan->instance->type == TERMINAL) {
   		scan->instance->chaine = word.substr(0, word.find("#")) + "'"; //substitu au split
	 		temp = word.substr(word.find("#")+1,temp.size()-1);
	 		scan->instance->action = atoi(temp.c_str());
   	} else {
   		scan->instance->chaine = word.substr(0, word.find("#"));
	 		temp = word.substr(word.find("#")+1,temp.size()-1);
	 		scan->instance->action = atoi(temp.c_str());
   	}
	} else {
		scan->instance->chaine = word;
		scan->instance->action = 0;
	}
	afficheInstance(scan->instance);
}
// void lireBlanc(Scanner * s) {

// }

void afficheInstance(Instance * inst) {
	cout << "Chaine : " << inst->chaine;
	cout << "\t Code : " << inst->code;
	cout << "\t Action : " << inst->action;
	switch(inst->type) {
		case TERMINAL : cout << "\t AtomType : TERMINAL" << endl;
			break;
		case NONTERMINAL : cout << "\t AtomType : NONTERMINAL" << endl;
	}
}
