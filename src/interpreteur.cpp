#include "interpreteur.hpp"

using namespace std;

void interpreter(int code, P_code &pcode, Pilex &pilex, int &co, int &spx) {
	switch(code) {
		case 1: {//lda
			spx = spx + 1;
			pilex[spx] = pcode[co + 1];
			co = co +2;
		}
		break;
		case 2: {//ldv
			spx = spx + 1;
			pilex[spx] = pilex[pcode[co + 1]];
			co = co +2;
		}
		break;
		case 3: {//ldc
			spx = spx + 1;
			pilex[spx] = pcode[co + 1];
			co = co +2;
		}
		break;
		case 4: {//jmp
			co = pcode[co + 1];
		}
		break;
		case 5: {//jif
			 if(pilex[spx] == 0) {
                co = pcode[co + 1];
            } else {
                co = co + 2;
            }
            spx--;

		}
		break;
		case 6: {//jsr

		}
		break;
		case 7: {//rsr

		}
		break;
		case 8: {//sup
			if pilex[spx - 1] > pilex[spx] {
	            pilex[spx - 1] = 1;
	        } else {
	            pilex[spx - 1] = 0;
	        }
			spx--;
	        co++;

		}
		break;
		case 9: {//supe
			if pilex[spx - 1] >= pilex[spx] {
	            pilex[spx - 1] = 1;
	        } else {
	            pilex[spx - 1] = 0;
	        }
			spx--;
	        co++;
		}
		break;
		case 10: {//inf
			if pilex[spx - 1] < pilex[spx] {
	            pilex[spx - 1] = 1;
	        } else {
	            pilex[spx - 1] = 0;
	        }
			spx--;
	        co++;
		}
		break;
		case 11: {//infe
			if pilex[spx - 1] <= pilex[spx] {
	            pilex[spx - 1] = 1;
	        } else {
	            pilex[spx - 1] = 0;
	        }
			spx--;
	        co++;
		}
		break;
		case 12: {//eq
			if pilex[spx - 1] == pilex[spx] {
	            pilex[spx - 1] = 1;
	        } else {
	            pilex[spx - 1] = 0;
	        }
			spx--;
	        co++;
		}
		break;
		case 13: {//diff
			if pilex[spx - 1] != pilex[spx] {
            pilex[spx - 1] = 1;
	        } else {
	            pilex[spx - 1] = 0;
	        }
			spx--;
	        co++;
		}
		break;
		case 14: {//rd
			string input;
            spx++;
            cin >> input;
            pilex[spx] = atoi(input.c_str());
            co++;
		}
		break;
		case 14: {//rdln
			string input;
            spx++;
            cin >> input;
            cout << endl;
            pilex[spx] = atoi(input.c_str());
            co++;
		}
		break;
		case 15: {//wrt
			cout << pilex[spx];
            spx++;
            co++;
		}
		break;
		case 16: {//wrtln
			cout << pilex[spx] << endl;
            spx++;
            co++;
		}
		break;
		case 17: {//add
			pilex[spx - 1] = pilex[spx - 1] + pilex[spx];
            spx--;
            co++;
		}
		break;
		case 18: {//moins
			pilex[spx - 1] = pilex[spx - 1] - pilex[spx];
            spx--;
            co++;
		}
		break;
		case 19: {//mult
			pilex[spx - 1] = pilex[spx - 1] / pilex[spx];
            spx--;
            co++;
		}
		break;
		case 17: {//div
			pilex[spx - 1] = pilex[spx - 1] * pilex[spx];
            spx--;
            co++;
		}
		break;
		case 18: {//neg
			pilex[spx] = 0 - pilex[spx];
            co++;
		}
		break;
		case 19: {//inc
			pilex[spx]++ ;
            co++;
		}
		break;
		case 20: {//dec
			pilex[spx]-- ;
            co++;
		}
		break;
		case 21: {//and
			pilex[spx] = pilex[spx] && pilex[spx -1];
            co++;
		}
		break;
		case 22: {//or
			pilex[spx] = pilex[spx] && pilex[spx -1];
            co++;
		}
		break;
		case 23: {//not
			pilex[spx] = (! pilex[spx]) ;
            co++;
		}
		break;
		case 24: {//aff
			pilex[pilex[spx - 1]] = pilex[spx];
            spx = spx - 2;
            co++;
		}
		break;
		default: {cout << "non implementé" << endl;} break;
			
	}
}

void exec(P_code &pcode, Pilex &pilex, int &co, int &spx) {
	while( pcode[co] != 29 ) {
		interpreter(pcode[co], pilex, co, spx);
	}

}