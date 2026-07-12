class Solution {
    vector<vector<int>> ans;
    vector<int> curr;
    int n;
private:
    void recursion(int idx, vector<int>& nums){
        if(idx >= n){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[idx]);
        recursion(idx+1, nums);
        curr.pop_back();

        while(idx+1 < n && nums[idx] == nums[idx+1]) idx++;

        recursion(idx+1, nums);

        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();

        recursion(0, nums);

        return ans;
    }
};