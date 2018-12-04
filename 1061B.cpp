#include <bits/stdc++.h>
using namespace std;

int main(){
	
	long long n,m;
	
	cin >> n >> m;
	
	long long soma = 0,arr[n];
	
	for(long long i=0;i<n;i++){
		
		cin >> arr[i];
		
		soma += arr[i];
		
	}
	
	sort(arr,arr+n);
	
	long long alt = 0;
	
	for(long long i=0;i<n;i++){
		
		if(arr[i] > alt){
			alt++;
		}
		
	}
	
	long long saida = n;
	
	saida += arr[n-1] - alt;
	
	saida = soma - saida;
	
	cout << saida << endl;
	
	return 0;
}