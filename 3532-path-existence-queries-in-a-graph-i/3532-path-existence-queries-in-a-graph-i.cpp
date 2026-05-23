class DisjointSet{
    public:
    vector<int> rank, parent, size;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }
    int findUParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }
    void unionByRank(int u, int v){
        int ult_u = findUParent(u);
        int ult_v = findUParent(v);
        if(ult_u == ult_v) return;
        
        if(rank[ult_u] < rank[ult_v]){
            parent[ult_u] = ult_v;
        }
        else if(rank[ult_v] < rank[ult_u]){
            parent[ult_v] = ult_u;
        }
        else{
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // if (maxDiff == 0) {
        //     return vector<bool>(queries.size(), true);
        // }

        vector<bool> ans;
        DisjointSet ds(n);

        for(int i=0; i<nums.size()-1; i++){
            if(abs(nums[i] - nums[i+1]) <= maxDiff){
                ds.unionBySize(i, i+1);
            }
        }

        for(auto &que : queries){
            int u = que[0];
            int v = que[1];

            if(u == v) ans.push_back(true);
            else{
                if(ds.findUParent(u) == ds.findUParent(v)) ans.push_back(true);
                else ans.push_back(false);
            }
        }

        return ans;
    }
};