class Solution {
private:
    void quickSort(vector<int>& nums, int low, int high){
        if(low < high){
            int partIdx = partition(nums, low, high);
            quickSort(nums, low, partIdx-1);
            quickSort(nums, partIdx+1, high);
        }
    }
    int partition(vector<int>& nums, int low, int high){
        int pivot = nums[low];
        int left = low;
        int right = high;

        while(left < right){
            while(left <= high-1 && nums[left] <= pivot) left++;

            while(right >= low+1 && nums[right] > pivot) right--;

            if(left < right) swap(nums[left], nums[right]);
        }
        swap(nums[low], nums[right]);
        return right;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);

        return nums;
    }
};