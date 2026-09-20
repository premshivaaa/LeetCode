class Solution {
private:
    void solve(vector<int>& nums, int target, int &idx, int left, int right) {
        if (left > right)
            return;

        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            idx = mid;
            return;
        }

        if (nums[mid] > target)
            solve(nums, target, idx, left, mid - 1);
        else
            solve(nums, target, idx, mid + 1, right);
    }

public:
    int search(vector<int>& nums, int target) {
        int idx = -1;
        solve(nums, target, idx, 0, nums.size() - 1);
        return idx;
    }
};