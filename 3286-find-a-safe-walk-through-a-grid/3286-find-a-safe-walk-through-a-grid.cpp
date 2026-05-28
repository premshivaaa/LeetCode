class Solution {
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, -1, 0, 1};
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        if(grid[0][0] == 1 && health <= 1) return false;
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> mat(m, vector<int>(n, -1));
        priority_queue<pair<int, pair<int,int>>> pq;
        
        if(grid[0][0]){
            pq.push({health-1, {0, 0}});
            mat[0][0] = health-1;
        }
        else{
            pq.push({health, {0, 0}});
            mat[0][0] = health;
        }

        while(!pq.empty()){
            int health = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n){
                    int newHealth = health - grid[nrow][ncol];

                    if(newHealth > 0 && newHealth > mat[nrow][ncol]){
                        mat[nrow][ncol] = newHealth;
                        pq.push({newHealth, {nrow, ncol}});
                    }
                }
            }
        }

        if(mat[m-1][n-1] < 1) return false;

        return true;
    }
};