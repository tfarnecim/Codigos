#include <bits/stdc++.h>
using namespace std;

int n,m;
string grafo[100];
bool passou[100][100];
int mx[] = {-1,1,0,0};
int my[] = {0,0,-1,1};

bool dentro(int y,int x){
	
	if(y >= 0 && y < n && x >= 0 && x < m) return true;
	
	return false;
	
}

bool dfs(int x,int y,int px,int py){
	
	passou[y][x] = true;
	
	for(int i=0;i<4;i++){
		
		int adjx = x + mx[i];
		int adjy = y + my[i];
		
		if(dentro(adjy,adjx) && !passou[adjy][adjx] && grafo[adjy][adjx]==grafo[y][x]){
			
			if(dfs(adjx,adjy,x,y)) return true;
			
		}else if(dentro(adjy,adjx) && passou[adjy][adjx] && grafo[adjy][adjx]==grafo[y][x] && (adjy!=py && adjx!=px)){
			
			return true;
			
		}
		
	}

	return false;
		
}

int main(){
	
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		
		cin >> grafo[i];
		
	}
	
	bool tem_ciclo = false;
	
	for(int i=0;i<n;i++){
		for(int c=0;c<m;c++){
			
			if(!passou[i][c]){
				
				if(dfs(c,i,-1,-1)){
					//cout << "DFS(" << i << "," << c << ",-1,-1)\n";
					tem_ciclo = true;
					c=m;
					i=n;
					
				}
				
			}
			
		}
	}
	
	if(tem_ciclo){
		
		cout << "Yes\n";
		
	}else{
		
		cout << "No\n";
		
	}
	
	return 0;
}
