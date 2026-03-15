class Solution {

private:
    bool check(int node, vector<vector<int>>& graph, vector<int>& color){
        color[0] = 0;
        queue<int> q;
        q.push(node);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : graph[node]){
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                } else if (color[it] == color[node]){
                    return false;
                }
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        for(int i=0; i<V; i++){
            if(color[i] == -1){
                if(check(i, graph, color) == false) return false;
            }
        }

        return true;
    }
};