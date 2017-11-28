#include <bits/stdc++.h>

using namespace std;

#define MAX_V 20050
#define INF_NUM 100000000

using ii = pair<int, int>;

vector<ii> G[MAX_V];
int distances[MAX_V];

int sssp_dijkstra(int source, int destiny, int N) {
    fill(distances, distances + N + 1, INF_NUM);

    priority_queue< ii, vector<ii>, greater<ii> > to_visit;

    distances[source] = 0;
    to_visit.push(ii(distances[source], source));

    while(!to_visit.empty()) {
        auto d = to_visit.top().first;
        auto v = to_visit.top().second;
        to_visit.pop();

        if (d > distances[v]) continue;

        for(auto i: G[v]) {
            auto i_v = i.first;
            auto i_d = i.second;

            if (distances[v] + i_d < distances[i_v]) {
                distances[i_v]  = distances[v] + i_d;
                to_visit.push(ii(distances[i_v], i_v));
            }
        }
    }

    return distances[destiny];
}

int main(){
  int ct, S, T, n, m, n1, n2, d, count=1;
  ios::sync_with_stdio(false);

  cin >> ct;
  while(ct--){
    cin >> n >> m >> S >> T;
    for(int i=0; i<n; i++) G[i].clear();
    while(m--){
      cin >> n1 >> n2 >> d;
      G[n1].push_back(ii(n2, d));
      G[n2].push_back(ii(n1, d));
    }
    cout << "Case #" << count++ << ": ";
    int best_time = sssp_dijkstra(S, T, n);
    best_time == INF_NUM? cout << "unreachable" : cout << best_time;
    cout << endl;
  }

  return 0;
}
