#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,b,c,time;
	scanf("%d %d %d", &a, &b, &c);
	time = (a+b+c)%24;
	if(time<0) time= 24+time;
	printf("%d\n", time);
	return 0;	
}
