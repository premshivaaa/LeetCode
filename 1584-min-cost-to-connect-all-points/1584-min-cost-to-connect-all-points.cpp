class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        u = findParent(u);
        v = findParent(v);

        if (u == v) return;

        if (rank[u] < rank[v]) {
            parent[u] = v;
        }
        else if (rank[v] < rank[u]) {
            parent[v] = u;
        }
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        // {weight, {u, v}}
        vector<pair<int, pair<int, int>>> edges;

        // Build all edges
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int wt = abs(points[i][0] - points[j][0]) +
                         abs(points[i][1] - points[j][1]);

                edges.push_back({wt, {i, j}});
            }
        }

        sort(edges.begin(), edges.end());

        DSU dsu(n);

        int cost = 0;
        int edgesUsed = 0;

        for (auto &edge : edges) {
            int wt = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            if (dsu.findParent(u) != dsu.findParent(v)) {
                dsu.unionByRank(u, v);
                cost += wt;
                edgesUsed++;

                // MST has exactly (n - 1) edges
                if (edgesUsed == n - 1)
                    break;
            }
        }

        return cost;
    }
};