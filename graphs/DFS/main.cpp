#include <bits/stdc++.h>
#define MAX_N 1000000
using namespace std;

vector <int> V[MAX_N];
bool visited[MAX_N];

void DFS(int v){
	visited[v]=true;
	for(int i=0; i<V[v].size(); i++){
		if(!visited[V[i]]){
			visited[V[i]]=true;
			DFS(V[i]);
		}
	}
}

int main(){
	int n;
	cin >> n;
	for (int i=0; i<n; i++){
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	DFS(1);
	return 0;
}
