class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {

                if(abs(nums[i] - nums[j]) <= min(nums[i], nums[j])) {
                    maxi = max(maxi, nums[i] ^ nums[j]);
                }

            }
        }

        return maxi;
    }
};