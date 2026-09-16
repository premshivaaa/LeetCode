class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k == 1) return nums;
        vector<int> ans;
        int n = nums.size();

        int cnt = 1;

        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i-1] + 1)
                cnt++;
            else
                cnt = 1;

            if(i >= k-1) {
                if(cnt >= k)
                    ans.push_back(nums[i]);
                else
                    ans.push_back(-1);
            }
        }

        return ans;
    }
};