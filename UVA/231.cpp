#include <bits/stdc++.h>

using namespace std;

#define MAX 100

vector<int> sequence;
vector<int> lis_n;

int lis(int N) {
    int max_lis = 0;

    for (int i = 0; i < N; ++i) {
        lis_n[i] = 1;
        for (int j = i - 1; j >= 0; --j)
            if (sequence[j] >= sequence[i])
                lis_n[i] = max(lis_n[i], lis_n[j] + 1);

        max_lis = max(max_lis, lis_n[i]);
    }
    return max_lis;
}

int main(){
  int height, i, counter=1, l_counter=0;
  bool was_last = false;

  while(1){
    i = 0;
    sequence.clear();
    lis_n.clear();
    while(1){
      scanf("%d", &height);
      if(height == -1 && was_last) return 0;
      if(height == -1){
        was_last = true;
        break;
      }else{
        was_last = false;
        sequence.push_back(height);
        lis_n.push_back(height);
        i++;
      }
    }
    if(l_counter) printf("\n");
    l_counter++;
    int result = lis(i);
    printf("Test #%d:\n", counter);
    printf("  maximum possible interceptions: %d\n", result);
    counter++;
  }
  return 0;
}
