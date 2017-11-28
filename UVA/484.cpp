#include <bits/stdc++.h>

using namespace std;

int main(){
	unordered_map<int, int> oc;
	unordered_map<int, bool> must_print;
	vector<int> v;
	
	int tmp;
	while(scanf("%d", &tmp) != EOF){
		v.push_back(tmp);
		must_print[tmp] = true;
		if(oc.find(tmp) != oc.end()) oc[tmp]++;	
		else oc[tmp]=1;
	}

	for(int i=0; i< (int) v.size(); i++){
		if(must_print[v[i]]){
			printf("%d %d\n", v[i], oc[v[i]]);
		}
		must_print[v[i]] = false;
	}
	return 0;
}
