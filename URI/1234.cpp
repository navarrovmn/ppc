#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	int last=0;
	while(getline(cin, s)){
		last = 0;
		for(int i=0; i<s.size(); ++i){
			if(s[i]==' '){
				printf(" ");
				continue;
			}
			if(last==0){
				printf("%c", toupper(s[i]));
				last = 1;
			}else{
				printf("%c", tolower(s[i]));
				last = 0;
			}
		}
		printf("\n");
	}
	return 0;	
}
