class Solution {
public:
    int findparent(int node, vector<int>& parent) {
        if (parent[node] == node)
            return node;
        return parent[node] = findparent(parent[node], parent);
    }


    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;
        // declaration 
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int comp = n;
        for (const auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];
            int parentU = findparent(u, parent);
            int parentV = findparent(v, parent);
            
            if (parentU != parentV) {
                parent[parentU] = parentV;
                comp--;
            }
        }
        return comp - 1;
    }
};