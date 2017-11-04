#include <bits/stdc++.h>

using namespace std;

typedef struct block{
  int x;
  int y;
  int z;

  block(int a, int b, int c){
    x = a;
    y = b;
    z = c;
  }
}block;

vector<block> sequence;

bool compare(block a, block b){
  if(a.x != b.x) return a.x < b.x;
  if(a.y != b.y) return a.y < b.y;
  return a.z < b.z;
}

int lis_n[185];

int lis(int N) {
    int max_lis = 0;
    for (int i = 0; i < N; ++i) {
        lis_n[i] = sequence[i].z;
        for (int j = i - 1; j >= 0; --j)
            if (sequence[j].x < sequence[i].x && sequence[j].y < sequence[i].y)
                lis_n[i] = max(lis_n[i], lis_n[j] + sequence[i].z);

        max_lis = max(max_lis, lis_n[i]);
    }
    return max_lis;
}

int main(){
  int n, x, y, z, counter=1, result=0;
  while(scanf("%d", &n), n){
    sequence.clear();
    memset(lis_n, 0, sizeof lis_n);

    while(n--){
      scanf("%d %d %d", &x, &y, &z);
      sequence.push_back(block(x, y, z));
      sequence.push_back(block(y, x, z));
      sequence.push_back(block(z, y, x));
      sequence.push_back(block(z, x, y));
      sequence.push_back(block(x, z, y));
      sequence.push_back(block(y, z, x));
    }

    sort(sequence.begin(), sequence.end(), compare);
    result = lis((int) sequence.size());
    printf("Case %d: maximum height = %d\n", counter, result);
    counter++;
  }
  return 0;
}
