#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000009
#define P system("pause")

ll modExpo(ll v,ll exp){
	
	if(exp==0) return 0;
	if(exp==1) return v%MOD;
	
	ll ans = modExpo(v,exp/2);
	ans = ((ans%MOD)*(ans%MOD))%MOD;
	
	if(exp%2!=0){
		ans = (ans*(v%MOD))%MOD;
	} 
	
	return ans;
	
}

ll MAX(ll a,ll b){
	if(a>b)return a;
	return b;
}

ll MIN(ll a,ll b){
	if(a<b)return a;
	return b;
}

int main(){
	
	ll n,m,k;
	
	cin >> n >> m >> k;
	
	ll ans = MIN(n%k,m);
	m -= MIN(n%k,m);
	
	ll dobra = MAX(0,m-((k-1)*(n/k)));
	
	ans += ((((modExpo(2,dobra+1)+1000000007)*k)%MOD) + ((m - (dobra*k))%MOD))%MOD;
	
	cout << ans << endl;
	
	return 0;
}