class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, pair<int,int>>> q;
        int total_time = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    //vis[i][j] = 1;
                    q.push({0, {i, j}});
                }
            }
        }
        int delrow[4] = {0, 1, 0, -1};
        int delcol[4] = {1, 0, -1, 0};
        while(!q.empty()){
            int time = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            total_time = time;

            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol] == 1){
                    //vis[nrow][ncol] = 1;
                    grid[nrow][ncol] = 2;
                    q.push({time+1, {nrow, ncol}});
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return total_time;
    }
};