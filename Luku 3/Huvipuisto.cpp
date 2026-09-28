//12:11

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main(){
	int numChild, maxW;
	int car = 0;
	string wh;
	cin >> numChild >> maxW;
	getline(cin, wh);
	getline(cin, wh);

	stringstream wS(wh);
	int w;
	int half = maxW/2 + 1;
	int halfPoint = 0;
	bool halfSet = false;
	vector<int> weights(numChild);

	for(int i = 0; i < numChild; i++){
		wS >> w;
		weights[i] = w;
	}
	
	sort(weights.begin(), weights.end());

	for(int i = 0; i < numChild; i++){
		w = weights[i];
		if(w >= half && !halfSet){
			halfPoint = i;
			halfSet = true;
			//cout << "< ";
		}
		//cout << w << " ";
	}
	
	int less = halfPoint - 1;
	int more = halfPoint;
	bool freePair = false;
	while(less >= 0 && more < numChild && halfSet){
		//cout << "\n" << weights[less] << " l - m " << weights[more];
		if(weights[less] + weights[more] > maxW){
			less--;
			if(!freePair){freePair = true;}
			else{
				car++;
				freePair = false;
			}
		}
		else{
			car++;
			less--;
			more++;
		}
	}

	if(halfSet){
		bool moreEnd = more >= numChild;
		//cout << (moreEnd ? " true " : " false ");
		car += moreEnd && less < 0 ? 0 : moreEnd ? less/2 + 1 : numChild - more + (freePair ? 1 : 0);
	}
	else{
		car = (numChild / 2) + ((numChild % 2) ? 1 : 0);
	}
	cout << car;
}