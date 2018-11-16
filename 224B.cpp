#include <bits/stdc++.h>
using namespace std;

int ocor[200000];

int main(){
	
	int n,m;
	
	cin >> n >> m;
	
	int arr[n+1];
	
	int dif = 0;
	
	for(int i=1;i<=n;i++){
		
		cin >> arr[i];
		
		if(ocor[arr[i]]==0){
			dif++;
		}
		
		ocor[arr[i]]++;
		
	}
	
	int ini = 1,fim = n;
	
	if(dif < m){
		cout << -1 << " " << -1 << endl;
		return 0;
	}
	
	while(true){
		
		int num = arr[fim];
		
		if(ocor[num]-1 == 0 && dif-1 < m){
			
			break;
			
		}
		
		if(ocor[num]-1 == 0 && dif-1 >= m){
			
			dif--;
			ocor[num]--;
			fim--;
			
		}
		
		if(ocor[num]-1 > 0){
			
			ocor[num]--;
			fim--;
			
		}
		
	}
	
	while(true){
		
		int num = arr[ini];
		
		if(ocor[num]-1 == 0 && dif-1 < m){
			
			break;
			
		}
		
		if(ocor[num]-1 == 0 && dif-1 >= m){

			dif--;
			ocor[num]--;
			ini++;
			
		}
		
		if(ocor[num]-1 > 0){
			
			ocor[num]--;
			ini++;
			
		}
		
	}
	
	cout << ini << " " << fim << endl;
	
	return 0;
}