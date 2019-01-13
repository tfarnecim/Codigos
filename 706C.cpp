#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll c[200000];
string s[200000];

ll dp[200000][2];

ll MIN(ll a,ll b){
	
	if(a<b)return a;
	return b;

}

string reverte(string s){
	
	string saida;
	
	for(int i=s.length()-1;i>=0;i--) saida+=s[i];
	
	return saida;
	
}

bool maior(string a, string b){//retorna se a é maior ou igual que b
	
	ll mini = min(a.length(),b.length());
	
	for(ll i=0;i<mini;i++){
		if(a[i]>b[i]){
			return true;
		}else if(a[i]<b[i]){
			return false;
		}
	}
	
	if(a.length() >= b.length()){
		return true;
	}else{
		return false;
	}
	
}

ll solve(ll i,ll j){
	
	if(dp[i][j]!=-1) return dp[i][j];
	
	ll minimo_i = 500000000000000;
	ll minimo_n = 500000000000000;
	
	string usa;
	
	if(j){
		usa = reverte(s[i]);
	}else{
		usa = s[i];
	}
	string t_i = reverte(s[i-1]);
	string t_n = s[i-1];
	
	if(maior(usa,t_i)){	
		minimo_i = MIN(minimo_i,solve(i-1,1));	
	}
	if(maior(usa,t_n)){
		minimo_n = MIN(minimo_n,solve(i-1,0));
	}
	
	ll v = 0;
	
	if(j){
		v+=c[i];
	}
	
	dp[i][j] = MIN(minimo_i+v,minimo_n+v);
	
	return dp[i][j];
	
}

int main(){
	
	ll n;
	
	cin >> n;
	
	for(ll i=1;i<=n;i++) cin >> c[i];
	
	for(ll i=1;i<=n;i++) cin >> s[i];
	
	memset(dp,-1,sizeof(dp));
	
	dp[1][0] = 0;
	dp[1][1] = c[1];
	
	ll res = MIN(solve(n,0),solve(n,1));
	
	if(res >= 500000000000000){
		cout << -1 << endl;
	}else{
		cout << res << endl;
	}
	
	return 0;
}