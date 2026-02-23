class Solution {

public:

    void backtrack(vector<int>& nums, int i, vector<vector<int>>& ans, vector<int>& curr){

        if(i == nums.size()){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        backtrack(nums, i+1, ans, curr);

        curr.pop_back();
        backtrack(nums, i+1, ans, curr);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        backtrack(nums, 0, ans, curr);

        return ans;
    }
};