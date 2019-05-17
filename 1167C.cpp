#include <bits/stdc++.h>
using namespace std;

vector <int> grafo[500100];
bool passou[500100];
int idcomp[500100];
int ncomp[500100];
int cont;

void dfs(int v,int id){
	cont++;
	passou[v]=true;
	idcomp[v]=id;
	for(int i=0;i<grafo[v].size();i++){
		int adj = grafo[v][i];
		if(!passou[adj]){
			dfs(adj,id);
		}
	}
}

int main(){
	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	int n,m;
	
	cin >> n >> m;
	
	for(int i=0;i<m;i++){
		
		int k;
		
		cin >> k;
		
		int group[k];
		
		for(int j=0;j<k;j++) cin >> group[j];
		
		for(int j=0;j<k-1;j++){
			grafo[group[j]].push_back(group[j+1]);grafo[group[j+1]].push_back(group[j]);
		}
			
	}
	
	int comp = 0;
	
	for(int i=1;i<=n;i++){
		if(!passou[i]){
			cont = 0;
			dfs(i,comp);
			ncomp[comp] = cont;
			comp++;
		}
	}
	
	for(int i=1;i<=n;i++) cout << ncomp[idcomp[i]] << " ";
	
	cout << endl;
	
	return 0;
}