#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int frosh;
  int a[5];
  string ab;
  char buffer[20];

  map<string, int> combinations;
  while(cin >> frosh, frosh){
    combinations.clear();
    while(frosh--){
      cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];

      sort(a, a+5);
      sprintf(buffer, "%d%d%d%d%d", a[0], a[1], a[2], a[3], a[4]);
      ab = buffer;

      combinations[ab]++;
    }
	   int maxi = 0, maxicount = 0;
    for(auto it = combinations.begin(); it != combinations.end(); it++){
      if(it->second > maxi)
        maxi = it->second, maxicount = 0;
      if(it->second == maxi)
        maxicount += maxi;
    }
    cout << maxicount << endl;
  }
  return 0;
}
