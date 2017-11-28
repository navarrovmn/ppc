#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int t, count=1, subs, D, tim;
  string subject;
  unordered_map<string, int> sub;

  cin >> t;
  while(t--){
    sub.clear();
    cout << "Case " << count << ": ";
    count++;

    cin >> subs;
    while(subs--){
      cin >> subject >> tim;
      sub[subject] = tim;
    }
    cin >> D;
    cin >> subject;
    if(sub.find(subject) != sub.end()){
      if(sub[subject] <= D){
        cout << "Yesss" << endl;
      }else if(sub[subject] > D && sub[subject] <= D+5){
        cout << "Late" << endl;
      }else{
        cout << "Do your own homework!" << endl;
      }
    }else{
      cout << "Do your own homework!" << endl;
    }
  }
  return 0;
}
