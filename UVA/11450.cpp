#include <bits/stdc++.h>

using namespace std;

int memo[100][100];
vector<int> itens[100];
int M, N;

int compras(int i, int dinheiro) {
  if (dinheiro < 0 ) {
    return numeric_limits<int>::lowest();
  }
  if (memo[i][dinheiro] != -1) {
    return memo[i][dinheiro];
  }
  if (i == N) {
    return M - dinheiro;
  }
  int max_custo = numeric_limits<int>::lowest();
  for (auto item : itens[i]) {
      max_custo = max(max_custo, compras(i + 1, dinheiro - item));
  }
  return memo[i][dinheiro] = max_custo;
}

int main(){
  ios::sync_with_stdio(false);
  int casos;

  cin >> casos;

  while(casos--){
    memset(memo, -1, sizeof memo);
    cin >> M >> N;
    for(int i=0; i<N; i++){
      int a;
      cin >> a;
      for(int j=0; j<a; j++){
        int b;
        cin >> b;
        itens[i].push_back(b);
      }
    }

    int custo = compras(0, M);
    if(custo < 0){
      cout << "no solution" << endl;
    }else{
      cout << custo << endl;
    }

  }
  return 0;
}
