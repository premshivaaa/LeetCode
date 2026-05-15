class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        vector<vector<int>> connected(n, vector<int>(n, 0));

        for (auto &r : roads) {
            int u = r[0];
            int v = r[1];

            degree[u]++;
            degree[v]++;

            connected[u][v] = 1;
            connected[v][u] = 1;
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int rank = degree[i] + degree[j];

                if (connected[i][j])
                    rank--;

                ans = max(ans, rank);
            }
        }

        return ans;
    }
};