#include <bits/stdc++.h>
using namespace std;

int mfp[6000010];//mfp[i] = menor fator primo de i

void crivo(){
	for(register int i=2;i<=sqrt(6000000);i++){
		if(mfp[i]==i){
			for(register int j=i*i;j<=6000000;j+=i){
				mfp[j] = min(mfp[j],i);
			}
		}
	}
}

void cont_fat(int v){//mostra os fatores de v
	while(v != 1){
		cout << mfp[v] << " ";
		v = v/mfp[v];
	}
	cout << endl;
}

int main(){

	for(register int i=0;i<6000000;i++) mfp[i] = i;
	
	mfp[0] = -1;
	mfp[1] = -1;
		
	crivo();
		
	int n;
	
	cin >> n;
	
	cont_fat(n);//use 1 < n < 5000000
	
    return 0;
}