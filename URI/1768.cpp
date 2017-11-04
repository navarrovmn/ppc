#include <bits/stdc++.h>

using namespace std;

int main(){
	int tree, spaces=0, aux=0, asterisco=1;
	string answ;
	while(scanf("%d", &tree) != EOF){
		spaces = tree/2;
		aux = spaces;
		aux++;
		while(aux--){
			answ.append(aux, ' ');
			answ.append(asterisco, '*');
			answ += "\n";
			printf("%s", answ.c_str());
			asterisco+=2;
			answ.clear();	
		}
		answ.append(spaces, ' ');
		answ.append(1, '*');
		answ += "\n";
		printf("%s", answ.c_str());
		answ.clear();
		spaces --;
		answ.append(spaces, ' ');
		answ.append(3, '*');
		answ += "\n";
		printf("%s", answ.c_str());
		answ.clear();
		asterisco=1;
		printf("\n");
	}
	return 0;	
}
