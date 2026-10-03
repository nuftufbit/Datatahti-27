// 13:25

#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int inverseWeight(vector<bool> visited, vector<int> input){
	int out = 0;
	//cout << "\nnew\n";
	for(int i = 0; i < input.size(); i++){
		//cout << visited[i] ? "1 " : "0 ";
		if(visited[i]){continue;}
		out += input[i];
	}
	//cout << out;
	return out;
}

void perms(int width, int depth, int curWeight, vector<int>& input, set<int>& res, vector<bool> visited){
	for(int i = 0; i <= input.size() - width + depth; i++){
		if(visited[i]){continue;}
		curWeight += input[i];
		visited[i] = true;
		if(width != depth + 1){
			perms(width, depth + 1, curWeight, input, res, visited);
		}
		else{
			res.insert(abs(curWeight - inverseWeight(visited, input)));
			//cout << "\n" << curWeight;
		}
		visited[i] = false;
	}
	return;
}

int main(){
	int aplNum;
	string weights;
	vector<int> weightsVec;
	cin >> aplNum;
	getline(cin, weights);
	getline(cin, weights);
	stringstream wS(weights);
	int weight;
	for(int i = 0; i < aplNum; i++){
		wS >> weight;
		weightsVec.push_back(weight);
	}
	sort(weightsVec.begin(), weightsVec.end());

	set<int> whts;
	for(int w = 0; w < aplNum / 2; w++){
		vector<bool> visited;
		visited.resize(aplNum, false);
		perms(w + 1, 0, 0, weightsVec, whts, visited);
	}
	cout << *whts.begin();
}