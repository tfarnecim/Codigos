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

ll gcd(ll a,ll b){
	if(a%b==0) return b;
	else return gcd(b,a%b);
}

ll lcd(ll a,ll b){
	return a*b/gcd(a,b);
}

//794B
//O PROBLEMA DA CENOURA

int main(){
	
	FASTIO;
	TIE;
	
	double n,h;
	
	cin >> n >> h;
	
	double area = h/2.0;
	double procura = area/n;
	
	for(int i=0;i<n-1;i++){
		
		double tot = i*procura;
				
		double ini = 0;
		double fim = h;
				
		while(fim - ini > 0.0000000001){
			
			double mid = (ini+fim)/2.0;
			
			double base = mid/h;
			   
			if(((mid*base)/2.0)-tot >= procura){
				fim = mid;
			}else{
				ini = mid;
			}
			
		}
		
		printf("%.10lf ",ini);
				
	}
	
	printf("\n");
	
	return 0;
}