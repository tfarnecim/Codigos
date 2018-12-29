#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define INF 1000000000
#define INFL 1000000000000000000

typedef long long ll;
typedef pair <ll, ll> pii;
typedef vector <ll> vi;

bool ligado(ll mask,ll i){
	
	if((mask & (1 << i)) == 0) return false;
	
	return true;
	
}

int main(){
	
	ll n,m;
	
	cin >> n >> m;
	
	ll mult = 1;
	
	map <ll,ll> cont;
	
	ll maxi = -1;
	
	ll bits = 0;
	
	for(int i=0;i<32;i++){
		
		if(ligado(n,i)){
			
			//cout << "BIT DO " << mult << " LIGADO\ni = " << i << endl;
			
			cont[mult] = 1;
			
			bits++;
					 
		    if(mult > maxi){
				maxi = mult;
			}
					 			
		}
		
		mult *= 2;
		
	}
	
	if(m < bits){
		cout << "NO\n";
		return 0;
	}
	
	while(bits < m && maxi != 1){
		
		cont[maxi]-=1;
		cont[maxi/2]+=2;
		
		if(cont[maxi]==0){
			maxi = maxi/2;
		}
		
		bits++;
		
	}
	
	if(cont[1] == n && m > n){
		cout << "NO\n";
		return 0;
	}
	
	cout << "YES\n";
	
	while(maxi!=0){
		
		for(int i=0;i<cont[maxi];i++){
			
			cout << maxi << " ";
			
		}
		
		maxi = maxi/2;
		
	}
	
	cout << endl;
	
	return 0;
}