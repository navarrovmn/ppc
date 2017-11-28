#include <bits/stdc++.h>

using namespace std;

string is_jolly(vector<int> sequence){
	vector<int> track;
		for(int i=0; i< (int) sequence.size() - 1; i++){
			int result = abs(sequence[i] - sequence[i+1]);
			if(result == 0 || result >= (int) sequence.size() || find(track.begin(), track.end(), result) != track.end()){
				return "Not jolly\n";
			}
			track.push_back(result);
		}
		return "Jolly\n";
}


int main(){
	int t, tmp;
	vector<int> sequence;

	while(scanf("%d", &t) != EOF){
		sequence.clear();
		while(t--){
			scanf("%d", &tmp);
			sequence.push_back(tmp);
		}
		printf("%s", is_jolly(sequence).c_str());	
	}
	return 0;
}
