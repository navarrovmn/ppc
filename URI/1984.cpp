#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n;
	scanf("%lld", &n);
	while(n>=1){
		printf("%lld", n%10);
		n /= 10;
	}
	printf("\n");
	return 0;	
}
