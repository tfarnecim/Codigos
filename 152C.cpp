#include <bits/stdc++.h>
using namespace std;

int main(){
	
	long long n,m;
	
	cin >> n >> m;
	
	string lista[n];
	
	for(long long i=0;i<n;i++){
		cin >> lista[i];
	}
	
	long long saida = 1;
	
	for(long long i=0;i<m;i++){
		
		map <char,long long> encontrou;
		
		long long mult = 0;
		
		for(long long c=0;c<n;c++){
			
			char pos = lista[c][i];
			
			if(encontrou[pos] < 1){
				encontrou[pos] = 1;
				mult++;
			}
			
		}
		
		saida = ((saida%1000000007)*(mult%1000000007))%1000000007;
		
	}
	
	cout << saida << endl;
	
	return 0;
}