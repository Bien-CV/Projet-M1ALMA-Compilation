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

		}
		break;
		case 7: {//rsr

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
            pilex[spx] = atoi(input.c_str());
            co++;
		}
		break;
		case 15: {//rdln
			string input;
            spx++;
            cin >> input;
            cout << endl;
            pilex[spx] = atoi(input.c_str());
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
			pilex[spx - 1] = pilex[spx - 1] / pilex[spx];
            spx--;
            co++;
		}
		break;
		case 21: {//div
			pilex[spx - 1] = pilex[spx - 1] * pilex[spx];
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
	//cout << pilex[0] << " , " << pilex[1] << " , " << pilex[2] << " et spx,co: " << spx << "," << co << endl;
}

void exec(P_code &pcode, Pilex &pilex) {
	int co = 0;
	int spx = 3;
	while( pcode[co] != 29 ) {
		// cout << pcode[co] << endl;
		interpreter(pcode, pilex, co, spx);
	}
	cout << "ok" << endl;

}

void doIt() {
	P_code pcodetest;
	Pilex pilextest(7,0);//wut, 3 pas assez, il faut + pour prevoir les sauv de val
	// pilextest.push_back(0);
	// pilextest.push_back(0);
	// pilextest.push_back(0);

	pcodetest.push_back(1);
	pcodetest.push_back(0);
	pcodetest.push_back(3);
	pcodetest.push_back(4);
	pcodetest.push_back(28);
	pcodetest.push_back(1);
	pcodetest.push_back(1);
	pcodetest.push_back(3);
	pcodetest.push_back(1);
	pcodetest.push_back(28);
	pcodetest.push_back(1);
	pcodetest.push_back(2);
	pcodetest.push_back(2);
	pcodetest.push_back(0);
	pcodetest.push_back(2);
	pcodetest.push_back(1);
	pcodetest.push_back(18);
	pcodetest.push_back(28);
	pcodetest.push_back(2);
	pcodetest.push_back(2);
	pcodetest.push_back(17);
	pcodetest.push_back(29);
  
	cout << "debut de l'execution" << endl;
	exec(pcodetest,pilextest);
	cout << "fin de l'execution" << endl; 
}