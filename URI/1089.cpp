#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, aux, inf=0, aaux;
	vector<int> notas;
	while(scanf("%d", &n) && n != 0){
		while(n--){
			scanf("%d", &aux);
			notas.push_back(aux);
		}
		aaux = notas.back();
		notas.push_back(notas.front());
		notas.insert(notas.begin(), aaux);
		for(int i=1; i<(int)notas.size()-1; i++){
			if(notas[i-1] > notas[i] && notas[i+1] > notas[i]) inf++;
			if(notas[i-1] < notas[i] && notas[i+1] < notas[i]) inf++;
		}
		printf("%d\n", inf);
		inf = 0;
		notas.clear();
	}
	return 0;	
}
