#include <bits/stdc++.h>
#define MAX 100

using namespace std;

int G[MAX][MAX];
int A[MAX][MAX];

int main(){
  int t, n, tmp, dominated_by, count, line, kase=1, plus;
  bool skip;
  scanf("%d", &t);
  for(int i=0; i<t; i++){
    memset(G, 0, sizeof G);
    memset(A, 0, sizeof A);
    count = 0;

    scanf("%d", &n);

    // This part builds the graphs
    for(int k=0; k<n; k++){
      for(int j=0; j<n; j++){
        scanf("%d", &tmp);
        G[k][j] = tmp;
      }
    }

    for(int q=0; q<1; q++){
      for(int r=0; r<n; r++){
        if(G[q][r]) count++;
      }
    }
    if(count == 0){
      memset(A, 0, sizeof A);
      A[0][0] = 1;
      skip = true;
    }else{
      skip = false;
    }

    // This part calculates the dominations
    if(!skip){
      for(int k=0; k<n; k++){
        count = 0;
        dominated_by = 0;
        line = 0;
        for(int l=0; l<n; l++){
            if(l == k || l == 0){
              A[l][k] = 1;
              continue;
            }
            if(G[l][k]){
              count++;
              dominated_by=k;
              line = l;
            }
        }
        if(count == 1){
          A[line][dominated_by] = 1;
        }
      }
    }

    plus = 2*n-1;
    // This part is for the pretty print
    printf("Case %d:\n", kase);
    kase++;
    for(int z=0; z<n; z++){
      printf("+");
      for(int p = 0; p<plus; p++) printf("-");
      printf("+\n");
      for(int s=0; s<n; s++){
        if(A[z][s] == 1){
          printf("|Y");
        }else{
          printf("|N");
        }
      }
      printf("|\n");
    }
    printf("+");
    for(int p = 0; p<plus; p++) printf("-");
    printf("+\n");
  }
  return 0;
}
