class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int, int> , int>> q;
        //int vis[m][n];
        int fresh = 0;
        int cnt = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                   //vis[i][j] = 2;
                    q.push({{i, j}, 0});
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int time = 0;
        int delrow[4] = {-1, 1, 0, 0};
        int delcol[4] = {0, 0, -1, 1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int tm  = q.front().second;
            time = max(time, tm);
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol] == 1){
                    q.push({{nrow, ncol}, tm + 1});
                    grid[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }

        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if(vis[i][j] != 2 && grid[i][j] == 1){
        //             return -1;
        //         }
        //     }
        // }
        if(fresh != cnt){
            return -1;
        }

        return time;
    }
};