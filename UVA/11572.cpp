#include <bits/stdc++.h>

using namespace std;

#define MAX 1000010
bool taken[1000010];

int main(){
  ios::sync_with_stdio(false);
  int t, n, aux, counter, repeated, result;
  vector<int> snowflakes;

  cin >> t;

  while(t--){
    snowflakes.clear();
    counter = result = repeated = 0;
    memset(taken, 0, sizeof(taken));
    cin >> n;
    for(int i=0; i<n; i++){
      cin >> aux;
      snowflakes.push_back(aux);

      if(taken[aux]){
        if(counter > result) result = counter;
        while(true){
          if(snowflakes[repeated] == aux) break;
          repeated++;
          counter--;
        }
        repeated++;
      }else{
        taken[aux] = true;
        counter++;
      }
    }
    if(counter > result) result = counter;
    cout << result << endl;
  }
  return 0;
}
