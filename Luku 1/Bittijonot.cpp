// 14:30 likely
// 14:51

#include <iostream>
using namespace std;

int main(){
	int n;
	long long a = 1;
	cin >> n;
	for(int i = 0; i < n; i++){
		a = (a * 2) % (1000000007);
	}
	cout << a;
	return 0;
}