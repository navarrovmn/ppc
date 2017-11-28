#include <bits/stdc++.h>

using namespace std;

int main(){
	set<int> jill;
	set<int> jack;
	int a, b, tmp;

	while(scanf("%d %d", &a, &b) && a+b != 0){
		jack.clear();
		jill.clear();
		while(a--){
			scanf("%d", &tmp);
			jack.insert(tmp);
		}

		
		while(b--){
			scanf("%d", &tmp);
			jill.insert(tmp);
		}
		
		int total = 0;

		for(auto it = jack.begin(); it != jack.end(); ++it){
			if(jill.find(*it) != jill.end()) total++;
		}
		printf("%d\n", total);
	}
	return 0;
}
