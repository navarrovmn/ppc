#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, q, a, c=0;
	vector<int> notas, aux;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &q);
		while(q--){
			scanf("%d", &a);
			a *= -1;
			notas.push_back(a);
		}
		aux = notas;
		stable_sort(notas.begin(), notas.end());
		for(int i=0; i<(int)notas.size(); i++){
			if(notas[i] == aux[i]) c++;
		}
		printf("%d\n", c);
		notas.clear();
		aux.clear();
		c=0;
	}
	return 0;	
}
