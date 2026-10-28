#include <iostream>
// 16:17 start
// 16:27 100
using namespace std;

int main(){
	int w, l;
	cin >> w >> l;
	int area = w * l;
	cout << area << " ";
	while(w>0 && l>0){
		if(w == l){
			break;
		}
		if(w>l){
			area -= l*l;
			w -= l;
			cout << area << " ";
		}
		else{
			area -= w*w;
			l -= w;
			cout << area << " ";
		}
	}
	cout << 0;
}
