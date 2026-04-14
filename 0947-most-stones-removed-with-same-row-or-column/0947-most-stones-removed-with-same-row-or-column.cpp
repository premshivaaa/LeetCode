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
    int removeStones(vector<vector<int>>& stones) {
        int n=0, m=0, totalStones = 0;
        for(auto it : stones){
            n = max(n, it[0]);
            m = max(m, it[1]);
            totalStones++;
        }
        DisjointSet ds(n + m + 1);
        unordered_set<int> stoneNodes;
        
        for(auto it : stones){
            int rowNode = it[0];
            int colNode = it[1] + n + 1;
            ds.unionBySize(rowNode, colNode);
            stoneNodes.insert(rowNode);
            stoneNodes.insert(colNode);
        }
        int counter = 0;
        for(auto node : stoneNodes){
            if(ds.findUParent(node) == node){
                counter++;
            }
        }
        
        return totalStones - counter;
    }
};