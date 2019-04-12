#include <bits/stdc++.h>
using namespace std;

int cont[200000];

int main(){
	
	int n;
	cin >> n;
	
	int arr[n];
	
	for(int i=0;i<n;i++){
		
		cin >> arr[i];
		
		for(int j=1;j<=sqrt(arr[i]);j++){
		
			if(arr[i]%j==0){
		
				if(arr[i]/j != j){
					cont[arr[i]/j]++;
					cont[j]++;
				}else{
					cont[arr[i]/j]++;	
				}
					
			}	
		
		}
	
	}
	
	int maxi = 1;
	
	for(int i=2;i<=100010;i++) maxi = max(cont[i],maxi);
	
	cout << maxi << endl;
	
	return 0;
}