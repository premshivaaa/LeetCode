class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto road : roads){
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        vector<long long> distances(n, LLONG_MAX);
        vector<int> ways(n, 0);

        distances[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long long, int>, 
                       vector<pair<long long, int>>, 
                       greater<pair<long long, int>>> pq;

        pq.push({0, 0});
        int mod = 1e9 + 7;

        while(!pq.empty()){
            auto [dist, node] = pq.top();
            pq.pop();

            if(dist != distances[node]) continue;

            for(auto [adjNode, edgeTime] : adj[node]){
                long long newDist = dist + edgeTime;

                if(newDist < distances[adjNode]){
                    distances[adjNode] = newDist;
                    ways[adjNode] = ways[node];
                    pq.push({newDist, adjNode});
                }
                else if(newDist == distances[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1];
    }
};