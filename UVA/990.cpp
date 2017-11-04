#include <bits/stdc++.h>

using namespace std;

vector<int> W;
vector<int> V;

int memo[35][1050];
int taken[35][1050];

int knapsack(int i, int w, int constant) {
    if (i < 0 || w <= 0) return 0;
    if (memo[i][w] != -1) return memo[i][w];
    if (3 * constant * W[i] > w) return memo[i][w] = knapsack(i - 1, w, constant);

		int time_taken = 3*constant*W[i];
    auto not_take = knapsack(i - 1, w, constant);
    auto     take = knapsack(i - 1, w - time_taken, constant) + V[i];

    if (take > not_take) {
        taken[i][w] = true;
        return memo[i][w] = take;
		}
    else return memo[i][w] = not_take;
}


void reconstruct(int i, int w, int constant) {
    stack <pair<int, int> > itens;
		int time_taken = 0;
		do {
        if (taken[i][w]) {
						time_taken = (3*constant*W[i]);
            w -= time_taken;
            itens.push(make_pair(W[i], V[i]));
        }
    } while(i--);

		printf("%d\n", (int) itens.size());
    while(!itens.empty()) {
			auto item = itens.top();
			printf("%d %d\n", item.first, item.second);
			itens.pop();
		}
}

int main(){
	int t, w, objects, we, v, result = 0;
	int counter = 0;
	while(scanf("%d %d\n", &t, &w) != EOF){
		if(counter) printf("\n");
		counter++;
		memset(memo, -1, sizeof memo);
		memset(taken, false, sizeof taken);
		V.clear();
		W.clear();

		scanf("%d", &objects);
		while(objects--){
			scanf("%d %d", &we, &v);
			V.push_back(v);
			W.push_back(we);
		}
		result = knapsack(V.size()-1, t, w);
		printf("%d\n", result);
		reconstruct(V.size()-1, t, w);
	}
	return 0;
}
