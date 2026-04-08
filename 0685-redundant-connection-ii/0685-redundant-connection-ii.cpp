class Solution {
public:
    struct DSU {
        vector<int> parent;
        DSU(int n) {
            parent.resize(n + 1);
            iota(parent.begin(), parent.end(), 0);
        }
        int find(int i) {
            if (parent[i] == i) return i;
            return parent[i] = find(parent[i]);
        }
        bool unite(int i, int j) {
            int rootI = find(i);
            int rootJ = find(j);
            if (rootI != rootJ) {
                parent[rootI] = rootJ;
                return true;
            }
            return false; // Cycle detected
        }
    };

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0);
        vector<int> cand1, cand2;

        // Step 1: Check for node with two parents
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (parent[v] != 0) {
                // Node v has two parents: the current u and the previous parent[v]
                cand1 = {parent[v], v};
                cand2 = edge;
                edge[1] = 0; // Temporarily "remove" candidate 2
            } else {
                parent[v] = u;
            }
        }

        // Step 2: Use Union-Find to find cycles
        DSU dsu(n);
        for (auto& edge : edges) {
            if (edge[1] == 0) continue; // Skip the "removed" edge
            int u = edge[0], v = edge[1];
            if (!dsu.unite(u, v)) {
                // If a cycle is detected
                if (cand1.empty()) return edge; // Case 2: Only a cycle exists
                return cand1; // Case 3: Both exist, candidate 1 is in the cycle
            }
        }

        return cand2; // Case 1: Only two parents exist, or Case 3 where cand2 was the redundant one
    }
};