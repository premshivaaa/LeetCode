class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        u = findUParent(u);
        v = findUParent(v);

        if (u == v) return;

        if (size[u] < size[v]) {
            swap(u, v);
        }

        parent[v] = u;
        size[u] += size[v];
    }
};

class Solution {
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();

        vector<unordered_set<int>> sets(n);

        for (int i = 0; i < n; i++) {
            for (int x : properties[i]) {
                sets[i].insert(x);
            }
        }

        DisjointSet ds(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                auto &a = (sets[i].size() < sets[j].size()) ? sets[i] : sets[j];
                auto &b = (sets[i].size() < sets[j].size()) ? sets[j] : sets[i];

                int common = 0;

                for (int x : a) {
                    if (b.count(x)) {
                        common++;

                        if (common >= k) {
                            ds.unionBySize(i, j);
                            break;
                        }
                    }
                }
            }
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (ds.findUParent(i) == i) {
                cnt++;
            }
        }

        return cnt;
    }
};