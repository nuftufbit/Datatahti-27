#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	float r;
	cin >> r;
	cout << setprecision(20) << (4.0/3.0)*3.14159*r*r*r;
	return 0;
}