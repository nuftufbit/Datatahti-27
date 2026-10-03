// 13:56
// 15:25 dfs figured out?
// 15:58 timeout on big input sizes

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfsAll(int curr, int curDepth, vector<vector<int>>& conns, vector<int>& order, vector<int>& depth, vector<int> visited){
	vector<int> curConns = conns[curr];
	order.push_back(curr);
	depth.push_back(curDepth);
	visited[curr] = 1;

	if(curConns.size() == 1){
		return;
	}
	cout << "sllkj";
	for(int i : curConns){
		if(visited[i] == 1){continue;}
		dfsAll(i, curDepth + 1, conns, order, depth, visited);
	}
}

int main(){
	int stationNum, trackNum;
	cin >> stationNum >> trackNum;
	vector<int> nodeSizes(stationNum);
	vector<vector<int>> connections(stationNum);
	vector<int> throughCount(stationNum);
	vector<vector<int>> straights(stationNum);

	int one;
	int two;
	for(int i = 0; i < stationNum - 1; i++){
		cin >> one >> two;
		connections[one - 1].push_back(two - 1);
		connections[two - 1].push_back(one - 1);
	}
	cout << "gggg";

	//cout << "conns:\n";
	//for(vector<int> v : connections){
	//	for(int i : v){
	//		cout << i << " ";
	//	}
	//	cout << "\n";
	//}

	vector<int> order;
	vector<int> depth;
	vector<int> visits(stationNum);
	dfsAll(connections[0][0], 1, connections, order, depth, visits);
	cout << "fgdjh";

	for(int m = 0; m < trackNum; m++){
		cin >> one >> two;
		auto pOne = find(order.begin(), order.end(), one);
		auto pTwo = find(order.begin(), order.end(), two);
		int onePlace = pOne - order.begin();
		int twoPlace = pTwo - order.begin();
		if(onePlace > twoPlace){int temp = twoPlace; twoPlace = onePlace; onePlace = temp;}
		int min;
		for(int i = onePlace; i < twoPlace; i++){
			if(min == 1){break;}
			if(min > depth[i]){min = depth[i];}
		}
		int lastBackPos = onePlace;
		int lastFrontPos = twoPlace;
		for(int f = onePlace, b = twoPlace; depth[f] != min && depth[b] != min; f++, b--){
			if(order[f] == lastBackPos){break;}
			if(depth[lastFrontPos] > depth[f]){
				throughCount[order[f]] += 1;
				lastFrontPos = f;
			}
			if(order[b] == lastFrontPos){break;}
			if(depth[lastBackPos] > depth[b]){
				throughCount[order[b]] += 1;
				lastBackPos = b;
			}
			throughCount[one] += 1;
			throughCount[two] += 1;
		}
	}
	for(int i : throughCount){
		cout << i << " ";
	}
}
