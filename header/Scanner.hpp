#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <iostream>
#include <fstream>
#include <string>

typedef struct {
	std::fstream * fs;
} Scanner;

void initScan(Scanner * s, std::string file);

std::string lireMot(Scanner * s);




#endif //SCANNER_HPP
