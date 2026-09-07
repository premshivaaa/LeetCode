class Solution {
private:
    int function(vector<int>& nums, int k){
        if(k < 0) return 0;
        int left = 0, right = 0, count = 0;
        unordered_map<int,int> mp;
        while(right < nums.size()){
            mp[nums[right]]++;
            while(mp.size() > k){
                mp[nums[left]]--;
                if(mp[nums[left]] == 0) mp.erase(nums[left]);
                left++;
            }
            count += (right-left+1);
            right++;
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return function(nums, k) - function(nums, k-1);
    }
};