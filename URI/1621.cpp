#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
int N, M;
int max_dist;
ii max_point;
char labirinth[505][505];
int dist[505][505];

bool is_valid(ii point){
  if (point.first < 0 || point.second < 0 || point.first >= N || point.second >= M) return false;
  if (labirinth[point.first][point.second] == '#') return false;
  if (dist[point.first][point.second] != -1) return false;
  return true;
}

void bfs_distance(ii point) {
    memset(dist, -1, sizeof dist);
    max_dist = 0;
    max_point = ii(-1, -1);

    auto initial_vertice = point;

    queue<ii> to_visit;
    to_visit.push(initial_vertice);
    dist[point.first][point.second] = 0;

    while(!to_visit.empty()) {
        auto v = to_visit.front();
        to_visit.pop();

        for(int i=0; i<4; i++) {
            auto point_to_be_visited = ii(v.first + dx[i], v.second + dy[i]);
            if(is_valid(point_to_be_visited)){
                  dist[point_to_be_visited.first][point_to_be_visited.second] = dist[v.first][v.second] + 1;
                  if(dist[point_to_be_visited.first][point_to_be_visited.second] > max_dist){
                    max_dist = dist[point_to_be_visited.first][point_to_be_visited.second];
                    max_point = point_to_be_visited;
                  }
                  to_visit.push(ii(point_to_be_visited));
            }
        }
    }
}


int main(){
  char aux;
  ii start_point;
  while(cin >> N >> M, N+M){
    for(int i=0; i<N; i++){
      for(int k=0; k<M; k++){
        cin >> aux;
        labirinth[i][k] = aux;
        if(aux == '.') start_point = ii(i, k);
      }
    }
    bfs_distance(start_point);
    bfs_distance(max_point);
    cout << max_dist << endl;
  }
  return 0;
}
