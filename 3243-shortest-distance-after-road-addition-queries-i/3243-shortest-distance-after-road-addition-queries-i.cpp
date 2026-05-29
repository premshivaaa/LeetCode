class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);

        for(int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }

        vector<int> ans;

        for(auto &q : queries) {
            int u = q[0];
            int v = q[1];

            adj[u].push_back(v);

            vector<int> dist(n, 1e9);
            dist[0] = 0;

            queue<int> bfs;
            bfs.push(0);

            while(!bfs.empty()) {
                int node = bfs.front();
                bfs.pop();

                for(auto nxt : adj[node]) {
                    if(dist[node] + 1 < dist[nxt]) {
                        dist[nxt] = dist[node] + 1;
                        bfs.push(nxt);
                    }
                }
            }

            ans.push_back(dist[n - 1]);
        }

        return ans;
    }
};