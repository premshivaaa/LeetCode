class Solution {
private:
    int solve(int index, vector<int>& nums, vector<int>& dp, int end){
        if(index > end) return 0;

        if(dp[index] != -1) return dp[index];

        int left = nums[index] + solve(index+2, nums, dp, end);
        int right = solve(index+1, nums, dp, end);

        return dp[index] = max(left, right);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        return max(solve(0, nums, dp1, n-2), solve(1, nums, dp2, n-1));
    }
};