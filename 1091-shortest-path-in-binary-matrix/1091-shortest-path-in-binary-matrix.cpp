class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        queue<pair<int,int>> q;
        q.push({0, 0});
        
        // mark visited
        grid[0][0] = 1;

        int delrow[8] = {-1,-1,-1,0,0,1,1,1};
        int delcol[8] = {-1,0,1,-1,1,-1,0,1};

        int steps = 1;

        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                // Early exit
                if(row == n-1 && col == n-1) return steps;

                for(int i=0; i<8; i++){
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n 
                       && grid[nrow][ncol] == 0){
                        
                        q.push({nrow, ncol});
                        grid[nrow][ncol] = 1; // mark visited
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};