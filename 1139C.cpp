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
#define MOD 1000000007
#define x real()
#define y imag()

typedef long long ll;
typedef vector <ll> vi;
typedef pair <ll,ll> pii;
typedef complex <double> point;

ll MAX(ll a,ll b){
	if(a>b)return a;
	return b;
}

ll MIN(ll a,ll b){
	if(a<b)return a;
	return b;
}

ll gcd(ll a,ll b){
	if(a%b==0) return b;
	else return gcd(b,a%b);
}

ll lcd(ll a,ll b){
	return a*b/gcd(a,b);
}

vector <pii> grafo[200000];
bool passou[200000];
int comp;

void dfs(ll v){
	
	comp++;
	passou[v] = true;
	
	for(int i=0;i<grafo[v].size();i++){
		
		ll adj = grafo[v][i].first;
		ll cor = grafo[v][i].second;
		
		if(!passou[adj] && !cor){
			dfs(adj);
		}	
			
	}
	
}

ll modExpo(ll v,ll exp){
	
	if(exp==0) return 1;
	if(exp==1) return v%MOD;
	
	ll ans = modExpo(v,exp/2);
	ans = (ans*ans)%MOD;

	if(exp%2!=0){
		ans = (ans * (v%MOD))%MOD;
	}
	
	return ans;
	
}

int main(){
	
	FASTIO;
	TIE;
	
	ll n,m;
	
	cin >> n >> m;
	
	for(int i=0;i<n-1;i++){
		
		int a,b,c;
		
		cin >> a >> b >> c;
		
		grafo[a].push_back(mp(b,c));
		grafo[b].push_back(mp(a,c));
		
	}
	
	ll ans = 0;
	
	for(int i=1;i<=n;i++){
		
		if(!passou[i]){
			
			comp = 0;
			dfs(i);
		
			ans = (ans + modExpo(comp,m))%MOD;
		
		}
		
	}
	
	ll all = modExpo(n,m);
	
	all = (all + (MOD-ans))%MOD;
	
	cout << all << endl;
	
	return 0;
}