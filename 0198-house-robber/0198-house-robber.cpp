class Solution {
    int n;
private:
    int solve(int index, vector<int>& nums, vector<int>& dp){
        if(index >= n) return 0;

        if(dp[index] != -1) return dp[index];

        int left = nums[index] + solve(index+2, nums, dp);
        int right = solve(index+1, nums, dp);

        return dp[index] = max(left, right);
    }
public:
    int rob(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(n, -1);

        return solve(0, nums, dp);
    }
};