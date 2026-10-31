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

// returns size 2 vector where [0] is width of each line, and [1] is positions
vector<vector<int>> allShapes2(vector<string> board){
	vector<vector<int>> outVec;
	for(int i = 0; i < board.size(); i++){
		outVec.push_back({});
		int width = 0;
		for(int j = 0; j < board[0].size(); j++){
			if(board[i][j] == '.'){continue;}
			else{ // is '#'
				outVec[1].push_back(j);
				width++;
			}
		}
		outVec[0].push_back(width);
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

vector<set<int>> vFlip(vector<set<int>>& shape){
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

vector<set<int>> rotateShape(vector<set<int>>& shape){
	int max = 0, min = 0, maxWidth = 1;
	for(set<int> s : shape){
		max = *prev(s.end(), 1) > max ? *prev(s.end(), 1) : max;
		min = *s.begin() < min ? *s.begin() : min;
		maxWidth = s.size() > maxWidth ? s.size() : maxWidth;
	}
	int minRow;
	for(int y = shape.size()-1; y >= 0; y--){
		if(shape[y].count(min) == 1){minRow = y; break;}
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
bool separateShape(vector<set<int>>& piecePos, vector<set<int>>& outVec, int x, int offset, int y = 0, int shapeHeight = 0){
	if(y >= piecePos.size()){return false;}
	if(piecePos[y].empty() || piecePos[y].count(x) == 0){return false;}
	if(outVec.size() < shapeHeight+1){outVec.push_back({});}

	outVec[shapeHeight].insert(x-offset);
	int begVal = *piecePos[y].begin();
	auto endIt = piecePos[y].end();
	endIt--;
	int endVal = *endIt;
	piecePos[y].erase(piecePos[y].find(x));

	if(!(x == begVal)){separateShape(piecePos, outVec, x-1, offset, y, shapeHeight);}

	if(!(x == endVal)){separateShape(piecePos, outVec, x+1, offset, y, shapeHeight);}

	if(!(y == piecePos.size()-1)){separateShape(piecePos, outVec, x, offset, y+1, shapeHeight+1);}

	return true;
}

bool separateShape2(vector<vector<int>>& allPiece, vector<vector<int>>& outVec, int searchVal, int valOffset, 
		int y = 0, int totalPosOff = 0, int shapeHeight = 0){
	if(y > allPiece[0].size() || allPiece[0][y] == 0){return false;}
	set<int> row = set<int>(allPiece[1].begin() + totalPosOff - (totalPosOff > 0 ? 1 : 0), 
				allPiece[1].begin() + totalPosOff + allPiece[0][y] - (totalPosOff > 0 ? 1 : 0));
	if(row.count(searchVal) == 0){return false;}
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
	vector<set<int>> startShapes = allShapes(board);

	board = newBoard(n);
	vector<set<int>> endShapes = allShapes(board);
	vector<set<int>> constEndShapes = endShapes;

	vector<set<int>> inShape;
	vector<set<int>> outShape;
	//vector<vector<set<int>>> shapesVec; //allShapes[shape][line][x]

	bool foundShape = true;
	int y = 0;
	while(y < board.size() && foundShape){
		if(startShapes[0].empty()){
			startShapes.erase(startShapes.begin());
			continue;
		}
		inShape = {};
		separateShape(startShapes, inShape, *startShapes[0].begin(), *startShapes[0].begin());

		foundShape = false;
		while(!foundShape && y < board.size()){
			if(!separateShape(endShapes, outShape, *endShapes[y].begin(), *endShapes[y].begin(), y)){y++;continue;}
			vector<set<int>> rotated = rotateShape(inShape);
			if(outShape == inShape || outShape == rotated
			|| outShape == hFlip(inShape) || outShape == hFlip(rotated)
			|| outShape == vFlip(inShape) || outShape == vFlip(rotated)
			|| outShape == hFlip(vFlip(inShape)) || outShape == hFlip(vFlip(rotated))){
				foundShape = true;
			}
			outShape = {};
		}
		endShapes = constEndShapes;
		y = 0;
	}

	/*
	while(y < board.size() || shapesVec.size() != 1){
		if(!separateShape(startShapes, inShape, *startShapes[y].begin(), *startShapes[y].begin(), y)){y++;continue;}

		for(auto it = shapesVec.begin(); it != shapesVec.end(); it++){
			vector<set<int>> sh = *it;
			vector<set<int>> rotated = rotateShape(sh);
			if(inShape == sh || inShape == rotated
			|| inShape == hFlip(sh) || inShape == hFlip(rotated)
			|| inShape == vFlip(sh) || inShape == vFlip(rotated)
			|| inShape == hFlip(vFlip(sh)) || inShape == hFlip(vFlip(rotated))){
				shapesVec.erase(it);
				break;
			}
		}
		inShape = {};
	}
	*/

	string line = "";
	for(int x = 0; x < m; x++){
		line += ".";
	}
	for(int y = 0; y < n; y++){
		board[y] = line;
	}

	for(int y = 0; y < inShape.size(); y++){
		for(int x : inShape[y]){
			board[y][x] = '#';
		}
	}
	for(string s : board){
		cout << s << "\n";
	}
}