#include <bits/stdc++.h>

using namespace std;

int main(){
  string name;
  cin >> name;

  set<char> dn(begin(name), end(name));

  if(dn.size() % 2){
    cout << "IGNORE HIM!" << endl;
  }else{
    cout << "CHAT WITH HER!" << endl;
  }

  return 0;
}
