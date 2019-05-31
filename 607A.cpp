#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF (ll)1e18

struct beacon{ll i,range;};
bool comp(beacon ant,beacon dps){return ant.i < dps.i;}

vector <ll> grafo[100010];
bool passou[100010];
ll dis[100010];

void dfs(ll v){
	passou[v]=true;
	for(ll i=0;i<grafo[v].size();i++){
		ll adj=grafo[v][i];
		if(!passou[adj]){
			dis[adj] = dis[v]+1;
			dfs(adj);
		}
	}
}

int main(){
	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;cin >> n;
	
	beacon a[n];
	
	for(ll i=0;i<n;i++) cin >> a[i].i >> a[i].range;
	
	if(n==1){
		cout << 0 << endl;
		return 0;
	}
	
	sort(a,a+n,comp);

	ll destroi[n];

	for(ll i=n-1;i>=0;i--){
		ll busca = a[i].i-a[i].range;
		ll ini = 0;
		ll fim = n-1;
		while(fim - ini > 0){
			ll mid = (fim+ini)/2;
			if(a[mid].i >= busca){
				fim = mid;
			}else{
				ini = mid+1;
			}
		}
		destroi[i] = i-ini;
	}
	
	for(ll i=n-1;i>=1;i--){
		if(i-1-destroi[i] >= 0){
			grafo[i].push_back(i-1-destroi[i]);grafo[i-1-destroi[i]].push_back(i);
		}
	}
	
	for(ll i=0;i<n;i++){
		if(!passou[i]){
			dis[i] = 1;
			dfs(i);
		}
	}
	
	ll mini = n-dis[n-1];
	ll pos = (n-2);
	
	for(ll i=1;i<n;i++){
		ll destruidos = pos+1-dis[pos];
		mini = min(mini,destruidos+i);
		pos--;
	}
	
	mini = min(mini,n);
	
	cout << mini << endl;
	
	return 0;
}