#include <bits/stdc++.h>
using namespace std;

int q;
int red;
int black;

int lg(int n){
	int c = 0;
	while((1<<c) <= n){
		c++;
	}
	return c-1;
}

int calc(int u,int v){
	
	int nvlu = lg(u);
	int nvlv = lg(v);
	
	if(nvlu%2==0) black++;
	else red++;
	
	if(nvlv%2==0) black++;
	else red++;
	
	while(u!=v){
		
		int paiu = u/2;
		int paiv = v/2;
		
		if(nvlu > nvlv){
		
			u = paiu;
			nvlu--;
			
			if(nvlu%2==0) black++;
			else red++;
		
		}else{
		
			v = paiv;
			nvlv--;
		
			if(nvlv%2==0) black++;
			else red++;
		
		}
		
	}
	
	if(nvlu%2==0) black--;
	else red--;
	
	return u;
}

int main(){
	
	bool muda = false;
	
	cin >> q;
	
	while(q--){
	
		black = 0;
		red = 0;
		
		string s;
		
		cin >> s;
		
		if(s=="Qi"){
			muda = !muda;
			continue;
		}
		
		int u,v;
		
		cin >> u >> v;
		
		calc(u,v);
		
		if(s=="Qb"){
			if(!muda){
				cout << black << endl;
			}else{
				cout << red << endl;
			}
		}
		
		if(s=="Qr"){
			if(!muda){
				cout << red << endl;
			}else{
				cout << black << endl;
			}
		}
		
	}
	
	return 0;
}