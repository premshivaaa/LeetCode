class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        // {neighbor, color}
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto &it : redEdges){
            adj[it[0]].push_back({it[1], 0}); // red
        }
        for(auto &it : blueEdges){
            adj[it[0]].push_back({it[1], 1}); // blue
        }

        // dist[node][color]
        vector<vector<int>> dist(n, vector<int>(2, INT_MAX));
        
        queue<pair<int,int>> q; // {node, last_color}

        // start from node 0 with both colors
        q.push({0, 0});
        q.push({0, 1});
        dist[0][0] = 0;
        dist[0][1] = 0;

        while(!q.empty()){
            auto [node, color] = q.front();
            q.pop();

            for(auto &[nei, edgeColor] : adj[node]){
                
                // must alternate color
                if(edgeColor != color && dist[nei][edgeColor] == INT_MAX){
                    dist[nei][edgeColor] = dist[node][color] + 1;
                    q.push({nei, edgeColor});
                }
            }
        }

        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            int d = min(dist[i][0], dist[i][1]);
            ans[i] = (d == INT_MAX ? -1 : d);
        }

        return ans;
    }
};