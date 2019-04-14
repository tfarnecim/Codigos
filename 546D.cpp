#include <bits/stdc++.h>
using namespace std;

int mfp[6000001];
int psum[6000000];

void crivo(){
	for(register int i=2;i<=sqrt(6000000);i++){
		if(mfp[i]==i){
			for(register int j=i*i;j<=6000000;j+=i){
				mfp[j] = min(mfp[j],i);
			}
		}
	}
}

int cont_fat(int v){
	int ans = 0;
	while(v != 1){
		ans++;
		v = v/mfp[v];
	}
	return ans;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	for(register int i=0;i<6000000;i++) mfp[i] = i;
	
	mfp[0] = -1;
	mfp[1] = -1;
		
	crivo();
		
	int n;
	
	cin >> n;
	
	psum[1] = 0;
	
	for(register int i=2;i<6000000;i++){
		psum[i] = psum[i-1] + cont_fat(i);
		// if(i<=6){
		// 	cout << cont_fat(i) << endl;
		// }
	}
	
	//cout << "CHEGOU\n";
	
	for(register int i=0;i<n;i++){
		
		int a,b;
		
		cin >> a >> b;
		
		cout << psum[a] - psum[b] << "\n";
		
	}
	
    return 0;
}