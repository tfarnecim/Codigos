#include <bits/stdc++.h>
using namespace std;

int n;
int dp[200][2];
vector <int> num;

int solve(int pos,int menor){
	
	if(dp[pos][menor]!=-1) return dp[pos][menor];
	
	if(pos==num.size()) return dp[pos][menor] = 0;
	
	int lim;

	if(menor){
		lim = 9;
	}else{
		lim = num[pos];
	}
	
	int resp = 0;
	
	for(int i=0;i<=lim;i++){
		
		int aux = menor;
		
		if(i < num[pos]) aux = 1;
		
		resp += i + solve(pos+1,aux);
		
	}
	
	return dp[pos][menor] = resp;
	
}

int main(){
		
	memset(dp,-1,sizeof(dp));
		
	cin >> n;
	
	vector <int> arr;
	
	while(n!=0){
		arr.push_back(n%10);
		n/=10;
	}
	
	for(int i=arr.size()-1;i>=0;i--){
		num.push_back(arr[i]);
	}
	
	cout << solve(0,0) << endl;
	
	return 0;
}