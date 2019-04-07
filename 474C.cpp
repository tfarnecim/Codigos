/*  AUTHOR: EVERNEWBIE
** QuestaoDoCapeta.cpp
*/
#include <bits/stdc++.h>
using namespace std;

typedef complex <double> point;

#define PI 3.141592653589793
#define x real()
#define y imag()

double conv(double theta){
	return (theta*PI)/180.0;
}

bool ordena(point ant,point dps){
	return ant.x < dps.x;
}

double ccw(point a,point b,point c){
	
	point d = b-a;
	point e = c-a;

	return (conj(d)*e).y;
	
}

double cont(vector <point> p){
	
	double res = 0;
	
	point orig = p[0];
	
	for(int i=2;i<p.size()-1;i++){
		
		res += ccw(orig,p[i],p[i-1]) / 2.0;
		
	}
	
	return abs(res);
	
}

double euclidean(point a,point b){
	
	return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
	
}

double dot(point a,point b,point c){
	
	point d = a-b;
	point e = c-b;
	
	return (conj(d)*e).x;
	
}

int main(){
	
	int n;
	
	cin >> n;
	
	for(int i=0;i<n;i++){
		
		vector <point> ini;
		vector <point> orig;
		
		for(int j=0;j<4;j++){
			int a,b,c,d;
			cin >> a >> b >> c >> d;
			ini.push_back({(double)a,(double)b});
			orig.push_back({(double)c,(double)d});
		}
		
		int exit = 666;
		
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				for(int l=0;l<4;l++){
					for(int m=0;m<4;m++){
						
						point at[4];
						
						at[0] = (ini[0]-orig[0])*polar(1.0,conv(90*j))+orig[0];
						at[1] = (ini[1]-orig[1])*polar(1.0,conv(90*k))+orig[1];
						at[2] = (ini[2]-orig[2])*polar(1.0,conv(90*l))+orig[2];
						at[3] = (ini[3]-orig[3])*polar(1.0,conv(90*m))+orig[3];
						
						sort(at,at+4,ordena);
						
						vector <point> stack; 
						
						stack.push_back(at[0]);
						stack.push_back(at[1]);
						
						int t = 2;
						
						for(int z=2;z<4;z++){
							while(t >= 2 && ccw(stack[t-2],stack[t-1],at[z]) > 0){
								stack.pop_back();
								t--;
							}
							t++;
							stack.push_back(at[z]);
						}
						
						for(int z=2;z>=0;z--){
							while(t >= 2 && ccw(stack[t-2],stack[t-1],at[z]) > 0){
								stack.pop_back();
								t--;
							}
							t++;
							stack.push_back(at[z]);
						}
						
						vector <double> dist;
						
						for(int z=1;z<t;z++){
							dist.push_back(euclidean(stack[z],stack[z-1]));
						}
						
						bool dis = true;
						
						for(int z=1;z<dist.size();z++){
							if(abs(dist[z]-dist[z-1]) > 0.000001 || dist[z]==0){
								dis = false;
								break;
							}
						}
						
						double area = cont(stack);
						
						bool angulo = true;
						
						for(int z=2;z<stack.size();z++){
							if(abs(dot(stack[z-2],stack[z-1],stack[z])) > 0.000001){
								angulo = false;
								break;
							}
						}
						
						if(dis && area && angulo){
							exit = min(exit,j+k+l+m);
						}
						
					}
				}
			}
		}
		
		if(exit == 666){
			cout << -1 << endl;
		}else{
			cout << exit << endl;
		}
		
	}
	
	return 0;
}