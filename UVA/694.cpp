#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, l, c=1, values=1;
	long long int aux; 

	while(scanf("%d %d", &a, &l) && a >= 0 && l >= 0 ){
		aux = a;
		while(aux != 1){
			if(aux % 2 == 0){
				aux /= 2;
				values++;
			}else if(aux % 2 != 0){
				if(l < 3*aux+1){
					break;
				}
				aux = 3*aux+1;
				values++;
			}
		}
		printf("Case %d: A = %d, limit = %d, number of terms = %d\n", c, a, l, values);
		c++;
		values = 1;
	}
	return 0;	
}
