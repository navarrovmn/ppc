#include <bits/stdc++.h>

using namespace std;

#define MAX_V 25

vector<int> G[MAX_V];
bool visited[MAX_V];
unordered_map<int, string> qualifications;
int many_visited;

void dfs(int v) {
    visited[v] = true;

    for(auto i: G[v])
        if (!visited[i])
            dfs(i);
}

int main(){
  ios::sync_with_stdio(false);
  int N, aux, spammer, t1, t2;
  string a1, a2, a3, name;

  while(cin >> N, N){
    for(int i=1; i<=N; i++){
      while(cin >> aux, aux){
        G[i].push_back(aux);
      }
    }

    while(cin >> spammer, spammer){
      many_visited = 0;
      cin >> t1 >> t2 >> a1 >> a2 >> a3;
      memset(visited, 0, sizeof visited);
      dfs(spammer);
      for(int k=1; k<=N; k++){
        if(visited[k]){
          int queue_size = G[k].size();
          if(queue_size < t1){
            qualifications[k] += " " + a1;
          }
          if(queue_size < t2 && queue_size >= t1){
            qualifications[k] += " " + a2;
          }
          if(queue_size >= t2){
            qualifications[k] += " " + a3;
          }
        }else{
          qualifications[k] += " " + a1;
        }

      }
    }

    for(int i=1; i<=N; i++){
      cin >> name;
      cout << name << ":" << qualifications[i] << " " << endl;
    }

    memset(G, 0, sizeof G);
    qualifications.clear();
  }
  return 0;
}
