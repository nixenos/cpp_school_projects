#include <bits/stdc++.h>
using namespace std;
int tree[1000000];
//const int M=16;
int M=0;
void insert (int a, int v){
    a+=M;
    while(a>=1){
        tree[a]+=v;
        a/=2;
    }
}
int querry (int a, int b){
    a+=M;
    b+=M;
    int res=0;
    while (a<b){
        if (a%2==1){
            res+=tree[a++];
        }
        if (b%2==0){
            res+=tree[b--];
        }
    a/=2;
    b/=2;
    }
    if (a==b){
        res+=tree[a];
    }
    return res;
}
int main(){
    int a,b,c;
    int wielkosc_drzewa;
    cin >> wielkosc_drzewa;
    int k=(int)log2(wielkosc_drzewa-1)+1;
    M=1<<k;
    //cin >>a>>b>>c;
    while (true){
        cin >> a;
        if (a==0){
            cin >> b >> c;
            insert(b,c);
        }
        else if (a==1){
            cin >> b >> c;
            cout << querry(b,c)<<endl;
        }
        else 
            break;
    }
}
