#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, aux;
	vector<int> par, impar;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &aux);
		if(aux % 2 == 0){
			par.push_back(aux);
		}
		else{
			aux = aux * -1;
			impar.push_back(aux);
		}
	}
	sort(par.begin(), par.end());
	sort(impar.begin(), impar.end());
	for(int i=0; i<(int)par.size(); i++){
		printf("%d\n", par[i]);
	}	
	for(int j=0; j<(int)impar.size(); j++){
		printf("%d\n", impar[j]*-1);
	}
	return 0;	
}
