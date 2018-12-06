#include <bits/stdc++.h>
using namespace std;

int main(){
	
	string s;
	
	cin >> s;
	
	int n = s.length(); 
	
	priority_queue <char , vector<char>, greater<char> > fila;
	
	string fim,ini;
	
	bool passou = false;
	
	for(int i=0;i<n;i++){
		
		if(s[i] == '1'){
			
			fila.push('1');
			
		}else if(s[i] == '2'){
			
			if(!passou){
				
				passou = true;
				fim += '2';
				
			}else{
				
				fim += '2';
				
			}
			
		}else{
			
			if(!passou){
				
				fila.push('0');
				
			}else{
				
				fim += '0';
				
			}
			
		}
		
	}
	
	while(!fila.empty()){
		
		ini += fila.top();
		
		fila.pop();
		
	}
	
	cout << ini + fim << endl;
	
	return 0;
}