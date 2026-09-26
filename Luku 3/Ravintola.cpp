//1:00
//1:20 - 6/11, others runtime errors
//1:51

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	int largest = 0;
	int here = 0;
	cin >> n;
	vector<int> start(n);
	vector<int> end(n);

	for(int i = 0; i < n; i++){
		int a;
		int b;
		cin >> a >> b;
		start[i] = a;
		end[i] = b;
	}

	sort(start.begin(), start.end());
	sort(end.begin(), end.end());
	int startP = 0;
	int endP = 0;
	for(int i = 0; i < 2*n; i++){
		if(startP >= start.size() || endP >= end.size()){
			break;
		}
		if(start[startP] < end[endP]){
			here += 1;
			startP += 1;
		}
		else{
			here -= 1;
			endP += 1;
		}

		largest = here > largest ? here : largest;
	}
	cout << largest;
}