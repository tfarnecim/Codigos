#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll tree[500000];
ll lazy[500000];

ll arr[200000];

void build(ll no,ll l,ll r){
	if(l==r){
		tree[no] = arr[l];
		return ;
	}
	ll mid = (l+r)/2;
	build(no*2,l,mid);
	build(no*2+1,mid+1,r);
	tree[no] = tree[no*2] + tree[no*2+1];
}

void propagate(ll no,ll l,ll r){
	if(l!=r){
		lazy[no*2] += lazy[no];
		lazy[no*2+1] += lazy[no];
	}
	tree[no] += (r-l+1)*lazy[no];
	lazy[no] = 0;
}

void update(ll no,ll l,ll r,ll x,ll y,ll v){
	propagate(no,l,r);
	if(r < x || y < l){
		return ;
	}
	if(x <= l && r <= y){
		tree[no]+=(r-l+1)*v;
		if(l!=r){
			lazy[no*2] += v;
			lazy[no*2+1] += v;
		}
		return;
	}
	ll mid = (l+r)/2;
	update(no*2,l,mid,x,y,v);
	update(no*2+1,mid+1,r,x,y,v);
	tree[no] = tree[no*2] + tree[no*2+1];
	return;
}

ll query(ll no,ll l,ll r,ll x,ll y){
	propagate(no,l,r);
	if(r < x || y < l){
		return 0;
	}
	if(x <= l && r <= y){
		return tree[no];
	}
	ll mid = (l+r)/2;
	ll r1 = query(no*2,l,mid,x,y);
	ll r2 = query(no*2+1,mid+1,r,x,y);
	return r1+r2;
}

int main(){
	
	ll n,q;
	
	cin >> n >> q;
	
	for(ll j=0;j<n;j++){
		cin >> arr[j];
	}
	
	build(1,0,n-1);
	
	memset(lazy,0,sizeof lazy);
	memset(tree,0,sizeof tree);
	
	for(ll j=0;j<q;j++){
		
		ll a;
		
		cin >> a;
		
		if(!a){
			
			ll l,r,v;
			
			cin >> l >> r >> v;
			
			update(1,0,n-1,l-1,r-1,v);
			
		}else{
			
			ll l,r;
			
			cin >> l >> r;
			
			cout << query(1,0,n-1,l-1,r-1) << endl;
			
		}
	}

	return 0;
}