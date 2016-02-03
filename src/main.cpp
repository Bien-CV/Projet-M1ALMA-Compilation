#include <iostream>
#include <string>

#include "generateur.hpp"

using namespace std;

int main() {
	
	Node** node;
	node = GenForet();

	for(int i = 0; i < 5; ++i) {
		ImprimeArbre(node[i], 0);
		cout << "\n";
	}
	
	return 0;
}
