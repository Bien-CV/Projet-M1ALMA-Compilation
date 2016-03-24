#ifndef INTERPRETEUR_HPP
#define INTERPRETEUR_HPP

#include <iostream>
#include <vector>

typedef std::vector<int> P_code;
typedef std::vector<int> Pilex;


void interpreter(int code, P_code &pcode, Pilex &pilex);
void exec(P_code pcode, Pilex pilex);


#endif //INTERPRETEUR_HPP