#include <bits/stdc++.h>
using namespace std;

//biblioteca
#define INF  1000000000
#define INFL 1000000000000000000
#define mp make_pair
#define alfa "abcdefghijklmnopqrstuvwxyz"
#define FASTIO ios::sync_with_stdio(false)
#define TIE cin.tie(NULL)
#define P system("pause")
#define PI 3.14159265358

typedef long long ll;
typedef vector <ll> vi;
typedef pair <ll,ll> pii;

ll MAX(ll a,ll b){
	if(a>b)return a;
	return b;
}

ll MIN(ll a,ll b){
	if(a<b)return a;
	return b;
}

vi grafo[200000];
bool passou_solve[200000];
bool passou[200000];
int dis[200000];
int res;
bool ini[200000];
bool fim[200000];
vi out;

void dfs(int v){
	
	passou[v] = true;
	
	for(int i=0;i<grafo[v].size();i++){
		
		int adj = grafo[v][i];
		
		if(!passou[adj]){
			dis[adj] = dis[v]+1;
			dfs(adj);
		}
		
	}
	
}

void dfs_solve(int v,int mi,int mp){
	
	passou_solve[v] = true;
	
	bool aux = ini[v];
	
	if(dis[v]%2==0){
	
	    if((ini[v]==fim[v] && mp%2!=0) || (ini[v]!=fim[v] && mp%2==0)){
			mp++;
			out.push_back(v);
		}
		
	}else{
		
		if((ini[v]==fim[v] && mi%2!=0) || (ini[v]!=fim[v] && mi%2==0)){
			mi++;
			out.push_back(v);
		}
		
	}
	
	for(int i=0;i<grafo[v].size();i++){
		
		int adj = grafo[v][i];
		
		if(!passou_solve[adj]){
			dfs_solve(adj,mi,mp);
		}
		
	}
	
}

int main(){
	
	FASTIO;
	
	int n;
	
	cin >> n;
	
	for(int i=0;i<n-1;i++){
		
		int a,b;
		
		cin >> a >> b;
		
		grafo[a].push_back(b);
		grafo[b].push_back(a);
		
	}
	
	dfs(1);
	
	for(int i=1;i<=n;i++) cin >> ini[i];
	for(int i=1;i<=n;i++) cin >> fim[i];
		
	dfs_solve(1,0,0);
	
	cout << out.size() << endl;
	
	for(int i=0;i<out.size();i++){
		cout << out[i] << "\n";
	}

	return 0;
}