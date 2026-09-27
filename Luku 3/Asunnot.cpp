// 14:56


#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main(){
	int apl, hs, diff;
	string allWish;
	string allSize;
	cin >> apl >> hs >> diff;
	getline(cin, allWish);
	getline(cin, allWish);
	stringstream wS(allWish);
	getline(cin, allSize);
	stringstream sS(allSize);
	int get = 0;


	vector<int> sizes(hs);
	vector<int> wishes(apl);
	int size;
	int wish;
	for(int i = 0; i < apl; i++){
		wS >> wish;
		wishes[i] = wish;
	}
	for(int i = 0; i < hs; i++){
		sS >> size;
		sizes[i] = size;
	}


	int minWish;
	int maxWish;
	bool getPlus = false;
	for(int i = 0; i < hs; i++){
		vector<int> aplNum;
		vector<int> diffNum;
		minWish = fmax(0, sizes[i] - diff);
		maxWish = sizes[i] + diff;
		for(int j = 0; j < apl; j++){ // give to smallest possible wish
			//cout << "\n" << wishes[j] << " - - " << sizes[i];
			if(minWish > wishes[j] || maxWish < wishes[j]){
				//cout << "\nrange - ";
				continue;
			}
			if(minWish == wishes[j]){
				get += 1;
				getPlus = true;
				wishes[j] = -1;
				break;
			}
			aplNum.push_back(j);
			diffNum.push_back(sizes[i] - wishes[j]);
			//cout << "\n" << wishes[j] << " - " << sizes[i];
		}
		if(getPlus || aplNum.empty()){
			continue;
		}

		int minApp = maxWish +1;
		int appNum = 0;
		for(int i = 0; i < aplNum.size(); i++){
			if(wishes[aplNum[i]] < minApp){
				minApp = wishes[aplNum[i]];
				appNum = aplNum[i];
			}
		}
		wishes[appNum] = -1;
		get += 1;
	}
	//cout << "\n";
	cout << get;
}