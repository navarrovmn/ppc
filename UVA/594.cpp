#include <bits/stdc++.h>

using namespace std;

int main(){
	long long int d;
		
	while(scanf("%lld", &d) != EOF){
		bitset<32> A(d);
		
		cout << d << " converts to ";
		for(int i=0; i<8; i++){
			bool tmp;
			tmp = A[i], A[i] = A[i+24], A[i+24] = tmp; 
			tmp = A[i+8], A[i+8] = A[i+16], A[i+16] = tmp; 
		}

		int ans = A.to_ulong();
		cout << ans << endl;
	}
	return 0;
}
