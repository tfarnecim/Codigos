#include <bits/stdc++.h>
using namespace std;

struct pesquisa{
	
	long long l,r,v;
	
};

long long arr[200000];

long long tree1[300000];
long long tree2[300000];

long long lazy1[3000000];
long long lazy2[3000000];

void propagate2(long long no,long long l,long long r){
	
	tree2[no] += (r-l+1)*lazy2[no];
	
	if(l!=r){
		lazy2[no*2] += lazy2[no];
		lazy2[no*2+1] += lazy2[no];
	}
	
	lazy2[no] = 0;
	
}

void update2(long long no,long long l,long long r,long long x,long long y){
	
	propagate2(no,l,r);
	
	if(r < x || y < l){
		return ;
	}
	if(x <= l && r <= y){
		
		tree2[no] += r-l+1;
		
		if(l!=r){
			lazy2[no*2]++;
			lazy2[no*2+1]++;
		}
		
		return ;
		
	}
	
	long long mid = (l+r)/2;
	
	update2(no*2,l,mid,x,y);
	update2(no*2+1,mid+1,r,x,y);
	
	tree2[no] = tree2[no*2]+tree2[no*2+1];
	
}

long long query2(long long no,long long l,long long r,long long x,long long y){
	
	if(r < x || y < l){
	
		return 0;
	
	}
	
	propagate2(no,l,r);
	
	if(x <= l && r <= y){
		
		return tree2[no];
		
	}
	
	long long mid = (l+r)/2;
	
	long long r1 = query2(no*2,l,mid,x,y);
	long long r2 = query2(no*2+1,mid+1,r,x,y);
	
	return r1 + r2;
	
}

void build1(long long no,long long l,long long r){
	
	if(l==r){
		tree1[no] = arr[l];
		return ;
	}
	
	long long mid = (l+r)/2;
	
	build1(no*2,l,mid);
	build1(no*2+1,mid+1,r);
	
	tree1[no] = tree1[no*2] + tree1[no*2+1];
	
}

void propagate1(long long no,long long l,long long r){
	
	tree1[no] += (r-l+1)*lazy1[no];
	
	if(l!=r){
		lazy1[no*2] += lazy1[no];
		lazy1[no*2+1] += lazy1[no];
	}
	
	lazy1[no] = 0;
	
}

void update1(long long no,long long l,long long r,long long x,long long y,long long v){
	
	propagate1(no,l,r);
	
	if(r < x || y < l){
		return ;
	}
	if(x <= l && r <= y){
		
		tree1[no] += (r-l+1) * v;
	
		if(l!=r){
			
			lazy1[no*2] += v;
			lazy1[no*2+1] += v; 
			
		}
		return;
	}
	
	long long mid = (l+r)/2;
	
	update1(no*2,l,mid,x,y,v);
	update1(no*2+1,mid+1,r,x,y,v);
	
	tree1[no] = tree1[no*2] + tree1[no*2+1];
	
}

long long query1(long long no,long long l,long long r,long long x,long long y){
	
	if(r < x || y < l){
		return 0;
	}
	
	propagate1(no,l,r);
	
	if(x <= l && r <= y){
		
		return tree1[no];
		
	}
	
	long long mid = (l+r)/2;
	
	long long r1 = query1(no*2,l,mid,x,y);
	long long r2 = query1(no*2+1,mid+1,r,x,y);

	return r1 + r2;

}

int main(){
	
	long long n,m,k;
	
	cin >> n >> m >> k;

	for(register long long i=0;i<n;i++){
		
		cin >> arr[i];
		
	}
		
	pesquisa pesquisas[m];
	
	for(register long long i=0;i<m;i++){
		
		cin >> pesquisas[i].l >> pesquisas[i].r >> pesquisas[i].v;  
		
	}
		
	for(register long long i=0;i<k;i++){
		
		long long a,b;
		
		cin >> a >> b;
		
		update2(1,0,m-1,a-1,b-1);
		
	}
	
	build1(1,0,n-1);
	
	for(register long long i=0;i<m;i++){
		
		long long times = query2(1,0,m-1,i,i);
		
		long long l = pesquisas[i].l;
		long long r = pesquisas[i].r;
		long long v = pesquisas[i].v;
		
		update1(1,0,n-1,l-1,r-1,v*times);
		
	}
	
	for(register long long i=0;i<n;i++){
		
        cout << query1(1,0,n-1,i,i) << " ";
		 	
	}
		
	return 0;
}