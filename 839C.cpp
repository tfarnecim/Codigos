#include <bits/stdc++.h>
using namespace std;

vector <int> grafo[200000];
bool passou[200000];
int dis[200000];
double prob[200000];

void bfs(int root){
	queue <int> fila;fila.push(root);passou[root]=true;prob[root]=1;
	while(!fila.empty()){
		int v = fila.front();fila.pop();
		double div = 0;
		for(int i=0;i<grafo[v].size();i++){
			if(!passou[grafo[v][i]]) div++;
		}
		for(int i=0;i<(int)grafo[v].size();i++){
			int adj = grafo[v][i];
			if(!passou[adj]){
				passou[adj] = true;
				dis[adj] = dis[v]+1;
				prob[adj] = prob[v]*(1.0/div);
				fila.push(adj);
			}
		}
	}
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;cin >> n;
	
	for(int i=0;i<n-1;i++){
		int a,b;cin >> a >> b;
		grafo[a].push_back(b);grafo[b].push_back(a);
	}
	
	bfs(1);
	
	double ev = 0;
	
	for(int i=2;i<=n;i++) if(grafo[i].size() < 2) ev += prob[i]*(double)dis[i];
	
	printf("%.10lf\n",ev);
	
	return 0;
}