#include<bits/stdc++.h>
using namespace std;

void DFS_Final(bool visited[],vector<int>adj[],int node)
{
    visited[node]=1;
    cout<<node<<" ";
    for(int i=0;i<adj[node].size();i++)
    {
        int x=adj[node][i];
        if(!visited[x]){
            DFS_Final(visited,adj,x);
        }
    }
}
/*
void DFS(bool visited[],vector<int>adj[],int vertex)/// activate this function if starting node isn't given
{
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            DFS_Final(visited,adj,i);
        }
    }
}
*/
main()
{
    int v,e;
    cin>>v>>e;
    vector<int>adj[v+3];
    bool visited[v+1]={0};
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        /// adj[b].push_back(a); [ if it's not a directed graph]
    }
    /// if starting node is given
    cout<<"Enter Starting Node ";
    int starting_node;
    cin>>starting_node;
    DFS_Final(visited,adj,starting_node);

    /// else iterate through every vertex
    /*
    DFS(visited,adj,vertex);
    */
}
