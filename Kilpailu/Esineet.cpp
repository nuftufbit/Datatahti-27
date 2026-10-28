#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<string> board(n);
	vector<vector<vector<int>>> shapes; // shapes[which shape][line][column]
	string line = "";
	getline(cin, line);
	for(int i = 0; i < n; i++){
		getline(cin, line);
		board.push_back(line);
	}

	int curShapeNum = 0;
	vector<vector<vector<int>>> lineShapes; // lineShapes[lineNum][which shape][pos]
	for(int i = 0; i < n; i++){
		curShapeNum = 0;
		lineShapes.push_back({{}});
		for(int j = 0; j < m; j++){
			if(board[i][j] == '.'){
				if(j == 0){continue;}
				if(board[i][j-1] == '#'){curShapeNum += 1;}
				continue;
			}
			if(board[i][j] == '#'){
				lineShapes[i][curShapeNum].push_back(j);
			}
		}
	}
	for(vector<vector<int>> vv : lineShapes){
		
	}
}