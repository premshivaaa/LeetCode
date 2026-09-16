class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();

        int streak = 1;

        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i-1] + 1)
                streak++;
            else
                streak = 1;

            if(i >= k - 1) {
                ans.push_back(streak >= k ? nums[i] : -1);
            }
        }

        return ans;
    }
};