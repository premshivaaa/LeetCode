class Solution {
    int n, total_val;
private:
    void recursion(int idx, vector<int>& nums, int xr_val){
        if(idx == n){
            total_val += xr_val;
            return;
        }

        recursion(idx+1, nums, xr_val ^ nums[idx]);

        recursion(idx+1, nums, xr_val);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        n = nums.size();
        total_val = 0;
        recursion(0, nums, 0);

        return total_val;
    }
};