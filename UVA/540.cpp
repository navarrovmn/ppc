#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> team_mapping;
queue<int> geral_queue;
queue<int> teams[1000];

int main(){
	int t, counter=0, aux, tmp, bt;
	string a;

	while(scanf("%d", &t), t){
		team_mapping.clear();
		for(int k=0; k<t; k++){
			while(! teams[k].empty()) teams[k].pop();
		}
		while(!geral_queue.empty()) geral_queue.pop();

		if(counter) printf("\n");
		counter++;

		printf("Scenario #%d\n", counter);

		for(int i=0; i<t; i++){
			scanf("%d", &aux);
			while(aux--){
				scanf("%d", &tmp);
				team_mapping[tmp] = i;	
			}
		}
		
		do{
			cin >> a;
			if(a[0] == 'E'){
				scanf("%d", &tmp);
				bt = team_mapping[tmp];
				if(teams[bt].empty()) geral_queue.push(bt);
				teams[bt].push(tmp);	
				
			}
			
			if(a[0] == 'D'){
				bt = geral_queue.front();
				aux = teams[bt].front();
				printf("%d\n", aux);
				teams[bt].pop();
				if(teams[bt].empty())	geral_queue.pop();
			}
		}while(a[0] != 'S');

	}
	printf("\n");
	return 0;
}
