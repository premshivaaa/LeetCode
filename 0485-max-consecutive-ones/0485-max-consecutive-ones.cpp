class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0, right = 0, maxlen = 0;

        while(right < nums.size()){
            if(nums[right] == 0) left = right + 1;

            maxlen = max(right - left + 1, maxlen);
            right++;
        }
        return maxlen;
    }
};