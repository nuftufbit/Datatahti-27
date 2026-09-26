//#include <string>
#include <iostream>
using namespace std;

int main() {
	string n;
	cin >> n;
	int length = 1;
	int max = 0;
	char last = 'p';
	for(int i = 0; i < n.length(); i++){
		if(n[i] == last){
			length += 1;
			continue;
		}
		last = n[i];
		max = length > max ? length : max;
		length = 1;
	}
	max = length > max ? length : max;
	cout << max;
}