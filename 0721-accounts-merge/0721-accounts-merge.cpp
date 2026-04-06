class DisjointSet{  
    public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }
    int findUParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mapMailNode;

        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail] = i;
                }
                else {
                    ds.unionBySize(mapMailNode[mail], i);
                }
            }
        }
        // merge the mails with same Ultimate Parent
        vector<vector<string>> mergedMails(n);
        for(auto it : mapMailNode){
            int node = ds.findUParent(it.second);
            string mail = it.first;

            mergedMails[node].push_back(mail);
        }
        // sort each merged mail respective to their names
        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            if(mergedMails[i].size() == 0) continue;

            sort(mergedMails[i].begin(), mergedMails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto mails : mergedMails[i]){
                temp.push_back(mails);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};