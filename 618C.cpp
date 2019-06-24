#include <bits/stdc++.h>
using namespace std;

typedef complex <double> point;

#define INF 1e18
#define X real()
#define Y imag()

double cross(point a,point b){
	return (conj(a)*b).Y;
}

int main(){
	
	int n;
	
	cin >> n;
	
	point a[n];
	
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		a[i] = {(double)x,(double)y};
	}
	
	int idx = -1;
	double mini = INF;
	
	for(int i=1;i<n;i++){
		if(abs(a[i]-a[0]) < mini){
			mini = abs(a[i]-a[0]);
			idx = i;
		}
	}
	
	vector <int> dir;
	vector <int> esq;
	
	for(int i=0;i<n;i++){
		
		if(i==0 || i==idx) continue;
	
		int res = (int)cross(a[0]-a[idx],a[i]-a[idx]);
		
		if(res < 0) esq.push_back(i);
		if(res > 0) dir.push_back(i);
		
	}
	
	mini = INF;
	int pos = -1;	

	for(int i=0;i<esq.size();i++){
		
		double dist = abs(a[0]-a[esq[i]]) + abs(a[idx]-a[esq[i]]);
		
		if(dist < mini){
			mini = dist;
			pos = esq[i];
		}
		
	}
	
	for(int i=0;i<dir.size();i++){
		
		double dist = abs(a[0]-a[dir[i]]) + abs(a[idx]-a[dir[i]]);
		
		if(dist < mini){
			mini = dist;
			pos = dir[i];
		}
		
	}
	
	cout << "1 " << idx+1 << " " << pos+1 << endl;
	
	return 0;
}