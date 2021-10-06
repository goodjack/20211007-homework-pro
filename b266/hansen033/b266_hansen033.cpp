#include <iostream>
using namespace std;

void output(int, int, int, int, int, int[10][10]);

int main(){
	int a, b, c;
	while(cin >> a >> b >> c){
		int array[10][10] = {-1}, instruction[c];
		for(int t = 0 ; t < a ; t ++)
			for(int t2 = 0 ; t2 < b ; t2 ++) cin >> array[t][t2];
		for(int t = 0 ; t < c ; t ++)
			cin >> instruction[t];

		int /*i*/statementA = 0, /*j*/statementB = 0, /*way*/statementC = 0, statementD = 0;
		for(int t = c - 1 ; t >= 0 ; t --){
			if(instruction[t] == 1){
				if(statementC == 0)
					statementA = statementA == 0 ? 1 : 0, statementD = statementD == 0 ? 1 : 0;
				else
					statementB = statementB == 0 ? 1 : 0, statementD = statementD == 0 ? 1 : 0;
			}
			else if(instruction[t] == 0){
				statementC = statementC == 0 ? 1 : 0;
				if(statementA == 1 && statementB == 0 && statementC == 1)
					statementB = 1;
				else if(statementA == 0 && statementB == 0 && statementD == 1)
					statementA = 1;
				else if(statementA == 0 && statementB == 1 && statementD == 1)
					statementB = 0;
				else if(statementA == 1 && statementB == 1 && statementD == 1)
					statementA = 0;
				else if(statementA == 1 && statementB == 0)
					statementA = 0;
				else if(statementA == 0 && statementB == 0)
					statementB = 1;
				else if(statementA == 0 && statementB == 1)
					statementA = 1;
				else if(statementA == 1 && statementB == 1)
					statementB = 0;
			}
			else
				cout << "instruction ERR" << endl;
		}

		if(statementC == 0)
			cout << a << " " << b << endl;
		else
			cout << b << " " << a << endl;
		
		output(statementA, statementB, statementC, a, b, array);
	}
}

void output(int statementA, int statementB, int statementC, int a, int b, int array[10][10]){
	int tstart, t2start, tlim, t2lim, tplus, t2plus;
	if(statementA == 0)
		tstart = 0, tlim = a, tplus = 1;
	else
		tstart = a - 1, tlim = -1, tplus = -1;
	if(statementB == 0)
		t2start = 0, t2lim = b, t2plus = 1;
	else
		t2start = b - 1, t2lim = -1, t2plus = -1;
	if(statementC == 1){
		int tempstart = tstart, templim = tlim, tempplus = tplus;
		tstart = t2start, tlim = t2lim, tplus = t2plus;
		t2start = tempstart, t2lim = templim, t2plus = tempplus;
	}
	switch(statementC){
		case 0:
			for(int t = tstart ; t != tlim ; t += tplus){
				for(int t2 = t2start ; t2 != t2lim ; t2 += t2plus){
					if(t2 != t2start)
						cout << " ";
					cout << array[t][t2];
				}
				cout << endl;
				}
			break;
		case 1:
			for(int t = tstart ; t != tlim ; t += tplus){
				for(int t2 = t2start ; t2 != t2lim ; t2 += t2plus){
					if(t2 != t2start)
						cout << " ";
					cout << array[t2][t];
				}
				cout << endl;
			}
			break;
		default:
			cout << "output ERR" << endl;
	}
}