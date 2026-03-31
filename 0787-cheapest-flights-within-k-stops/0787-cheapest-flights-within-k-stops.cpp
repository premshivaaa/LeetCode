class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto flight : flights){
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        vector<int> costs(n, INT_MAX);
        costs[src] = 0;
        queue<pair<int, pair<int, int>>> q; // { stops, {node, price}};
        q.push({0, {src, 0}});

        while(!q.empty()){
            int node = q.front().second.first;
            int price = q.front().second.second;
            int stops = q.front().first;
            q.pop();

            if(stops > k) continue;

            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgeP = it.second;
                if(price + edgeP < costs[adjNode]){
                    costs[adjNode] = price + edgeP;
                    q.push({stops + 1, {adjNode, costs[adjNode]}});
                }
            }
        }


        if(costs[dst] == INT_MAX) return -1;
        return costs[dst];
    }
};