#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;

vector<int> sequence;
int lis_seq[MAX];
int lis_seq_i[MAX];
int lis_parents[MAX];
int lis_max_i = -1;

int lis(int N) {
    int lis_size = 0;
    for (int i = 0; i < N; ++i) {
        int p = lower_bound(lis_seq, lis_seq + lis_size, sequence[i]) - lis_seq;
        lis_seq[p] = sequence[i];
        lis_seq_i[p] = i;

        lis_parents[i] = (p ? lis_seq_i[p-1] : -1);

        if(p+1 > lis_size){
          lis_size = p+1;
          lis_max_i = i;
        }

    }
  return lis_size;
}

void reconstruct() {
    stack<int> s;
    for(int i = lis_max_i; i != -1; i = lis_parents[i]) s.push(sequence[i]);

    printf("%d\n", s.top());
    while(s.pop(), !s.empty()) printf("%d\n", s.top());
}

int main(){
  int n;
  memset(lis_seq, 0, sizeof lis_seq);

  while(scanf("%d", &n) != EOF){
    sequence.push_back(n);
  }

  int result = lis(sequence.size());
  printf("%d\n-\n", result);
  reconstruct();
  return 0;
}
