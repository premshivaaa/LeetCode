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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, -1, 0, 1};

        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col] == 1){
                    for(int i=0; i<4; i++){
                        int nrow = row + delrow[i];
                        int ncol = col + delcol[i];
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]){
                            int node = (row * n) + col;
                            int adjNode = (nrow * n) + ncol;
                            ds.unionBySize(node, adjNode);
                        }
                    }
                }
            }
        }
        
        int maxi = INT_MIN;
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col] == 0){
                    unordered_set<int> st;
                    for(int i=0; i<4; i++){
                        int nrow = row + delrow[i];
                        int ncol = col + delcol[i];
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol] == 1){
                            int adjNode = (nrow * n) + ncol;
                            st.insert(ds.findUParent(adjNode));
                        }
                    }
                    int total = 1;
                for(auto it : st){
                    total += ds.size[it];
                }
                maxi = max(maxi, total);
                }
            }
        }
        for(int i=0; i<n*n; i++){
            maxi = max(maxi, ds.size[ds.findUParent(i)]);
        }

        return maxi;
    }
};