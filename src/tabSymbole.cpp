#include <iostream>

#include "tabSymbole.hpp"

using namespace std;

void initTableSymbole(type_tableSymbole & tabSymb) {
	tabSymb["S"] = 0;
	tabSymb["N"] = 1;
	tabSymb["E"] = 2;
	tabSymb["T"] = 3;
	tabSymb["F"] = 4;
	tabSymb["->"] = 5;
	tabSymb["."] = 6;
	tabSymb["+"] = 7;
	tabSymb["*"] = 8;
	tabSymb[";"] = 9;
	tabSymb[","] = 10;
	tabSymb["("] = 11;
	tabSymb[")"] = 12;
	tabSymb["["] = 13;
	tabSymb["]"] = 14;
	tabSymb["(/"] = 15;
	tabSymb["/)"] = 16;
	tabSymb["ELTER"] = 17;
	tabSymb["IDNTER"] = 18;
}

int rechercheSymbole(string s, type_tableSymbole & tabSymb) {
	if (tabSymb.find(s) != tabSymb.end()) {
		return tabSymb.find(s)->second;
	} else {
		return -1;
	}
}