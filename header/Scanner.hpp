#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "typage.hpp"

typedef struct {
	std::fstream * fs;
	std::map <std::string, int> tabSymbole;
} Scanner;

void initScan(Scanner * s, std::string file);

Node * lireMot(Scanner * s);




#endif //SCANNER_HPP
