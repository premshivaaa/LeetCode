class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int req = 0, actual = 0, n = nums.size();
        for(int i=1; i<=n; i++) req += i;
        for(int x : nums){
            actual += x;
        }
        return req - actual;
    }
};