// 18:13
// 18:45 ~ probably started figuring the example out here
// 19:22

#include <iostream>
#include <vector>
using namespace std;

void search(int y, int& tot, bool (col)[8], bool (downD)[15], bool (upD)[15], bool (skip)[8][8]){
	if(y == 8){
		tot++;
		return;
	}
	for(int x = 0; x < 8; x++){
		if(skip[y][x] || col[x] || upD[x+y] || downD[x-y+7]){continue;}
		col[x] = upD[x+y] = downD[x-y+7] = true;
		search(y + 1, tot, col, downD, upD, skip);
		col[x] = upD[x+y] = downD[x-y+7] = false;
	}
}

int main(){
	string board[8];
	int total = 0;
	for(int i = 0; i < 8; i++){
		cin >> board[i];
	}
	bool columns[8] = {false, false, false, false, false, false, false, false};
	bool diagD[15] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
	bool diagU[15] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
	bool disallow[8][8];
	for(int tile = 0; tile < 64; tile++){
		if(board[tile / 8][tile % 8] == '*'){
			disallow[tile / 8][tile % 8] = true;
		}
		else{disallow[tile / 8][tile % 8] = false;}
	}
	search(0, total, columns, diagD, diagU, disallow);
	cout << total;
}