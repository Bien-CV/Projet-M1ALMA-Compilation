#include "interpreteur.hpp"

using namespace std;

void interpreter(int code, P_code &pcode, Pilex &pilex, int &c0, int &spx) {
	switch(code) {
		case 1: {//lda
			spx = spx + 1;
			pilex[spx] = pcode[c0 + 1];
			c0 = c0 +2;
		}
		break;
		case 2: {//ldv
			spx = spx + 1;
			pilex[spx] = pilex[pcode[c0 + 1]];
			c0 = c0 +2;
		}
		break;
		case 3: {//ldc
			spx = spx + 1;
			pilex[spx] = pcode[c0 + 1];
			c0 = c0 +2;
		}
		break;
		case 4: {//jmp

		}
		break;
		case 5: {//jif

		}
		break;
		case 6: {//jsr

		}
		break;
		case 7: {//rsr

		}
		break;
		case 8: {//sup

		}
		break;
		case 9: {//supe

		}
		break;
		case 10: {//inf

		}
		break;
		case 11: {//infe

		}
		break;
		case 12: {//eq

		}
		break;
		case 13: {//diff

		}
		break;
		case 14: {//rd

		}
		break;
		case 14: {//rdel

		}
		break;
		
			
	}
}

void exec(P_code &pcode, Pilex &pilex, int &c0, int &spx) {
	while( pcode[c0] != 29 ) {
		interpreter(pcode[c0], pcode, pilex, c0, spx);
	}

}