#include <bits/stdc++.h>

using namespace std;

vector<int> G[50050];
int dist[50050];

pair<int, int> result = make_pair(0, 0);

void bfs_distance(int x) {
  int initial_vertice = x;
  queue<int> to_visit;
  to_visit.push(initial_vertice);
  dist[initial_vertice] = 0;

  while(!to_visit.empty()) {
    auto v = to_visit.front();
    to_visit.pop();

    for (auto i: G[v]) {
      if (dist[i] == -1) {
        dist[i] = dist[v] + 1;
        if(dist[i] > result.second){
          result.first = x;
          result.second = dist[i];
        }
      to_visit.push(i);
      }
    }
  }
}

int main(){
  int n, ng, ini_v, las_v, counter=1;
  scanf("%d", &n);
  while(n--){
    scanf("%d", &ng);
    for(int i=1; i<=ng; i++){
      scanf("%d %d", &ini_v, &las_v);
      G[ini_v].push_back(las_v);
    }
    for(int i=1; i<=ng; i++){
      memset(dist, -1, sizeof dist);
      bfs_distance(i);
    }
    memset(G, 0, sizeof G);
    printf("Case %d: %d\n", counter, result.first);
    result = make_pair(0, 0);
    counter++;
  }
  return 0;
}
