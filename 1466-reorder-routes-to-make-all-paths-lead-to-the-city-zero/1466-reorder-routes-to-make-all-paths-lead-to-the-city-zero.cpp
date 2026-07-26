class Solution {
private:
    void dfs(int node, vector<vector<pair<int, int>>>& adj,
             vector<int>& vis, int& ans) {

        vis[node] = 1;

        for (auto &it : adj[node]) {
            int next = it.first;
            int cost = it.second;

            if (!vis[next]) {
                ans += cost;
                dfs(next, adj, vis, ans);
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back({v, 1}); // original direction
            adj[v].push_back({u, 0}); // reverse direction
        }

        vector<int> vis(n, 0);
        int ans = 0;

        dfs(0, adj, vis, ans);

        return ans;
    }
};