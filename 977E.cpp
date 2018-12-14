#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

vector <ll> grafo[300000];
bool encontrou[300000];
vector <ll> passou;

void dfs(int v){
	
	passou.pb(v);
	encontrou[v] = true;
	
	for(int i=0;i<grafo[v].size();i++){
		
		ll adj = grafo[v][i];
		
		if(!encontrou[adj]){
			
			dfs(adj);
			
		}
		
	}
	
}

int main(){
	
	int n,m;
	
	cin >> n >> m;
	
	for(int i=0;i<m;i++){
		
		ll a,b;
		
		cin >> a >> b;
		
		grafo[a].pb(b);
		grafo[b].pb(a);
				
	}
	
	ll ans = 0;
	
	for(int i=1;i<=n;i++){
		
		if(!encontrou[i]){
			
			passou.clear();
			
			dfs(i);
			
			bool So2 = true;
			
			for(int i=0;i<passou.size();i++){
				
				if(grafo[ passou[i] ].size() != 2){
					So2 = false;
					break;
				}
				
			}
			
			if(So2){
				ans++;
			}
			
		}
		
	}
	
	cout << ans << endl;
	
	return 0;
}