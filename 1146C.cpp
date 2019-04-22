#include <bits/stdc++.h>
using namespace std;

int main(){

	int t;
	
	cin >> t;
	
	for(int i=0;i<t;i++){
		
		int n;
		
		cin >> n;
		
		cout << 1 << " " << n-1 << " " << 1 << " ";
		
		for(int j=2;j<=n;j++) cout << j << " ";	
		cout << endl;
	
		fflush(stdout);	
	
		int maxi;
		
		cin >> maxi;
		
		int ini = 2;
		int fim = n;
		
 	    	while(fim - ini > 0){
			
			int mid = (ini+fim)/2;//3
			
			cout << 1 << " " << mid-ini+1 << " " << 1 << " ";
			
			for(int j=ini;j<=mid;j++) cout << j << " ";
			cout << endl;
			
			fflush(stdout);
		
			int ans;
		
			cin >> ans;//9
			
			if(ans != maxi){
				ini = mid+1;
			}else{
				fim = mid;
			}
			 
		}
		
		int node = ini;
		
		cout << "1 " << n-1 << " " << node << " ";
		
		for(int j=1;j<=n;j++) if(j!=node) cout << j << " ";
		cout << endl;
	
		fflush(stdout);
	
		int resp;
		
		cin >> resp;
		
		cout << "-1 " << resp << endl;
		fflush(stdout);
		
	}

	return 0;
}
