class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> degree(n+2, 0);

        for(auto it : edges){
            degree[it[0]]++;
            degree[it[1]]++;
        }

        for(int i = 1; i <= n+1; i++){
            if(degree[i] == n) return i;
        }
        return -1;
    }
};