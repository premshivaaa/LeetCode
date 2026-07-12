class Solution {
    vector<vector<int>> ans;
    int n;
private:
    void recursion(int idx, vector<int>& nums, vector<int>& curr){
        if(idx >= n){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[idx]); // include
        recursion(idx+1, nums, curr);
        curr.pop_back();
        recursion(idx+1, nums, curr); // exclude
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> curr;
        recursion(0, nums, curr);

        return ans;
    }
};