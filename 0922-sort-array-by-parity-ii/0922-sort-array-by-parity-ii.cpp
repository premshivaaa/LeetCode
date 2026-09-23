class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int left = 0, right = 1, n = nums.size();

        while (right < n && left < n) {
            if(nums[left]%2==1 && nums[right]%2==0){
                swap(nums[left],nums[right]);
                left+=2;
                right+=2;
            }
            if(left < n && nums[left]%2==0) left+=2;
            if(right < n && nums[right]%2==1) right+=2;
        }

        return nums;
    }
};