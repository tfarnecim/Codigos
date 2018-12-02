#include <bits/stdc++.h>
using namespace std;

int para[200000];
int conta[200000];

int main(){
	
	int n;
	
	cin >> n;
	
	int arr[n];
	int pSum[n+1];
	
	pSum[n] = 0;
	
	memset(para,-1,sizeof para);
	
	for(int i=0;i<n;i++){
		
		cin >> arr[i];
		
		if(para[ arr[i] ] == -1){
			
			para[ arr[i] ] = i;
			
		}
		
	}
	
	for(int i=n-1;i>=0;i--){
		
		if(conta[ arr[i] ] > 0){
			
			pSum[i] = pSum[i+1];
			
		}else{
			
			conta[ arr[i] ]++;
			pSum[i] = pSum[i+1] + 1;
			
		}
		
	}
	
	long long saida = 0;
	
	for(int i=1;i<=100100;i++){
		
		if(para[i] != -1){
			
			saida += pSum[ para[i] + 1];
			
		}
		
	}
	
	cout << saida << endl;
	
	return 0;
}