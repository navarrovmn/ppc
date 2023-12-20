#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;

int main() {
    vector<string> k = {"huguinho", "zezinho", "luisinho"};
    vector <int> a, b;

    for(int i=0; i<3; i++) {
        int tmp;
        cin >> tmp;

        a.push_back(tmp);
        b.push_back(tmp);
    }
    sort(a.begin(), a.end());

    int result = a[1];
    for(int i=0; i<3; i++) {    
        if(b[i] == result) {
            cout << k[i] << endl;
        }
    }

    return 0;
}
