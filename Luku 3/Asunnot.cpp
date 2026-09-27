// 14:56


#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


int main(){
	typedef long long ll;
	ll apl, hs, diff;
	ll get = 0;
	string allWish;
	string allSize;
	cin >> apl >> hs >> diff;
	getline(cin, allWish);
	getline(cin, allWish);
	stringstream wS(allWish);
	getline(cin, allSize);
	stringstream sS(allSize);


	vector<ll> sizes(hs);
	vector<ll> wishes(apl);
	ll s;
	ll w;
	for(int i = 0; i < apl; i++){
		wS >> w;
		wishes[i] = w;
	}
	for(int i = 0; i < hs; i++){
		sS >> s;
		sizes[i] = s;
	}
	sort(wishes.begin(), wishes.end());
	sort(sizes.begin(), sizes.end());

	for(int wish = 0, size = 0; wish < apl && size < hs;){
		if(abs(wishes[wish] - sizes[size]) <= diff){
			get++;
			wish++;
			size++;
		}
		else if(sizes[size] < wishes[wish]){
			size++;
		}
		else{wish++;}
	}

	cout << get;
}