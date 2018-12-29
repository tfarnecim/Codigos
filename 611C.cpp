#include <bits/stdc++.h>
using namespace std;

int psumL[600][600];
int psumC[600][600];

int main(){
	
	int n,m;
	
	cin >> n >> m;
	
	string s[n+1];
	
	for(int i=0;i<m+1;i++){
		s[0]+='#';
	}
	
	for(int i=1;i<=n;i++){
		s[i]+='#';
	}
	
	for(int i=1;i<=n;i++){
		
		string aux;
		
		cin >> aux;
		
		s[i] += aux;
		
	}
	
	for(int i=1;i<=n;i++){
		for(int c=1;c<=m;c++){
			
			int somaL = 0;
			int somaC = 0;
			
			if(s[i-1][c]=='.' && s[i][c]=='.') somaC++;
			if(s[i][c-1]=='.' && s[i][c]=='.') somaL++;
			
			psumL[i][c] = psumL[i-1][c] + psumL[i][c-1] - psumL[i-1][c-1] + somaL;
			psumC[i][c] = psumC[i-1][c] + psumC[i][c-1] - psumC[i-1][c-1] + somaC;
			
		}
	}
	
	int q;
	
	cin >> q;
	
	for(int i=0;i<q;i++){
		
		int i1,c1,i2,c2;
		
		cin >> i1 >> c1 >> i2 >> c2;
		
		int horizontal = psumL[i2][c2] - psumL[i2][c1] - psumL[i1-1][c2] + psumL[i1-1][c1];
		int vertical   = psumC[i2][c2] - psumC[i2][c1-1] - psumC[i1][c2] + psumC[i1][c1-1];
		
		cout << horizontal + vertical << endl;
		
	}
	
	return 0;
}