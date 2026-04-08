class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }

    bool unionBySize(int u, int v) {
        int pu = findUParent(u);
        int pv = findUParent(v);

        if (pu == pv) return false; // cycle detected

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> parent(n + 1, -1);
        vector<int> edge1, edge2;

        // Step 1: Detect node with two parents
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];

            if (parent[v] == -1) {
                parent[v] = u;
            } else {
                // Node with two parents found
                edge1 = {parent[v], v}; // first edge
                edge2 = {u, v};         // second edge
                edge[1] = 0;            // invalidate second edge
            }
        }

        // Step 2: DSU to detect cycle
        DisjointSet ds(n);

        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];

            if (v == 0) continue; // skip invalidated edge

            if (!ds.unionBySize(u, v)) {
                // Cycle found
                if (edge1.empty()) {
                    return edge;   // Case 1: only cycle
                }
                return edge1;      // Case 3: two parents + cycle
            }
        }

        // Step 3: No cycle → return second edge
        return edge2;              // Case 2: two parents only
    }
};