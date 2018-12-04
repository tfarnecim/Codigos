#include <bits/stdc++.h>
using namespace std;

int main(){
	
	string s;
	
	cin >> s;
	
	int n = s.length();
	
	s+='b';
	
	int saida[n];
	
	for(int i=0;i<n;i++){
		
		if(s[i]=='b' && s[i+1]=='a'){
			saida[i] = 1;
		}else if(s[i]=='a' && s[i+1]=='b'){
			saida[i] = 1;
		}else{
			saida[i] = 0;
		}
		
	}
	
	for(int i=0;i<n;i++){
		
		cout << saida[i] << " ";
		
	}
	
	cout << endl;
	
	return 0;
}