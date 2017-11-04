#include <bits/stdc++.h>

using namespace std;

int main(){
	double result;
	int n;
	scanf("%d", &n);
	result = (pow(((1 + sqrt(5))/2.0), n) - pow(((1 - sqrt(5))/2.0), n))/sqrt(5);
	printf("%.1f\n", result);
	return 0;	
}
