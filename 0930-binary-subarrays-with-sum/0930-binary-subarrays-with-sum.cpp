class Solution {
private:
    int function(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        
        int left = 0, right = 0, count = 0, sum = 0;
        while(right < nums.size()){
            sum += nums[right];
            while(sum > goal){
                sum -= nums[left];
                left++;
            }

            count += (right-left+1);

            right++;
        }
        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return function(nums, goal) - function(nums, goal - 1);
    }
};