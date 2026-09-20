class Solution {
private:
    void solve(vector<int>& nums, int target, int &idx, int left, int right){
        if(left > right) return;
        int mid = left + (right - left) / 2;
        if(nums[mid] == target){
            idx = mid;
            return;
        }
        if(nums[left] <= nums[mid]){ // only moving towards sorted array here - classic bs
            if(nums[left] <= target && target < nums[mid]) solve(nums, target, idx, left, mid-1);
            else solve(nums, target, idx, mid+1, right);
        }
        else{ // or here
            if(nums[mid] < target && target <= nums[right]) solve(nums, target, idx, mid+1, right);
            else solve(nums, target, idx, left, mid-1);
        }
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int idx = -1;
        solve(nums, target, idx, 0, n-1);
        return idx;
    }
};