#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD ((ll)(1e9+7))

ll cont[3];
ll f[200100][3];
ll n,l,r;

ll solve(ll n,ll k){
	if(f[n][k]!=-1)return f[n][k];
	if(n==1)return f[n][k] = cont[k];
	return f[n][k] = ((((solve(n-1,0)*cont[(k-0+3)%3])%MOD) + ((solve(n-1,1)*cont[(k-1+3)%3])%MOD))%MOD + (solve(n-1,2)*cont[(k-2+3)%3]))%MOD;
}

int main(){
	
	memset(f,-1,sizeof f);
	
	cin >> n >> l >> r;
	
	cont[0] = (r+0)/3 - (l-1)/3;
	cont[2] = (r+1)/3 - (l-0)/3;
	cont[1] = (r+2)/3 - (l+1)/3;
	
	cout << solve(n,0) << endl;
	
	return 0;
}