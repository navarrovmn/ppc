#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	bool trade;

	while(scanf("%d", &n), n){
		bitset<40> A(n);
		bitset<40> B;
		bitset<40> C;
		trade = true;

		for(int i=0; i < 40; i++){
			bool vrf = A[i];
			if(vrf){
				if(trade){
					B[i] = A[i];
					trade = false;
				}else{
					C[i] = A[i];
					trade = true;
				}
			}
		}
		cout << B.to_ulong() << " " << C.to_ulong() << endl;
	}
	return 0;
}
