class Solution {
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {     
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] == 1) return -1;
        if(grid[n-1][m-1] == 1) return -1;

        int delrow[8] = {-1, 0, 1, 0, -1, 1, -1, 1};
        int delcol[8]= {0, -1, 0, 1, -1, 1, 1, -1};

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[0][0] = 1;

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> q;
        q.push({1, {0,0}});

        while(!q.empty()){
            int row = q.top().second.first;
            int col = q.top().second.second;
            int dis = q.top().first;
            q.pop();

            if(row == n-1 && col == m-1) return dis;

            for(int i=0; i<8; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !grid[nrow][ncol] && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({dis+1, {nrow, ncol}});
                }
            }
        }

        return -1;
    }
};