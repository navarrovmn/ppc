#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> mapping;

void generate_list(){
	queue<string> a;

	string actual;
	int count = 1;
	
	for(char ch = 'a'; ch <= 'z'; ch++) a.push(string(1, ch));

	while(!a.empty()){
		actual = a.front();
		a.pop();

		mapping[actual] = count;
		count++;
		
		if(actual.size() == 5) continue;
		
		for(char ch = actual[actual.size()-1]+1; ch <= 'z'; ch++) a.push(actual+ch);
	}
}


int main(){
	generate_list();
	string test;

	while(getline(cin, test)){
		if(mapping.find(test) != mapping.end()){
			printf("%d\n", mapping[test]);
		}else{
			printf("0\n");
		}
	}	

	return 0;
}
