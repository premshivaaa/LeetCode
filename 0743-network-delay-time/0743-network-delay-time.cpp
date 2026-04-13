class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(const auto &it : times){
            adj[it[0]].emplace_back(it[1], it[2]);
        }

        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<>
        > pq;

        pq.emplace(0, k);

        while(!pq.empty()){
            auto [currDist, node] = pq.top();
            pq.pop();

            if(currDist > dist[node]) continue;

            for(const auto &[adjNode, edgeW] : adj[node]){
                int newDist = currDist + edgeW;

                if(newDist < dist[adjNode]){
                    dist[adjNode] = newDist;
                    pq.emplace(newDist, adjNode);
                }
            }
        }

        int maxi = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX) return -1;
            maxi = max(maxi, dist[i]);
        }

        return maxi;
    }
};