// 12:55
// 13:08 first
// 13:21

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(){
	string jono;
	set<string> perms;
	cin >> jono;
	sort(jono.begin(), jono.end());

	do{
		perms.insert(jono);
	} while(next_permutation(jono.begin(), jono.end()));

	cout << perms.size() << "\n";
	for(string s : perms){
		cout << s << "\n";
	}
}