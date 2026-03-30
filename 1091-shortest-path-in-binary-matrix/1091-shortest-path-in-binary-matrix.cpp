class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vector<vector<int>> dist(n, vector(n, INT_MAX));
        dist[0][0] = 1;
        queue<pair<int,int>> q;
        q.push({0, 0});

        int delrow[8] = {-1,-1,-1,0,0,1,1,1};
        int delcol[8] = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<8; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && 
                dist[row][col] + 1 < dist[nrow][ncol] && grid[nrow][ncol] == 0){
                    dist[nrow][ncol] = dist[row][col] + 1;
                    q.push({nrow, ncol});
                }
            }
        }

        if(dist[n-1][n-1] == INT_MAX) return -1;

        return dist[n-1][n-1];
    }
};