
#include "/comptes/E10A324K/M1info/S2/compil/Projet-M1ALMA-Compilation/header/Scanner.hpp"

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

Node * lireMot(Scanner *s) {
	string word = "";
	char x ;
	x = s->fs->get();
	while ((!s->fs->eof()) && (x != ' ') && (x != '\n')) {
		word += x;
		x = s->fs->get();
    }
    if(word[1] == '\''){
    	//créer terminal
    }
    Node *m 
    int type = s->tabSymbole.find(word)
    switch() {
    	//tester si non terminal deja present. si oui trouver bon type de node, sinon ???

    }
    //cout << word << endl;
    // return word;
}

