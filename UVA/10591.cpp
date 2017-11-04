#include <bits/stdc++.h>

using namespace std;

int next_number(int n){
	long long int sum = 0, aux = n;
	while(aux >= 1){
	 	int remainder = aux%10;
		sum += pow(remainder, 2);
    aux /= 10;
  }
	return sum;
}

int main(){
	int t, p=1, num;
	set<long long int> values;
	long long int aux;
	scanf("%d", &t);
	for(int i=0; i<t; i++){
		scanf("%d", &num);
		aux = num;
		while(true){
			aux = next_number(aux);
			if(aux == 1){
				printf("Case #%d: %d is a Happy number.\n", p, num);
				p++;
				break;
			}else{
				if(find(values.begin(), values.end(), aux) != values.end()){
					printf("Case #%d: %d is an Unhappy number.\n", p, num);
					p++;
					break;
				}else{
					values.insert(aux);
				}
			}
		}
		values.clear();
	}
	return 0;	
}
