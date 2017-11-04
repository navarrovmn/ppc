#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, q, m, a, cas=1;
	vector<int> marbles;
	while(scanf("%d %d", &n, &q) && n != 0 && q != 0){
		while(n--){
			scanf("%d", &m);
			marbles.push_back(m);
		}
		sort(marbles.begin(), marbles.end());
		printf("CASE# %d:\n", cas);
		while(q--){
			scanf("%d", &a);
			auto it = lower_bound(marbles.begin(), marbles.end(), a);
			if(binary_search(marbles.begin(), marbles.end(), a)){
				printf("%d found at %d\n", a, (int)(it - marbles.begin())+1);
			}else{
				printf("%d not found\n", a);
			}
		}
		cas++;
		marbles.clear();
	}
	return 0;	
}
