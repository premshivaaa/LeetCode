class DisjointSet {
public:
    vector<int> rank, parent, size;

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUParent(u);
        int pv = findUParent(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
private:
    int intersect(vector<int>& a, vector<int>& b) {
        unordered_set<int> st(a.begin(), a.end());

        int cnt = 0;

        for (auto &it : b) {
            if (st.find(it) != st.end()) {
                cnt++;
                st.erase(it);
            }
        }

        return cnt;
    }

public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();

        DisjointSet ds(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int common = intersect(properties[i], properties[j]);

                if (common >= k) {
                    ds.unionBySize(i, j);
                }
            }
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (ds.findUParent(i) == i) cnt++;
        }

        return cnt;
    }
};