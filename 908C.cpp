#include <bits/stdc++.h>
using namespace std;

//CREATED BY: Douglas Alves

//    ##  ##
//   ########
//    ######
//     ####
//      ##

#define P system("pause")
#define PI 3.14159265358
#define X real()
#define Y imag()
typedef complex <double> point;

int main(){
	
	int n;
	double r;
	cin >> n >> r;
	
	int a[n];
	
	for(int i=0;i<n;i++)cin >> a[i];
	
	vector <double> calc;

	for(int i=0;i<n;i++){
		
		double maxi = r;
		
		for(int j=0;j<calc.size();j++){
			
			double L = abs(a[i]-a[j])*abs(a[i]-a[j]);
			double R = (2*r)*(2*r);
			
			if(abs(a[i]-a[j]) <= 2*r){
				if(sqrt(R-L)+calc[j] > maxi){
					maxi = sqrt(R-L)+calc[j];
				}
			}
			
		}
		
		calc.push_back(maxi);
		
	}
	
	for(int i=0;i<n;i++) printf("%.10lf ",calc[i]);
	
	cout << endl;
	
	return 0;
}