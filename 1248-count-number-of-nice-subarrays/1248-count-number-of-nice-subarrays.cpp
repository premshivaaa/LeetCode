class Solution {
private:
    int function(vector<int>& nums, int k){
        if(k < 0) return 0;
        int left = 0, right = 0, count = 0, sum = 0; 

        while(right < nums.size()){
            sum += (nums[right] % 2);

            while(sum > k){
                sum -= (nums[left] % 2);
                left++;
            }
            count += (right-left+1);
            right++;
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return function(nums, k) - function(nums, k-1);
    }
};