#include <bits/stdc++.h>
#define MAX_ITEMS 105

using namespace std;


int peso[MAX_ITEMS];
int valor[MAX_ITEMS];
int matriz_memo[15000][15000];
int aaaaa = 0;

int nepseq(int item, int weight) {
		aaaaa++;
    if (item < 0 || weight <= 0) {
        return 0;
    }

    if (matriz_memo[item][weight] != -1) {
        return matriz_memo[item][weight];
    }

    if (peso[item] > weight) {
        return matriz_memo[item][weight] = nepseq(item - 1, weight);
    }

    return matriz_memo[item][weight] = max(nepseq(item - 1, weight),
                                    nepseq(item - 1, weight - peso[item]) + valor[item]);
}

int main(){
	int t, num_items;
	scanf("%d", &t);
	while(t--){
		memset(peso, 0, sizeof(peso));
		memset(valor, 0, sizeof(valor));
		memset(matriz_memo, -1, sizeof(matriz_memo));
		scanf("%d", &num_items);
		int sum = 0;
		for(int i=0; i<num_items; ++i){
			int tmp;
			scanf("%d", &tmp);
			peso[i] = tmp;
			valor[i] = tmp;
			sum+=tmp;
		}
		int maior = nepseq(num_items, sum/2);
		printf("%d\n", sum-(maior*2));
	}
	return 0;
}
