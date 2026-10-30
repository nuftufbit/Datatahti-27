#include <iostream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

vector<set<int>> allShapes(vector<string> board){
	vector<set<int>> outVec; // outVec[lineNum][pos]
	for(int i = 0; i < board.size(); i++){
		outVec.push_back({});
		for(int j = 0; j < board[0].size(); j++){
			if(board[i][j] == '.'){continue;}
			else{ // is '#'
				outVec[i].insert(j);
			}
		}
	}
	return outVec;
}

vector<set<int>> hFlip(vector<set<int>> shape){
	vector<set<int>> outVec;
	auto lastP = shape[0].end();
	lastP--;
	int offset = *lastP;
	for(set<int> s : shape){
		outVec.push_back({});
		for(int x : s){
			outVec[outVec.size()-1].insert(offset-x);
		}
	}
	return outVec;
}

vector<set<int>> vFlip(vector<set<int>> shape){
	vector<set<int>> outVec;
	int offset = *shape[shape.size()-1].begin();
	for(int y = shape.size()-1; y >= 0; y--){
		outVec.push_back({});
		for(int x : shape[y]){
			outVec[shape.size()-1 - y].insert(x-offset);
		}
	}
	return outVec;
}

vector<set<int>> rotateShape(vector<set<int>> shape){
	//hFlip: else - big top
	vector<set<int>> outVec;
	int x = 0;
	bool noX = false;
	do{
		noX = true;
		outVec.push_back({});
		for(int y = shape.size()-1; y >= 0; y--){
			if(shape[y].size() <= x){continue;}
			noX = false;
			outVec[x].insert(shape.size()-1 - y);
		}
		x++;
	}while(!noX);
	outVec.pop_back();
	return outVec;
}

// x should be the first value of a row when initing this, offset should be the same value as x
bool separateShape(vector<set<int>>& linePos, vector<set<int>>& outVec, int x, int offset, int y = 0, int shapeHeight = 0){
	if(y >= linePos.size()){return false;}
	if(linePos[y].empty() || linePos[y].count(x) == 0){return false;}
	if(outVec.size() < shapeHeight+1){outVec.push_back({});}

	outVec[shapeHeight].insert(x-offset);
	int begVal = *linePos[y].begin();
	auto endIt = linePos[y].end();
	endIt--;
	int endVal = *endIt;
	linePos[y].erase(linePos[y].find(x));

	if(!(x == begVal)){separateShape(linePos, outVec, x-1, offset, y, shapeHeight);}

	if(!(x == endVal)){separateShape(linePos, outVec, x+1, offset, y, shapeHeight);}

	if(!(y == linePos.size()-1)){separateShape(linePos, outVec, x, offset, y+1, shapeHeight+1);}

	return true;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<string> board(n);
	vector<vector<vector<int>>> shapes; // shapes[which shape][line][column]
	string line = "";
	getline(cin, line);
	for(int i = 0; i < n; i++){
		getline(cin, line);
		board[i] = line;
	}

	vector<set<int>> lineShapes = allShapes(board);

	/*
	for(set<int> v : lineShapes){
		cout << "\n[ ";
		for(int i : v){
			cout << i << " ";
		}
		cout << "]";
	}
	*/

	vector<set<int>> shape;
	separateShape(lineShapes, shape, *lineShapes[0].begin(), *lineShapes[0].begin());
	shape = rotateShape(shape);
	for(set<int> v : shape){
		cout << "\n[ ";
		for(int i : v){
			cout << i << " ";
		}
		cout << "]";
	}

	/*
	int y = 0;
	while(y < board.size()){
		if(!separateShape(lineShapes, shape, *lineShapes[y].begin(), *lineShapes[y].begin(), y)){y += 1;continue;}
		cout << "\n--------";
		for(set<int> v : shape){
			cout << "\n[ ";
			for(int i : v){
				cout << i << " ";
			}
			cout << "]";
		}
		shape = {};
	}
	cout << " done";
	*/
		

	vector<vector<vector<vector<int>>>> rotateShapes; //rotateShapes[shape][rotation][tile][offset from top(left)]
}