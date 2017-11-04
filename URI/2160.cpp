#include <bits/stdc++.h>

using namespace std;

int main(){
	string nome;
	getline(cin, nome);
	if(nome.size() <= 80){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	return 0;	
}
