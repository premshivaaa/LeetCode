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
    bool equationsPossible(vector<string>& equations) {
        DisjointSet ds(26);

        // Step 1: Process all ==
        for(auto it : equations){
            if(it[1] == '='){
                int u = it[0] - 'a';
                int v = it[3] - 'a';
                ds.unionBySize(u, v);
            }
        }

        // Step 2: Process all !=
        for(auto it : equations){
            if(it[1] == '!'){
                int u = it[0] - 'a';
                int v = it[3] - 'a';
                if(ds.findUParent(u) == ds.findUParent(v)) return false;
            }
        }

        return true;
    }
};