#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int t, m, n, count, aux, count2;
  vector<int> unordered;
  vector<int> ordered;

  cin >> t;
  while(t--){
    cin >> m >> n;
    count = 0;
    count2 = 0;

    while(m--){
      cin >> aux;
      unordered.push_back(aux);
    }

    while(n--) {
      cin >> aux;

      while((int) ordered.size() < aux){
        auto it = lower_bound(ordered.begin(), ordered.end(), unordered[count2]);
        ordered.insert(it, unordered[count2++]);
      }

      cout << ordered[count++] << endl;
    }
    if(t) cout << endl;
    unordered.clear();
    ordered.clear();
  }

  return 0;
}
