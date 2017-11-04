#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b, c, result;
	while(scanf("%d %d %d", &a, &b, &c) != EOF){
		result = a+b+c;
		if(result == 0 || result == 3){
			printf("*\n");
		}else{
			if(a != b && a != c){
				printf("A\n");
			}else if(b != a && b != c){
				printf("B\n");
			}else{
				printf("C\n");
			}
		}
	}
	return 0;	
}
