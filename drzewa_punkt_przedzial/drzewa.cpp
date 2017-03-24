#include <bits/stdc++.h>
using namespace std;
vector <int> tree;
const int M=16;
//int M=0;
void insert (int a, int v){
    a+=M;
    while(a>=1){
        tree[a]+=v;
        a/=2;
    }
}
void query (int a, int b){
    while (a<b){
        if (a%2==1){
            
int main(){
    cin >> n;
    //int k=(int)log2(n-1)+1;
    //M=1<<k;
