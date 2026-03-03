class Solution {

private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, int n){
        vis[node] = 1;

        for(int i=0; i<n; i++){
            if(!vis[i] && adj[node][i] == 1){
                dfs(i, adj, vis, n);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int count = 0;


        for(int i=0; i<n; i++){
            if(!vis[i]){
                count++;
                dfs(i, isConnected, vis, n);
            }
        }
        return count;
    }
};