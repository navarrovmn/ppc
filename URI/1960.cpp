#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<string> cent = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
	vector<string> dez = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
	vector<string> uni = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
	
	string a;
	int b;
	scanf("%d", &b);
	int unidade = b%10;
	b /= 10;
	int dezena = b%10;
	b /= 10;
	int centena = b%10;
	
	
	a += cent[centena];
	a += dez[dezena];
	a += uni[unidade];
	
	printf("%s\n", a.c_str());
	return 0;	
}
