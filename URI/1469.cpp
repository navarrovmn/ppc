#include <bits/stdc++.h>

using namespace std;

#define MAX_V 1000

vector<int> G[MAX_V];
bool visited[MAX_V];
unordered_map<int, int> idade;
vector<int> pessoas_passadas;

void dfs(int v) {
    visited[v] = true;
    pessoas_passadas.push_back(v);

    for(auto i: G[v])
        if (!visited[i])
            dfs(i);
}

void trade_node(int a, int b, int n){
	vector<int> aux = G[a];
	G[a] = G[b];
	G[b] = aux;
	for(int i=1; i<=n; i++){
		vector<int> vetor_atual = G[i];
		auto ita = find(vetor_atual.begin(), vetor_atual.end(), a);
		auto itb = find(vetor_atual.begin(), vetor_atual.end(), b);
		if(ita != vetor_atual.end()){
			G[i][ita-vetor_atual.begin()] = b;
		}
		if(itb != vetor_atual.end()){
      G[i][itb-vetor_atual.begin()] = a;
		}
	}
}

int main(){
	int n, m, l, age, gerente, gerenciado, aux1, aux2;
	char c;
	while(scanf("%d %d %d", &n, &m, &l) != EOF){
    memset(G, 0, sizeof G);
    idade.clear();

  	for(int i=1; i<=n; i++){
  		scanf("%d", &age);
  		idade[i] = age;
  	}
  	for(int i=1; i<=m; i++){
  		scanf("%d %d", &gerente, &gerenciado);
  		G[gerenciado].push_back(gerente);
  	}
  	for(int i=0; i<l; i++){
      getchar();
  		scanf("%c", &c);
  		if(c == 'T'){
  			scanf("%d %d", &aux1, &aux2);
  			trade_node(aux1, aux2, n);
  		}
      if(c == 'P'){
  			scanf("%d", &aux1);
        memset(visited, false, sizeof visited);
        pessoas_passadas.clear();
        dfs(aux1);
        int resultado = 1000;
        for(int p=1; p<(int) pessoas_passadas.size(); p++){
          resultado = min(resultado, idade[pessoas_passadas[p]]);
        }
        if(resultado < 1000){
          printf("%d\n", resultado);
        }else{
          printf("*\n");
        }
  		}
  	}
  }
	return 0;
}
