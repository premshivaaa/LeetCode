class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n <= 1) return {0};
        vector<int> degree(n, 0);
        vector<vector<int>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            degree[it[0]]++;
            degree[it[1]]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(degree[i] == 1) q.push(i);
        }

        int remaining = n;
        while(remaining > 2){
            int size = q.size();
            remaining -= size;

            for(int i=0; i<size; i++){
                int node = q.front();
                q.pop();
                for(auto it : adj[node]){
                    degree[it]--;
                    if(degree[it] == 1) q.push(it);
                }
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
        }

        return ans;
    }
};