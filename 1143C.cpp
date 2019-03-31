#include <bits/stdc++.h>
using namespace std;

vector <int> grafo[200000];
bool mark[200000];
int nivel[200000];
bool passou[200000];

void bfs(int root){
	
	queue <int> fila;
	
	fila.push(root);
	passou[root] = true;
	nivel[root] = 0;
	
	while(!fila.empty()){
		
		int v = fila.front();
		fila.pop();
		
		for(int i=0;i<grafo[v].size();i++){
			
			int adj = grafo[v][i];
			
			if(!passou[adj]){
				passou[adj] = true;
				fila.push(adj);
				nivel[adj] = nivel[v]+1;
			}
			
		}
		
	}
	
}

int main(){
	
	int n;
	
	cin >> n;
	
	int root = -1;
	
	for(int i=1;i<=n;i++){
		
		int a;
		
		cin >> a >> mark[i];
		
		if(a!=-1){
		
			grafo[i].push_back(a);
			grafo[a].push_back(i);
				
		}else{
			
			root = i;
			
		}
		
	}
	
	bfs(root);
	
	vector <int> ans;
	
	for(int i=1;i<=n;i++){
		
		if(i!=root && mark[i]){
			
			bool ok = true;
			
			for(int j=0;j<grafo[i].size();j++){
				
				int adj = grafo[i][j];
				
				if(nivel[adj] > nivel[i] && !mark[adj]){
					ok = false;
					break;
				}
				
			}
			
			if(ok) ans.push_back(i);
			
		}
		
	}
	
	if(ans.size()==0){
		cout << -1 << endl;
		return 0;
	}
	
	for(int i=0;i<ans.size();i++){
		cout << ans[i] << " ";
	}
	
	cout << endl;
	
	return 0;
}