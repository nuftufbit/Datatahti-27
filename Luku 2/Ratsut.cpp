// 22:10 likely
// 23:02

#include <iostream>
using namespace std;

int main(){
	long long n;
	cin >> n;

	switch (n)
	{
	case 1:
		cout << 0;
		break;
	case 2:
		cout << 3+2+1;
		break;
	case 3:
		cout << (8*9)/2 - 3*2 - 2;
		break;
	case 4:
		cout << (15*16)/2 - 4*6;
	default:
		cout << (n*n*(n*n -1))/2 - (n-2)*10 - (n-4)*(n-2)*4 - (n-4)*2 - 4;
	}
}