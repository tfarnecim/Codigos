#include <bits/stdc++.h>
using namespace std;

long long tree[600000];
long long arr[300000];

void build(long long l,long long r,long long no){
	
	if(l==r){
		tree[no] = arr[l];
		return ;
	}
	
	long long mid = (l+r)/2;
	
	build(l,mid,no*2);
	build(mid+1,r,no*2+1);
	
	tree[no] = tree[no*2] * tree[no*2+1];
	
	return ;
	
}

void update(long long l,long long r,long long no,long long v,long long idx){
	
	if(l==r){
	
		tree[no] = v;
		arr[idx] = v;
		return ;
			
	}
	
	long long mid = (l+r)/2;
	
	if(l <= idx && idx <= mid){
		
		update(l,mid,no*2,v,idx);
		
	}else{
		
		update(mid+1,r,no*2+1,v,idx);
		
	}
	
	tree[no] = tree[no*2] * tree[no*2+1];
	
}

long long query(long long l,long long r,long long no,long long x,long long y){
	
	if(y < l || r < x){
	
		return 1;
			
	}else if(x <= l && r <= y){
		
		return tree[no];
		
	}
	
	long long mid = (l+r)/2;
	
	long long r1 = query(l,mid,no*2,x,y);
	long long r2 = query(mid+1,r,no*2+1,x,y);
	
	return r1 * r2;
	
}

int main(){
	
	long long n,k;
	
	cin >> n >> k;
		
	for(long long i=0;i<n;i++){
		
		cin >> arr[i];
		
	}
	
	string s;
	
	build(0,n-1,1);
	
	for(long long i=0;i<k;i++){
		
		char q;
		long long a,b;
		
		cin >> q >> a >> b;
		
		if(q=='P'){
			
			long long resp = query(0,n-1,1,a-1,b-1);
			
			if(resp > 0){
				
				s+='+';
				
			}else if(resp < 0){
				
				s+='-';
				
			}else{
				
				s+='0';
				
			}
			
		}else{
			
			update(0,n-1,1,b,a-1);
			
		}
		
	}
	
	cout << s << endl;
	
	return 0;
}