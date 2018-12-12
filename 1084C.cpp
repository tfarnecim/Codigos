#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	
	string s;
	
	cin >> s;
	
	ll mult = 1;
	ll at = 1;
	
	for(ll i=0;i<s.length();i++){
		
		if(s[i]=='b'){
			
			//mult *= at;
			
			mult = ( (mult%1000000007) * (at%1000000007) ) % 1000000007;
			
			at = 1;
			
		}else if(s[i]=='a'){
			
			at++;
		
		}
		
	}
	
	cout << mult - 1 << endl;
	
	return 0;
}
