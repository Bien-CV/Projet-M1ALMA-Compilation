
#include "/comptes/E10A324K/M1info/S2/compil/Projet-M1ALMA-Compilation/header/Scanner.hpp"

using namespace std;

void initScan(Scanner * s, string file) {
	fstream * f = new fstream;
	f->open(file, fstream::in);
	s->fs = f;
}

string lireMot(Scanner *s) {
	string word = "";
	char x ;
	x = s->fs->get();
	while ((!s->fs->eof()) && (x != ' ') && (x != '\n')) {
		word += x;
		x = s->fs->get();
    }
    cout << word << endl;
    return word;
}

