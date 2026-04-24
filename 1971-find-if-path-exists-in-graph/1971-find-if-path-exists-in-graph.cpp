class Solution {
private:
    bool dfs(int node, int destination, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1;
        if(node == destination) return true;

        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it, destination, adj, vis)) return true;
            }
        }
        return false;
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);

        return dfs(source, destination, adj, vis);
    }
};