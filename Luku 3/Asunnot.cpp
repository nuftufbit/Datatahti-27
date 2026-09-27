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
	ll size;
	ll wish;
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
	//cout << "\n\n";


	ll minWish;
	ll maxWish;
	ll offset = 0;
	for(int i = 0; i < sizes.size(); i++){
		size = sizes[i];
		minWish = fmax(1, size - diff);
		maxWish = size + diff;


		if(wishes[0] > maxWish || wishes[wishes.size() - 1] < minWish){continue;}
		//cout << "\n" << offset << "\n";
		if(wishes[offset] == minWish){
			get += 1; 
			offset += 1; 
			//cout << offset; 
			continue;
		}

		//cout << "\n  new i " << i << " num " << wishes[offset] << " size " << size;
		ll moveMult = 1;
		ll moveOff = 0;
		bool att = false;
		
		//cout << "\noff " << offset << " move " << moveOff << "\n" << wishes[offset + moveOff] << " min " << minWish << "\nnext " << wishes[offset + moveOff + 1];
		//cout << "\nmin " << minWish << " ";
		while(moveMult > 1 || !att){
			att = true;
			//cout << "num " << wishes[offset + moveOff];
			//cout << "\nmult " << moveMult << " off " << moveOff;
			
			if(wishes[offset + moveOff] == minWish){break;}
			
			if(wishes[offset + moveOff] > minWish){
				//cout << "\ndown ";
				if(moveOff == 0){
					//cout << " broke ";
					break;}
				moveMult /= 2;
				moveOff -= moveMult;
			}
			else if(wishes[offset + moveOff] < minWish){
				//cout << "\nup ";
				if(offset + moveOff == wishes.size() - 1){break;}
				moveMult *= 2;
				moveOff += moveMult;
			}

			if(offset + moveOff > wishes.size() - 1){
				moveOff = wishes.size() - offset - 1;
				//cout << "\nmax ";
				moveMult = 1;
				att = false;
			}
		}
		
		ll curPos = wishes[offset + moveOff];
		//cout << " final " << minWish << " " << curPos << " " << maxWish << "\n";
		if(minWish == curPos){
			get += 1;
			offset += moveOff + 1;
		}
		if(minWish > curPos){
			if(offset + moveOff == wishes.size() - 1){break;}
			if(wishes[offset + moveOff + 1] >= minWish && wishes[offset + moveOff + 1] <= maxWish){
				get += 1;
				//cout << "small big - moveOff " << moveOff << " new off ";
				offset += moveOff + 1;
				//cout << offset << "\n\n";
			}
			else{offset += moveOff;}
		}
		if(minWish < curPos){
			if(maxWish >= curPos){
				//cout << "big small - moveOff " << moveOff << " new off ";
				get += 1;
				offset += moveOff + 1;
				//cout << offset << "\n\n";
			}
		}
		if(offset >= wishes.size() - 1){break;}
	}
	//cout << "\nout\n";
	cout << get;
}