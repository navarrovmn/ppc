#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, counter=1, sum=0;
	while(scanf("%d", &n)!=EOF){
		for(int i=1; i<=n; ++i){
			sum+=i;
		}
		sum++;
		if(sum==1){
			printf("Caso %d: 1 numero\n", counter);
			printf("0");
		}else{
			printf("Caso %d: %d numeros\n", counter, sum);
			for(int j=0; j<=n; ++j){
				int o = j <= 1 ? 1 : j;
				if(j) printf(" ");
				for(int i=0; i<o; ++i){
					if(i) printf(" ");
					printf("%d", j);
				}
			}
			printf("\n");
		}
		printf("\n");
		sum = 0;
		counter++;
	}
	return 0;	
}
