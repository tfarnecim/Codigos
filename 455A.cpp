#include <bits/stdc++.h>
using namespace std;

long long ocur[200000];
long long dp[200000];

//dp[i] = maior soma possivel usando apenas valores menores ou iguais a i

//dp[i] = ou pega o de tras pq não pode somar com o elemento-1
//        ou pega o de dois passos atras junto com o atual

int main(){
	
	long long n;
	
	cin >> n;
	
	long long arr[n];
	
	for(long long i=0;i<n;i++){
		
		cin >> arr[i];
	
		ocur[ arr[i] ]++;
			
	}
	
	dp[0] = 0;
	dp[1] = ocur[1];
	
	for(long long i=2;i<=100000;i++){
		
		dp[i] = max( dp[i-1] , dp[i-2] + ocur[i] * i);
		
	}
	
	cout << dp[100000] << endl;
	
	return 0;
}