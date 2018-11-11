#include <bits/stdc++.h>
using namespace std;

struct cadeira{
	
	int id,t;
	
};

struct request{
	
    int id,t,v;	
	
};

bool Rordena(request ant,request dps){
	if(ant.v > dps.v){
	    return true;	
	}else if(ant.v == dps.v){
		if(ant.t < dps.t) return true;
	}
	return false;
}

bool Cordena(cadeira ant,cadeira dps){
	if(ant.t < dps.t) return true;
	return false;
}

bool usou[2000];

int main(){
	
	int n,k;
	
	cin >> n;
	
	request r[n];
	
	for(int i=0;i<n;i++){
		
		scanf("%d%d",&r[i].t,&r[i].v);
		
		r[i].id = i+1;
		
	}
	
	sort(r,r+n,Rordena);
	
	cin >> k;
	
	cadeira c[k];
	
	for(int i=0;i<k;i++){
		
		scanf("%d",&c[i].t);
		
		c[i].id = i+1;
		
	}
	
	sort(c,c+k,Cordena);
	
	vector < pair <int,int> > saida;
	
	int soma = 0;
	
	for(int i=0;i<n;i++){
		
		int solicitacao = r[i].id;
		
		bool conseguiu = false;
		int lugar = -1;
		
		for(int j=0;j<k;j++){
			
			int id_cadeira = c[j].id;
			
			if(c[j].t >= r[i].t && !usou[id_cadeira]){
				
				usou[id_cadeira] = true;
				conseguiu = true;
				lugar = id_cadeira;
				break;
				
			}
			
		}
		
		if(conseguiu){
		
			saida.push_back(make_pair(solicitacao,lugar));	
			soma += r[i].v;
			
		}
			
	}
	
	cout << saida.size() << " " << soma << endl;
	
	for(int i=0;i<saida.size();i++){
		
		cout << saida[i].first << " " << saida[i].second << endl;
		
	}
	
	return 0;
}