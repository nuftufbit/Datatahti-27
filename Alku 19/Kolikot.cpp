//18:18
//18:43

#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	int last = 0, remainder = n;
	vector<int> order;
	while(remainder > last){
		last++;
		remainder -= last;
		order.push_back(last);
	}
	while(remainder > 0){
		for(int i = 1; i <= order.size(); i++){
			order[order.size() - i]++;
			remainder--;
			if(remainder <= 0){break;}
		}
	}
	cout << order.size() << "\n";
	for(int i : order){
		cout << i << " ";
	}
}