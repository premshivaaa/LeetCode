class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto edge : edges){
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]*2});
        }
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push({0, 0});

        while(!pq.empty()){
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(dist[node] > weight) continue;

            for(auto it : adj[node]){
                int adjNode = it.first;
                int adjWeight = it.second;

                if(dist[node] + adjWeight < dist[adjNode]){
                    dist[adjNode] = dist[node] + adjWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        if(dist[n-1] == INT_MAX) return -1;

        return dist[n-1];
    }
};