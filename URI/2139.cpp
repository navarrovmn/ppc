#include <bits/stdc++.h>

using namespace std;

int main(){
	int m, d, t;
	unordered_map<int, int> meses;
	meses[1]=31;
	meses[2]=29;
	meses[3]=31;
	meses[4]=30;
	meses[5]=31;
	meses[6]=30;
	meses[7]=31;
	meses[8]=31;
	meses[9]=30;
	meses[10]=31;
	meses[11]=30;
	meses[12]=25;
	while(scanf("%d %d", &m, &d)!=EOF){
		t = 0;
		if(m == 12 && d == 25){
			printf("E natal!\n");
		}else if(m == 12 && d == 24){
			printf("E vespera de natal!\n");
		}else if(m == 12 && d > 25){
			printf("Ja passou!\n");
		}else{
			if(m == 12){
				printf("Faltam %d dias para o natal!\n", 25-d);	
			}else{
				for(int i=m+1; i<= 12; ++i){
					t+=meses[i];	
				}
				t += meses[m]-d;
				printf("Faltam %d dias para o natal!\n", t);
			}
		}
	}
	return 0;	
}
