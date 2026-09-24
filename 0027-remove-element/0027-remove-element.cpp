class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {

            while (right >= left && nums[right] == val) {
                right--;
            }

            if (left <= right && nums[left] == val) {
                swap(nums[left], nums[right]);
                right--;
            }

            left++;
        }

        return right + 1;
    }
};