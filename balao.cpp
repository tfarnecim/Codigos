#include <bits/stdc++.h>
using namespace std;

//CREATED BY: Douglas Alves

/*


▓█████ ██▒   █▓▓█████  ██▀███   ███▄    █ ▓█████  █     █░ ▄▄▄▄    ██▓▓█████ 
▓█   ▀▓██░   █▒▓█   ▀ ▓██ ▒ ██▒ ██ ▀█   █ ▓█   ▀ ▓█░ █ ░█░▓█████▄ ▓██▒▓█   ▀ 
▒███   ▓██  █▒░▒███   ▓██ ░▄█ ▒▓██  ▀█ ██▒▒███   ▒█░ █ ░█ ▒██▒ ▄██▒██▒▒███   
▒▓█  ▄  ▒██ █░░▒▓█  ▄ ▒██▀▀█▄  ▓██▒  ▐▌██▒▒▓█  ▄ ░█░ █ ░█ ▒██░█▀  ░██░▒▓█  ▄ 
░▒████▒  ▒▀█░  ░▒████▒░██▓ ▒██▒▒██░   ▓██░░▒████▒░░██▒██▓ ░▓█  ▀█▓░██░░▒████▒
░░ ▒░ ░  ░ ▐░  ░░ ▒░ ░░ ▒▓ ░▒▓░░ ▒░   ▒ ▒ ░░ ▒░ ░░ ▓░▒ ▒  ░▒▓███▀▒░▓  ░░ ▒░ ░
 ░ ░  ░  ░ ░░   ░ ░  ░  ░▒ ░ ▒░░ ░░   ░ ▒░ ░ ░  ░  ▒ ░ ░  ▒░▒   ░  ▒ ░ ░ ░  ░
   ░       ░░     ░     ░░   ░    ░   ░ ░    ░     ░   ░   ░    ░  ▒ ░   ░   
   ░  ░     ░     ░  ░   ░              ░    ░  ░    ░     ░       ░     ░  ░
           ░                                                    ░            

*/

#define FASTIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

//nó 0 a 10^6 eh segmento pontual do chão
//nó 10^6+1 a 10^6+n+1 eh segmento normal dado na entrada

struct linha{
	int x1,y1;//y1 = menor altura
	int x2,y2;
};

bool cmp(linha l1, linha l2){
	return l1.y1 < l2.y1;
}

set <int> grafo[1100100];//2000100
int calc[1100100];//2000100

int patriarca(int v){
	if(calc[v]!=-1) return calc[v];
	int u = *grafo[v].begin();
	if(grafo[u].count(v) > 0){
		return calc[v] = v;
	}
	return calc[v] = patriarca(u);
}

int main(){

	FASTIO;

	int n,c;

	while(cin >> n >> c){

		linha l[n+1+1000001];//[n+1+1000001]

		for(int i=0;i<=1000000;i++){//<=1000000
			l[i].x1 = i;
			l[i].y1 = 0;
			l[i].x2 = i;
			l[i].y2 = 0;
		}

		for(int i=0;i<n;i++){
			linha x;
			cin >> x.x1 >> x.y1 >> x.x2 >> x.y2;
			if(x.y2 < x.y1){
				swap(x.y1,x.y2);
				swap(x.x1,x.x2);
			}
			l[1000001+i] = x;
		}

		l[1000001+n].x1 = 0;
		l[1000001+n].y1 = 1000100;//1000100
		l[1000001+n].x2 = 1000100;//1000100
		l[1000001+n].y2 = 1000100;//1000100

		sort(l+1000001,l+(n+1+1000001),cmp);//n+1+1000001

		set < pair<int,int> > lista;

		for(int i=0;i<=1000001+n;i++){//1000001+n

			int L = min(l[i].x1,l[i].x2);
			int R = max(l[i].x1,l[i].x2);
			int v = i;

			bool reta;

			if(l[i].y1 == l[i].y2 && l[i].x1 != l[i].x2) reta = true;
			else reta = false;
			set < pair<int,int> >::iterator it_left  = lista.lower_bound({L,0});//>=L
			set < pair<int,int> >::iterator it_right = lista.upper_bound({R,10000000});//>R

			set < pair<int,int> >::iterator it;

			bool pode = true;

			if(it_left == lista.end() || it_right == lista.begin() || lista.empty()) pode = false;
			if(pode && (*it_left).first > (*it_right).first || it_left == it_right) pode = false;

			if(pode){

				for(it = it_left;it != it_right;it++){
					grafo[(*it).second].insert(v);
					if(reta){
						grafo[v].insert((*it).second);
					}
				}

				lista.erase(it_left,it_right);

			}

			if(reta) continue;
			lista.insert({l[i].x2,v});

		}

		for(int i=0;i<=1000001+n;i++){//<=1000001+n
			patriarca(i);
		}

		for(int i=0;i<c;i++){

			int q;cin >> q;
			int pai = calc[q];

			if(*grafo[pai].begin() == 1000001+n){//1000001+n
				cout << l[pai].x2 << endl;
				continue;
			}

			cout << l[pai].x2 << " " << l[*grafo[pai].begin()].y1 << endl;

		}

		for(int i=0;i<=n+1000001;i++){//n+1000001
			grafo[i].clear();
			calc[i]=-1;
		}

	}

	return 0;
}
