#include<bits/stdc++.h>
using namespace std;
#define local 
#define ll long int

void dfs(int node,vector<int> adj[],vector<int> &vis){
     vis[node]=1;
     cout<<node<<" ";
     for(auto it:adj[node]){
         if(!vis[it])
            dfs(it,adj,vis);
     }
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> adj[n+1];
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> vis(n+1,0);
	for(int i=1;i<=n;i++){
	    if(!vis[i])
	    dfs(i,adj,vis);
	}
}
