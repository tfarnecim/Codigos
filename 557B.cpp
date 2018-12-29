#include <bits/stdc++.h>
using namespace std;

int main(){
	
	long long n,w;
	
	cin >> n >> w;
	
	long long n2 = n*2;
	
	long long arr[n2];
	
	for(long long i=0;i<n2;i++){
		
		cin >> arr[i];
		
	}
	
	sort(arr,arr+n2);
	
	double fim = ((2.0/3.0) * w)/(double)n;
	double ini = 0;
	
	while(fim - ini > 0.00000000000001){
		
		double mid = (fim+ini)/2.0;
		
		bool aguenta = true;
		
		for(int i=0;i<n;i++){
			if(arr[i]<mid/2.0){
				aguenta = false;
				break;
			}
		}
		
		for(int i=n;i<n2;i++){
			if(arr[i]<mid){
				aguenta = false;
				break;
			}
		}
		
		if(aguenta){
			ini = mid;
		}else{
			fim = mid;
		}
			
	}
	
	printf("%.20lf\n",ini * n + (ini/2) * n);
	
	return 0;
}