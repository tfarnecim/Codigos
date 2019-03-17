#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;
#define pb push_back

int main(){
	
	int n,k;
	
	cin >> n >> k;
	
	if(n <= k*2+1){
		cout << 1 << endl;
		cout << min(k+1,n) << endl;
		return 0;
	}
	
	int UI = -1;
	int UJ = -1;
	
	for(int i=1;i<=k+1;i++){
		for(int j=1;j<=k+1;j++){
			if((n-( (i + k) + (j + k) )) % (k*2+1) == 0){
				UI = i;
				UJ = n-j+1;
				i = k+2;
				break;
			}
		}
	}
	
	vi resp;
	
	resp.pb(UI);
	
	for(int i=UI+(k*2+1);i<UJ;i+=k*2+1){
		resp.pb(i);
	}
	
	resp.pb(UJ);
	
	cout << resp.size() << endl;
	
	for(int i=0;i<resp.size();i++){
		cout << resp[i] << " ";
	}
	
	cout << endl;

	return 0;
}