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
	delete scan;
}


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
    	for(size_t i = 0; i < word.size(); i++) {
    		if(word[i] != '\'') {
    			temp += word[i];
    		}
    	}
    	word = temp;
    	temp = "";
   } else { // c'est un non terminal
    	if ( (numSymb = rechercheSymboleDansG0(word, tabSymb)) != -1 ) { //on l'a pas trouvé dans la table des symboles
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
   		scan->instance->chaine = word.substr(0, word.find("#")) ; //substitu au split
	 		temp = word.substr(word.find("#")+1,temp.size()-1);
	 		//cout << " action detectée pour " << scan->instance->chaine << " , : " << temp << endl;
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

void initScanGPL(Scanner_GPL * scan, string file) {
	scan->fs = new fstream;
	scan->fs->open(file, fstream::in);
	scan->instance = new Instance_GPL();
	scan->listeidents = new vector<string>;
	scan->isident = false;
}

void closeScanGPL(Scanner_GPL * scan) {
	if(scan->fs->is_open()) {
		scan->fs->close();
	}
	delete scan->instance;
	delete scan->fs;
	delete scan->listeidents;
	delete scan;
}

bool itisanumber(std::string word){
	int asciinb = int(word[0]);
	return ((asciinb > 48) && (asciinb < 58));
}

void lireMotGPL(Scanner_GPL * scan, type_tableSymbole & tabSymb) {
	string word = "";
	string temp = "";
	char carac;

	carac = scan->fs->get();

	//capture d'un mot
	while ((!scan->fs->eof()) && (carac != ' ') && (carac != '\n')) {
		word += carac;
		carac = scan->fs->get();
   }

   scan->instance->chaine = word;

   bool alreadyFound = (find(scan->listeidents->begin(), scan->listeidents->end(), word) != scan->listeidents->end());

   if(alreadyFound) { //est deja dans la liste des ident
   		scan->instance->symb = IDENT;
   		scan->instance->code = rechercheSymbole("ident",tabSymb);
   } else if(scan->isident) {// on a vu une decl avant
   		scan->instance->symb = IDENT;
   		scan->instance->code = rechercheSymbole("ident",tabSymb);
   		scan->isident = false;
   		scan->listeidents->push_back(word);
   } else if((word.compare("Program") == 0) || (word.compare("const") == 0) || (word.compare("var") == 0)) { //on va tomber sur une declaration
   		scan->instance->symb = SYMBOLE;
   		scan->instance->code = rechercheSymbole(word,tabSymb);
   		scan->isident = true;
   } else {
   		if(itisanumber(word)) {
   			scan->instance->symb = ENT;
   			scan->instance->code = rechercheSymbole("entier",tabSymb);
   		} else {//c'est un symbole complexe
   			scan->instance->symb = SYMBOLE;
   			scan->instance->code = rechercheSymbole(word,tabSymb);
   		}
   }
   afficheInstance_GPL(scan->instance);
}

void afficheInstance_GPL(Instance_GPL * inst) {
	cout << "Chaine : " << inst->chaine;
	cout << "\t Code : " << inst->code;
	switch(inst->symb) {
		case ENT : cout << "\t AtomType : ENT" << endl;
			break;
		case SYMBOLE : cout << "\t AtomType : SYMBOLE" << endl;
			break;
		case NOTHING : cout << "\t AtomType : NOTHING" << endl;
			break;
		case IDENT : cout << "\t AtomType : IDENT" << endl;
	}
}
