class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n + 1);
        
        for (auto &p : paths) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        vector<int> ans(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            bool used[5] = {false};

            for (auto it : adj[i]) {
                used[ans[it]] = true;
            }

            for (int color = 1; color <= 4; color++) {
                if (!used[color]) {
                    ans[i] = color;
                    break;
                }
            }
        }

        return vector<int>(ans.begin() + 1, ans.end());
    }
};