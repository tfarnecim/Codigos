#include <bits/stdc++.h>
using namespace std;

//biblioteca
#define INF  1000000000
#define INFL 1000000000000000000
#define mp make_pair
#define alfa "abcdefghijklmnopqrstuvwxyz"
#define FASTIO ios::sync_with_stdio(0)
#define TIE cin.tie(0);cout.tie(0)
#define P system("pause")
#define PI 3.14159265358
#define MOD 1000000007
//#define x real()
//#define y imag()

typedef long long ll;
typedef vector <ll> vi;
typedef pair <ll,ll> pii;
typedef complex <double> point;

ll MAX(ll a,ll b){
	if(a>b)return a;
	return b;
}

ll MIN(ll a,ll b){
	if(a<b)return a;
	return b;
}

ll gcd(ll a,ll b){
	return a%b==0 ? b : gcd(b,a%b);
}

ll lcd(ll a,ll b){
	return a*b/gcd(a,b);
}

string To_String(ll v){
	string s;
	while(v!=0){
		s += (v%10)+48;
		v/=10;
	}
	return s;
}

ll To_Int(string s){
	ll ans = 0;
	for(int i=0;i<s.length();i++){
		ans *= 10;
		ans += (s[i]-48);
	}
	return ans;
}

int main(){

	int arr[] = {4,8,15,16,23,42};
	
	map <int,pii> numb;
	
	for(int i=0;i<6;i++) for(int j=0;j<6;j++) if(i!=j) numb[arr[i]*arr[j]] = {arr[i],arr[j]}; 
	
	pii ant;
	int mult;	

	cout << "? 1 2\n";
	fflush(stdout);
	
	cin >> mult;
	
	ant = numb[mult];
	pii primeiro = ant;
	
	int ans[6];
	
	for(int i=2;i<=4;i++){
		
		cout << "? " << i << " " << i+1 << endl;
		fflush(stdout);
		cin >> mult;
		pii at = numb[mult];
	
		if(at.first==ant.first){
			ans[i-1] = ant.first;
		}
		
		if(at.second==ant.first){
			ans[i-1] = ant.first;
		}
	
		if(at.first==ant.second){
			ans[i-1] = ant.second;
		}
		
		if(at.second==ant.second){
			ans[i-1] = ant.second;
		}
		
		ant = at;
		
	}

	if(primeiro.first!=ans[1]){
		ans[0] = primeiro.first;
	}else{
		ans[0] = primeiro.second;
	}
	
	if(ant.first!=ans[3]){
		ans[4] = ant.first;
	}else{
		ans[4] = ant.second;
	}
	
	ans[5] = -1;
	
	for(int i=0;i<6;i++){
		bool ok = false;
		for(int j=0;j<6;j++){
			if(arr[i]==ans[j]){
				ok = true;
				break;
			}
		}
		if(!ok){
			ans[5] = arr[i];
			break;
		}
	}
	
	cout << "! ";
	for(int i=0;i<6;i++){
		cout << ans[i] << " "; 
	}
	
	cout << endl;
	fflush(stdout);
	return 0;
}