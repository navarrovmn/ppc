#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;

vector<int> sequence;
int lis_seq[MAX];

int lis(int N) {
    int lis_size = 0;

    for (int i = 0; i < N; ++i) {
        printf("Iteration i=%d\n", i);
        printf("Lower_bound(%d)\n", sequence[i]);
        int p = lower_bound(lis_seq, lis_seq + lis_size, sequence[i]) - lis_seq;
        printf("Index of lower: %d\n", p);
        lis_seq[p] = sequence[i];
        printf("Lis_size: %d P + 1: %d\n", lis_size, p+1);
        lis_size = max(lis_size, p + 1);
        printf("---------------------------------\n");
    }

    return lis_size;
}

int main(){
  int n;
  memset(lis_seq, 0, sizeof lis_seq);

  while(scanf("%d", &n) != EOF){
    sequence.push_back(n);
  }

  int result = lis(sequence.size());
  printf("%d\n-\n", result);
  return 0;
}
