#ifndef INTERPRETEUR_HPP
#define INTERPRETEUR_HPP

#include <iostream>
#include <vector>

typedef std::vector<int> P_code;
typedef std::vector<int> Pilex;


void interpreter(P_code &pcode, Pilex &pilex, int &co, int &spx);
void exec(P_code &pcode, int nbvar) ;


#endif //INTERPRETEUR_HPP