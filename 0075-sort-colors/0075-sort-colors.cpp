class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0, ones = 0, twos = 0;
        for(int x : nums){
            if(x == 0) zeros++;
            else if(x == 1) ones++;
            else twos++;
        }
        int i = 0;
        while(zeros--){
            nums[i] = 0;
            i++;
        }
        while(ones--){
            nums[i] = 1;
            i++;
        }
        while(twos--){
            nums[i] = 2;
            i++;
        }
    }
};