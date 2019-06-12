#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f[2010][2010];
vector <ll> divisores[2010];

#define MOD (((ll)1e9)+7)

ll solve(ll n,ll k){
	if(f[n][k]!=-1)return f[n][k];
	if(k==1)return f[n][k] = 1;
	ll ans = 0;
	for(ll i=0;i<divisores[n].size();i++){//log n
		ans = (ans + solve(divisores[n][i],k-1))%MOD;
	}
	return f[n][k] = ans;
}

int main(){
	
	memset(f,-1,sizeof(f));
	
	ll n,k;cin >> n >> k;
	
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=sqrt(i);j++){
			if(i%j==0){
				if(i/j != j){divisores[i].push_back(i/j);divisores[i].push_back(j);}
				else divisores[i].push_back(j);
			}
		}
	}
	
	ll ans = 0;
	
	for(ll i=1;i<=n;i++) ans = (ans + solve(i,k))%MOD;
	
	cout << ans << endl;
		
	return 0;
}