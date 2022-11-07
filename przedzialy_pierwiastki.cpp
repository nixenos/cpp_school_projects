#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
const int MAX_TAB=1000000;
const int MAX_SQ=400;
int tab[MAX_TAB]={0};
int kub[MAX_SQ]={0};
int n=0;
int sqt=0;
void inserting(int a, int b){
    //int sqt=ceil(sqrt(n));
    tab[a]+=b;
    kub[a/sqt]+=b;
}
int querry(int a, int b){
    //int sqt=ceil(sqrt(n));
    int kub_a=a/sqt;
    int kub_b=b/sqt;
    int res=0;
    for (int i=kub_a+1; i<=kub_b; ++i){
        res+=kub[i];
    }
    for (int i=a; i<min(b, (kub_a+1)*(sqt-1)); i++){
        res+=tab[i];
    }
    if(kub_a!=kub_b){
        for (int i=kub_b*sqt; i<=b; i++){
            res+=tab[i];
        }
    }
    return res;
}
int main(){
    cin >> n;
    sqt=ceil(sqrt(n));
    int a, b, v;
    int x=0;
    while (cin>>x){
        switch(x){
            case 0:{
                       cin >> a >> v;
                       inserting(a, v);
                       break;
            }
            case 1:{
                       cin >> a >> b;
                       cout << querry(a, b) << endl;
                       break;
                   }
            case 2:{
                       for (int i=0; i<n; i++){
                           cerr << tab[i] << " ";
                       }
                       cerr << endl;
                       for (int i=0; i<sqt; i++){
                           cerr << kub[i] << " ";
                       }
                       cerr << endl;
                       break;
                   }
            case 3:{
                       break;
                       //break;
                   }
        }
    }
	return 0;
}
