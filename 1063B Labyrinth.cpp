#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define INF 900000000000

typedef long long ll;
typedef pair <ll,ll> pii;

int n,m;
int r,c;
int lef,rigth;
string grafo[3000];
ll dist_esq[3000][3000];
ll dist_dir[3000][3000];
ll mx[] = {0,0,-1,1};
ll my[] = {-1,1,0,0};

bool fora(ll y,ll x){
	
	if(y<0 || y>=n || x<0 || x>=m) return true;
	
	return false;
	
}

void bfs_esq(ll y,ll x){
	
	for(ll i=0;i<n;i++){
		for(ll c=0;c<m;c++){
			dist_esq[i][c] = INF;
		}
	}
	
	dist_esq[y][x] = 0;
	deque <pii> d;
	d.push_front(mp(y,x));
	
	while(!d.empty()){
		
		//cout << "CHEGOU\n";
		
		pii v = d.front();
		d.pop_front();
		
		for(ll i=0;i<4;i++){
			
			ll adjx = v.second+mx[i];
			ll adjy = v.first+my[i];
			
			ll dis;
			
			if(mx[i]==-1){
				dis = 1;
			}else{
				dis = 0;
			}
			
			if(!fora(adjy,adjx) && grafo[adjy][adjx]=='.' && dist_esq[adjy][adjx] > dist_esq[v.first][v.second]+dis){
				
				dist_esq[adjy][adjx] = dist_esq[v.first][v.second]+dis;
				
				if(dis==1){
					d.push_back(mp(adjy,adjx));
				}else{
					d.push_front(mp(adjy,adjx));
				}
				
			}
			
		}
		
	}
	
}

void bfs_dir(ll y,ll x){
	
	for(ll i=0;i<n;i++){
		for(ll c=0;c<m;c++){
			dist_dir[i][c] = INF;
		}
	}
	
	dist_dir[y][x] = 0;
	deque <pii> d;
	d.push_front(mp(y,x));
	
	while(!d.empty()){
		
		pii v = d.front();
		d.pop_front();
		
		for(ll i=0;i<4;i++){
			
			ll adjx = v.second+mx[i];
			ll adjy = v.first+my[i];
			
			ll dis;
			
			if(mx[i]==1){
				dis = 1;
			}else{
				dis = 0;
			}
			
			if(!fora(adjy,adjx) && grafo[adjy][adjx]=='.' && dist_dir[adjy][adjx] > dist_dir[v.first][v.second]+dis){
				
				dist_dir[adjy][adjx] = dist_dir[v.first][v.second]+dis;
				
				if(dis==1){
					d.push_back(mp(adjy,adjx));
				}else{
					d.push_front(mp(adjy,adjx));
				}
				
			}
			
		}
		
	}
	
}

int main(){
	
	scanf("%d%d",&n,&m);
	scanf("%d%d",&r,&c);
	scanf("%d%d",&lef,&rigth);
	
	for(ll i=0;i<n;i++){
		
		cin >> grafo[i];
		
	}
	
	bfs_esq(r-1,c-1);
	bfs_dir(r-1,c-1);
	
	ll saida = 0;
	
	for(ll i=0;i<n;i++){
		for(ll c=0;c<m;c++){
			//cout << dist_dir[i][c] << " ";
			if(dist_esq[i][c] <= lef && dist_dir[i][c] <= rigth){
				saida++;
			}
		}
		//cout << endl;
	}
	
	cout << saida << endl;
	
	return 0;
}