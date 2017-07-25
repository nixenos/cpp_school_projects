//dfs na listach sasiedstwa
#include <bits/stdc++.h>
#include <unistd.h>
#define MAX_N 10000
using namespace std;
int n; //wierzchołki
int m; //krawędzie
vector <int> neighbours[MAX_N+1]; //lista sasiedztwa
int father[MAX_N+1]={0};
bool visited[MAX_N+1]={0};
int dfs(int v){
    visited[v]=true;
    for(int i=0; i<neighbours[v].size(); i++){
        if (!visited[neighbours[v][i]]){
            dfs(neighbours[v][i]);
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        neighbours[a].push_back(b);
        neighbours[b].push_back(a);
    }
    dfs(1);
	return 0;
