#include <bits/stdc++.h>
#define MAX_V 50050
#define next iuahdfuioahds

using namespace std;

bool visited[MAX_V], useless[MAX_V];
int next[MAX_V], can_reach[MAX_V];

int dfs(int v) {
    if(can_reach[v]) return can_reach[v];
    return can_reach[v] = dfs(next[v]) + 1;
}

int main(){
  int n, ng, ini_v, las_v, counter=1;
  scanf("%d", &n);
  while(n--){
    scanf("%d", &ng);
    for(int i=1; i<=ng; i++){
      scanf("%d %d", &ini_v, &las_v);
      next[ini_v] = las_v;
    }
    for(int i=1; i<=ng; i++){
      if(!visited[i]){
        int node = i;
        while(!visited[node]){
          visited[node] = true;
          node = next[node];
        }
        if(!useless[node]){
          int cycle_start = node;
          int cycle_size = 0;
          do{
            cycle_size++;
            node = next[node];
          }while(node != cycle_start);
          cycle_start = node;
          do{
            can_reach[node] = cycle_size;
            node = next[node];
          }while(node != cycle_start);
        }
        node = i;
        while(!useless[node]){
          useless[node] = true;
          node = next[node];
        }
      }
    }
    int popular_node = -1, max_reach = 0;
    int reach = 0;
    for(int i=1; i<=ng; i++){
      reach = dfs(i);
      if(reach > max_reach){
        max_reach = reach;
        popular_node = i;
      }
    }
    memset(can_reach, 0, sizeof can_reach);
    memset(visited, false, sizeof visited);
    memset(useless, false, sizeof useless);
    printf("Case %d: %d\n", counter, popular_node);
    counter++;
  }
  return 0;
}
