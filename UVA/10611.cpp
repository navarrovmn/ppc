#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int monk, aux;
  vector<int> heights;
  cin >> monk;
  while(monk--){
    cin >> aux;
    heights.push_back(aux);
  }
  cin >> monk;
  while(monk--){
    cin >> aux;
    auto low = lower_bound(heights.begin(), heights.end(), aux);
    auto up = upper_bound(heights.begin(), heights.end(), aux);
    if(low != heights.begin()){
      low--;
      cout << *low;
    }else{
      cout << "X";
    }
    cout << " ";
    if(up != heights.end()){
      cout << *up;
    }else{
      cout << "X";
    }
    cout << endl;
  }
  return 0;
}
