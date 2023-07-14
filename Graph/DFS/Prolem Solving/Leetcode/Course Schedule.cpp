class Solution {
public:
    vector<vector<int>>g;
    bool vis[2010] = {false};
    bool pathVis[2010] = {false};
    bool dfs(int node){
        vis[node] = true;
        pathVis[node] = true;
        for(int adjacent : g[node]){
            if(!vis[adjacent] && dfs(adjacent))return true;
            else if(pathVis[adjacent])return true;
        }
        pathVis[node] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& v) {
        g.resize(2001);
        for(int i=0;i<v.size();i++){
             g[v[i][0]].push_back(v[i][1]);
        }       
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i))return false;
            }
        }
        return true;
    }
};
// O(V+E)