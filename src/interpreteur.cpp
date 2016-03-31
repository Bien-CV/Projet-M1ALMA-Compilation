#include "interpreteur.hpp"

using namespace std;

void interpreter(P_code &pcode, Pilex &pilex, int &co, int &spx) {
	switch(pcode[co]) {
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
			cout << "jsr non implementé" << endl;
		}
		break;
		case 7: {//rsr
			cout << "rsr non implementé" << endl;
		}
		break;
		case 8: {//sup
			if(pilex[spx - 1] > pilex[spx]){
	            pilex[spx - 1] = 1;
	        } else {
	            pilex[spx - 1] = 0;
	        }
			spx--;
	        co++;

		}
		break;
		case 9: {//supe
			if(pilex[spx - 1] >= pilex[spx]){
	            pilex[spx - 1] = 1;
	        } else {
	            pilex[spx - 1] = 0;
	        }
			spx--;
	        co++;
		}
		break;
		case 10: {//inf
			if(pilex[spx - 1] < pilex[spx]){
	            pilex[spx - 1] = 1;
	        } else {
	            pilex[spx - 1] = 0;
	        }
			spx--;
	        co++;
		}
		break;
		case 11: {//infe
			if(pilex[spx - 1] <= pilex[spx]){
	            pilex[spx - 1] = 1;
	        } else {
	            pilex[spx - 1] = 0;
	        }
			spx--;
	        co++;
		}
		break;
		case 12: {//eq
			if(pilex[spx - 1] == pilex[spx]){
	            pilex[spx - 1] = 1;
	        } else {
	            pilex[spx - 1] = 0;
	        }
			spx--;
	        co++;
		}
		break;
		case 13: {//diff
			if(pilex[spx - 1] != pilex[spx]){
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
            cout << pilex[spx];
            pilex[pilex[spx-1]] = atoi(input.c_str());
            co++;
		}
		break;
		case 15: {//rdln
			string input;
            spx++;
            cin >> input;
            cout << endl;
            pilex[pilex[spx-1]] = atoi(input.c_str());
            co++;
		}
		break;
		case 16: {//wrt
			cout << pilex[spx];
            spx++;
            co++;
		}
		break;
		case 17: {//wrtln
			cout << pilex[spx] << endl;
            spx++;
            co++;
		}
		break;
		case 18: {//add
			pilex[spx - 1] = pilex[spx - 1] + pilex[spx];
            spx--;
            co++;
		}
		break;
		case 19: {//moins
			pilex[spx - 1] = pilex[spx - 1] - pilex[spx];
            spx--;
            co++;
		}
		break;
		case 20: {//mult
			pilex[spx - 1] = pilex[spx - 1] * pilex[spx];
            spx--;
            co++;
		}
		break;
		case 21: {//div
			pilex[spx - 1] = pilex[spx - 1] / pilex[spx];
            spx--;
            co++;
		}
		break;
		case 22: {//neg
			pilex[spx] = 0 - pilex[spx];
            co++;
		}
		break;
		case 23: {//inc
			pilex[spx]++ ;
            co++;
		}
		break;
		case 24: {//dec
			pilex[spx]-- ;
            co++;
		}
		break;
		case 25: {//and
			pilex[spx] = pilex[spx] && pilex[spx -1];
            co++;
		}
		break;
		case 26: {//or
			pilex[spx] = pilex[spx] && pilex[spx -1];
            co++;
		}
		break;
		case 27: {//not
			pilex[spx] = (! pilex[spx]) ;
            co++;
		}
		break;
		case 28: {//aff
			pilex[pilex[spx - 1]] = pilex[spx];
            spx = spx - 2;
            co++;
		}
		break;
		default: {cout << "non implementé" << endl;} break;
			
	}
}

void exec(P_code &pcode, int nbvar) {
	int co = 0;
	Pilex pilex(pcode.size(),0);
	int spx = nbvar;
	while( pcode[co] != 29 ) {
		interpreter(pcode, pilex, co, spx);
	}
	cout << "ok" << endl;

}