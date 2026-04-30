class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        // Build graph
        for (auto &it : prerequisites) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        // Store prerequisites using bitset (faster than set)
        vector<bitset<101>> pre(n);

        // Topological sort (Kahn's Algorithm)
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int u = q.front(); 
            q.pop();

            for (auto v : adj[u]) {
                // u is prerequisite of v
                pre[v][u] = 1;

                // inherit all prerequisites of u
                pre[v] |= pre[u];

                if (--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Answer queries
        vector<bool> ans;
        for (auto &q : queries) {
            ans.push_back(pre[q[1]][q[0]]);
        }

        return ans;
    }
};