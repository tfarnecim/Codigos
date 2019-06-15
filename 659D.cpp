#include <bits/stdc++.h>
using namespace std;

typedef complex<int> point;

double cross(point a,point b){return (conj(a)*b).Y;}

int main(){
	
	int n;cin >> n;
	
	point a[n+1];
	
	for(int i=0;i<=n;i++){
		
		int x,y;cin >> x >> y;
		a[i] = {x,y};
		
	}

	int ans = 0;
	
	for(int i=1;i<n;i++) if(cross(a[i-1]-a[i],a[i+1]-a[i]) < 0) ans++;
	
	cout << ans << endl;
	
	return 0;
}