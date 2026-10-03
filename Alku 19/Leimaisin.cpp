// 18:48

#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool inSet(string val, set<string> strSet){
	for(string s : strSet){
		if(val == s){
			return true;
		}
	}
	return false;
}

int main(){
	string target, stamp;
	cin >> target >> stamp;

	set<string> combs;
	string temp = "";
	for(int i = 1; i < stamp.size(); i++){
		temp = "";
		temp += stamp[i-1];
		temp += stamp[i];
		combs.insert(temp);
		temp = "";
		temp += stamp[i];
		temp += stamp[0];
		combs.insert(temp);
		temp = "";
		temp += stamp[stamp.size()-1];
		temp += stamp[i-1];
		combs.insert(temp);
	}
	temp = "";
	temp += stamp[stamp.size()-1];
	temp += stamp[stamp.size()-1];
	combs.insert(temp);
	temp = "";
	temp += stamp[0];
	temp += stamp[0];
	combs.insert(temp);

	for(int i = 1; i < target.size(); i++){
		temp = "";
		temp += target[i-1];
		temp += target[i];
		if(!inSet(temp, combs)){
			cout << "-1 " << temp;
			return 0;
		}
	}

	combs.clear();
	for(int i = 1; i < target.size(); i++){
		temp = "";
		temp += target[i-1];
		temp += target[i];
		combs.insert(temp);
	}
	for(int i = 1; i < stamp.size(); i++){
		temp = "";
		temp += stamp[i-1];
		temp += stamp[i];
		if(!inSet(temp, combs)){
			cout << "-1 " << temp;
			return 0;
		}
	}

	string curWhole = "";
	bool hasPrev = false;
	vector<int> breakIndexs;
	vector<int> backBreaks;
	for(int i = 0; i < target.length(); i++){
		curWhole += target[i];
		//cout << "w " << curWhole << "\n";

		if(curWhole == stamp){
			curWhole = "";
			if(target[i] == stamp[0]){
				curWhole += target[i];
				breakIndexs.push_back(i);
			}
			else{breakIndexs.push_back(i + 1);}
			continue;
		}

		if(stamp.find(curWhole) == string_view::npos){
			curWhole = "";
			breakIndexs.push_back(i);
			if(target[i] == stamp[0]){
				curWhole += target[i];
			}
			continue;
		}
	}

	if(breakIndexs[breakIndexs.size() - 1] >= target.size()){breakIndexs.pop_back();}
	cout << breakIndexs.size() + 1 << "\n";
	cout << 1 << " ";
	
	for(int i = breakIndexs.size() - 1; i >= 0; i--){
		if(i == breakIndexs.size() - 1){
			cout << breakIndexs[breakIndexs.size() - 1] - (stamp.size() - (target.size() - breakIndexs[breakIndexs.size() - 1])) + 1 << " ";
		}
		if(target[breakIndexs[i]] == stamp[0]){
			cout << breakIndexs[i] + 1 << " ";
			continue;
		}
		cout << breakIndexs[i] - (stamp.size() - (breakIndexs[i+1] - breakIndexs[i])) + 1 << " ";
	}

	//debug
	//cout << "\nbreaks: ";
	//for(int i : breakIndexs){
	//	cout << i << " ";
	//}
	//cout << "\nback: ";
	//for(int i : backBreaks){
	//	cout << i << " ";
	//}
}