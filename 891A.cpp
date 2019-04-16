#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	return a%b==0?b:gcd(b,a%b);
}

int tree[8000];
int arr[4000];

void build(int no,int l,int r){

	if(l==r){
		tree[no] = arr[l];
		return ;
	}
	
	int mid = (l+r)/2;
	
	build(no*2,l,mid);
	build(no*2+1,mid+1,r);
	
	tree[no] = gcd(tree[no*2],tree[no*2+1]);
	
}

int query(int no,int l,int r,int x,int y){
	
	if(r < x || y < l){//fora
		return -1;
	}
	
	if(x <= l && r <= y){//dentro
		return tree[no];
	}
	
	int mid = (l+r)/2;
	
	int r1 = query(no*2,l,mid,x,y);
	int r2 = query(no*2+1,mid+1,r,x,y);
	
	if(r1==-1){
		return r2;
	}
	
	if(r2==-1){
		return r1;
	}
	
	return gcd(r1,r2);
	
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	
	cin >> n;

	int um = 0;
	
	for(int i=0;i<n;i++){cin >> arr[i]; if(arr[i]==1) um++;}
		
    if(um > 0){
		cout << n-um << endl;
		return 0;
	}
		
	build(1,0,n-1);
		
	int mini = 1e9;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
			
			int calc = query(1,0,n-1,j,j+i);
			
			if(calc==1){
				mini = min(mini,i+n-1);
			}
			
		}
	}

	if(mini==1e9){
		cout << -1 << endl;
		return 0;
	}
	
	cout << mini << endl;
	
	return 0;
}