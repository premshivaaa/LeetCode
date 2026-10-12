class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int left = 0, right = n-1, main = n-1;
        while(left <= right){
            if(abs(nums[left]) > abs(nums[right])){
                ans[main] = nums[left] * nums[left];
                left++;
                main--;
            }
            else{
                ans[main] = nums[right] * nums[right];
                right--;
                main--;
            }
        }
        return ans;
    }
};