#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,m,d;

    cin >> n >> m >> d;

    set < pair <int,int> > conj;

    int arr[n];

    for(int i=0;i<n;i++){

        cin >> arr[i];

        conj.insert( make_pair(arr[i],i) );

    }

    int saida[n];

    int dia = 1;

    while(!conj.empty()){

        set < pair <int,int> >::iterator it = conj.begin();

        while(it != conj.end()){
            
            saida[it->second] = dia;

            int x = it->first;

            conj.erase(it);

            it = conj.lower_bound(make_pair(x+d+1,0));

        } 

        dia++;

    }

    cout << dia-1 << endl;
    
    for(int i=0;i<n;i++){

        cout << saida[i] << " ";

    }

    cout << endl;

    return 0;
}
