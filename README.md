```
#include <bits/stdc++.h>
using namespace std;

int n,m;
int r,c;
int x,y;
bool consegue[3000][3000];
bool passou[3000][3000];
string grafo[3000];
int my[] = {1,-1};

bool fora(int y,int x){
	
	if(y<0 || y>n || x<0 || x>m) return true;
	
	return false;
	
}

void dfs(int y,int x,int dir,int esq){
	
	passou[y][x] = true;
	consegue[y][x] = true;
	
	for(int i=0;i<2;i++){
		
		int adjx = x;
		int adjy = y+my[i];
		
		if(!fora(adjy,adjx) && !passou[adjy][adjx] && grafo[adjy][adjx]=='.'){
			
			dfs(adjy,adjx,dir,esq);
			
		}
		
	}
	
	if(!fora(y,x+1) && !passou[y][x+1] && dir > 0 && grafo[y][x+1]=='.'){
		
		dfs(y,x+1,dir-1,esq);
		
	}
	
	if(!fora(y,x-1) && !passou[y][x-1] && esq > 0 && grafo[y][x-1]=='.'){
		
		dfs(y,x-1,dir,esq-1);
		
	}
	
	passou[y][x] = false;
	
}

int main(){
	
	scanf("%d%d",&n,&m);
	scanf("%d%d",&r,&c);
	scanf("%d%d",&x,&y);
	
	for(int i=0;i<n;i++){
		
		cin >> grafo[i];
		
	}
	
	dfs(r-1,c-1,y,x);
	
	int resp = 0;
	
	for(int i=0;i<n;i++){
		for(int c=0;c<m;c++){
			if(consegue[i][c]){
				resp++;
			}
		}
	}
	
	cout << resp << endl;
	
	return 0;
}
```
