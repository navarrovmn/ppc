#include <bits/stdc++.h>

using namespace std;

int main(){
	char nome[25];
	vector<int> answer;
	unordered_map<char, int> keys;
	keys['B'] = 1;
	keys['F'] = 1;
	keys['P'] = 1;
	keys['V'] = 1;
	keys['C'] = 2;
	keys['G'] = 2;
	keys['J'] = 2;
	keys['K'] = 2;
	keys['Q'] = 2;
	keys['S'] = 2;
	keys['X'] = 2;
	keys['Z'] = 2;
	keys['D'] = 3;
	keys['T'] = 3;
	keys['L'] = 4;
	keys['M'] = 5;
	keys['N'] = 5;
	keys['R'] = 6;
	
	while(scanf("%s", nome) != EOF){
		for(unsigned int i=0; i<strlen(nome); i++){
			if(i==0){
				if(keys.find(nome[i])!=keys.end()){	
					answer.push_back(keys[nome[i]]);
				}
				continue;
			}
			if(keys.find(nome[i])!=keys.end()){
				if(keys.find(nome[i-1])!=keys.end()){
					if(keys[nome[i]] != keys[nome[i-1]]){
						answer.push_back(keys[nome[i]]);
					}
				}else{
					answer.push_back(keys[nome[i]]);	
				}
			}
		}
		for(int j=0; j<(int)answer.size(); j++){
			printf("%d", answer[j]);
		}
		printf("\n");
		answer.clear();
	}
	return 0;	
}
