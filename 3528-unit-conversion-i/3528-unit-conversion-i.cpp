class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size();

        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &it : conversions) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        const int MOD = 1e9 + 7;

        vector<int> ans(n + 1);
        ans[0] = 1;

        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto &[adjNode, wt] : adj[node]) {
                ans[adjNode] = (1LL * ans[node] * wt) % MOD;
                q.push(adjNode);
            }
        }

        return ans;
    }
};