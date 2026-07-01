class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int ele : nums){
            result ^= ele;
        }

        return result;
    }
};