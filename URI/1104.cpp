#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b, aux, maxa=0, maxb=0;
	set<int> al, ma;
	
	while(scanf("%d %d", &a, &b) && a > 0 && b > 0){
		while(a--){
			scanf("%d", &aux);
			al.insert(aux);
		}
		while(b--){
			scanf("%d", &aux);
			ma.insert(aux);
		}
		for(set<int>::iterator i= al.begin(); i != al.end(); ++i){
			int k = *i;
			if(ma.find(k) == ma.end()) maxa++;
		}
		for(set<int>::iterator j= ma.begin(); j != ma.end(); ++j){
			int k = *j;
			if(al.find(k) == al.end()) maxb++;
		}
		printf("%d\n", min(maxa, maxb));
		al.clear();
		ma.clear();
		maxa=0;
		maxb=0;
	}
	return 0;	
}
