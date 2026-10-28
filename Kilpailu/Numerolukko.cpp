#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
// 16:35 start
// 18:39 100
using namespace std;

int countTotal(string curr, vector<int> targetV, int offset, int n){
	int curVal = 0;
	for(int i = 0; i < n; i++){
			int c = ((curr[i] - '0') + offset) % 10;
			//int modDiff = targetV[i] - c - 10;
			int modDiff = targetV[i] > c ? c - (targetV[i] - 10) : targetV[i] - (c-10);
			curVal += abs((abs(modDiff) > abs(targetV[i] - c) ? targetV[i] - c : modDiff));
	}
	return curVal;
}

int main(){
	int n;
	string target, curr;
	cin >> n >> target >> curr;
	vector<int> targetV(n);
	int total = 0;
	int minFull = 0;
	int minFullVal = 1000000;

	for(int i = 0; i < n; i++){
		targetV[i] = target[i] - '0';
	}

	for(int j = 0; j < 10; j++){
		int curVal = 0;
		int jMod = (j > 5 ? 10-j : j);
		curVal = countTotal(curr, targetV, j, n);
		if(curVal + jMod < minFullVal){
			minFull = j;
			minFullVal = curVal + jMod;
		}
	}
	minFull = minFull > 5 ? minFull - 10 : minFull;
	/*
	for(int i = 0; i < n; i++){
		int temp = total;

		int c = ((curr[i] - '0') + minFull) % 10;
		int modDiff = targetV[i] > c ? c - (targetV[i] - 10) : targetV[i] - (c-10);
		total += abs((abs(modDiff) > abs(targetV[i] - c) ? targetV[i] - c : modDiff));

		cout << "\n" << modDiff << " " << targetV[i] - c << " " << c;
		cout << " - " << total - temp;
	}
	*/
	//cout << "\n" << total << " " << minFull << "\n";
	cout << abs(minFull) + countTotal(curr, targetV, minFull, n);
}