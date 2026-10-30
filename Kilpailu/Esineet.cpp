#include <iostream>
#include <sstream>
#include <vector>
#include <set>
// took about maybe 10h? to get runtime errors
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
	int max = 0, min = 0, maxWidth = 1;
	for(set<int> s : shape){
		max = *prev(s.end(), 1) > max ? *prev(s.end(), 1) : max;
		min = *s.begin() < min ? *s.begin() : min;
		maxWidth = s.size() > maxWidth ? s.size() : maxWidth;
	}
	int minRow;
	for(int y = shape.size()-1; y >= 0; y--){
		if(shape[y].count(min) == 1){minRow = y;}
	}
	vector<set<int>> outVec((max-min)+1);
	for(int y = 0; y < shape.size(); y++){
		int val = minRow-y;
		for(int x = 0; x < shape[y].size(); x++){
			outVec[*next(shape[y].begin(), x)-min].insert(val);
		}
	}
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

vector<string> newBoard(int h){
	vector<string> board(h);
	string line = "";
	getline(cin, line);
	for(int i = 0; i < h; i++){
		getline(cin, line);
		board[i] = line;
	}
	return board;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<string> board = newBoard(n);
	vector<vector<vector<int>>> shapes; // shapes[which shape][line][column]
	
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
	vector<set<vector<set<int>>>> shapesVec; //allShapes[shape][rotation][line][x]
	int y = 0;
	while(y < board.size()){
		if(!separateShape(lineShapes, shape, *lineShapes[y].begin(), *lineShapes[y].begin(), y)){y += 1;continue;}
		shapesVec.push_back({});
		int shapeNum = shapesVec.size()-1;
		vector<set<int>> rotShape = rotateShape(shape);

		shapesVec[shapeNum].insert(shape);
		shapesVec[shapeNum].insert(hFlip(shape));
		shapesVec[shapeNum].insert(vFlip(shape));
		shapesVec[shapeNum].insert(hFlip(vFlip(shape)));
		shapesVec[shapeNum].insert(rotShape);
		shapesVec[shapeNum].insert(hFlip(rotShape));
		shapesVec[shapeNum].insert(vFlip(rotShape));
		shapesVec[shapeNum].insert(hFlip(vFlip(rotShape)));
		shape = {};
	}

	board = newBoard(n);
	lineShapes = allShapes(board);
	string line = "";
	bool foundShape = true;
	y = 0;

	/*
	for(set<int> s : lineShapes){
		cout << "[ ";
		for(int i : s){
			cout << i << " ";
		}
		cout << "]\n";
	}
	cout << "************\n";
	cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n";
	for(set<vector<set<int>>> svs : shapesVec){
		cout << "#################################\n#################################\n\n";
		for(vector<set<int>> vs : svs){
			cout << "------------------------------\n";
			for(set<int> s : vs){
				cout << "[ ";
				for(int i : s){
					cout << i << " ";
				}
				cout << "]" << "\n";
			}
		}
	}
	*/
	
	for(int x = 0; x < m; x++){
		line += ".";
	}
	for(int y = 0; y < n; y++){
		board[y] = line;
	}
	while(y < board.size() || shapesVec.size() != 1){
		if(!separateShape(lineShapes, shape, *lineShapes[y].begin(), *lineShapes[y].begin(), y)){y += 1;continue;}
		/*
		cout << "----------------\n";
		for(set<int> s : shape){
			cout << "[ ";
			for(int i : s){
				cout << i << " ";
			}
			cout << "]\n";
		}
		cout << "*******\n";
		for(set<int> s : lineShapes){
			cout << "[ ";
			for(int i : s){
				cout << i << " ";
			}
			cout << "]\n";
		}
		*/
		for(auto it = shapesVec.begin(); it != shapesVec.end(); it++){
			set<vector<set<int>>> rotations = *it;
			if(rotations.count(shape) == 1){
				shapesVec.erase(it);
				break;
			}
		}
		shape = {};
	}

	for(int y = 0; y < (*next(shapesVec[0].begin(), shapesVec[0].size()-1)).size(); y++){
		for(int x : (*next(shapesVec[0].begin(), shapesVec[0].size()-1))[y]){
			board[y][x] = '#';
		}
	}

	for(string s : board){
		cout << s << "\n";
	}
}