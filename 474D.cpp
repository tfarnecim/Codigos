#include <bits/stdc++.h>
using namespace std;

int f[100010];
int prefix[100100];

#define MOD 1000000007

int main(){
	
	int t,k;cin >> t >> k;
	
	f[0] = 1;
	
	for(int i=1;i<100010;i++){
		f[i] += f[i-1];
		if(i-k >= 0)f[i] = (f[i]+f[i-k])%MOD;
	}

	for(int i=1;i<=100010;i++) prefix[i] = (prefix[i-1] + f[i])%MOD;

	for(int i=0;i<t;i++){
		
		int a,b;
		cin >> a >> b;
		
		cout << ((prefix[b]+MOD)-prefix[a-1])%MOD << endl;
		
	}
	
	return 0;
}