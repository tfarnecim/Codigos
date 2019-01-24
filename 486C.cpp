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

ll dis(char a,char b){
	
	string alfabeto = alfa;
	
	ll pos1;
	ll pos2;
	
	for(ll i=0;i<26;i++){
		
		if(alfabeto[i]==a){
		    pos1 = i;
			break;	
		}
		
	}
	
	for(ll i=0;i<26;i++){
		
		if(alfabeto[i]==b){
		    pos2 = i;
			break;	
		}
		
	}
	
	ll dis1 = 0;
	ll dis2 = 0;
	
	ll aux3 = pos1;
	
	while(alfabeto[pos1%26] != alfabeto[pos2]){
		dis1++;
		pos1++;
	}
	
	pos1 = aux3;
	
	while(alfabeto[(pos1+52)%26] != alfabeto[pos2]){
		dis2++;
		pos1--;
	}
	
	return MIN(dis1,dis2);
	
}

int main(){
	
	ll n,k;
	
	cin >> n >> k;
	
	string s;
	
	cin >> s;
	
	ll sum = 0;
	vi v;
	
	ll n2 = n/2 + (n%2);
	
	vi idx1;
	vi idx2;
	
	for(ll i=0;i<n2;i++){
		
		ll d = dis(s[i],s[n-1-i]);
		
		if(d > 0){
			
			sum += d;
			idx1.pb(i+1);
			// cout << "I=" << i+1 << endl;
			idx2.pb(n-i);
			
		}
		
	}
	
	ll dis1 = 0;
	ll dis2 = 0;
	
	if(!idx1.empty()){
		dis1 = MIN(abs(k-idx1[0])+abs(idx1[0]-idx1[idx1.size()-1]),  abs(k-idx1[idx1.size()-1]) + abs(idx1[idx1.size()-1]-idx1[0]));
	}
	if(!idx2.empty()){
		dis2 = MIN(abs(k-idx2[0])+abs(idx2[0]-idx2[idx2.size()-1]),  abs(k-idx2[idx2.size()-1]) + abs(idx2[idx2.size()-1]-idx2[0]));
	}

	// cout << "DIS[" << 0 << "] = " << dis1 << endl;
	// cout << "DIS[" << 1 << "] = " << dis2 << endl;
	
	cout << MIN(sum+dis1,sum+dis2) << endl;
	
	return 0;
}