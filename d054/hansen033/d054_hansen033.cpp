#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long input, pointer = 3;
	vector<long long> list;
	list.push_back(0);//無用
	list.push_back(1);
	list.push_back(5);
	list.push_back(11);
	cin >> input;
	while(cin >> input){
		if(input <= pointer)
			cout << list[input] << endl;
		else{
			for(long long t = pointer + 1 ; t <= input ; t ++, pointer ++)
				list.push_back(list[t - 1] + 4 * list[t - 2] + 2 * list[t - 3]); //重點 a[c]=a[c-1]+4*a[c-2]+2*a[c-3]
			cout << list[input] << endl;
		}
	}
}