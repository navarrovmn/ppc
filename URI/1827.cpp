#include <bits/stdc++.h>

using namespace std;

void matrix(int n){
	bool quadrado_enabled = false;
	int central = n/2;
	int quadrado = n/3;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; j++){
			if(i==j && j == central){
				printf("4");
			}else if(j >= 0+quadrado && j <= n-1-quadrado && i >= 0+quadrado && i <= n-1-quadrado){
				printf("1");
			}else if(j == i  && !quadrado_enabled && i != n/2){
				printf("2");
			}else if(i+j+1 == n && !quadrado_enabled && i != n/2){
				printf("3");
			}else{
				printf("0");
			}
		}
	printf("\n");
	}
}

int main(){
	int n;
	while(scanf("%d", &n)!=EOF){
		matrix(n);
		printf("\n");
	}
	return 0;
}
