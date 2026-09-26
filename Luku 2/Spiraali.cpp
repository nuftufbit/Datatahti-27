// 21:35 likely
// 21:59 sub
// 22:07

#include <iostream>
using namespace std;

int main(){
	long long y;
	long long x;
	cin >> y >> x;

	if(x == y){
		if(y % 2 == 0){
			long long temp = y;
			y = x;
			x = temp;
		}
		cout << x*x - y + 1;
	}
	if(x > y){
		cout << ((x % 2 == 1) ? x*x - y + 1: (x-1)*(x-1) + y) ;
	}
	if(x < y){
		cout << ((y % 2 == 0) ? y*y - x + 1: (y-1)*(y-1) + x);
	}
}