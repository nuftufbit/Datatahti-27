// 14:56


#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int srch(int target, int curPlace, int curSize, vector<int> vec){
	if(vec[curPlace] == target){return curPlace;}
	if(curSize == 0){
		return curPlace;
	}
	curPlace += vec[curPlace] < target ? curSize / 2 : -curSize/2;
	//cout << "\n" << curPlace;
	curPlace = clamp((unsigned long long)curPlace, (unsigned long long)0, (unsigned long long)vec.size() - 1);
	curSize /= 2;
	//cout << "\n" << vec[curPlace] << " v - t " << target;
	//cout << "\n" << curPlace << " - p - s - " << curSize;
	return srch(target, curPlace, curSize, vec);
}

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
	vector<bool> used(apl);
	int size;
	int wish;
	int minWish;
	int maxWish;
	for(int i = 0; i < apl; i++){
		wS >> wish;
		wishes[i] = wish;
	}
	for(int i = 0; i < hs; i++){
		sS >> size;
		sizes[i] = size;
	}
	sort(wishes.begin(), wishes.end());
	sort(sizes.begin(), sizes.end());
	for(int i = 0; i < wishes.size(); i++){
		//cout << wishes[i] << " ";
		}
	//cout << "\n";
	
	for(int i = 0; i < sizes.size(); i++){
		size = sizes[i];
		//cout << size << " new\n";
		minWish = fmax(1, size - diff);
		maxWish = size + diff;

		if(wishes[0] > maxWish || wishes[wishes.size() - 1] < minWish){continue;}

		int minPlace = srch(minWish, wishes.size() / 2, wishes.size(), wishes);
		int maxPlace = srch(maxWish, wishes.size() / 2, wishes.size(), wishes);
		
		//cout << " min " << minPlace << " max " << maxPlace;

		if(minPlace == maxPlace){
			if(used[minPlace]){continue;}
			used[minPlace] = true;
			get += 1;
			continue;
		}//|| (wishes[minPlace] < minWish || wishes[minPlace] > maxWish)

		for(int j = minPlace; j < maxPlace; j++){
			if(used[j]){continue;}
			used[j] = true;
			get += 1;
		}
		
	}
	
	//cout << "\nout\n";
	cout << get;
}