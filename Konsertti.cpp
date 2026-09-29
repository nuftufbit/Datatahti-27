// 14:52
// 15:16 first
// 15:51

#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
	int numTicket, numCust;
	string prc, off;
	cin >> numTicket >> numCust;
	getline(cin, prc);
	getline(cin, prc);
	getline(cin, off);
	stringstream pS(prc), oS(off);

	int price;
	vector<int> priceSet;

	for(int i = 0; i < numTicket; i++){
		pS >> price;
		priceSet.push_back(price);
	}
	sort(priceSet.begin(), priceSet.end());

	int offer;
	for(int i = 0; i < numCust; i++){
		oS >> offer;
		auto close = lower_bound(priceSet.begin(), priceSet.end(), offer);
		if(close == priceSet.end()){close--;}

		while(*close > offer && close > priceSet.begin()){
			close--;
		}
		
		if(close == priceSet.begin()){
			if(*close > offer){
				cout << "QAQ\n";
				continue;
			}
		}
		cout << *close << "\n";
		priceSet.erase(close);
	}
}