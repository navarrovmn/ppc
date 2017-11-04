#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

bool pairCompare(const pair<int, int> firstElem, const pair<int, int> secondElem) {
  if(firstElem.first != secondElem.first) return firstElem.first < secondElem.first;
  else return firstElem.second < secondElem.second;
}

vector<ii> sequence;
int lis_n[10000];

int lis(int N) {
    int max_lis = 0;
    for (int i = 0; i < N; ++i) {
        lis_n[i] = 1;
        for (int j = i - 1; j >= 0; --j)
            if (sequence[j].first <= sequence[i].first && sequence[j].second <= sequence[i].second)
                lis_n[i] = max(lis_n[i], lis_n[j] + 1);

        max_lis = max(max_lis, lis_n[i]);
    }

    return max_lis;
}

int main(){
  int n, l, m, result;
  while(scanf("%d", &n), n){
    sequence.clear();
    memset(lis_n, 0, sizeof lis_n);
    for(int i=0; i<n; i++){
      scanf("%d %d", &l, &m);
      sequence.push_back(make_pair(l, m));
    }
    sort(sequence.begin(), sequence.end(), pairCompare);
    result = lis(sequence.size());
    printf("%d\n", result);
  }
  printf("*\n");
  return 0;
}
