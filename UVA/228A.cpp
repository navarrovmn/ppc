#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  set<int> shoes;
  int shoe, b = 4;

  while(b--){
    cin >> shoe;
    shoes.insert(shoe);
  }

  cout << 4 - shoes.size() << endl;

  return 0;
}
