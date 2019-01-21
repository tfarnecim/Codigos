#include <bits/stdc++.h>
using namespace std;

#define INF 30000000

typedef long long ll;

struct contest{
    ll change,div;	
};

ll soma(ll val,ll id,ll muda){
	
	if(id==0){
		
		if(val!=-INF){
			val = val+muda;
		}
		
	}else{
		
		if(val!=INF){
			val = val+muda;
		}
		
	}
	
	return val;
	
}

int main(){
	
	ll n;
	
	cin >> n;
	
	contest arr[n];
	
	ll muda = 0;
	
	for(ll i=0;i<n;i++){
		
		cin >> arr[i].change >> arr[i].div;
		
		muda += arr[i].change;
		
	}
	
	muda *= -1;
	
	bool dif = false;
	
	for(ll i=0;i<n-1;i++){
		if(arr[i].div != arr[i+1].div){
			dif = true;
			break;
		}
	}
	
	if(!dif){
		cout << "Infinity\n";
		return 0;
	}
	
	ll fim =  INF;
	ll ini = -INF;
	
	if(arr[0].div==1){
		ini = 1900;
	}else{
		fim = 1899;
	}
	
	for(ll i=1;i<n;i++){
		
		fim = soma(fim,1,arr[i-1].change);
		ini = soma(ini,0,arr[i-1].change);
		
		if(fim == INF && arr[i].div==2){
			fim = 1899;
		}else if(ini == -INF && arr[i].div==1){
			ini = 1900;
		}
		
		if(arr[i].div == 1){
			
			if(fim < 1900){
				cout << "Impossible\n";
				return 0;
			}
			
		}else{
			
			if(ini > 1899){
				cout << "Impossible\n";
				return 0;
			}
			
		}
		
		 // cout << "FIM = " << fim << endl;
		 // cout << "INI = " << ini << endl;
		
	}
	
	fim += arr[n-1].change;
	ini += arr[n-1].change;
	
	// cout << "FIM = " << fim << endl;
	// cout << "INI = " << ini << endl;
	// cout << endl;
	
	while(fim-ini > 0){
		
		ll mid = ceil((ini+fim)/2.0);
		
		ll aux = mid;
		
		//cout << mid << endl;
		
		mid += muda;
		
		bool consegue = true;
		
		for(int i=1;i<n;i++){
			
			mid += arr[i-1].change;
			
			if(arr[i].div==1 && mid < 1900){
				
				consegue = false;
				break;
				
			}else if(arr[i].div==2 && mid >= 1900){
				
				consegue = false;
				break;
				
			}
			
		}
		
		if(consegue){
			
			ini = aux;
			
		}else{
			
			fim = aux-1;
			
		}
		
	}
	
	//cout << endl;
	
	cout << ini << endl;
	
	return 0;
}