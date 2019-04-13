#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	
	cin >> n;
	
	string s;
	
	cin >> s;
	
	if(n%2!=0){
		cout << ":(\n";
		return 0;
	}
	
	int a=n/2;
	int f=n/2;
	
	for(int i=0;i<s.length();i++){
		if(s[i]=='('){
			a--;
		}else if(s[i]==')'){
			f--;
		}
	}
	
	if(a<0 || f<0){
		cout << ":(\n";
		return 0;
	}
	
	for(int i=0;i<n;i++){
		if(s[i]=='?'){
			if(a>0){
				a--;
				s[i] = '(';
			}else{
				f--;
				s[i] = ')';
			}
		}
	}
	
	vector <int> stack;
	
	for(int i=1;i<n-1;i++){
		
		stack.push_back(s[i]);
		
		int t = stack.size();
		
		if(t > 1 && stack[t-1]==')' && stack[t-2]=='('){
			stack.pop_back();
			stack.pop_back();
		}
		
		t = stack.size();
		
		if(t==1 && stack[0]==')'){
			cout << ":(\n";
			return 0;
		}
		
	}
	
	if(stack.size()>0){
		cout << ":(\n";
		return 0;
	}
	
	if(s[0]=='(' && s[n-1]==')'){
		cout << s << endl;
		return 0;
	}
	
	cout << ":(\n" << endl;
	
	return 0;
}