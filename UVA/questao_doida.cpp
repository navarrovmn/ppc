#include <bits/stdc++.h>

using namespace std;

int main(){
	long long N, L, R, l, r, ans;
	while(scanf("%lld %lld %lld", &N, &L, &R) != EOF){
		ans = 0;
		for(int i=31; i>=0; i--){
			if(N&(1LL << i)){
				l = ans + (1LL << i);
				if(l <= L) ans += 1LL<<i;
			}else{
				r = ans + (1LL << i);
				if(r <= R) ans += 1LL<<i;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
