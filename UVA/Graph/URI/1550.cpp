#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

#define MAX_V 1000

unordered_map<int, bool> visited;

int reverse(int a){
  if(a < 10) return a;
  int result = 0, num, aux=a, pot=0;
  while(aux >= 1){
    aux/=10;
    pot++;
  }
  while(pot--){
    num = a%10;
    result += (num*pow(10, pot));
    a/=10;
  }
  return result;
}

void bfs(int a, int b) {
    visited.clear();

    queue<ii> to_visit;
    to_visit.push(make_pair(a, 0));
    visited[a] = true;

    while(!to_visit.empty()) {
        auto v = to_visit.front();
        if(v.first == b){
          printf("%d\n", v.second);
          break;
        }

        to_visit.pop();

        if(!visited[v.first+1]){
          visited[v.first+1] = true;
          to_visit.push(make_pair(v.first+1, v.second+1));
        }
        if(!visited[reverse(v.first)]){
          visited[reverse(v.first)] = true;
          to_visit.push(make_pair(reverse(v.first), v.second+1));
        }

    }
}

int main(){
  int t, a, b;
  scanf("%d", &t);
  while(t--){
    scanf("%d %d", &a, &b);
    bfs(a, b);
  }
  return 0;
}
