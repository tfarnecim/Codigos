#include <bits/stdc++.h>
using namespace std;

int n,m;
vector <int> grafo[2000];
bool passou[2000];

bool dfs(int v,int pai){
	
	passou[v] = true;
	
	for(int i=0;i<grafo[v].size();i++){
		
		int adj = grafo[v][i];
	
		if(!passou[adj]){
			
			if(dfs(adj,v)) return true;
			
		}else if(passou[adj] && adj!=pai){
			
			return true;
			
		}
			
	}
	
	return false;
	
}

int main(){
	
	cin >> n >> m;
	
	for(int i=0;i<m;i++){
		
		int a,b;
		
		cin >> a >> b;
		
		grafo[a].push_back(b);
		grafo[b].push_back(a);
		
	}
	
	cout << dfs(1,-1) << endl;
	
	return 0;
}