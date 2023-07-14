class Solution {
  public:
    bool vis[100005] = {false};
    bool pathVis[100005] = {false};
    bool hasCycle(vector<int> adj[], int node){
        vis[node] = true;
        pathVis[node] = true;
        for(int j : adj[node]){
            if(!vis[j] && hasCycle(adj,j))return true;
            else if(pathVis[j])return true;
        }
        pathVis[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
       for(int i=0;i<V;i++){
           if(!vis[i]){
               if(hasCycle(adj,i))return true;
           }
       }
       return false;
    }
};
// O(V+E)