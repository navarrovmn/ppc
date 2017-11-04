#include <bits/stdc++.h>

using namespace std;

int main(){
	int longest=0;
	vector<string> lines;
	string aux, a, answ;
	while(getline(cin, a)){
		lines.push_back(a);
		if((int) a.size() > longest) longest = a.size();
	}
	for(int i = 0; i < longest; ++i){
		for(int k=0; k<(int)lines.size(); ++k){
			aux = lines[k];
			if(i < (int) aux.size()){
				answ += aux[i];
			}else{
				answ += " ";
			}
		}
		reverse(answ.begin(), answ.end());
		printf("%s\n", answ.c_str());
		answ.clear();
	}
	return 0;
}
