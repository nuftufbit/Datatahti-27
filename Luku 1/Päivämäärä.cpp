#include <iostream>
#include <string>
using namespace std;

int main(){
	string pvm;
	cin >> pvm;
	int pv, kk, vs;
	int kulunut = 0;
	pv = pvm.find(".") > 1 ? stoi(pvm.substr(0, pvm.find("."))) : pvm[0] - '0';
	kk = pvm.find_last_of(".") - pvm.find(".") == 3 ? 
	stoi(pvm.substr(pvm.find(".")+1, pvm.find_last_of(".") - pvm.find(".")-1)) : (int)pvm[pvm.find(".")+1] - '0';
	vs = stoi(pvm.substr(pvm.find_last_of(".")+1, 4));

	kulunut = (vs - 1800) * 365 + (vs - 1800) / 4 - (vs > 2100 ? 2 : vs > 1900 ? 1 : 0) 
				- ((vs % 4 == 0 && vs % 100 != 0) || vs % 400 == 0 ? 1 : 0);

	kulunut = kulunut + ((kk-1)/2) * 61 + (kk > 8 ? 1 : 0) + (kk % 2 == 1 ? 0 : kk > 9 ? 30 : 31);

	// Helmikuu
	kulunut = kk < 3 ? kulunut : (vs % 4 == 0 && vs % 100 != 0) || vs % 400 == 0 ? kulunut - 1 : kulunut - 2;

	kulunut = kulunut + pv;

	switch (kulunut % 7){
	case 6:
		cout << "maanantai";
		break;
	case 0:
		cout << "tiistai";
		break;
	case 1:
		cout << "keskiviikko";
		break;
	case 2:
		cout << "torstai";
		break;
	case 3:
		cout << "perjantai";
		break;
	case 4:
		cout << "lauantai";
		break;
	case 5:
		cout << "sunnuntai";
		break;
	}
}