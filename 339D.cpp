#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi arr[20];

int main(){
	
	ios::sync_with_stdio(false);
	
	int n,m;
	
	cin >> n >> m;
		
	for(int i=0;i<pow(2,n);i++){
	
		int a;
		
		cin >> a;
		
		arr[0].push_back(a);
			
	}
	
	int at = pow(2,n);
	
	for(int i=1;i<=n;i++){
		
		at = at/2;
		int pos = 0;
		
		if(i%2!=0){
		    
			for(int j=0;j<at;j++){
				
				arr[i].push_back(arr[i-1][pos] | arr[i-1][pos+1]);
				pos+=2;
							
			}
				
		}else{
			
			for(int j=0;j<at;j++){
				
				arr[i].push_back(arr[i-1][pos] ^ arr[i-1][pos+1]);
				pos+=2;
							
			}
			
		}
		
	}
	
	for(int i=0;i<m;i++){
		
		int pos,v;
		
		cin >> pos >> v;
		
		int at = v;
		
		pos--;
		
		for(int j=0;j<n;j++){
			
			arr[j][pos] = at;
			
			if(j%2==0){
				
				if(pos%2==0){
					at = arr[j][pos]|arr[j][pos+1];
				}else{
					at = arr[j][pos]|arr[j][pos-1];
				}
				
			}else{
				
				if(pos%2==0){
					at = arr[j][pos]^arr[j][pos+1];
				}else{
					at = arr[j][pos]^arr[j][pos-1];
				}
				
			}
			pos = pos/2;
		}
		
		cout << at << endl;
		
	}
	
	return 0;
}