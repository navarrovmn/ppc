#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

bool my_func(int a, int b){
	return a>b;
}

void print_vector(vector<int> v){
	for(int i=0; i<(int)v.size(); i++){
		printf("%d ", v[i]);
	}
	printf("\n");
}

int main(){
	int t, n, e, tmp;
	scanf("%d", &t);
	vector<int> jobs_p;
	vector<ii> pares;
	int total;	

	while(t--){
		jobs_p.clear();
		pares.clear();
		total = 0;
		scanf("%d %d", &n, &e);
		for(int i=0; i<n; i++){
			scanf("%d", &tmp);
			pares.push_back(ii(i, tmp));
			jobs_p.push_back(tmp);
		}
		sort(jobs_p.begin(), jobs_p.end(), my_func);
		
		while(1){
			ii actual = pares.front();
			if(actual.second == jobs_p[0]){
				total++;
				pares.erase(pares.begin());
				jobs_p.erase(jobs_p.begin());
				if(actual.first == e) break;
			}else{
				pares.erase(pares.begin());
				pares.push_back(actual);
			}
		}
		printf("%d\n", total);
	}

	return 0;
}
