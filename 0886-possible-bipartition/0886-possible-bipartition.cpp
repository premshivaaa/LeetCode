class DisjointSet{
    public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }
    int findUParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int ult_u = findUParent(u);
        int ult_v = findUParent(v);
        if(ult_u == ult_v) return;
        
        if(size[ult_u] < size[ult_v]){
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        else{
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto &it : dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        DisjointSet ds(n);

        for(int i = 1; i <= n; i++){
            for(auto it : adj[i]){
                if(ds.findUParent(i) == ds.findUParent(it)) 
                    return false;

                // union all neighbors of i together
                ds.unionBySize(adj[i][0], it);
            }
        }
        return true;
    }
};