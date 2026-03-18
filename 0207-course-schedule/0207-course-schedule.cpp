class Solution {

private:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 2;

        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it, adj, vis) == false) return false;
            } else if (vis[it] == 2){
                return false;
            }
        }
        vis[node] = 1;
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses, 0);

        for(auto it : prerequisites){
            adj[it[0]].push_back(it[1]);
        }

        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis) == false) return false;
            }
        }

        return true;
    }
};