class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for(int j=0; j<k; j++) sum += nums[j];
        double max_avg = sum / k;

        for(int i=k; i<nums.size(); i++){
            sum += nums[i] - nums[i-k];
            max_avg = max(max_avg, sum / k);
        }

        return max_avg;
    }
};