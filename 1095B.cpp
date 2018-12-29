#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define INF 1000000000
#define INFL 1000000000000000000

typedef long long ll;
typedef pair <ll, ll> pii;
typedef vector <ll> vi;

int main(){
	
	ll n;
	
	cin >> n;
	
	ll arr[n];
	
	for(int i=0;i<n;i++){
		
		cin >> arr[i];
			
	}
	
	sort(arr,arr+n);
	
	if(n==2){
		cout << 0 << endl;
		return 0;
	}
	
	cout << min(arr[n-1]-arr[1],arr[n-2]-arr[0]) << endl;
	
	return 0;
}