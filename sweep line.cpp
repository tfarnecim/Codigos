#include <bits/stdc++.h>
using namespace std;

//funciona até N = 1000
#define N 1100

struct point{
    int x,y;	
};
struct event{
	int i,t;	
};

point rect[N][2];
bool usado[N*2];

bool comp_x(event ant,event dps){return rect[ant.i][ant.t].x < rect[dps.i][dps.t].x;}
bool comp_y(event ant,event dps){return rect[ant.i][ant.t].y < rect[dps.i][dps.t].y;}

int main(){
	
	int n,d;
	
	cin >> n;d = n*2;
	
	//primeiro ponto = superior esquerdo
	//segundo ponto = inferior direito
	
	event linhav[d];
	event linhah[d];
	
	for(int i=0;i<n;i++) cin >> rect[i][0].x >> rect[i][0].y >> rect[i][1].x >> rect[i][1].y;
	
	//inicializando
	for(int i=0;i<d;i++){linhah[i].i = i<n?i:i-n;linhah[i].t = i<n?0:1;}
	for(int i=0;i<d;i++){linhav[i].i = i<n?i:i-n;linhav[i].t = i<n?0:1;}
		
	sort(linhav,linhav+d,comp_x);
	sort(linhah,linhah+d,comp_y);
	
	int area = 0;
	usado[linhav[0].i] = true;
	
	for(int i=1;i<d;i++){
		                        /*ponto atual*/                   /*ponto anterior*/
		int delta_x = (rect[linhav[i].i][linhav[i].t].x) - (rect[linhav[i-1].i][linhav[i-1].t].x);
		
		cout << "EVENTO ATUAL.IND = " << linhav[i].i << endl;
		cout << "EVENTO ATUAL.TIP = " << linhav[i].t << endl;
		cout << endl;
		
		int iniy;
		int cont = 0;
		
		for(int j=0;j<d;j++){
			
			int pos = linhah[j].i;
			int tip = linhah[j].t;
			
			if(usado[pos]){
				
				if(tip == 0){
					
					cont--;
					if(cont==0){
						area += (rect[pos][0].y - iniy) * delta_x;
					}
					
				}else{
					
					if(cont==0){
						iniy = rect[pos][1].y;
					}
					cont++;
					
				}
				
			}
			
		}
		
		if(linhav[i].t){
			usado[linhav[i].i] = false;
		}else{
			usado[linhav[i].i] = true;
		}
		
	}
	
	cout << area << endl;
	
	return 0;
}