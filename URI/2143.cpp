#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, p;
	do{
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d", &p);
			if(p%2!=0){
				printf("%d\n", (p-1)*2+1);
			}else{
				printf("%d\n", (p-2)*2+2);
			}
		}
	}while(n!=0);
	return 0;	
}
