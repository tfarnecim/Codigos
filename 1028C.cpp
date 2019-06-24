#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF ((ll)1e18)
#define INV -INF

struct rect{
	ll x1,y1,x2,y2;
};

ll MAX(ll a,ll b){return a>b?a:b;}
ll MIN(ll a,ll b){return a<b?a:b;}

rect intersection(rect a,rect b){

	if(a.x1 == INV && a.y1 == INV && a.x2 == INV && a.y2 == INV) return a;
	if(b.x1 == INV && b.y1 == INV && b.x2 == INV && b.y2 == INV) return b;
	
	rect ans;
	
	ans.x1 = MAX(a.x1,b.x1);
	ans.y1 = MAX(a.y1,b.y1);
	ans.x2 = MIN(a.x2,b.x2);
	ans.y2 = MIN(a.y2,b.y2);
	
	if(ans.x1 > ans.x2 || ans.y1 > ans.y2){
		return ans = {-INF,-INF,-INF,-INF};
	}
	
	return ans;
}

rect prefix[135674];
rect sufix[135674];

int main(){
	
	ll n;
	
	cin >> n;
	
	rect a[n+1];
	
	for(ll i=1;i<=n;i++) cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
	
	prefix[0] = {-INF,-INF,INF,INF};
	sufix[n+1] = {-INF,-INF,INF,INF};	

	for(ll i=1;i<=n;i++) prefix[i] = intersection(prefix[i-1],a[i]);
	for(ll i=n;i>=1;i--) sufix[i]  = intersection( sufix[i+1],a[i]);

	for(int i=1;i<=n;i++){
		
		if( sufix[i+1].x1 == INV &&  sufix[i+1].y1 == INV &&  sufix[i+1].x2 == INV &&  sufix[i+1].y2 == INV) continue;
		if(prefix[i-1].x1 == INV && prefix[i-1].y1 == INV && prefix[i-1].x2 == INV && prefix[i-1].y2 == INV) continue;

		rect ans = intersection(sufix[i+1],prefix[i-1]);
		
		if(ans.x1 == INV && ans.y1 == INV && ans.x2 == INV && ans.y2 == INV) continue;
		
		cout << ans.x1 << " " << ans.y1 << endl;
		return 0;
	}
			
	return 0;
}