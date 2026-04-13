class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto &it : times){
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        pq.push({0, k});

        while(!pq.empty()){
            auto [currDist, node] = pq.top();
            pq.pop();

            for(auto &it : adj[node]){
                int adjNode = it.first;
                int edgeW = it.second;

                if(currDist + edgeW < dist[adjNode]){
                    dist[adjNode] = currDist + edgeW;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int maxi = 0;
        for(int i=1; i<=n; i++){
            if(dist[i] == INT_MAX) return -1;
            maxi = max(maxi, dist[i]);
        }

        return maxi;
    }
};