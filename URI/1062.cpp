#include <bits/stdc++.h>

using namespace std;

int v[1050];

int main(){
  int n;
  ios::sync_with_stdio(false);
  while(cin >> n, n){
      while(cin >> v[0], v[0]){
        int current = 0;
        stack<int> p;

        for(int i=1; i<n; i++) cin >> v[i];

        for(int i=1; i<=n; i++){
          p.push(i);

          while(p.size() && v[current] == p.top()){
            current++;
            p.pop();
          }
        }
        cout << (p.size()? "No" : "Yes") << endl;
      }
      cout << endl;
  }
  return 0;
}
