// 19:40 likely
// 20:28 sub
// 21:33 done, fiddling with getline shenanigans

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int max;
	int offset;
	string nums;
	string temp;
	vector<int> slots;
	cin >> max;
	getline(cin, nums);
	getline(cin, nums);

	slots.resize(max);

	for(int i = 0; i < slots.size() - 1; i++){
			int length = 0;
		while(nums[i+offset+length] != ' ' && i+offset+length < nums.length()){
			length = length + 1;
		}
		slots[length == 1 ? nums[i+offset] - '0' - 1 : stoi(nums.substr(i+offset, length)) - 1] = i + 1;
		offset = offset + length;
	}
	for(int i = 0; i < slots.size(); i++){
		if(slots[i] == 0){
			cout << i + 1;
			break;
		}
	}
}