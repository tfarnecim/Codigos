#include <bits/stdc++.h>
using namespace std;

int n,m;
string grafo[200];
bool passou[200][200];

bool dentro(int y,int x){
	
	if(y >= 0 && y < n && x >= 0 && x < m) return true;
	
	return false;
	
}

int my[] = {1,-1,0,0};
int mx[] = {0,0,1,-1};

bool tem_ciclo;

void dfs(int y,int x,int atravessou){
	
	passou[y][x] = true;
	
	for(int i=0;i<4;i++){
		
		int vx,vy;
		
		vx = x+mx[i];
		vy = y+my[i];
		
		//cout << !fora(vy,vx) << " " << passou[vy][vx] << endl;
		
		if(dentro(vy,vx) && !passou[vy][vx] && grafo[vy][vx]==grafo[y][x]){
			
			dfs(vy,vx,atravessou+1);
			
		}else if(dentro(vy,vx) && passou[vy][vx] && grafo[vy][vx]==grafo[y][x] && atravessou + 1 >= 4){
			
			tem_ciclo = true;
			
		}
		
	}
	
	passou[y][x] = false;
	
}

int main(){
	
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		
		cin >> grafo[i];
		
	}
	
	for(int i=0;i<n;i++){
		for(int c=0;c<m;c++){
			dfs(i,c,1);
		}
	}
	
	if(tem_ciclo){
		
		cout << "Yes\n";
		
	}else{
		
		cout << "No\n";
		
	}
	
	return 0;
}