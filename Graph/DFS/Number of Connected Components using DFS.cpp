#include<bits/stdc++.h>
using namespace std;
int connected_components;
void DFS(bool visited[],vector<int>adj[],int node)
{
    visited[node]=1;
    for(int i=0;i<adj[node].size();i++){
        int n=adj[node][i];
        if(!visited[n]){
            DFS(visited,adj,n);
        }
    }
}
main()
{
    int vertex,edge;
    cin>>vertex>>edge;
    connected_components=0;
    vector<int>adj[vertex+1];
    bool visited[vertex+1]={0};
    for(int i=0;i<edge;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=vertex;i++){
        if(!visited[i]){
            connected_components++;
            DFS(visited,adj,i);
        }
    }
    cout<<connected_components<<endl;
}
