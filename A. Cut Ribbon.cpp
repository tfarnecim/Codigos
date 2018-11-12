#include <bits/stdc++.h>
using namespace std;

int n,v[3];

int tab[5000][5000];

int solve(int t,int colocou){
	
	if(tab[t][colocou] != -1) return tab[t][colocou];
	
	if(t == n) return tab[t][colocou] = colocou;
	
	int saida = -1;
	
	for(int i=0;i<3;i++){
		
		if(t + v[i] <= n){
			
			saida = max(saida,solve(t+v[i],colocou+1));
			
		}
		
	}
	
	tab[t][colocou] = saida;
	
	return saida;
	
}

int main(){
	
	memset(tab,-1,sizeof tab);
	
	cin >> n >> v[0] >> v[1] >> v[2];
	
	cout << solve(0,0) << endl;
	
	return 0;
}