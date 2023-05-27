#include<bits/stdc++.h>
using namespace std;
int maxD,maxNode;
void DFS(bool visited[],vector<int>adj[],int node,int distance)
{
    visited[node]=1;
    if(distance>maxD){
        maxD=distance;
        maxNode=node;
    }
    for(int i=0;i<adj[node].size();i++){
        int n=adj[node][i];
        if(!visited[n]){
            DFS(visited,adj,n,distance+1);
        }
    }
}
main()
{
    int vertex;
    cin>>vertex;
    vector<int>adj[vertex+1];
    bool visited[vertex+1]={0};
    for(int i=0;i<vertex-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    maxD=-1;
    DFS(visited,adj,1,0);
    maxD=-1;
    memset(visited,0,sizeof(visited));
    DFS(visited,adj,maxNode,0);
    cout<<maxD;
}
