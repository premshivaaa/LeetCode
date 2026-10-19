class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int zeros = 0, prod = 1;
        for(int ele : nums){
            if(ele == 0){
                zeros++;
            } else {
                prod *= ele;
            }
            if(zeros >= 2) return vector<int> (n, 0);
        }
        vector<int> ans(n);
        if(zeros == 1){
            for(int i=0; i<n; i++){
                if(nums[i] == 0) ans[i] = prod;
                else ans[i] = 0;
            }
        }
        else{
            for(int i=0; i<n; i++){
                ans[i] = prod / nums[i];
            }
        }
        return ans;
    }
};