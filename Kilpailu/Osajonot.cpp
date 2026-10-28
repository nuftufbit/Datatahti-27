#include <iostream>
#include <string>
#include <set>
// around 19:00 start?
// 19:53 10, time limit
using namespace std;

int main(){
	string full;
	cin >> full;
	int size = full.size();
	int jonoTot = 0;
	set<string> jonot;

	for(int i = 1; i <= size / 2; i++){
		string jono = "";
		//cout << "\n" << i << " ";
		for(int j = 0; j <= size - i; j++){
			//cout << j;
			jono = full.substr(j, i);
			//if(jonot.count(jono) == 0){cout << jono << "\n";}
			jonot.insert(jono);
		}
	}
	for(string s : jonot){
			string jono = s + s;
			int jonoSize = jono.size();
			for(int j = 0; j < size - (jono.size() - 1); j++){
				if(full.substr(j, jonoSize) == jono && jono != ""){
					//cout << jono << "\n";
					jonoTot += 1;
				}
			}
		}
	//cout << "\n";
	cout << jonoTot;
}