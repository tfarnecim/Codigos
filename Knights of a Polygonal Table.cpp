#include <bits/stdc++.h>
using namespace std;

//biblioteca
#define INF  1000000000
#define INFL 1000000000000000000
#define pb push_back
#define mp make_pair
#define alfa "abcdefghijklmnopqrstuvwxyz"

typedef long long ll;
typedef vector <ll> vi;
typedef pair <ll,ll> pii;

ll MAX(ll a,ll b){
	if(a>b)return a;
	return b;
}

ll MIN(ll a,ll b){
	if(a<b)return a;
	return b;
}

struct w{

	ll p,d,i;
		
};

bool ordena(w ant,w dps){
	
	if(ant.p < dps.p){
		return true;
	}
	
	return false;
	
}

int main(){
	
	ll n,k;
	
	cin >> n >> k;
	
	w arr[n];
	
	for(ll i=0;i<n;i++){
		
		cin >> arr[i].p;
		arr[i].i = i;
		
	}
	
	for(ll i=0;i<n;i++){
		
		cin >> arr[i].d;
		
	}
	
	if(k==0){
	
		for(ll i=0;i<n;i++){
		
			cout << arr[i].d << " ";
		
		}
			
		cout << endl;
		return 0;
			
	}
	
	ll tam = 0;
	
	ll sum = 0;
	
	priority_queue <ll,vector<ll>,greater<ll> > fila;
	
	sort(arr,arr+n,ordena);
	
	ll ans[n];
	
	for(ll i=0;i<n;i++){
		
		if(tam < k){
			
			tam++;
			ans[arr[i].i] = sum+arr[i].d;
			fila.push(arr[i].d);
			sum += arr[i].d;
			
		}else{
			
			ans[arr[i].i] = sum + arr[i].d;
			
			if(fila.top() < arr[i].d){
				sum-=fila.top();
				fila.pop();
				sum += arr[i].d;
				fila.push(arr[i].d);
			}
			
		}
		
	}
	
	for(ll i=0;i<n;i++){
		
		cout << ans[i] << " ";
		
	}
	
	cout << endl;
	
	return 0;
}