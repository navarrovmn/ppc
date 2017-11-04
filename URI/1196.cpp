#include <bits/stdc++.h>

using namespace std;

int main(){
	string in;
	unordered_map<char, char> a;
	a['1'] = '`';
	a['S'] = 'A';
	a['O'] = 'I';
	a['D'] = 'S';
	a['F'] = 'D';
	a['G'] = 'F';
	a['H'] = 'G';
	a['J'] = 'H';
	a['K'] = 'J';
	a['L'] = 'K';
	a[';'] = 'L';
	a['\''] = ';';
	a['W'] = 'Q';
	a['E'] = 'W';
	a['R'] = 'E';
	a['T'] = 'R';
	a['Y'] = 'T';
	a['U'] = 'Y';
	a['I'] = 'U';
	a['P'] = 'O';
	a['['] = 'P';
	a[']'] = '[';
	a['\\'] = ']';
	a['X'] = 'Z';
	a['C'] = 'X';
	a['V'] = 'C';
	a['B'] = 'V';
	a['N'] = 'B';
	a['M'] = 'N';
	a[','] = 'M';	
	a['/'] = '.';
	a['.'] = ',';
	a['2'] = '1';
	a['3'] = '2';
	a['4'] = '3';
	a['5'] = '4';
	a['6'] = '5';
	a['7'] = '6';
	a['8'] = '7';
	a['9'] = '8';
	a['0'] = '9';
	a['-'] = '0';
	a['='] = '-';
	while(getline(cin, in)){
		for(unsigned i=0; i<in.size(); i++){
			if(in[i] != ' ' && in[i] != '\n'){
				in[i] = a[in[i]];
			}
		}
		printf("%s\n", in.c_str());	
	}
	return 0;	
}
