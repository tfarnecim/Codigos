#include <bits/stdc++.h>
using namespace std;

int tree[300000][3];
int lazy[300000];

void propagate(int no,int l,int r){
	
	int aux[3] = {tree[no][0], tree[no][1], tree[no][2]};
	
	int muda = lazy[no];
	
	tree[no][0] = aux[(300003 - muda)%3];
	tree[no][1] = aux[(300004 - muda)%3];
	tree[no][2] = aux[(300005 - muda)%3];
	
	if(l!=r){
	    lazy[no*2] += lazy[no];
	    lazy[no*2+1] += lazy[no];
	}
	
	lazy[no] = 0;
	
}

void build(int no,int l,int r){
	
	if(l==r){
		tree[no][0] = 1;
		tree[no][1] = 0;
		tree[no][2] = 0;
		return ;
	}
	
	int mid = (l+r)/2;
	
	build(no*2,l,mid);
	build(no*2+1,mid+1,r);
	
	tree[no][0] = tree[no*2][0] + tree[no*2+1][0];
	tree[no][1] = tree[no*2][1] + tree[no*2+1][1];
	tree[no][2] = tree[no*2][2] + tree[no*2+1][2];

	return ;
	
}

void update(int no,int l,int r,int x,int y){
	
	propagate(no,l,r);
	
	if(r < x || y < l){
		return ;
	}
	if(x <= l && r <= y){
		int aux[3] = {tree[no][0],tree[no][1],tree[no][2]};
		
		//cuidado
		tree[no][0] = aux[2];
		tree[no][1] = aux[0];
		tree[no][2] = aux[1];
		
		if(l!=r){
			lazy[no*2]++;	
			lazy[no*2+1]++;
		}
		
		return ;
		
	}
	
	int mid = (l+r)/2;
	update(no*2,l,mid,x,y);
	update(no*2+1,mid+1,r,x,y);
	
	tree[no][0] = tree[no*2][0] + tree[no*2+1][0];
	tree[no][1] = tree[no*2][1] + tree[no*2+1][1];
	tree[no][2] = tree[no*2][2] + tree[no*2+1][2];
	
}
//query pedra
int query0(int no,int l,int r,int x,int y){
	
	if(r < x || y < l){
		return 0;
	}
	if(x <= l && r <= y){
		
		propagate(no,l,r);
		
		return tree[no][0];
	}
	
	propagate(no,l,r);
	
	int mid = (l+r)/2;

	int r1 = query0(no*2,l,mid,x,y);
	int r2 = query0(no*2+1,mid+1,r,x,y);
	
	return r1+r2;
	
}
//query papel
int query1(int no,int l,int r,int x,int y){
	
	if(r < x || y < l){
		return 0;
	}
	if(x <= l && r <= y){
		
		propagate(no,l,r);
		
		return tree[no][1];
	}
	
	propagate(no,l,r);
	
	int mid = (l+r)/2;

	int r1 = query1(no*2,l,mid,x,y);
	int r2 = query1(no*2+1,mid+1,r,x,y);
	
	return r1+r2;
	
}
//query tesoura
int query2(int no,int l,int r,int x,int y){
	
	if(r < x || y < l){
		return 0;
	}
	if(x <= l && r <= y){
		
		propagate(no,l,r);
		
		return tree[no][2];
	}
	
	propagate(no,l,r);
	
	int mid = (l+r)/2;

	int r1 = query2(no*2,l,mid,x,y);
	int r2 = query2(no*2+1,mid+1,r,x,y);
	
	return r1+r2;
	
}

int main(){
	
	int n,m;
	
	while(cin >> n >> m){
		
		memset(lazy,0,sizeof(lazy));
		
		build(1,0,n-1);
		
		for(int i=0;i<m;i++){
			
			char c;
			int a,b;
			
			cin >> c >> a >> b;
			
			if(c=='M'){
				
				update(1,0,n-1,a-1,b-1);
				
			}else{
				
				int pedra   = query0(1,0,n-1,a-1,b-1);
				int papel   = query1(1,0,n-1,a-1,b-1);
				int tesoura = query2(1,0,n-1,a-1,b-1);
				
				cout << pedra << " " << papel << " " << tesoura << endl;
				
			}
			
		}
		
		cout << endl;
		
	}
	
	return 0;
}
