
bool vis[100005] = {false};
bool pathVis[100005] = {false};
bool hasCycle(vector<vector<int>>g, int node){
    vis[node] = true;
    pathVis[node] = true;
    for(int j=0; j<g[node].size(); j++){
        int adjacent = g[node][j];
        if(!vis[adjacent] && hasCycle(g,adjacent))return true;
        else if(pathVis[adjacent])return true;
    }
    pathVis[node] = false;
    return false;
}
// O(V+E)