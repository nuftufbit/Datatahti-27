#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	string alph = "abcdefghijklmnn";
	int n, k;
	cin >> n >> k;
	alph = alph.substr(0, k);
	string outStr = "";
	map<string, char> noMap;
	
	// only need to look back at odd length substrings
	for(int i = 0; i < n; i++){
		string useAlph = alph;
		//cout << i << " " << outStr << "\n";
		for(int l = 1; l <= i; l++){
			string subS = outStr.substr(outStr.length()-l, l);
			if(l == 1){useAlph.erase(useAlph.find(subS), 1); continue;}
			//cout << subS << " - " << useAlph << " - " << l << "\n";
			if(noMap.find(subS) != noMap.end()){
				auto mIt = noMap.find(subS);
				useAlph.erase(useAlph.find(mIt->second), 1);
				continue;
			}

			if(l%2 == 0){continue;}

			if(subS.substr(0, l/2) == subS.substr(l/2+1, l/2)){
				if(useAlph.find(subS[l/2]) == -1){continue;}
				useAlph.erase(useAlph.find(subS[l/2]), 1);
			}
		}

		if(useAlph == ""){cout << "IMPOSSIBLE"; return 0;}

		if(useAlph.length() == 1){
			noMap[outStr.substr(0, outStr.length()-1)] = outStr[outStr.length()-1];
		}
		outStr += useAlph[0];
	}
	cout << outStr;
}