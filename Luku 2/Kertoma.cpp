// 23:10 likely
// 00:34 close
// 00:41

#include <iostream>
#include <vector>
using namespace std;

int main(){
	long long n;
	long long fives = 0;
	cin >> n;

	int curNum = 5;
	while(curNum < n){
		fives += n / curNum;
		curNum *= 5;
	}
	cout << fives;
}