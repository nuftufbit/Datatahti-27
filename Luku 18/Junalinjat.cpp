// 13:56
// 15:25 dfs figured out?
#include <iostream>
#include <vector>
using namespace std;

bool dfs(int find, int curr, int from, vector<vector<int>>& conns, vector<int>& visited){
	if(curr == find){
		visited.push_back(curr);
		return true;
	}

	vector<int> curConns = conns[curr];

	//cout << "conns:\n";
	//for(int i : curConns){
	//	cout << i << " ";
	//}
	//cout << "\n";

	if(curConns.size() == 1 && from != -1){
		return false;
	}

	bool foundRight = false;
	for(int i : curConns){
		//cout << "num " << i << " - ";
		if(i == from){continue;}
		foundRight = dfs(find, i, curr, conns, visited);
		if(foundRight){break;}
	}
	if(foundRight){
		visited.push_back(curr);
	}
	return foundRight;
}

int main(){
	int stationNum, trackNum;
	cin >> stationNum >> trackNum;
	vector<int> nodeSizes(stationNum);
	vector<vector<int>> connections(stationNum);
	vector<int> throughCount(stationNum);

	int one;
	int two;
	for(int i = 0; i < stationNum - 1; i++){
		cin >> one >> two;
		connections[one - 1].push_back(two - 1);
		connections[two - 1].push_back(one - 1);
	}

	//cout << "conns:\n";
	//for(vector<int> v : connections){
	//	for(int i : v){
	//		cout << i << " ";
	//	}
	//	cout << "\n";
	//}

	for(int m = 0; m < trackNum; m++){
		cin >> one >> two;
		vector<int> order;
		bool dfsOut = dfs(two - 1, one - 1, -1, connections, order);
		if(!dfsOut){continue;}
		for(int i : order){
			throughCount[i] += 1;
		}
	}
	for(int i : throughCount){
		cout << i << " ";
	}
}
