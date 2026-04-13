class Solution {
    vector<vector<int>> ans;
    int n;

private:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& path){
        if(node == n-1){
            ans.push_back(path);
            return;
        }

        for(auto it : graph[node]){
            path.push_back(it);
            dfs(it, graph, path);
            path.pop_back();
        }       
    }


public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        if(n <= 1) return {{0}};

        vector<int> path;
        path.push_back(0);

        dfs(0, graph, path);

        return ans;
    }
};