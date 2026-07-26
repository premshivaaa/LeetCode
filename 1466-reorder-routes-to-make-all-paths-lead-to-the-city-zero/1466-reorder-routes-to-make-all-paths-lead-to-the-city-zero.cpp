class Solution {
private:
    void dfs(int node, vector<vector<pair<int,int>>>& adj, vector<int>& vis, int& count){
        vis[node] = 1;

        for(auto &it : adj[node]){
            int edge = it.first;
            int wt = it.second;

            if(!vis[edge]){
                count += wt;
                dfs(edge, adj, vis, count);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        vector<int> vis(n, 0);
        for(auto it : connections){
            adj[it[0]].push_back({it[1], 1});
            adj[it[1]].push_back({it[0], 0});
        }

        int count = 0;
        dfs(0, adj, vis, count);
        
        return count;
    }
};