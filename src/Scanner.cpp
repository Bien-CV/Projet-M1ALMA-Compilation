
#include "header/Scanner.hpp"

using namespace std;

void initScan(Scanner * s, string file) {
	fstream * f = new fstream;
	f->open(file, fstream::in);
	s->fs = f;
	/**************/

	s->tabSymbole["S"] = 1;
	s->tabSymbole["N"] = 2;
	s->tabSymbole["E"] = 3;
	s->tabSymbole["T"] = 4;
	s->tabSymbole["F"] = 5;
	s->tabSymbole["->"] = 6;
	s->tabSymbole["."] = 7;
	s->tabSymbole["+"] = 8;
	s->tabSymbole["*"] = 9;
	s->tabSymbole[";"] = 10;
	s->tabSymbole[","] = 11;
	s->tabSymbole["("] = 12;
	s->tabSymbole[")"] = 13;
	s->tabSymbole["["] = 14;
	s->tabSymbole["]"] = 15;
	s->tabSymbole["(/"] = 16;
	s->tabSymbole["/)"] = 17;
	s->tabSymbole["ELTER"] = 18;
	s->tabSymbole["IDNTER"] = 19;
}

int recherche(string s) {
	if (s->tabSymbole.find(s) != s->tabSymbole.end()) {
		return s->tabSymbole.find(s)->second;
	} else {
		return -1;
	}
}

// int rechercheEtAjout(String s) {
// 	if (s->tabSymbole.find(s) != s->tabSymbole.end()) {
// 		return s->tabSymbole.find(s)->second;
// 	} else {
// 		s->tabSymbole.insert()//?
// 		return -1;
// 	}
// }

Node lireMot(Scanner *s) {
	string word = "";
	string temp;
	int type;
	char x ;
	Instance ins;
	x = s->fs->get();
	while ((!s->fs->eof()) && (x != ' ') && (x != '\n')) {
		word += x;
		x = s->fs->get();
    }
    if(word[0] == '\''){
    	ins.code = 18;
    	ins.type = TERMINAL;
    	if (word.find("#") != std::string::npos) {
    		ins.chaine = word.split("#")[0] + "'";
    		temp =word.split("#")[1];
    		ins.action = temp.substr(0,temp.size() -1);
		} else {
			ins.chaine = word;
			ins.action = -1; 
		}



    } else { // c'est un non terminal
    	if ( (type = recherche(word)) != -1 ) { //on l'a trouvé dans la table des symboles
    		ins.code = type;
    		ins.action = -1;
    		ins.type = NONTERMINAL;
    		ins.chaine = word;
    	} else {
    		ins.code = 19;
    		ins.action = -1;
    		ins.type = NONTERMINAL;
    		ins.chaine = word;
    	}
    }
    return ins;
}
