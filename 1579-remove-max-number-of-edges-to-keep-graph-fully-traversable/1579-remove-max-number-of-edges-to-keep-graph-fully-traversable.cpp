class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }

    bool unionBySize(int u, int v) {
        int pu = findUParent(u);
        int pv = findUParent(v);

        if(pu == pv) return false;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }

        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet alice(n);
        DisjointSet bob(n);

        int removable = 0;
        int aliceComponents = n;
        int bobComponents = n;

        // Process Type 3 edges first
        for(auto &e : edges) {
            int type = e[0];
            int u = e[1];
            int v = e[2];

            if(type == 3) {
                if(alice.unionBySize(u, v)) {
                    bob.unionBySize(u, v);

                    aliceComponents--;
                    bobComponents--;
                }
                else {
                    removable++;
                }
            }
        }

        // Process Type 1 and Type 2 edges
        for(auto &e : edges) {
            int type = e[0];
            int u = e[1];
            int v = e[2];

            if(type == 1) {
                if(alice.unionBySize(u, v)) {
                    aliceComponents--;
                }
                else {
                    removable++;
                }
            }
            else if(type == 2) {
                if(bob.unionBySize(u, v)) {
                    bobComponents--;
                }
                else {
                    removable++;
                }
            }
        }

        if(aliceComponents != 1 || bobComponents != 1) {
            return -1;
        }

        return removable;
    }
};