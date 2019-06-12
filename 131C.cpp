#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll binomio[40][40];

ll solve(ll n,ll k){
	if(binomio[n][k]!=-1)return binomio[n][k];
	if(k==0 || k==n)return binomio[n][k] = 1;
	return binomio[n][k] = solve(n-1,k-1) + solve(n-1,k);
}

int main(){
	
	memset(binomio,-1,sizeof binomio);
	
	ll b,g,t;cin >> b >> g >> t;

	ll ans = 0;
	
	for(ll i=1;i<=g;i++) for(ll j=4;j<=b;j++) if(i+j==t) ans += solve(b,j)*solve(g,i);
	
	cout << ans << endl;
		
	return 0;
}