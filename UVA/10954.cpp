#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  priority_queue<int, vector<int>, greater<int>> num;
  int n, cost, aux;

  while(cin >> n, n){
    cost = 0;
    while(n--){
      cin >> aux;
      num.push(aux);
    }

    while(num.size() != 1){
      int a = num.top();
      num.pop();
      int b = num.top();
      num.pop();
      cost += a+b;
      num.push(a+b);
    }
    num.pop();
    cout << cost << endl;
  }
  return 0;
}
