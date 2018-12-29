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
	
	string s;
	
	cin >> s;
	
	string saida ;
	
	int salto = 0;
	
	for(int i=0;i<s.length();i+=salto){
		
		saida += s[i];
		
		salto++;
		
	}
	
	cout << saida << endl;
	
	return 0;
}