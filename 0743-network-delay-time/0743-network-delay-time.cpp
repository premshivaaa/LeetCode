class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1); // { v, w }
        for(auto it : times){
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        queue<pair<int, int>> q;
        q.push({k, 0});

        while(!q.empty()){
            int node = q.front().first;;
            int currDist = q.front().second;
            q.pop();

            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgeW = it.second;

                if(currDist + edgeW < dist[adjNode]){
                    dist[adjNode] = currDist + edgeW;
                    q.push({adjNode, dist[adjNode]});
                }
            }
        }
        int maxi = INT_MIN;
        for(int i=1; i<=n; i++){
            if(dist[i] == INT_MAX) return -1;

            maxi = max(maxi, dist[i]);
        }
        return maxi;
    }
};