#include <bits/stdc++.h>
using namespace std;

//biblioteca
#define INF  1000000000
#define INFL 1000000000000000000
#define mp make_pair
#define alfa "abcdefghijklmnopqrstuvwxyz"
#define FASTIO ios::sync_with_stdio(false)
#define TIE cin.tie(NULL)
#define P system("pause")
#define PI 3.14159265358

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

char escolhe(string s,int i,int p,char c){
	
	while(c-96 <= p){
		if(i-1 >= 0 && c==s[i-1]) c++;
        else if(i-2 >= 0 && c==s[i-2]) c++;
  	    else break;
	}
	
	if(c-96 > p) return 'X';

	return c;
	
}

int main(){
	
	FASTIO;
	
	int n,p;
	
	cin >> n >> p;
	
	string s;
	
	cin >> s;
	
	int pos = -1;
	
	for(int i=n-1;i>=0;i--){
		
		char res = escolhe(s,i,p,s[i]+1);
		
		if(res != 'X'){
			s[i] = res;
			pos = i;
			break;
		}else{
			s[i] = 'a';
		}
		
	}
	
	if(pos == -1){
		cout << "NO\n";
		return 0;
	}
	
	for(int i=pos+1;i<n;i++){
		
		char resp = escolhe(s,i,p,s[i]);
		
		if(resp != 'X'){
			s[i] = resp;
		}else{
			cout << "NO\n";
			return 0;
		}
		
	}
	
	cout << s << endl;
	
	return 0;
}