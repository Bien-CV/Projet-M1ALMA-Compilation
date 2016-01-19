#include <iostream>
#include <string>

#include "generateur.hpp"

using namespace std;

int main() {
	
	Atom* a = GenAtom(0,0, TERMINAL);

	cout << a->code << endl;

	delete(a);
	return 0;
}