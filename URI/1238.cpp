#include <bits/stdc++.h>

using namespace std;

int main(){
	char a[50], b[50];
	int n, m;
	scanf("%d", &n);
	for(int i=0; i<n; ++i){
		scanf("%s %s", a, b);
		int s1 = strlen(a);
		int s2 = strlen(b);
		m = max(s1, s2);
		for(int j=0; j<m; ++j){
			if(j<s1) printf("%c", a[j]);
			if(j<s2) printf("%c", b[j]);
		}
		printf("\n");
	}
	return 0;
}
