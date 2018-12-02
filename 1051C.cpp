#include <bits/stdc++.h>
using namespace std;

vector <int> aparece[200];

int main(){
	
	int n;
	
	cin >> n;
	
	int arr[n];
	
	int ajuda = 0;
	
	for(int i=0;i<n;i++){
		
		cin >> arr[i];
		
		aparece[ arr[i] ].push_back(i);
		
		if(aparece[ arr[i] ].size() == 3){
			
			ajuda++;
			
		}
		
	}
	
	int uns = 0;
	
	for(int i=1;i<=100;i++){
		
		if(aparece[i].size() == 1){
			uns++;
		}
		
	}
	
	if(uns%2!=0 && !ajuda){
		
		cout << "NO\n";
		return 0;
		
	}
	
	bool A = true;
	
	string saida;
	
	for(int i=0;i<n;i++){
		
		saida += ' ';
		
	}
	
	for(int i=0;i<n;i++){
		
		if(aparece[arr[i]].size()==1){
			
			if(A){
				
				saida[i] = 'A';
				A = false;
				
			}else{

				saida[i] = 'B';
				A = true;
				
			}
			
		}
		
		if(aparece[arr[i]].size()==2){
			
			saida[i] = 'A';
			
		}
		
	}
	
	for(int i=1;i<=100;i++){
		
		if(aparece[i].size() > 2 && uns%2==0){
			
			for(int c=0;c<aparece[i].size();c++){
				
				int pos = aparece[i][c];
				
				saida[pos] = 'A';
				
			}
			
		}else if(aparece[i].size() > 2 && uns%2!=0){
		
			saida[aparece[i][0]] = 'B';
			
			for(int c=1;c<aparece[i].size();c++){
				
				int pos = aparece[i][c];
				
				saida[pos] = 'A';
				
			}
			
			uns++;
				
		}
		
	}
	
	cout << "YES\n";
	cout << saida << endl;
	
	return 0;
}