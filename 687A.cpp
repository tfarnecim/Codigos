#include <bits/stdc++.h>
using namespace std;

int tipo[1000100];
vector <int> grafo[1000100];
bool passou[1000100];
bool errado;

void dfs(int v,int t){
	passou[v] = true;
	tipo[v] = t;
	//cout << "TIPO[" << v << "] = " << t << endl;
	for(int i=0;i<grafo[v].size();i++){
		int adj = grafo[v][i];
		if(!passou[adj]){
			dfs(adj,1-t);
		}else if(passou[adj] && tipo[adj]==tipo[v]){
			//cout << "ARESTA " << v << " " << adj << endl;
			errado = true;
		}
	}
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	
	cin >> n >> m;
	
	for(int i=0;i<m;i++){
		int a,b;cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}
	
	for(int i=1;i<=n;i++){
		if(!passou[i]){
			dfs(i,0);
		}
	}
	
	if(errado){
		cout << -1 << endl;
		return 0;
	}
	
	vector <int> ans1,ans2;
	
	for(int i=1;i<=n;i++){
		if(tipo[i]){
			ans1.push_back(i);
		}else{
			ans2.push_back(i);
		}
	}
	
	cout << ans1.size() << endl;
	
	for(int i=0;i<ans1.size();i++){
		cout << ans1[i] << " ";
	}
	
	cout << endl;
	
	cout << ans2.size() << endl;
	
	for(int i=0;i<ans2.size();i++){
		cout << ans2[i] << " ";
	}
	
	cout << endl;
	
	return 0;
}