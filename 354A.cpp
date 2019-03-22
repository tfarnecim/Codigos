#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll Prefix[200000];
ll Sufix[200000];

int main(){
	
	ll n,l,r,ql,qr;
	
	cin >> n >> l >> r >> ql >> qr;
	
	ll arr[n+1];
	
	for(ll i=1;i<=n;i++) cin >> arr[i];
	
	for(ll i=1;i<=n;i++) Prefix[i] = Prefix[i-1] + (arr[i]*l);
	for(ll i=n;i>=1;i--) Sufix[i] = Sufix[i+1] + (arr[i]*r);
	
	ll ans = 1e18 * 5;

	for(ll i=0;i<=n;i++){
		
		ll at = Prefix[i] + Sufix[i+1];
		
		ll d = i - (n-i);
			
		if(abs(d) > 0){
			if(d < 0){
				at += qr*(abs(d)-1);
			}else{
				at += ql*(abs(d)-1);
			}
		}
			
		if(at < ans){
			ans = at;
		}
		
	}

	cout << ans << endl;

	return 0;
}