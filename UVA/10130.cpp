#include <bits/stdc++.h>

using namespace std;

int max_value;

vector<int> W;
vector<int> V;

int memo[1050][35];
int taken[1050][35];

int knapsack(int i, int w) {
    if (i < 0 || w <= 0) return 0;
    if (memo[i][w] != -1) return memo[i][w];
    if (W[i] > w) return memo[i][w] = knapsack(i - 1, w);

    auto not_take = knapsack(i - 1, w);
    auto     take = knapsack(i - 1, w - W[i]) + V[i];

    if (take > not_take) {
        taken[i][w] = true;
        return memo[i][w] = take;
		}
    else return memo[i][w] = not_take;
}

int main(){
	int casos, objetos, p, w, pessoas, ppessoa;
	scanf("%d", &casos);
	for(int i=0; i<casos; i++){
    memset(memo, -1, sizeof memo);
		max_value = 0;
		V.clear();
		W.clear();

		scanf("%d", &objetos);
		while(objetos--){
			scanf("%d %d", &p, &w);
			V.push_back(p);
			W.push_back(w);
		}
		scanf("%d", &pessoas);
		while(pessoas--){
			memset(taken, false, sizeof taken);
			scanf("%d", &ppessoa);
			max_value += knapsack(V.size()-1, ppessoa);
		}
		printf("%d\n", max_value);
	}

	return 0;
}
