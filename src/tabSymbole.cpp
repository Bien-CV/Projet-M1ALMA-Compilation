#include <iostream>

#include "tabSymbole.hpp"

using namespace std;

void initTableSymbole(type_tableSymbole & tabSymb) {
	tabSymb[0] = "S";
	tabSymb[1] = "N";
	tabSymb[2] = "E";
	tabSymb[3] = "T";
	tabSymb[4] = "F";
	tabSymb[5] = "->";
	tabSymb[6] = ".";
	tabSymb[7] = "+";
	tabSymb[8] = "*";
	tabSymb[9] = ";";
	tabSymb[10] = ",";
	tabSymb[11] = "(";
	tabSymb[12] = ")";
	tabSymb[13] = "[";
	tabSymb[14] = "]";
	tabSymb[15] = "(/";
	tabSymb[16] = "/)";
	tabSymb[17] = "ELTER";
	tabSymb[18] = "IDNTER";
}

int rechercheSymboleDansG0(string s, type_tableSymbole & tabSymb) {
	int nb = 0;//pour retenir ou on est dans la tab symb
	for (auto &it : tabSymb) {

		if(nb == 19) {
			return -1;
		}
		nb++;
		if (it.second == s){
			return it.first;
		}

	}
	return -1;
}

int rechercheSymbole(string s, type_tableSymbole & tabSymb) {
	for (auto &it : tabSymb) {
		if (it.second == s){
			return it.first;
		}
	}
	return -1;
}

int recherche_symb_ac_add(string s, type_tableSymbole & tabSymb) {
	//if (tabSymb.find(s) != tabSymb.end()) {
	int id = -1;
	for (auto &it : tabSymb) {
		if (it.second == s){
			return it.first;
		}
	} 
	id = tabSymb.end()->first;//on recupere la valeure de la prochaine case qui serait genere
	tabSymb[id] = s;
	return id;
}