class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        unordered_set<int> st;

        for(int ele : nums){
            if(ele == original){
                original = ele*2;
            }
        }
        return original;
    }
};