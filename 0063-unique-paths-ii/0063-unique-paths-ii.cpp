class Solution {
private:
    int solve(int x, int y, int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        if(x >= m || y >= n) return 0;
        if(obstacleGrid[x][y] == 1) return 0;

        if(x == m-1 && y == n-1) return 1;

        if(dp[x][y] != -1) return dp[x][y];

        int right = solve(x, y+1, m, n, obstacleGrid, dp);
        int down = solve(x+1, y, m, n, obstacleGrid, dp);

        return dp[x][y] = right + down; 
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(101, vector<int>(101, -1));
        return solve(0, 0, obstacleGrid.size(), obstacleGrid[0].size(), obstacleGrid, dp);
    }
};